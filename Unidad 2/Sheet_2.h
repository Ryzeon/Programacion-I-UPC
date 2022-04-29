//
// Created by ryzeon on 20/04/22.
//

#ifndef EJERCICIOS_SHEET_2_H
#define EJERCICIOS_SHEET_2_H

#include <math.h>


class Sheet_2 {
public:
    Sheet_2(int exercise) {
        switch (exercise) {
            case 1:
                Sheet_2::exercise_1();
                break;
            case 2:
                Sheet_2::exercise_2();
                break;
            case 3:
                Sheet_2::exercise_3();
                break;
            case 4:
                Sheet_2::exercise_4();
                break;
            case 5:
                Sheet_2::exercise_5();
                break;
            case 6:
                Sheet_2::exercise_6();
                break;

        }
    }

private:

    double *askForValues(int amountOfValues, const string &message, string *valuesInLiteral) {
        auto *values = new double[amountOfValues];
        for (int i = 0; i < amountOfValues; i++) {
            cout << message << " " << valuesInLiteral[i] << ">> ";
            cin >> values[i];
        }
        return values;
    }

    void exercise_1() {
        cout << "1.- Área de un Triangulo" << endl;
        cout << "2.- Área de un Rectángulo" << endl;
        cout << "3.- Área de un Circulo" << endl;
        cout << "4.- Área de un Cuadrado" << endl;
        cout << "5.- Salir" << endl;
        int option;
        cout << "Ingrese una opción >> ";
        cin >> option;
        switch (option) {
            case 1: {
                double *values = askForValues(2, "Ingrese el valor de la", new string[2]{"base", "altura"});
                double base = values[0];
                double altura = values[1];
                cout << "El área del triangulo es: " << base * altura / 2 << endl;
                break;
            }
            case 2: {
                double *values = askForValues(2, "Ingrese el valor de la", new string[2]{"base", "altura"});
                cout << "El área del rectángulo es: " << values[0] * values[1] << endl;
                break;
            }
            case 3: {
                double *values = askForValues(1, "Ingrese el valor del radio", new string[1]{"radio"});
                double radio = values[0];
                cout << "El área del circulo es: " << M_PI * pow(radio, 2) << endl;
                break;
            }
            case 4: {
                double *values = askForValues(1, "Ingrese el valor del lado", new string[1]{"lado"});
                cout << "El área del cuadrado es: " << pow(values[0], 2) << endl;
                break;
            }
            case 5:
                break;
            default: {
                cout << "Opción inválida" << endl;
                exercise_1();
                break;
            }
        }
    }

    void exercise_2() {
        int hoursWorked;
        char category;
        cout << "Ingrese las horas trabajadas >> ";
        cin >> hoursWorked;
        cout << "Ingrese la categoría >> ";
        cin >> category;
        category = toupper(category);
        int pricePerHour = 0;
        switch (category) {
            case 'A':
                pricePerHour = 30;
                break;
            case 'B':
                pricePerHour = 35;
                break;
            case 'C':
                pricePerHour = 40;
                break;
            case 'D':
                pricePerHour = 45;
                break;
            case 'E':
                pricePerHour = 50;
                break;
            default:
                cout << "Categoría inválida" << endl;
                exercise_2();
                break;
        }
        cout << "El sueldo es: " << hoursWorked * pricePerHour << endl;
    }

