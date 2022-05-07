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
            if (pizzaCode == 0) {
                cout << "El codigo de pizza es 0, a continuacion se imprimira los resultados";
                return;
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
            bool isFree = kindOfOrder == 'D' ? timeOfDelivery == 30 : timeOfDelivery == 20;
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
        // big = 1
        // fam = 1
        // superFam = 1
        if (big == fam && fam == superFam) {
            cout << "Las 3 pizza fueron la mas vendidas" << endl;
        }
            // big 5
            // fam 3
            // superfam 2
        else if (big > fam && big > superFam) {
            cout << "La pizza mas vendida fue la grande" << endl;
        }
            // big 3
            // fam 5
            // superfam 2
        else if (fam > big && fam > superFam) {
            cout << "La pizza mas vendida fue la familiar" << endl;
        }
            // big 3
            // fam 2
            // superfam 5
        else if (superFam > big && superFam > fam) {
            cout << "La pizza mas vendida fue la super familiar" << endl;
        }
            // big 2
            // fam 2
            // super fam 1
        else if (big == fam && fam > superFam) {
            cout << "Las pizza mas vendidas fueron la grande y familiar" << endl;
        }
            // big 2
            // fam 1
            // superFam 2
        else if (big == superFam && big > fam) {
            cout << "Las pizza mas vendidas fueron la grande y super familiar" << endl;
        }
            // big 1
            // fam 2
            // super Fam 2
        else if (fam == superFam && fam > big) {
            cout << "Las pizza mas vendidas fueron la familiar y super familiar" << endl;

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
        double a = utils::ask<double>(
                "Ingrese A: ",
                ([](double v) { return v >= 0.5 && v <= 2.0; }),
                "El valor de a debe estar entre 0.5 y 2"
        );
        float result = 0.0;
        int divisor = 2, exponential = 1, multi = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                result += ((float) multi * (float) utils::calculateExponential(a, exponential)) / (float) divisor;
            } else {
                result -= ((float) multi * (float) utils::calculateExponential(a, exponential)) / (float) divisor;
            }
            divisor += 2;
            multi += 2;
            exponential *= 2;
        }
        cout << "La seria mare es " << result << endl;
        float toMultiply = ((float) utils::calculateExponential(-1, n + 1) /
                            ((float) ((2 * n) -
                                      1 * (utils::calculateExponential(a, utils::calculateExponential(2, n - 1)))) /
                             (float) 2 * (float) n));
        cout << "los ultmo es " << toMultiply << endl;
        result *= toMultiply;
        cout << "El resultado de la serie será: " << result << endl;
    }

    void exercise_4() {

    }

};


#endif //EJERCICIOS_SHEET_9_H
