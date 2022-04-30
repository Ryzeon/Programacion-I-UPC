//
// Created by ryzeon on 28/04/22.
//

#ifndef EJERCICIOS_SHEET_7_H
#define EJERCICIOS_SHEET_7_H

#include <functional>


class Sheet_7 {
public:
    Sheet_7(int choice) {
        switch (choice) {
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
            case 8:
                exercise_8();
                break;
            case 9:
                exercise_9();
                break;
        }
    }

private:

    void exercise_1() {
        int n;
        cout << "Ingrese un N: ";
        cin >> n;
        if (n < 0) {
            cout << "El numero es invalido" << endl;
            exercise_1();
            return;
        }
        int favor = 0, against = 0, abstains = 0;
        for (int i = 0; i < n; ++i) {
            int reply = ask<int>("Ingrese 1 para favor, 2 para contra, 3 para abstenerse: ",
                                 ([](int x) { return x < 1 || x > 3; }), "Debes ingresar 1, 2 o 3");
            if (reply == 1) {
                favor++;
            } else if (reply == 2) {
                against++;
            } else {
                abstains++;
            }
        }
        double percent_favor = (double) favor / n * 100;
        double percent_against = (double) against / n * 100;
        double percent_abstains = (double) abstains / n * 100;
        cout << "Favor: " << percent_favor << "%" << endl;
        cout << "Contra: " << percent_against << "%" << endl;
        cout << "Abstencion: " << percent_abstains << "%" << endl;
        cout << "Total: " << percent_favor + percent_against + percent_abstains << "%" << endl;
        cout << "Segun la encuesta "
             << (percent_favor == percent_against ? "es empate" : (percent_favor > percent_abstains ? "ganan a favor"
                                                                                                    : "ganan a contra"))
             << endl;
    }

    void exercise_2() {
        double money;
        cout << "Ingrese la cantidad de dinero: ";
        cin >> money;
        if (money < 0) {
            cout << "El numero es invalido" << endl;
            exercise_2();
            return;
        }
        for (int i = 0; i < 10; ++i) {
            money += money * 0.005;
        }
        cout << "El dinero al final de los 10 años sera de: " << money << endl;
    }

    void exercise_3() {
        map<int, double *> members = {
                {0, new double[11]},
                {1, new double[11]},
                {2, new double[11]},
                {3, new double[11]},
                {4, new double[11]}
        };
        for (int i = 0; i < 5; ++i) {
            cout << "-------------------" << endl;
            cout << "Obteniendo datos del paciente " << (i + 1) << endl;
            double last_weight = 0;
            while (last_weight == 0) {
                cout << "Ingrese el ultimo peso del paciente: ";
                cin >> last_weight;
                if (last_weight < 0) {
                    cout << "El numero es invalido" << endl;
                    last_weight = 0;
                }
                members[i][0] = last_weight;
            }
            for (int j = 0; j < 10; ++j) {
                int weight = 0;
                while (weight == 0) {
                    cout << "Ingrese el peso " << "(" << (j + 1) << "): ";
                    cin >> weight;
                    if (weight < 0) {
                        cout << "El numero es invalido" << endl;
                        weight = 0;
                    }
                }
                members[i][j + 1] = weight;
            }
            cout << "-------------------" << endl;
        }
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "Resultados" << endl;
        for (int i = 0; i < 5; ++i) {
            double lastWeight = members[i][0];
            double weight = 0;
            for (int j = 0; j < 10; ++j) {
                weight += members[i][j + 1];
            }
            weight /= 10;
            cout << "El paciente " << (i + 1) << (lastWeight - weight > 0 ? "SUBIO" : "BAJO") << " de peso" << endl;
        }
    }

