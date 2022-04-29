//
// Created by ryzeon on 28/04/22.
//

#ifndef EJERCICIOS_SHEET_5_H
#define EJERCICIOS_SHEET_5_H


class Sheet_5 {

public:
    Sheet_5(int choise) {
        switch (choise) {
            case 1:
                this->exercise_1();
                break;
            case 2:
                this->exercise_2();
                break;
            case 3:
                this->exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        int hoursInParking;
        cout << "Ingresa el numero de horas: ";
        cin >> hoursInParking;
        if (hoursInParking < 0) {
            cout << "No puedes ingresar un numero negativo" << endl;
            exercise_1();
            return;
        }

        double cost = 0;
        if (hoursInParking <= 2) {
            cost = hoursInParking * 5;
        } else if (hoursInParking >= 3 && hoursInParking <= 5) {
            cost = 10 + (hoursInParking - 2) * 4;
        } else if (hoursInParking > 5 && hoursInParking <= 10) {
            cost = 10 + 12 + (hoursInParking - 5) * 3;
        } else {
            cost = 10 + 12 + 15 + (hoursInParking - 10) * 2;
        }
        cout << "El costo total es: $" << cost << endl;
    }

    void exercise_2() {
        string input;
        cout << "Ingresa el codigo asignado: ";
        cin >> input;
        if (input.length() < 16) {
            cout << "El codigo debe tener 16 digitos" << endl;
            exercise_2();
            return;
        }
        // split input into two parts input has 16 digits so split is at index 8 and split into a array
        string firstPart = input.substr(0, 8);
        string secondPart = input.substr(8, 16);

        // Now decode first part
        int typeOfCallCharCode[2] = {
                stoi(firstPart.substr(0, 2)),
                stoi(firstPart.substr(2, 4))
        };
        // convert the char code to string
        string typeOfFirstCall;
        for (int i: typeOfCallCharCode) {
            typeOfFirstCall += char(i);
        }
        int
                FirstCallHours = stoi(firstPart.substr(4, 2)),
                FirstCallMinutes = stoi(firstPart.substr(6, 2));
        double costFirstCall = (FirstCallHours * 60 + FirstCallMinutes) * (typeOfFirstCall == "FI" ? 0.15 : 0.35);
        // End decode first part

        // Now decode second part
        string typeOfSecondCall;
        int typeOfSecondCallCharCode[2] = {
                stoi(secondPart.substr(0, 2)),
                stoi(secondPart.substr(2, 4))
        };
        for (int i: typeOfSecondCallCharCode) {
            typeOfSecondCall += char(i);
        }
        int
                SecondCallHours = stoi(secondPart.substr(4, 2)),
                SecondCallMinutes = stoi(secondPart.substr(6, 2));
        double costSecondCall = (SecondCallHours * 60 + SecondCallMinutes) * (typeOfSecondCall == "FI" ? 0.15 : 0.35);
        // End decode second part
        if (typeOfFirstCall == "FI") {
            cout << "Cantidad de horas a Fijo: " << FirstCallHours << endl;
            cout << "Cantidad de minutos a Fijo: " << FirstCallMinutes << endl;
            cout << "Costo de horas a Celular: " << SecondCallHours << endl;
            cout << "Costo de minutos a Celular: " << SecondCallMinutes << endl;
            cout << "Monto a pagar por el consumo: " << (costFirstCall + costSecondCall) << endl;
            if (costFirstCall > costSecondCall) {
                cout << "El mayor gasto lo tuvo al realizar llamadas a (F: fijo; C: celular): F" << endl;
            } else {
                cout << "El mayor gasto lo tuvo al realizar llamadas a (F: fijo; C: celular): C" << endl;
            }
        } else {
            cout << "Cantidad de horas a Fijo: " << SecondCallHours << endl;
            cout << "Cantidad de minutos a Fijo: " << SecondCallMinutes << endl;
            cout << "Costo de horas a Celular: " << FirstCallHours << endl;
            cout << "Costo de minutos a Celular: " << FirstCallMinutes << endl;
            cout << "Monto a pagar por el consumo: " << (costFirstCall + costSecondCall) << endl;
            if (costFirstCall > costSecondCall) {
                cout << "El mayor gasto lo tuvo al realizar llamadas a (F: fijo; C: celular): F" << endl;
            } else {
                cout << "El mayor gasto lo tuvo al realizar llamadas a (F: fijo; C: celular): C" << endl;
            }
        }
    }

    void exercise_3() {
        char type;
        cout << "Cobertura amplia (A) o daños a terceros (B): ";
        cin >> type;
        type = toupper(type);
        if (!(type == 'A' || type == 'B')) {
            cout << "Error, ingrese una opcion valida" << endl;
            return;
        }
        double price = type == 'A' ? 1200 : 950;
        if (getReply("Tiene por hábito beber alcohol")) {
            price += price * 0.1;
        }
        if (getReply("Usa lentes")) {
            price += price * 0.05;
        }
        if (getReply("Padece alguna enfermedad")) {
            price += price * 0.05;
        }
        int age;
        cout << "Edad: ";
        cin >> age;
        if (age > 40) {
            price += price * 0.2;
        } else {
            price += price * 0.1;
        }

        cout << "El costo de la poliza es: " << price << endl;
    }

    bool getReply(string toAsk) {
        char reply;
        cout << toAsk << " (S: si; N: no): ";
        cin >> reply;
        reply = toupper(reply);
        if (reply == 'S') {
            return true;
        } else if (reply == 'N') {
            return false;
        } else {
            cout << "Error, ingrese una opcion valida" << endl;
            return getReply(toAsk);
        }
    }
};


#endif //EJERCICIOS_SHEET_5_H
