#include <iostream>
using namespace std;


double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double david(double a, double b)
{
    return a / b;
}

void sumArrs(const int* A, const int* B, int* C, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(C + i) = *(A + i) + *(B + i);
    }
}

int main()
{
    
    /*double (*operations[])(double, double) = {add,sub,mul,david};
    int choice;
    double a, b;
    

    cout << "(1) +\n";
    cout << "(2) -\n";
    cout << "(3) *\n";
    cout << "(4) /\n";

    cout << "choose operation: ";
    cin >> choice;

    cout << "enter two numbers: ";
    cin >> a >> b;

    cout << "res= " << operations[choice - 1](a, b) << endl;

    */

    const int size = 5;

    int a[size] = { 1, 2, 3, 4, 5 };
    int b[size] = { 10, 20, 30, 40, 50 };
    int c[size];

    sumArrs(a,b,c, size);
    cout << "arr C:\n";

    for (int i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }

}