    void exercise_4() {
        double total = 0;
        int n;
        cout << "Ingrese el numero de clientes ";
        cin >> n;
        if (n < 0) {
            cout << "El numero es invalido" << endl;
            exercise_4();
            return;
        }
        for (int i = 1; i <= n; ++i) {
            auto value = ask<double>("Ingrese el monto a pagar del cliente:", ([](int v) { return v > 0; }),
                                     "El valor debe ser mayor a 0");
            int boolColor = ask<int>("Ingrese el color de la bola (1 = rojo, 2 = azul, 3 = blanca): ",
                                     ([](double v) { return v == 1 || v == 2 || v == 3; }),
                                     "El valor debe ser 1, 2 o 3");
            if (boolColor == 1) {
                value -= value * 0.4;
            } else if (boolColor == 2) {
                value -= value * 0.25;
            }
            cout << "El cliente " << (i + 1) << " debe pagar " << value << endl;
            total += value;
        }
        cout << "Lo acumulado de todos los clientes es de: " << total << endl;
    }

    void exercise_5() {
        int n;
        cout << "Numero de tarjetas del censo: ";
        cin >> n;
        if (n < 0) {
            cout << "El numero es invalido" << endl;
            exercise_5();
            return;
        }
        int man = 0, woman = 0, manMore30Divorced = 0, womanV = 0;
        for (int i = 0; i < n; ++i) {
            char gen = ask<char>("Ingrese el sexo (M: Masculino; F: Femenino): ", ([](char v) {
                char xd = toupper(v);
                return xd == 'M' || xd == 'F';
            }), "Debes ingresar solo M o F");
            int age = ask<int>("Ingrese la edad: ", ([](int v) { return v > 0; }), "La edad debe ser mayor a 0");
            char marital = ask<char>("Estado Civil (A: Soltero; B: Casado; C: Viudo; D: Divorciado): ", ([](char v) {
                char xd = toupper(v);
                return xd == 'A' || xd == 'C' || xd == 'D' || xd == 'B';
            }), "Debes ingresar solo A, B, C o D");
            gen = toupper(gen);
            marital = toupper(marital);

            if (gen == 'M') {
                man++;
                if (age > 30 && (marital == 'S' || marital == 'D')) {
                    manMore30Divorced++;
                }
            } else {
                woman++;
                if (marital == 'D' && age >= 16 && age <= 21) {
                    womanV++;
                }
            }
        }

        cout << "Número de jóvenes viudas que están entre 16 y 21 años es" << womanV << endl;
        int total = man + woman;
        double manPercentage = ((double) man / total) * 100;
        double womanPercentage = ((double) woman / total) * 100;
        cout << "El porcentae de hombres es " << manPercentage << "%" << endl;
        cout << "El porcentaje de mujeres es " << womanPercentage << "%" << endl;
        cout << "Número de hombres mayores de 30 años solteros o divorciados es " << manMore30Divorced << endl;
    }

    void exercise_6() {
        double childs = 0, childs_weights = 0, young = 0, young_weights = 0, adult = 0, adult_weights = 0, old = 0, old_weights = 0;
        for (int i = 0; i < 50; ++i) {
            int age = ask<int>("Ingrese la edad: ", ([](int v) { return v > 0; }), "La edad debe ser mayor a 0");
            double weight = ask<double>("Ingrese el peso: ", ([](double v) { return v > 0; }),
                                        "El peso debe ser mayor a 0");
            if (age > 0 && age <= 12) {
                childs++;
                childs_weights += weight;
            } else if (age >= 13 && age <= 29) {
                young++;
                young_weights += weight;
            } else if (age >= 30 && age <= 59) {
                adult++;
                adult_weights += weight;
            } else {
                old++;
                old_weights += weight;
            }
        }
        double childs_average = childs_weights / childs;
        double young_average = young_weights / young;
        double adult_average = adult_weights / adult;
        double old_average = old_weights / old;
        cout << "Promedio de peso de los niños es " << childs_average << endl;
        cout << "Promedio de peso de los jóvenes es " << young_average << endl;
        cout << "Promedio de peso de los adultos es " << adult_average << endl;
        cout << "Promedio de peso de los ancianos es " << old_average << endl;
    }

