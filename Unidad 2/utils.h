//
// Created by ryzeon on 3/05/22.
//

#ifndef EJERCICIOS_UTILS_H
#define EJERCICIOS_UTILS_H

#include <functional>
#include <iostream>

using namespace std;

class utils {
    // method to ask but works with generic types return the value and work with a condition so a predicate like in java
public:
    template<typename T>
    static T ask(const string &message = "Ingrese un valor: ",
                 function<bool(T const &)> condition = [](T const &v) { return true; },
                 const string &message_condition = "El numero es invalido") {
        bool done = false;
        T finalValue;
        while (!done) {
            T value;
            cout << message;
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << message_condition << endl;
            } else if (!condition(value)) {
                cout << message_condition << endl;
            } else {
                done = true;
                finalValue = value;
            }
        }
        return finalValue;
    }

    static double calculateExponential(double base, double exponent) {
        double result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }

    static double calculateFactorial(double number) {
        double result = 1;
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        return result;
    }
};


#endif //EJERCICIOS_UTILS_H
