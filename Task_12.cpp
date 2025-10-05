#include <iostream>
const double PI = 3.14159265358979323846;

using namespace std;

// Функция модуля
double fabs(double x) {
    if (x < 0)
        return -x;
    return x;
}

// Функция возведения числа в степень
double pow(double x, int y) {
    double z = 1;
    for (int i = 1; i <= y; ++i)
        z *= x;
    return z;
}

// Функция нахождения корня квадратного для неотрицательных чисел
double sqrt(double x) {
    if (x < 0)
        return 0;
    if (x == 0)
        return 0;

    double guess = x;
    double prev_guess;
    for (int i = 0; i <= 100; ++i) {
        prev_guess = guess;
        guess = (guess + x / guess) / 2;
        if (fabs(guess - prev_guess) < 1e-10)
            break;
    }
    return guess;
}

// Нахождение arctg
double arctg(double x) {
    if (x > 1)
        return PI / 2 - arctg(1 / x);
    if (x < -1)
        return -PI / 2 - arctg(1 / x);
    if (x == 0)
        return 0;
    double result = 0.0;
    double term = x;
    int n = 1;
    for (int i = 0; i <= 100; ++i) {
        result += term;
        n += 2;
        term = -term * pow(x, 2) * (n - 2) / n;
        if (fabs(term) < 1e-10)
            break;
    }
    return result;
}

// Нахождение arccos
double arccos(double x) {
    if (x >= 1)
        return 0;
    if (x <= -1)
        return PI;
    return PI / 2 - arctg(x / sqrt(1 - pow(x, 2)));
}

// Функция нахождения кубического корня из числа
double sqrt3(double x) {
    double t, t_new = fabs(x / 3);
    do {
        t = t_new;
        t_new = (2 * t + x / pow(t, 2)) / 3;
    } while (fabs(t - t_new) > 1e-10);
    return x >= 0 ? t_new : -t_new;
}

// Функция нахождния факториала
int factorial(int x) {
    int result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

// Реализация fmod для нахождения остатка от деления double
double fmod(double a, double b) {
    double devision = a / b;
    int temp = int(devision); 
    return a - ((devision < 0) ? temp - 1 : temp) * b;
}

// Функция нахождения cos
double calc_cos(double x) {
    bool sign = false;
    int term = 10;
    double result = 1;
    x = fmod(x, (2 * PI));
    if (x < 0) {
        x = -x;
    }
    if (x > (PI / 2)) {
        x = PI - x;
        sign = true;
    }
    for (int i = 1; i <= term; ++i) {
        if (i % 2 == 1)
            result -= pow(x, i * 2) / factorial(2 * i);
        else
            result += pow(x, i * 2) / factorial(2 * i);
    }
    return sign ? -result : result;
}

int main() {
    bool isIncorrect;
    double p, q, delta;
    do {
        isIncorrect = false;
        cout << "Введите значения p, q: ";
        cin >> p >> q;
        if (cin.fail()) {
            cin.clear();
            cout << "Ошибка: вводу подлежат только вещественные числа" << endl;
            while (cin.get() != '\n');
            isIncorrect = true;
        }
    } while (isIncorrect);

    delta = pow((q / 2), 2) + pow((p / 3), 3);
    if (delta > 0) {
        cout << "Вещественный корень данного уравнения один: x = " << sqrt3(-q / 2 + sqrt(delta)) + sqrt3(-q / 2 - sqrt(delta)) << endl;
    } else if (delta == 0) {
        cout << "Вещественных корней данного уравнения 3: x1 = " << 2 * sqrt3(-q / 2) << ", x2 = x3 = " << -sqrt3(-q / 2) << endl;
    } else {
        cout << "Вещественных корней данного уравнения 3:" << endl;
        for (int k = 0; k < 3; ++k) {
            cout << "x" << k <<" = " << 2 * sqrt(-p / 3) * calc_cos((1.0 / 3.0) * arccos(-q / 2 / sqrt(pow(-p / 3, 3))) - (2 * PI * k) / 3) << endl;
        }
    }
    return 0;
}