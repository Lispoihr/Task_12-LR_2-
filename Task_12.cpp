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
    double a, b, c, D, t1, t2;
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
            cout << "Ошибка: это уже не биквадратное уравнение(a != 0)!!!" << endl;
            isIncorrect = true;
        }
    } while (isIncorrect);

    D = pow(b, 2) - 4 * a * c;
    bool flag1 = false, flag2 = false;

    if (D > 0) {
        t1 = (-b - sqrt(D)) / (2 * a);
        t2 = (-b + sqrt(D)) / (2 * a);
        if (t1 >= 0) {
            cout << "Корни x1 = " << sqrt(t1) << ", x2 = " << -sqrt(t1) << endl;
            flag1 = true;
        }
        if (t2 >= 0) {
            cout << "Корни x" << (flag1 ? 3 : 1) << " = " << sqrt(t2) << ", x" << (flag1 ? 4 : 2) << " = " << -sqrt(t2) << endl;
            flag2 = true;
        }
        if (!flag1 && !flag2)
            cout << "Корней нет!!!" << endl;
    }
    else if (D == 0) {
        t1 = -b / (2 * a);
        if (t1 >= 0)
            cout << "Корни x1 = " << sqrt(t1) << ", x2 = " << -sqrt(t1) << endl;
        else
            cout << "Корней нет!!!" << endl;
    } else {
        cout << "Дискриминант отрицательный => Действительных корней нет!!!" << endl;
    }
    return 0;
}