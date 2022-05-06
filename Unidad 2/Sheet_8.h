//
// Created by ryzeon on 3/05/22.
//

#ifndef EJERCICIOS_SHEET_8_H
#define EJERCICIOS_SHEET_8_H

#include "utils.h"

class Sheet_8 {
public:
    Sheet_8(int choise) {
        switch (choise) {
            case 1:
                exercise_1();
                break;
            case 2:
                exercise_2();
                break;
            case 3:
                exercise_3();
                break;
            case 4:
                exercise_4();
                break;
            case 5:
                exercise_5();
                break;
            case 6:
                exercise_6();
                break;
            case 7:
                exercise_7();
                break;
        }
    }

private:

    const function<bool(const int &)> positiveValidator = ([](int v) { return v > 0; });

    void exercise_1() {
        int a = utils::ask<int>("Ingresa B: ", positiveValidator, "B debe ser mayor a 0");
        int b = utils::ask<int>("Ingresa C: ", positiveValidator, "C debe ser mayor a 0");
        double result = utils::calculateExponential(a, b);
        cout << "El resultado es: " << result << endl;
    }

    void exercise_2() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        cout << "El resultado es: " << utils::calculateFactorial(n) << endl;
    }

    void exercise_3() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += utils::calculateFactorial(i);
        }
        cout << "El resultado es: " << sum << endl;
    }

    void exercise_4() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i / utils::calculateFactorial(i);
        }
        cout << "El resultado es: " << sum << endl;
    }

    void exercise_5() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                sum += 1 / utils::calculateFactorial(i);
            } else {
                sum -= i / utils::calculateFactorial(i);
            }
        }
        cout << "El resultado es: " << sum << endl;
    }

    void exercise_6() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += utils::calculateExponential(i, i + 1) / utils::calculateFactorial(i);
        }
        cout << "El resultado es: " << sum << endl;
    }

    void exercise_7() {
        int n = utils::ask<int>("Ingresa N: ", positiveValidator, "A debe ser mayor a 0");
        double sum = 0;
        int rest = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i/ utils::calculateFactorial(i - rest);
            rest++;
        }
        cout << "El resultado es: " << sum << endl;
    }
};


#endif //EJERCICIOS_SHEET_8_H
