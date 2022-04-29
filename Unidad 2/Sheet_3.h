//
// Created by ryzeon on 27/04/22.
//

#ifndef EJERCICIOS_SHEET_3_H
#define EJERCICIOS_SHEET_3_H

// estructuras selectivas
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
            case 4:
                Sheet_3::exercise_4();
                break;
        }
    }

private:
    void exercise_1() {
        char brand;
        cout << "Ingrese el frabricante (M: Microsoft; A: Apple; L: Linux) >> ";
        cin >> brand;
        brand = toupper(brand);
        if (brand == 'M' || brand == 'A' || brand == 'L') {
            char kindOfProgram;
            cout << "Ingrese el tipo de programa S: Sistema operativo; L: Lenguaje de programación >> ";
            cin >> kindOfProgram;
            kindOfProgram = toupper(kindOfProgram);
            if (!(kindOfProgram == 'S' || kindOfProgram == 'L')) {
                cout << "Opcion de programa invalid" << endl;
                exercise_1();
                return;
            }
            char promL = 'N';
            if (kindOfProgram == 'L') {
                cout << "Ingrese el lenguage de programacion (C: Celular; T: Tabla; O: Otros) >> ";
                cin >> promL;
                promL = toupper(promL);
                if (!(promL == 'C' || promL == 'T' || promL == 'O')) {
                    cout << "Opcion invalida" << endl;
                    exercise_1();
                    return;
                }
            }
            bool opSys = promL == 'N';
            double price = 0;
            switch (brand) {
                case 'M': {
                    if (opSys) {
                        price = 1500;
                    } else {
                        switch (promL) {
                            case 'C':
                                price = 1800;
                                break;
                            case 'T':
                                price = 1200;
                                break;
                            case 'O':
                                price = 900;
                                break;
                        }
                    }
                    break;
                }
                case 'A': {
                    if (opSys) {
                        price = 2500;
                    } else {
                        switch (promL) {
                            case 'C':
                                price = 1900;
                                break;
                            case 'T':
                                price = 1800;
                                break;
                            case 'O':
                                price = 1600;
                                break;
                        }
                    }
                    break;
                }
                case 'L': {
                    if (opSys) {
                        price = 1000;
                    } else {
                        switch (promL) {
                            case 'C':
                                price = 100;
                                break;
                            case 'T':
                                price = 150;
                                break;
                            case 'O':
                                price = 50;
                                break;
                        }
                    }
                    break;
                }
            }
            cout << "El precio seria " << price;
        } else {
            cout << "Opcion invalida!" << endl;
            exercise_1();
        }

    }

    void exercise_2() {
        int age;
        char nationality;
        cout << "Ingrese la edad del jugador >> ";
        cin >> age;
        if (age < 0 || age > 60) {
            cout << "La edad es invalida" << endl;
            exercise_2();
            return;
        }
        cout << "Ingrese la nacionalidad del jugador (E: Extranjero; N: Nacional >> ";
        cin >> nationality;
        nationality = toupper(nationality);
        if (!(nationality == 'E' || nationality == 'N')) {
            cout << "Nacionalidad invalida!" << endl;
            exercise_2();
            return;
        }
        int total = 2500;
        if (nationality == 'E') {
            total += 500; // Bono para el extranjero
        }
        if (age >= 15 && age <= 20) {
            total += 1400;
        } else if (age >= 21 && age < 25) {
            total += 1500;
        } else if (age >= 25 && age <= 30) {
            total += 1200;
        } else {
            total += 800;
        }
        cout << "El sueldo del jugador es de " << total << " soles" << endl;
    }

    void exercise_3() {
        char product;
        cout << "Ingrese el tipo de producto (O: Oficina; J: Juegos; U: Utilitarios >> ";
        cin >> product;
        product = toupper(product);
        if (!(product == 'O' || product == 'J' || product == 'U')) {
            cout << "Producto invalido!" << endl;
            exercise_3();
            return;
        }
        char typeOfPhone;
        cout << "Ingrese el tipo de telefono (i: iPhone; A: Android) >> ";
        cin >> typeOfPhone;
        typeOfPhone = toupper(typeOfPhone);
        if (!(typeOfPhone == 'I' || typeOfPhone == 'A')) {
            cout << "Tipo de telefono invalido!" << endl;
            exercise_3();
            return;
        }
        int amount;
        cout << "Ingrese la cantidad de productos >> ";
        cin >> amount;
        if (amount < 0) {
            cout << "Cantidad invalida!" << endl;
            exercise_3();
            return;
        }
        double pricePerUnit;
        switch (product) {
            case 'O':
                if (typeOfPhone == 'I') {
                    pricePerUnit = 50.60;
                } else {
                    pricePerUnit = 20.30;
                }
                break;
            case 'J':
                if (typeOfPhone == 'I') {
                    pricePerUnit = 90.80;
                } else {
                    pricePerUnit = 40.50;
                }
                break;
            default:
                if (typeOfPhone == 'I') {
                    pricePerUnit = 60.50;
                } else {
                    pricePerUnit = 30.60;
                }
                break;
        }
        double total = amount * pricePerUnit;
        cout << "El precio total es de " << total << " soles" << endl;
    }

    void exercise_4() {
        int codeOfEmployer;
        cout << "Ingrese el codigo del empleado >> ";
        cin >> codeOfEmployer;
        if (codeOfEmployer < 100 || codeOfEmployer > 999) {
            cout << "Codigo invalido!" << endl;
            exercise_4();
            return;
        }
        int firstDigit = codeOfEmployer / 100;
        int secondDigit = (codeOfEmployer / 10) % 10;
        int thirdDigit = codeOfEmployer % 10;
        string encryptedCode;

        // Encrypt the code for the first digit
        if (firstDigit >= 1 && firstDigit <= 3) {
            encryptedCode += "X";
        } else if (firstDigit >= 4 && firstDigit <= 6) {
            encryptedCode += "Y";
        } else if (firstDigit >= 7 && firstDigit <= 9) {
            encryptedCode += "Z";
        } else {
            encryptedCode += "#";
        }

        // Encrypt the code for the second digit
        if (secondDigit >= 1 && secondDigit <= 3) {
            encryptedCode += "T";
        } else if (secondDigit >= 4 && secondDigit <= 6) {
            encryptedCode += "W";
        } else if (secondDigit >= 7 && secondDigit <= 9) {
            encryptedCode += "P";
        } else {
            encryptedCode += "&";
        }

        // Encrypt the code for the third digit
        if (thirdDigit >= 1 && thirdDigit <= 3) {
            encryptedCode += "Q";
        } else if (thirdDigit >= 4 && thirdDigit <= 6) {
            encryptedCode += "W";
        } else if (thirdDigit >= 7 && thirdDigit <= 9) {
            encryptedCode += "M";
        } else {
            encryptedCode += "@";
        }

        cout << "El codigo encriptado es " << encryptedCode << endl;
    }
};


#endif //EJERCICIOS_SHEET_3_H
