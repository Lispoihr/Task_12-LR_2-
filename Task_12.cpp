#include <iostream>

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

// Функция нахождения корня для неотрицательных чисел
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

int main() {
    bool isIncorrect;
    double a, b, c, D, t1, t2, D1, D2;
    double _a = 1, _b1, _b2, _c = 1;
    do {
        isIncorrect = false;
        cout << "Введите значения a, b, c: ";
        cin >> a >> b >> c;
        if (cin.fail()) {
            cin.clear();
            cout << "Ошибка: вводу подлежат только вещественные числа" << endl;
            while (cin.get() != '\n');
            isIncorrect = true;
        }
        if (a == 0) {
            cout << "Ошибка: a не может быть равно 0!!!" << endl;
        }
    } while (isIncorrect);

    //at^2 + bt - 2a+c = 0
    c = c - 2 * a;
    D = pow(b, 2) - 4 * a * c;

    if (D > 0) {
        //x^2 - tx + 1 = 0;
        t1 = (-b - sqrt(D)) / (2 * a);
        t2 = (-b + sqrt(D)) / (2 * a);
        int n = 0;
        _b1 = -t1, _b2 = -t2;
        D1 = pow(_b1, 2) - 4 * _a * _c, D2 = pow(_b2, 2) - 4 * _a * _c;
        if (D1 > 0) {
            cout << "Корни x1 = " << (-_b1 - sqrt(D1)) / (2 * _a) << ", x2 = " << (-_b1 + sqrt(D1)) / (2 * _a) << endl;
            n += 2;
        } else if (D1 == 0) {
            cout << "Корень x1 = " << -_b1 / (2* _a) << endl;
            ++n;
        }
        if (D2 > 0) {
            cout << "Корни x" << n + 1 << " = " << (-_b2 - sqrt(D2)) / (2 * _a) << ", x" << n + 2 <<" = " << (-_b2 + sqrt(D2)) / (2 * _a) << endl;
            n += 2;
        } else if (D2 == 0) {
            cout << "Корень x" << n + 1 << " = " << -_b2 / (2 * _a) << endl;
            ++n;
        }
        if (n == 0) {
            cout << "Корней нет!!!" << endl;
        }
    }
    else if (D == 0) {
        t1 = (-b - sqrt(D)) / (2 * a);
        _b1 = -t1;
        D1 = pow(_b1, 2) - 4 * _a * _c;
        if (D1 > 0) {
            cout << "Корни x1 = " << (-_b1 - sqrt(D1)) / (2 * _a) << ", x2 = " << (-_b1 + sqrt(D1)) / (2 * _a) << endl;
        } else if (D1 == 0) {
            cout << "Корень x1 = " << -_b1 / (2* _a) << endl;
        } else {
            cout << "Корней нет!!!" << endl;
        }
    } else {
        cout << "Дискриминант отрицательный => Действительных корней нет!!!" << endl;
    }
    return 0;
}