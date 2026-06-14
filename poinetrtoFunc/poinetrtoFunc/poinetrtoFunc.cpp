#include <iostream> // Подключаем библиотеку для ввода/вывода
using namespace std;

// Пустая функция FOO (в данном примере не используется)
void FOO() {
    // Здесь могла бы быть какая-то логика
}

// Обычная функция, которая принимает два int и возвращает их сумму
int sum(int num1, int num2) {
    return num1 + num2;
}

double sum(double num1, double num2 = 10.0) {
    return num1 + num2;
}

double sub(double num1, double num2 ) {
    return num1 - num2;
}
double mul(double num1, double num2 = 10.0) {
    return num1 * num2;
}
double div(double num1, double num2 = 10.0) {
    return num1 / num2;
}

//csallback

void calcANdPrint(double num1, double num2, double(*callback)(double, double)) {
    cout << callback(num1, num2) << '\n';
}

template<typename T1, typename T2>
//double(T1) * int(T2) = double(T1)
// int(t1 * double(t2) = double(t2)
auto multiply(T1 value1, T2 value2) {
    return value1 * value2;
}

int main()
{
    cout<<multiply(10, 12.3)<<'\n';

    //auto decltype
    auto number = 10;
    auto number1 = 10 + 8.7;

    decltype(10 + 9.6) number2 = 10;

    /*double (*calc[])(double, double) = { sum,sub,mul,div};

    double num1, num2;
    cin >> num1 >> num2;*/

    //for (int i = 0; i < 4; i++) {
    //    calcANdPrint(num1, num2, calc[i]);
    //    /*cout << calc[i](num1, num2) << '\n';*/
    //}

    // Объявляем указатель на функцию:
    // int(*ptr)(int, int) — это тип "указатель на функцию, которая принимает два int и возвращает int"
    // Присваиваем ему адрес функции sum (имя функции без скобок — это её адрес)
    int (*ptr)(int, int) = sum;

    // Вызываем функцию через указатель:
    // ptr(12, 10) — это то же самое, что sum(12, 10)
   /* cout << "sum: " << ptr(12, 10) << ' ';*/

    
}


    /*int(*ptr) (int, int) = sum;
    int n1;
    cout << "number1: " ;
    cin >> n1;
    int n2;
    cout << "number2: ";
    cin >> n2;
    cout << "sum: " << ptr(n1, n2) << ' ';*/

    /*cout << FOO << ' ';
    cout << main << ' ';*/


