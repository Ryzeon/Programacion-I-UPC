//
// Created by ryzeon on 3/05/22.
//

#ifndef EJERCICIOS_SHEET_9_H
#define EJERCICIOS_SHEET_9_H

#include "utils.h"


class Sheet_9 {
public:
    Sheet_9(int choise) {
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
        }
    }

private:

    void exercise_1() {
        double k = utils::ask<double>("Ingresa K: ",
                                      ([](double i) { return i > 0.0 && i <= 20.00; }),
                                      "El  valor de K debe ser positivo y no debe ser mayor que 20");
        double a = utils::ask<double>("Ingresa A: ",
                                      ([](double i) { return i > 0.0; }),
                                      "El  valor de A debe ser positivo");
        double total = 0.0;
        for (int i = 1; i <= k; i++) {
            if (i == 1 || i == 2) {
                if (i == 1) {
                    total += a + i;
                } else {
                    total += utils::calculateExponential(a, (double) i) / (double) i;
                }
            } else {
                total += utils::calculateExponential(a, (double) i) / utils::calculateFactorial((double) i);
            }
        }
        cout << "El resultado sera: " << total << endl;
    }

    void exercise_2() {
        int lastPizzaCode = 1;
        int totalSell = 0;
        int freeOrders = 0;
        int timeToDispatchDelivery = 0, completeOrdersDelivery = 0;
        int timeToDispatchInLocal = 0, completeOrdersInLocal = 0;
        int big = 0, fam = 0, superFam = 0;
        while (lastPizzaCode != 0) {
            int pizzaCode = utils::ask<int>(
                    "Ingresa el codigo de la pizza: ",
                    ([](int v) {
                        return (v == 0 || v > 999 && v <= 9999);
                    }),
                    "La codigo de pizza tener 4 digitos"
            );
            lastPizzaCode = pizzaCode;
            if (lastPizzaCode == 0) {
                cout << "El codigo de pizza es 0, a continuacion se imprimira los resultados";
                break;
            }
            int kindOfPizza = utils::ask<int>(
                    "Ingrese el tipo de pizza: ",
                    ([](int v) { return v >= 1 && v <= 3; }),
                    "El tipo de pizza solo puede ser entrer [1-3]"
            );
            if (kindOfPizza == 1) {
                big++;
            } else if (kindOfPizza == 2) {
                fam++;
            } else {
                superFam++;
            }
            char kindOfOrder = utils::ask<int>(
                    "Ingrese el tipo de pedido (D: Delivery; M: Mostrador): ",
                    ([](char v) {
                        v = toupper(v);
                        return v == 'D' || v == 'M';
                    })
            );
            kindOfOrder = toupper(kindOfOrder);
            int timeOfDelivery = utils::ask<int>(
                    "Ingresa el tiempo de entrega: ",
                    ([](int v) { return v > 0; }),
                    "El tiempo de entrega debe ser mayor de 0"
            );
            int pizzaPrice = kindOfPizza == 1 ? 50 : (kindOfPizza == 2 ? 60 : 68);
            bool isFree = kindOfOrder == 'D' ? timeOfDelivery >= 30 : timeOfDelivery >= 20;
            if (isFree) {
                cout << "La pizza es gratis!" << endl;
                freeOrders++;
            } else {
                cout << "El costo de la pizza es " << pizzaPrice << endl;
                totalSell += pizzaPrice;
                if (kindOfOrder == 'D') {
                    completeOrdersDelivery++;
                    timeToDispatchDelivery += timeOfDelivery;
                } else {
                    completeOrdersInLocal++;
                    timeToDispatchInLocal += timeOfDelivery;
                }
            }
        }
        cout << "El importe recaudado es " << totalSell << endl;
        cout << "Se entregaron " << freeOrders << " pedidos gratis" << endl;
        int max = 0, max2 = 0;
        string maxName, maxName2;
        if (big > fam && big > superFam) {
            max = big;
            maxName = "Grande";
        } else if (fam > big && fam > superFam) {
            max = fam;
            maxName = "Familiar";
        } else {
            max = superFam;
            maxName = "Super Familiar";
        }
        if (big > fam && big > superFam && big != max) {
            max2 = big;
            maxName2 = "Grande";
        } else if (fam > big && fam > superFam && fam != max) {
            max2 = fam;
            maxName2 = "Familiar";
        } else if (superFam > big && superFam > fam && superFam != max) {
            max2 = superFam;
            maxName2 = "Super Familiar";
        } else {
            max2 = max;
            maxName2 = maxName;
        }
        if (maxName == maxName2) {
            cout << "El mayor tipo de pizza es " << maxName << " con " << max << " pedidos" << endl;
        } else {
            cout << "Las 2 mas vendidas son " << maxName << " y " << maxName2 << endl;
        }
        cout << "El tiempo de entrega es: " << endl;
        cout << "  Delivery: " << (timeToDispatchDelivery / completeOrdersDelivery) << endl;
        cout << "  Mostrador: " << (timeToDispatchInLocal / completeOrdersInLocal) << endl;
    }

    void exercise_3() {
        int n = utils::ask<int>(
                "Ingrese N: ",
                ([](int v) { return v > 0 && v < 21; }),
                "El valor de n debe ser mayor que 0 y menor de 22"
        );
        float a = utils::ask<float>(
                "Ingrese A: ",
                ([](float v) { return v >= 0.5 && v <= 2.0; }),
                "El valor de a debe estar entre 0.5 y 2"
        );
        float result = 0.0;
        for (int i = 1; i <= n; i++) {
            float doubleN = i * 2;
            float denominator = doubleN * doubleN;
            result += pow(-1, i + 1) *
                      ((doubleN - 1) * pow(a, pow(2, i - 1)) / doubleN);
        }
        cout << "El resultado de la serie será: " << result << endl;
    }

    void exercise_4() {
        int n;
        do {
            cout << "Ingrese N: ";
            cin >> n;
        } while (!(n >= 2 && n <= 10));
        for (int i = 0; i < n; i++) {

            // i = 0;
            // n = 5
            int numberToLoop = (n - 1);
            for (int j = n; )
            for (int j = 0; j < n; j++) {
//                0 +++
            }
        }
    }

};


#endif //EJERCICIOS_SHEET_9_H
