//
// Created by ryzeon on 8/04/22.
//

#ifndef EJERCICIOS_SHEET_4_H
#define EJERCICIOS_SHEET_4_H

#include <iostream>
#include <math.h>
#include <map>

using namespace std;

class Sheet_4 {
public:
    Sheet_4(int choose) {
        switch (choose) {
            case 1:
                Sheet_4::exercise_1();
                break;
            case 2:
                Sheet_4::exercise_2();
                break;
            case 3:
                Sheet_4::exercise_3();
                break;
            case 4:
                Sheet_4::exercise_4();
                break;
            case 5:
                Sheet_4::exercise_5();
                break;
            case 6:
                Sheet_4::exercise_6();
                break;
            case 7:
                Sheet_4::exercise_7();
                break;
            case 8:
                Sheet_4::exercise_8();
                break;
        }
    }

private:
    void exercise_1() {
        double weight, height;
        cout << "Ingrese el peso >> ";
        cin >> weight;
        cout << "Ingresa la estatura >> ";
        cin >> height;
        double imc = weight / pow(height, 2);
        string result =
                imc < 15 ? "Criterio de ingreso en hospital" : (imc >= 15 && imc < 20) ? "bajo peso" : (imc >= 20 &&
                                                                                                        imc < 30)
                                                                                                       ? "peso normal (saludable)"
                                                                                                       : (imc >= 30 &&
                                                                                                          imc < 40)
                                                                                                         ? "sobrepeso (obesidad de grado I)"
                                                                                                         : "sobrepeso crónico (obesidad de grado II)";
        cout << "El resultado es >> " << result;
    }

    void exercise_2() {
        string input;
        cout << "Ingresa el input >> ";
        cin >> input;
        if (input.size() % 2 != 0) {
            cout << "La cantidad de digitos debe ser par.";
            return;
        }
        cout << "Output >> " << convertString(input);
    }

    string convertString(string input) {
        string output;
        for (int i = 0; i < input.size() - (input.size() / 2); i++) {
//            cout << "Index " << i << endl;
//            cout << "Primara " << input[i] << " la ultima " << input[input.size() - (i + 1)] << endl;
            output += input[i];
            output += input[input.size() - (i + 1)];
        }
        return output;
    }

    void exercise_3() {
        int age;
        cout << "Ingresa la age del jugador >>";
        cin >> age;
        string nacionality;
        cout << "Ingresa la nacionalidad (E: Extranjero; N: Nacional) >> ";
        cin >> nacionality;
        int salary = 2500;
        if (nacionality != "N") {
            salary += 500;
        }
        int toAdd =
                age >= 15 && age <= 20 ? 1400 : (age >= 21 && age <= 25 ? 1500 : (age >= 26 && age <= 30 ? 1200 : 800));
        salary += toAdd;
        cout << "El sueldo que recibe es de " << salary;
    }

    void exercise_4() {
        string numbers;
        cout << "Ingresa los numeros >> ";
        cin >> numbers;
        int sum = 0;
        int num1 = stoi(numbers.substr(0, 1));
        int num2 = stoi(numbers.substr(1, 1));
        int num3 = stoi(numbers.substr(2, 1));
        int num4 = stoi(numbers.substr(3, 1));
        if (num1 % 2 != 0) {
            sum += num1;
        }
        if (num2 % 2 != 0) {
            sum += num2;
        }
        if (num3 % 2 != 0) {
            sum += num3;
        }
        if (num4 % 2 != 0) {
            sum += num4;
        }
        cout << "El resultado es >> " << sum;
    }

    void exercise_5() {
        int type;
        double price;
        cout << "Ingresa el tipo de pizza [1, 2, 3] >> ";
        cin >> type;
        cout << "Ingresa el precio de la pizza >> ";
        cin >> price;
        double discount = type == 1 ? 10 : type == 2 ? 15 : 20;
        double finalPrice = price - ((discount / 100) * price);

        // para poder imprimir y reformatear decimales
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "Total a pagar >> " << finalPrice;
    }

