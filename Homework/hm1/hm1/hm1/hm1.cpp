#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Користувач вводить час у секундах.Необхідно написати програму, яка переведе введені користувачем секунди в години, хвилини, секунди і виведе їх на екран.
    /*int seconds;
    cout << "enter amount of seconds: ";
    cin >> seconds;

    int hours = seconds / 3600;
    int remaining = seconds % 3600;
    int minutes = remaining / 60;
    int secleft = remaining % 60;

    cout << "hours: " << hours << "\nminutes: " << minutes << "\nseconds:" << secleft;*/

    //task2 Завдання 2 //Написати програму, яка перетворює введене з клавіатури дробове число в грошовий формат.Наприклад, число 12, 5 має бути перетворено до вигляду 12грн. 50 шагів.
    /*double money;
    cout << "enter money, example: 12.5 : ";
    cin >> money;
    int gr = money;
    int kop = (money - gr) * 100;
    cout<< "grivenb: " << gr;
    cout << " kopiyok: " << kop;*/

    //task3 
    /*cout << "calculating V of runner \n";
    int S;
    cout << "enter S: ";
    cin >> S;
    double t;
    cout << "enter Time (min,sec): ";
    cin >> t;
    int minutes = t;

    int seconds = round((t - minutes) * 100);
    int time = minutes * 60 + seconds;

    

    cout << "distance: " << S << '\n';
    cout << "Time: " << minutes << "min" << seconds << 's' << '=' << time << "seconds" << '\n';
    double km = S / 1000.0;
    double h = (double)time / 3600.0;

    float speed = km / h;
    
    cout << "V: " << speed << "kmh";*/

    //task4
    /*int totalDays;
    cout << "Enter number of days: ";
    cin >> totalDays;

    int weeks = totalDays / 7;
    int remainingdays = totalDays % 7;

    cout << totalDays << " days = " << weeks << " weeks and " << remainingdays << " days.\n";*/

    //task5
    double distance, timeToDrive;

    cout << "Enter distance to airport (km): ";
    cin >> distance;
    cout << "Enter time allowed (hours, e.g. 1.5): ";
    cin >> timeToDrive;
    double requiredSpeed = distance / timeToDrive;

    cout << "You need to drive at speed: " << requiredSpeed << " kmh";


}