    void exercise_7() {
        int n = ask<int>("Ingrese el numero de empleados: ", ([](int v) { return v > 0; }),
                         "El numero de empleados debe ser mayor a 0");
        double baseSalary = ask<double>("Ingrese el salario base: ", ([](double v) { return v > 0; }),
                                        "El salario base debe ser mayor a 0");
        for (int i = 0; i < n; ++i) {
            cout << "------------------------------------------------------" << endl;
            cout << "Empleado " << i + 1 << endl;
            double totalSalary = baseSalary;
            for (int j = 1; j <= 3; ++j) {
                double sale = ask<double>("Ingrese el monto de la venta: ", ([](double v) { return v > 0; }),
                                          "El monto de la venta debe ser mayor a 0");
                totalSalary += sale * 0.10;
            }
            cout << "El salario total es " << totalSalary << endl;
            cout << "------------------------------------------------------" << endl;
        }
    }

    void exercise_8() {
        int n = ask<int>("Ingrese el numero de universitarios a registrar: ", ([](int v) { return v > 0; }),
                         "El numero de universitarios debe ser mayor a 0");
        int upc = 0, pucp = 0, unmsm = 0, unfv = 0, ulima = 0, uch = 0;
        for (int i = 0; i < n; ++i) {
            // get a 6 digits number
            int cardDigits = ask<int>("Ingrese el numero de carnet: ",
                                      ([](int v) { return v >= 100000 && v <= 999999; }),
                                      "El numero de carnet debe tener 6 digitos");
            int firstDigit = cardDigits / 100000;
            switch (firstDigit) {
                case 1:
                case 2:
                    upc++;
                    break;
                case 3:
                case 4:
                    pucp++;
                    break;
                case 5:
                    unmsm++;
                    break;
                case 6:
                    unfv++;
                    break;
                case 7:
                    ulima++;
                    break;
                case 8:
                    uch++;
                    break;
            }
        }
        cout << "Universitarios de la UPC: " << upc << endl;
        cout << "Universitarios de la PUC: " << pucp << endl;
        cout << "Universitarios de la UNMSM: " << unmsm << endl;
        cout << "Universitarios de la UNFV: " << unfv << endl;
        cout << "Universitarios de la Ulima: " << ulima << endl;
        cout << "Universitarios de la UCH: " << uch << endl;
    }

    void exercise_9() {
        double pricePerSeat = ask<double>("Ingrese el precio por asiento: ", ([](double v) { return v > 0; }),
                                          "El precio por asiento debe ser mayor a 0");
        int lastAge = 0;
        while (lastAge < 0) {
            lastAge = ask<int>("Ingrese la edad de la persona a registrar:");
            if (lastAge >= 5) {
                int discount;
                if (lastAge >= 5 && lastAge <= 14) {
                    discount = 35;
                } else if (lastAge >= 15 && lastAge <= 19) {
                    discount = 25;
                } else if (lastAge >= 20 && lastAge <= 45) {
                    discount = 10;
                } else if (lastAge >= 46 && lastAge <= 65) {
                    discount = 25;
                } else {
                    discount = 35;
                }
                double  toPay = pricePerSeat * (100 - discount) / 100;
                cout << "El precio a pagar es: " << toPay << endl;
            } else {
                cout << "No puedes vender una entrada a alguien menor de 5 años" << endl;
            }
        }
    }

    // method to ask but works with generic types return the value and work with a condition so a predicate
    template<typename T>
    T ask(const string &message = "Ingrese un valor: ",
          function<bool(T const &)> condition = [](T const &v) { return true; },
          const string &message_condition = "El numero es invalido") {
        T value;
        cout << message;
        cin >> value;
        if (!condition(value)) {
            cout << message_condition << endl;
            return ask<T>(message, condition, message_condition);
        }
        return value;
    }
};


#endif //EJERCICIOS_SHEET_7_H