    void exercise_6() {
        string code;
        cout << "Ingrese código del empleado >> ";
        cin >> code;
        if (code.length() < 12) {
            cout << "Codigo de invalido.";
            return;
        }
        int max = convertToSeconds(9, 0, 0);
        int
                nameChar = stoi(code.substr(0, 2)),
                lastName_1_Char = stoi(code.substr(2, 2)),
                lastName_2_Char = stoi(code.substr(4, 2)),
                hour = stoi(code.substr(6, 2)),
                minutes = stoi(code.substr(8, 2)),
                seconds = stoi(code.substr(10, 2));
        int join = convertToSeconds(hour, minutes, seconds);
        cout << "Hora de entrada: " << hour << endl;
        cout << "Minuto de entrada: " << minutes << endl;
        cout << "Segundos de entrada: " << seconds << endl;
        cout << "Su nombre empieza con la letra: " << (char) nameChar << endl;
        cout << "Su apellido paterno inicia con la letra: " << (char) lastName_1_Char << endl;
        cout << "Su apellido materno inicia con la letra: " << (char) lastName_2_Char << endl;
        cout << "Llegó tarde (1: sí; 0: no): " << (join > max ? 1 : 0) << endl;
    }

    int convertToSeconds(int hours, int minutes, int seconds) {
        return (hours * 3600) + (minutes * 60) + seconds;
    }

    void exercise_7() {
        string kingOfCar, color;
        int age;
        cout << "Ingrese el modelo: ";
        cin >> kingOfCar;
        cout << "Color (B: blanco; M: metalizado; O: otros): ";
        cin >> color;
        cout << "Edad: ";
        cin >> age;
        // para poder imprimir y reformatear decimales
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "Precio del seguro: " << calculatePrice(getPrice(kingOfCar, color), age);
    }

    double getPrice(string king, string color) {
        map<string, map<string, double>> pricesMap = {
                {"A", {
                              {"B", 240.50},
                              {"M", 330.00},
                              {"O", 270.50}
                      }},
                {"B", {
                              {"B", 300.00},
                              {"M", 360.50},
                              {"O", 330.00}
                      }},
        };
        return pricesMap[king][color];
    }

    double calculatePrice(double price, int age) {
        double increment = age < 31 ? 25 : (age > 31 && age < 65) ? 0 : 10;
        double toAdd = (increment / 100) * price;
        return price + toAdd;
    }

    void exercise_8() {
        string zone;
        cout << "Ingrese la zona elegida (Vip, Platea, Popular): ";
        cin >> zone;
        int tickets;
        cout << "Ingrese el número de entradas: ";
        cin >> tickets;
        string vip;
        cout << "Es socio de la U (S: sí; N: no): ";
        cin >> vip;
        double price = getPriceByZone(zone);
        double discount = discountPerTickets(tickets);
        double discontVip = vip == "S" || vip == "s" ? 8 : 0;

        // para poder imprimir y reformatear decimales
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "El monto a pagar es: " << calculatePrice(price, tickets, discount, discontVip);
    }

    double calculatePrice(double price, int amount, double discount, double vipdiscount) {
        double totalPrice = price * amount;
        totalPrice = totalPrice - obtainDiscount(totalPrice, discount);
        totalPrice = totalPrice - obtainDiscount(totalPrice, vipdiscount);
        return totalPrice;
    }

    double obtainDiscount(double price, double discount) {
        return (discount / 100) * price;
    }

    double getPriceByZone(string zone) {
        return (zone == "V" || zone == "v") ? 350 : (zone == "P" || zone == "p" ? 130 : 50);
    }

    double discountPerTickets(int tickets) {
        return (tickets > 3 && tickets < 6) ? 5 : (tickets > 7 && tickets < 9) ? 7.5 : (tickets > 9) ? 10 : 0;
    }
};


#endif //EJERCICIOS_SHEET_4_H
