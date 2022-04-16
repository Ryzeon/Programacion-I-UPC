//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_1_H
#define EJERCICIOS_SHEET_1_H

#include <iostream>

using namespace std;

class Sheet_1 {
public:
    explicit Sheet_1(int choise) {
        // se que esto esta feo pero xd :PIPIPI:
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
            case 6:
                Sheet_1::exercise_6();
                break;
            case 7:
                Sheet_1::exercise_7();
                break;
            case 8:
                Sheet_1::exercise_8();
                break;
            case 9:
                Sheet_1::exercise_9();
                break;
            case 10:
                Sheet_1::exercise_10();
                break;
            case 11:
                Sheet_1::exercise_11();
                break;
            case 12:
                Sheet_1::exercise_12();
                break;
            case 13:
                Sheet_1::exercise_13();
                break;
            case 14:
                Sheet_1::exercise_14();
                break;
            case 15:
                Sheet_1::exercise_15();
                break;
            case 16:
                Sheet_1::exercise_16();
                break;
            case 17:
                Sheet_1::exercise_17();
                break;
            case 18:
                Sheet_1::exercise_18();
                break;
            case 19:
                Sheet_1::exercise_19();
                break;
            case 20:
                Sheet_1::exercise_20();
                break;
            case 21:
                Sheet_1::exercise_21();
                break;
            case 22:
                Sheet_1::exercise_22();
                break;
            case 23:
                Sheet_1::exercise_23();
                break;
            case 24:
                Sheet_1::exercise_24();
                break;
            case 25:
                Sheet_1::exercise_25();
                break;
            case 26:
                Sheet_1::exercise_26();
                break;
            case 27:
                Sheet_1::exercise_27();
                break;
            case 28:
                Sheet_1::exercise_28();
                break;
            case 29:
                Sheet_1::exercise_29();
                break;
            case 30:
                Sheet_1::exercise_30();
                break;
        }
    }

private:
    void exercise_1() {
        int number;
        cout << "Ingresa el numero: ";
        cin >> number;
        cout << "El numero es " << (number % 2 == 0 ? "par" : "impar") << endl;
    }

    void exercise_2() {
        double dinosaure_weight, elephant_weight;
        cout << "Ingresa el peso del dinosauro: ";
        cin >> dinosaure_weight;
        cout << "Ingresa el peso del elefante: ";
        cin >> elephant_weight;
        if (dinosaure_weight > elephant_weight) {
            cout << "El dinosauro pesa mas que el elefante" << endl;
        } else if (dinosaure_weight < elephant_weight) {
            cout << "El elefante pesa mas que el dinosauro" << endl;
        } else {
            cout << "El dinosauro y el elefante pesan lo mismo" << endl;
        }
    }

    void exercise_3() {
        double grade;
        cout << "Ingresa tu calificacion: ";
        cin >> grade;
        if (grade >= 0 && grade <= 20) {
            string status = grade <= 12.5 ? "Desaprobado" : "Aprobado";
            cout << "El alumno esta " << status << endl;
        } else {
            cout << "Calificacion invalida" << endl;
        }
    }

    void exercise_4() {

    }

    void exercise_5() {

    }

    void exercise_6() {

    }

    void exercise_7() {

    }

    void exercise_8() {

    }

    void exercise_9() {

    }

    void exercise_10() {

    }

    void exercise_11() {

    }

    void exercise_12() {

    }

    void exercise_13() {

    }

    void exercise_14() {

    }

    void exercise_15() {

    }

    void exercise_16() {

    }

    void exercise_17() {

    }

    void exercise_18() {

    }

    void exercise_19() {

    }

    void exercise_20() {

    }

    void exercise_21() {

    }

    void exercise_22() {

    }

    void exercise_23() {

    }

    void exercise_24() {

    }

    void exercise_25() {

    }

    void exercise_26() {

    }

    void exercise_27() {

    }


    void exercise_28() {

    }

    void exercise_29() {

    }

    void exercise_30() {

    }
};


#endif //EJERCICIOS_SHEET_1_H
