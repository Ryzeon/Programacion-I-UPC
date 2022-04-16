//
// Created by ryzeon on 10/04/22.
//

#ifndef EJERCICIOS_SHEET_5_H
#define EJERCICIOS_SHEET_5_H

#include <iostream>
#include <map>
#include <time.h>

using namespace std;


class Sheet_5 {
public:
    Sheet_5(int choise) {
        switch (choise) {
            case 1:
                Sheet_5::exercise_1();
                break;
            case 2:
                Sheet_5::exercise_2();
                break;
            case 3:
                Sheet_5::exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        double amount;
        cout << "Ingrese el monto a pagar >> ";
        cin >> amount;
        if (amount < 100) {
            cout << "No aplica a la promocion.";
            return;
        }
        int choise;
        cout << "Ingresa un numero del 1 al 5 >> ";
        cin >> choise;
        if (choise < 0 || choise > 5) {
            cout << "No puedes ingresar ese valor!";
            return;
        }
        map<int, int> discounts = {
                {1, 0},
                {2, 10},
                {3, 20},
                {4, 25},
                {5, 50}
        };
        double discount = obtainDiscount(amount, discounts[choise]);
        cout << "Total a pagar >> " << (amount - discount);
    }

    double obtainDiscount(double price, double discount) {
        return (discount / 100) * price;
    }

    void exercise_2() {
        string input;
        cout << "Ingresa el codigo >> ";
        cin >> input;
        input = input.substr(0, 16);
        int
                unique = stoi(input.substr(0, 3)),
                fragil = stoi(input.substr(3, 1)),
                pp_1 = stoi(input.substr(4, 2)),
                pp_2 = stoi(input.substr(6, 2)),
                day = stoi(input.substr(8, 2)),
                month = stoi(input.substr(10, 2)),
                year = stoi(input.substr(12, 4));
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        int nowYear = timeinfo->tm_year + 1900;
        int nowMonth = timeinfo->tm_mon + 1;
        int nowDay = timeinfo->tm_mday;
        cout << nowYear << endl;
        cout << nowMonth << endl;
        cout << nowDay << endl;
        cout << "Número único: " << unique << endl;
        cout << "Frágil (N: No; S: Sí): " << (fragil == 0 ? "S" : "N") << endl;
        cout << "País de procedencia: " << (char) pp_1 << (char) pp_2 << endl;
        cout << "Día, mes y año de vencimiento: " << day << "-" << month << "-" << year << endl;
        cout << "Bien se encuentra vencido al día de hoy (N: No; S: Sí): " << (
                (nowYear > year || nowYear == year && nowMonth > month ||
                 nowYear == year && nowMonth == month && nowDay > day) ? "S" : "N");
    }

    void exercise_3() {
        double salary;
        cout << "Sueldo mensual >> ";
        cin >> salary;
        string kingOfHouse, creditCar, fam;
        cout << "Tipo de vivienda (P: pariente; A: alquilada; M: propia): ";
        cin >> kingOfHouse;
        cout << "Tarjeta de crédito (N: no tiene; S: si tiene): ";
        cin >> creditCar;
        cout << "Tiene carga familiar (N: no tiene; S: si tiene): ";
        cin >> fam;
        int points = salary < 1500 ? 6 : (salary >= 1500 && salary <= 6000 ? 12 : 18);
        points += kingOfHouse == "P" ? 2 : kingOfHouse == "A" ? 5 : 10;
        points += creditCar == "N" ? 0 : 6;
        points += fam == "N" ? 3 : 6;
        cout << "Puntaje Obtenido: " << points << endl;
        cout << "Se le otorga el préstamo (0: No; 1: Sí): " << (points > 20 ? "1" : "0");
    }
};


#endif //EJERCICIOS_SHEET_5_H
