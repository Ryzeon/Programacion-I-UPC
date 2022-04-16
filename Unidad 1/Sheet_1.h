//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_1_H
#define EJERCICIOS_SHEET_1_H

#include <iostream>

using namespace std;

class Sheet_1 {
public:
    Sheet_1(int choise) {
        switch (choise) {
            case 1:
                Sheet_1::exercise_1();
                break;
            case 2:
                Sheet_1::exercise_2();
                break;
            case 3:
                Sheet_1::exercise_3();
                break;
            case 4:
                Sheet_1::exercise_4();
                break;
            case 5:
                Sheet_1::exercise_5();
                break;
        }
    }

private:
    void exercise_1() {
        int amount;
        cout << "Ingresa el numero de neumaticos >> ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Debes ingresar una cantidar mayor a 0";
            return;
        }
        int price = amount < 3 ? 145 : amount >= 3 && amount <= 5 ? 138 : 135;
        cout << "El cliente pagara un total de S/" << (price * amount) << ", costando " << price << " por neumatico.";
    }

    void exercise_2() {
        string gen;
        cout << "Ingresa el sexo (F/M) >> ";
        if (gen != "M" || gen != "F") {
            cout << "Opcion invalida!";
            return;
        }
        cin >> gen;
        bool isMale = gen == "M";
        int age;
        cout << "Ingresa la edad >> ";
        cin >> age;
        int price = isMale ? (age < 25 ? 1000 : 700) : (age < 21 ? 800 : 500);
        cout << "Debera pagar el total de S/ " << price;
    }

    void exercise_3() {
        double diameter;
        cout << "Ingresa el diametro de la pizza >> ";
        cin >> diameter;
        int extra;
        cout << "Ingresa la cantidad extra de ingredientes >> ";
        cin >> extra;
        double totalPrice = (diameter * 1.5) + (extra * 2.5);
        cout << "El precio total de la pizza es S/" << totalPrice;
    }

    void exercise_4() {
        int hours;
        cout << "Ingresa la cantidad de horas trabajadas >> ";
        cin >> hours;
        int extraHours = hours - 40;
        bool hasWorkingExtraHours = extraHours >= 1;
        int normalPrice = (hours - extraHours) * 16;
        int extraHoursTotalPrice = extraHours * 20;
        cout << "Se le paga al obrero un total de " << normalPrice << " por trabajar " << hours;
        if (hasWorkingExtraHours) {
            cout << " con un addicional de " << extraHoursTotalPrice << " por trabajar " << extraHours
                 << " horas extrnas";
        }
    }

    void exercise_5() {
        double price, amount;
        cout << "Ingresa el precio del articulo >> ";
        cin >> price;
        cout << "Ingresa la cantidad del articulo >> ";
        cin >> amount;
        if (amount <= 0) {
            cout << "El precio no puede ser menor a 0";
            return;
        }
        double total = price * amount;
        double subTotal = total / 1.18;
        double igv = total - subTotal;

        // para poder imprimir y reformatear decimales
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "<--------------FACTURA-------------->" << "\n" << "\n";
        cout << "x" << amount << " Producto (" << price << ")" << "\n";
        cout << "SubTotal >> " << subTotal << "\n";
        cout << "IGV >> " << igv << "\n";
        cout << "Total >> " << total << "\n";
        cout << "<-------------FACTURA-------------->" << "\n";
    }
};


#endif //EJERCICIOS_SHEET_1_H
