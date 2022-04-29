//
// Created by ryzeon on 27/04/22.
//

#ifndef EJERCICIOS_SHEET_4_H
#define EJERCICIOS_SHEET_4_H

// estructuras selectivas
class Sheet_4 {
public:
    Sheet_4(int choise) {
        switch (choise) {
            case 1:
                Sheet_4::exercise_1();
                break;
            case 2:
                Sheet_4::exercise_2();
                break;
            case 3:
                Sheet_4::exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        char type;
        cout << "Ingresa el tipo de producto (P: Papa; C: Cebolla; L: Limon; A: Aji; M: Maiz): ";
        cin >> type;
        type = toupper(type);
        if (!(type == 'P' || type == 'C' || type == 'L' || type == 'A' || type == 'M')) {
            cout << "Tipo de producto no valido" << endl;
            exercise_1();
            return;
        }
        int amount;
        cout << "Ingresa la cantidad de sacos: ";
        cin >> amount;
        if (amount < 0) {
            cout << "Cantidad de sacos no valida" << endl;
            exercise_1();
            return;
        }
        double pricePerSack;
        switch (type) {
            case 'P':
                pricePerSack = 20.5;
                break;
            case 'C':
                pricePerSack = 19.4;
                break;
            case 'L':
                pricePerSack = 32.3;
                break;
            case 'A':
                pricePerSack = 16.5;
                break;
            default:
                pricePerSack = 19.8;
                break;
        }
        double total = pricePerSack * amount;
        cout << "El precio total es: " << total << endl;
    }

    void exercise_2() {
        char zone;
        cout << "Zona elegida (V: vip; P: platea; O: popular): ";
        cin >> zone;
        zone = toupper(zone);
        if (!(zone == 'V' || zone == 'P' || zone == 'O')) {
            cout << "Zona no valida" << endl;
            exercise_2();
            return;
        }
        char typeOfPayment;
        cout << "Tipo de pago (C: contado; T: Tarjeta): ";
        cin >> typeOfPayment;
        typeOfPayment = toupper(typeOfPayment);
        if (!(typeOfPayment == 'C' || typeOfPayment == 'T')) {
            cout << "Tipo de pago no valido" << endl;
            exercise_2();
            return;
        }
        // null char
        char typeOfBank;
        if (typeOfPayment == 'T') {
            cout << "Tarjeta de que banco (C: crédito; N: continental; O: otros): ";
            cin >> typeOfBank;
            typeOfBank = toupper(typeOfBank);
            if (!(typeOfBank == 'C' || typeOfBank == 'N' || typeOfBank == 'O')) {
                cout << "Banco no valido" << endl;
                exercise_2();
                return;
            }
        }
        int price;
        switch (zone) {
            case 'V':
                if (typeOfPayment == 'C') {
                    price = 1500;
                } else {
                    switch (typeOfBank) {
                        case 'C':
                            price = 2000;
                            break;
                        case 'N':
                            price = 1900;
                            break;
                        default:
                            price = 2100;
                            break;
                    }
                }
                break;
            case 'P':
                if (typeOfPayment == 'C') {
                    price = 750;
                } else {
                    switch (typeOfBank) {
                        case 'C':
                            price = 950;
                            break;
                        case 'N':
                            price = 875;
                            break;
                        default:
                            price = 1020;
                            break;
                    }
                }
                break;
            default:
                if (typeOfPayment == 'C') {
                    price = 265;
                } else {
                    switch (typeOfBank) {
                        case 'C':
                            price = 320;
                            break;
                        case 'N':
                            price = 300;
                            break;
                        default:
                            price = 335;
                            break;
                    }
                }
                break;
        }
        cout << "Precio de entrada: " << price << endl;
    }

    void exercise_3() {
        int productCode;
        cout << "Ingresa el codigo del producto >> ";
        cin >> productCode;
        if (productCode < 0 || productCode > 999999) {
            cout << "Codigo invalido" << endl;
            exercise_3();
            return;
        }
        int firstDigit = productCode / 100000;
        double price;
        cout << "Ingresa el precio >> ";
        cin >> price;
        if (price < 0) {
            cout << "Precio invalido" << endl;
            exercise_3();
            return;
        }
        double discount;
        switch (firstDigit) {
            case 4:
            case 9:
                discount = 4.5;
                break;
            case 1:
            case 5:
                discount = 8;
                break;
            case 2:
            case 6:
                discount = 3.5;
                break;
            case 8:
                discount = 4.25;
                break;
            case 3:
            case 7:
                discount = 11;
                break;
            default:
                discount = 0;
                break;
        }
        double totalDiscount = price * discount / 100;
        double totalPrice = price - totalDiscount;
        cout << "El precio total es de " << totalPrice << endl;
    }
};


#endif //EJERCICIOS_SHEET_4_H
