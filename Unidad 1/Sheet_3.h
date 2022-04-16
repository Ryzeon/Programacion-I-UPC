//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_3_H
#define EJERCICIOS_SHEET_3_H

#include <iostream>
#include <string>

using namespace std;

class Sheet_3 {
public:
    Sheet_3(int choise) {
        switch (choise) {
            case 1:
                Sheet_3::exercise_1();
                break;
            case 2:
                Sheet_3::exercise_2();
                break;
            case 3:
                Sheet_3::exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        double amount;
        cout << "Ingresa la cantidad de litros consumidos >> ";
        cin >> amount;
        // tarifa mensual
        double toPay = 20;
        if (amount >= 51) {
            toPay += (amount - 100) * 2;
        }
        if (amount > 200) {
            toPay += (amount - 200) * 3.5;
        }
        cout << "Deberas pagar S/" << toPay;
    }

    void exercise_2() {
        string code;
        cout << "Ingresa el codigo de barras >> ";
        cin >> code;
        if (code.length() < 12) {
            cout << "Codigo de barras invalido.";
            return;
        }
        int dayToExpired = stoi(code.substr(0, 2)),
                monthToExpired = stoi(code.substr(2, 2)),
                yearToExpired = stoi(code.substr(4, 4)),
                charLetter = stoi(code.substr(8, 2)),
                pp = stoi(code.substr(10, 2));
        cout << "Día de vencimiento: " << dayToExpired << endl;
        cout << "Mes de vencimiento: " << monthToExpired << endl;
        cout << "Año de vencimiento: " << yearToExpired << endl;
        cout << "El tipo de producto es: " << (char) charLetter << endl;
        cout << "Producto perecible : " << (pp == 0 ? 1 : 0) << endl;
    }

    void exercise_3() {
        int years;
        string grade;
        cout << "Ingrese la cantidad de años que labora >> ";
        cin >> years;
        cout << "Estudios (P: primaria; S: secundaria; U: universitario; G: posgrado) >> ";
        cin >> grade;
        int pointsPerGrade = grade == "P" ? 5 : (grade == "S" ? 10 : (grade == "U" ? 20 : 30));
        int pointPerYear = years > 5 ? 10 : 5;
        cout << "Puntage obtenido: " << (pointPerYear + pointsPerGrade);
    }
};


#endif //EJERCICIOS_SHEET_2_H