    void exercise_3() {
        int dayOfBirth;
        cout << "Ingrese el día de nacimiento >> ";
        cin >> dayOfBirth;
        int monthOfBirth;
        cout << "Ingrese el mes de nacimiento >> ";
        cin >> monthOfBirth;
        if (dayOfBirth > 31 || dayOfBirth < 1 || monthOfBirth > 12 || monthOfBirth < 1) {
            cout << "Fecha inválida" << endl;
            exercise_3();
        }
        int dayOfYear = dayOfBirth + 31 * (monthOfBirth - 1);
//        Capricornio (22/12 - 20/1) = 0
//         Acuario (21/1 - 19/2) = 1
//         Piscis (20/2 - 20/3) = 2
//         Aries (21/3 - 20/4) = 3
//         Tauro (21/4 - 21/5) = 4
//         Géminis (22/5 - 21/6) = 5
//         Cáncer (21/6 - 23/7)  = 6
//         Leo (24/7 - 23/8) = 7
//         Virgo (24/8 - 23/9) = 8
//         Libra (24/9 - 23/10) = 9
//         Escorpio (24/10 - 22/11) = 10
//         Sagitario (23/11 - 21/12) = 11
        int zodiacSign = dayOfYear % 12;
        string zodiacSignName;
        switch (zodiacSign) {
            case 0:
                zodiacSignName = "Capricornio";
                break;
            case 1:
                zodiacSignName = "Acuario";
                break;
            case 2:
                zodiacSignName = "Piscis";
                break;
            case 3:
                zodiacSignName = "Aries";
                break;
            case 4:
                zodiacSignName = "Tauro";
                break;
            case 5:
                zodiacSignName = "Géminis";
                break;
            case 6:
                zodiacSignName = "Cáncer";
                break;
            case 7:
                zodiacSignName = "Leo";
                break;
            case 8:
                zodiacSignName = "Virgo";
                break;
            case 9:
                zodiacSignName = "Libra";
                break;
            case 10:
                zodiacSignName = "Escorpio";
                break;
            case 11:
                zodiacSignName = "Sagitario";
                break;
        }
        cout << "Tu signo es: " << zodiacSignName << endl;
    }

    void exercise_4() {
        int num;
        cout << "Ingrese un número >> ";
        cin >> num;
        if (num < 0) {
            cout << "Número inválido" << endl;
            exercise_4();
        }
        int v;
        cout << "Ingrese un el valor de V >> ";
        cin >> v;
        if (v < 0) {
            cout << "Valor inválido" << endl;
            exercise_4();
        }
        double val;
        switch (num) {
            case 1:
                val = 100 * v;
                break;
            case 2:
                val = pow(100, v);
                break;
            case 3:
                val = 100.00 / v;
                break;
            default:
                val = 0;
                break;
        }
        cout << "El valor es: " << val << endl;
    }

    void exercise_5() {
        int month, year;
        cout << "Ingrese el mes >> ";
        cin >> month;
        cout << "Ingrese el año >> ";

        cin >> year;
        if (month < 1 || month > 12) {
            cout << "Mes inválido" << endl;
            exercise_5();
        }
        if (year < 0) {
            cout << "Año inválido" << endl;
            exercise_5();
        }
        int daysOfMonth;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daysOfMonth = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                daysOfMonth = 30;
                break;
            case 2:
                if (year % 4 == 0) {
                    daysOfMonth = 29;
                } else {
                    daysOfMonth = 28;
                }
                break;
        }
        cout << "El mes tiene " << daysOfMonth << " días" << endl;
    }

    void exercise_6() {
        int kind;
        cout << "Ingresa el tipo de consumo (1-2) >> ";
        cin >> kind;
        if (kind < 1 || kind > 2) {
            cout << "Tipo inválido" << endl;
            exercise_6();
        }
        int quantity;
        cout << "Ingresa la cantidad de consumo >> ";
        cin >> quantity;
        if (quantity < 0) {
            cout << "Cantidad inválida" << endl;
            exercise_6();
        }

        switch (kind) {
            case 1:
                cout << "El costo es: " << quantity * 1.58 << endl;
                break;
            case 2:
                // Por los primeros 100(que es el consumo mínimo) S/.0.35 por unidad.
                // Por el exceso de 100 hasta 500 inclusive es de S/.1.05 por unidad.
                // Por los restantes es de 1.36 por unidad.
                if (quantity <= 100) {
                    cout << "El costo es: " << quantity * 0.35 << endl;
                } else if (quantity > 100 && quantity <= 500) {
                    int cost = 100 * 1.05;
                    cout << "El costo es: " << cost + ((quantity - 100) * 1.05) << endl;
                } else {
                    int cost = 100 * 0.35;
                    quantity = quantity - 100;
                    int exceso = quantity - 500;
                    cout << "El costo es: " << cost + (500 * 1.05) + (exceso * 1.36) << endl;
                }
                break;
        }
    }
};


#endif //EJERCICIOS_SHEET_2_H
