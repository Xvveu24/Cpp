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
    /*double distance, timeToDrive;

    cout << "Enter distance to airport (km): ";
    cin >> distance;
    cout << "Enter time allowed (hours, ex: 1.5): ";
    cin >> timeToDrive;
    double requiredSped = distance / timeToDrive;

    cout << "yuy need to drive at speed: " << requiredSped << " kmh";*/

    // task6
    /*double distance, consmpt;
    double price1, price2, price3;

    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Enter fuel consumption per 100 km: ";
    cin >> consmpt;

    cout << "Enter price of gasoline 1: ";
    cin >> price1;

    cout << "Enter price of gasoline 2: ";
    cin >> price2;

    cout << "Enter price of gasoline 3: ";
    cin >> price3;

    double fuelNeeded = distance * consmpt / 100.0;

    cout << '\n' << "Fuel needed: " << fuelNeeded << " liters\n";
    cout <<  "Cost for gasoline 1: " << fuelNeeded * price1 << '\n';
    cout << "Cost for gasoline 2: " << fuelNeeded * price2 << '\n';
    cout << "Cost for gasoline 3: " << fuelNeeded * price3 << '\n';*/
    
    // task7
    /*int totalSeconds;

    cout << "Enter seconds from beginning of day: ";
    cin >> totalSeconds;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    cout << "current tiem, : " << hours << " h " << minutes << " min " << seconds << " sec\n";

    int secondsToMid = 24 * 3600 - totalSeconds;

    int hLeft = secondsToMid / 3600;
    int mLeft = (secondsToMid % 3600) / 60;
    int sLeft = secondsToMid % 60; 

    cout << "until midnight: " << hLeft << " h " << mLeft << " min " << sLeft << " sec\n";*/

    // task8
    int workedS;

    cout << "enter seconds from beginning of work day: ";
    cin >> workedS;

    int workDS = 8 * 3600;

    if (workedS >= workDS)
    {
        cout << "wrrking day is over\n";
    } else {
        int remainingS = workDS - workedS;
        int remainingH = remainingS / 3600;

        cout << "go WORK for the next " << remainingH <<" hours😂😂" << '\n';
    }

}

