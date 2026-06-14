#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#pragma comment(lib, "winmm.lib")

struct GameState {
    double posX, posY;
    double velX, velY;
    int boxSize;
    bool dragging;
    POINT lastMouse;
    COLORREF bgColor;
    double timeSinceChange;
} game;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void PhysicsUpdate(HWND hwnd, double dt);
void ResetBoxPosition(HWND hwnd);

MMRESULT timerID;
LARGE_INTEGER freq, lastTime;
HWND g_hwnd;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    srand((unsigned)time(NULL));

    const wchar_t CLASS_NAME[] = L"SinisterBox";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClass(&wc)) return 0;

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Sinister Roaming Box",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );
    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    game.boxSize = 60;
    game.dragging = false;
    ResetBoxPosition(hwnd);

    // Initial roaming velocity
    game.velX = (rand() % 200 - 100) / 10.0;
    game.velY = (rand() % 200 - 100) / 10.0;
    game.bgColor = RGB(255, 255, 255);
    game.timeSinceChange = 0;

    g_hwnd = hwnd;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&lastTime);
    timeBeginPeriod(1);
    timerID = timeSetEvent(1, 0, [](UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        double dt = (now.QuadPart - lastTime.QuadPart) / (double)freq.QuadPart;
        lastTime = now;
        PhysicsUpdate(g_hwnd, dt);
        }, 0, TIME_PERIODIC);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    timeKillEvent(timerID);
    timeEndPeriod(1);
    return 0;
}

void ResetBoxPosition(HWND hwnd) {
    RECT client;
    GetClientRect(hwnd, &client);
    game.posX = (client.right - game.boxSize) / 2.0;
    game.posY = (client.bottom - game.boxSize) / 2.0;
}

void PhysicsUpdate(HWND hwnd, double dt) {
    RECT client;
    GetClientRect(hwnd, &client);

    if (!game.dragging) {
        // Move
        game.posX += game.velX * dt * 1000;
        game.posY += game.velY * dt * 1000;

        // Bounce
        double elasticity = 0.9;
        if (game.posX < 0) { game.posX = 0; game.velX = -game.velX * elasticity; }
        if (game.posX + game.boxSize > client.right) { game.posX = client.right - game.boxSize; game.velX = -game.velX * elasticity; }
        if (game.posY < 0) { game.posY = 0; game.velY = -game.velY * elasticity; }
        if (game.posY + game.boxSize > client.bottom) { game.posY = client.bottom - game.boxSize; game.velY = -game.velY * elasticity; }

        // Friction but never stop
        double friction = 0.995;
        game.velX *= friction;
        game.velY *= friction;
        double minSpeed = 0.5;
        if (fabs(game.velX) < minSpeed) game.velX = (game.velX >= 0 ? minSpeed : -minSpeed);
        if (fabs(game.velY) < minSpeed) game.velY = (game.velY >= 0 ? minSpeed : -minSpeed);

        // Random behavior timer
        game.timeSinceChange += dt;
        if (game.timeSinceChange > (rand() % 3 + 2)) { // every 2-5 seconds
            // Random direction change
            game.velX += (rand() % 200 - 100) / 10.0;
            game.velY += (rand() % 200 - 100) / 10.0;

            // Random background flash
            game.bgColor = RGB(rand() % 256, rand() % 256, rand() % 256);

            // Sometimes speed burst
            if (rand() % 4 == 0) {
                game.velX *= 2;
                game.velY *= 2;
            }

            game.timeSinceChange = 0;
        }
    }

    InvalidateRect(hwnd, NULL, FALSE);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_LBUTTONDOWN: {
        int mouseX = GET_X_LPARAM(lParam);
        int mouseY = GET_Y_LPARAM(lParam);

        if (mouseX >= game.posX && mouseX <= game.posX + game.boxSize &&
            mouseY >= game.posY && mouseY <= game.posY + game.boxSize) {
            game.dragging = true;
            game.velX = game.velY = 0;
            game.lastMouse.x = mouseX;
            game.lastMouse.y = mouseY;
            SetCapture(hwnd);
        }
    }
                       return 0;

    case WM_MOUSEMOVE:
        if (game.dragging) {
            int mouseX = GET_X_LPARAM(lParam);
            int mouseY = GET_Y_LPARAM(lParam);

            double dx = mouseX - game.lastMouse.x;
            double dy = mouseY - game.lastMouse.y;

            game.posX += dx;
            game.posY += dy;

            // Throw boost
            game.velX = dx * 3.0;
            game.velY = dy * 3.0;

            game.lastMouse.x = mouseX;
            game.lastMouse.y = mouseY;

            InvalidateRect(hwnd, NULL, FALSE);
        }
        return 0;

    case WM_LBUTTONUP:
        if (game.dragging) {
            game.dragging = false;
            ReleaseCapture();
        }
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT client;
        GetClientRect(hwnd, &client);

        // Double buffering
        HDC memDC = CreateCompatibleDC(hdc);
        HBITMAP memBitmap = CreateCompatibleBitmap(hdc, client.right, client.bottom);
        HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

        // Fill background with current sinister color
        HBRUSH bgBrush = CreateSolidBrush(game.bgColor);
        FillRect(memDC, &client, bgBrush);
        DeleteObject(bgBrush);

        // Draw the roaming box
        RECT boxRect = {
            (LONG)game.posX,
            (LONG)game.posY,
            (LONG)(game.posX + game.boxSize),
            (LONG)(game.posY + game.boxSize)
        };
        HBRUSH boxBrush = CreateSolidBrush(RGB(255, 0, 0));
        FillRect(memDC, &boxRect, boxBrush);
        DeleteObject(boxBrush);

        // Copy from memory DC to screen
        BitBlt(hdc, 0, 0, client.right, client.bottom, memDC, 0, 0, SRCCOPY);

        // Cleanup
        SelectObject(memDC, oldBitmap);
        DeleteObject(memBitmap);
        DeleteDC(memDC);

        EndPaint(hwnd, &ps);
    }
                 return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Console entry point wrapper
int main() {
    return wWinMain(GetModuleHandle(NULL), NULL, GetCommandLineW(), SW_SHOWNORMAL);
}
