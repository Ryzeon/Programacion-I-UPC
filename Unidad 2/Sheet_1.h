//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_1_H
#define EJERCICIOS_SHEET_1_H

#include <iostream>
#include <valarray>
#include <iomanip>

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
        int age;
        cout << "Ingresa la edad de la persona : ";
        cin >> age;
        int price = age < 18 ? 7 : (age >= 18 && age <= 50) ? 15 : 5;
        cout << "El precio de la entrada es: " << price << endl;
    }

    void exercise_5() {
        int a, b, c;
        cout << "Ingrese los lados del triangulo (A B C): ";
        cin >> a >> b >> c;
        if (a > 0 && b > 0 && c > 0) {
            //  Cada lado debe ser menor a
            //la suma y mayor a la diferencia de los otros dos lados.
            bool is_triangle = a + b > c && a + c > b && b + c > a;
            if (is_triangle) {
                cout << "SI ES UN TRIANGULO" << endl;
            } else {
                cout << "NO ES UN TRIANGULO" << endl;
            }
        } else {
            cout << "Todos los lados deben ser mayores que 0" << endl;
        }
    }

    void exercise_6() {
        int a, b, c, value;
        cout << "Ingrese el valor de A: ";
        cin >> a;
        cout << "Ingrese el valor de B: ";
        cin >> b;
        cout << "Ingrese el valor de C: ";
        cin >> c;
        cout << "Ingrese un valor para evaluar: ";
        cin >> value;
        double discriminant = pow(b, 2) - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << fixed << setprecision(2);
            cout << "Las raices son: " << x1 << " y " << x2 << endl;
        } else {
            cout << "No tiene raices reales" << endl;
        }
        double result = a * pow(value, 2) + b * value + c;
        cout << a << "(" << value << ")^2 + " << b << "(" << value << ") + " << c << " = " << result << endl;
    }

    void exercise_7() {
        int n1, n2;
        cout << "Ingrese dos numeros enteros (N1 N2): ";
        cin >> n1 >> n2;
        if (n1 >= 0 && n2 >= 0) {
            if (n1 % n2 == 0) {
                cout << n1 << " es multiplo de " << n2 << endl;
            } else {
                cout << n1 << " no es multiplo de " << n2 << endl;
            }
        } else {
            cout << "Los numeros deben ser mayores que 0" << endl;
        }
    }

    void exercise_8() {
        char gen;
        cout << "Ingrese su genero (F o M): ";
        cin >> gen;
        gen = toupper(gen);
        double age;
        cout << "Ingrese la edad de la persona: ";
        cin >> age;
        double ticks = round(((gen == 'F' ? 220 : 210) - age) / 10);
        cout << "El número debe ser de " << ticks << " pulsaciones por cada 10 segundos aproximadamente." << endl;
    }

    void exercise_9() {
        int gl, gv;
        cout << "Ingrese la cantidad de goels del equpo local: ";
        cin >> gl;
        cout << "Ingrese la cantidad de goels del equipo visitante: ";
        cin >> gv;
        if (gl > gv) {
            cout << "Ganó el equipo local" << endl;
        } else if (gl < gv) {
            cout << "Ganó el equipo visitante" << endl;
        } else {
            cout << "Empate" << endl;
        }
    }

    void exercise_10() {
        int type1, type2, type3;
        double money;
        cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 1: ";
        cin >> type1;
        cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 2: ";
        cin >> type2;
        cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 3: ";
        cin >> type3;
        cout << "Ingrese el Monto de la propina: ";
        cin >> money;
        double total = type1 * 0.75 + type2 * 1.15 + type3 * 0.65;
        cout << "El monto total de la compra es: " << total << endl;
        if (money >= total) {
            cout << "LA PROPINA ES SUFICIENTE PARA PAGAR POR LOS CARAMELOS" << endl;
        } else {
            cout << "LA PROPINA NO FUE SUFICIENTE PARA PAGAR POR LOS CARAMELOS" << endl;
        }
    }

    void exercise_11() {
        int gigas;
        cout << "Ingrese los GB consumidos: ";
        cin >> gigas;
        if (gigas >= 0) {
            if (gigas <= 4) {
                cout << "Paga S/.50 por mes." << endl;
            } else if (gigas > 4 && gigas <= 8) {
                cout << "Paga S/.85 por mes." << endl;
            } else {
                double total = 85 + (gigas - 8) * 4.5;
                cout << "Paga S/." << total << " por mes." << endl;
            }
        } else {
            cout << "Los GB deben ser mayores que 0" << endl;
        }
    }

    void exercise_12() {
        int grades, amountOfFaults;
        cout << "Ingrese el promedio de notas: ";
        cin >> grades;
        cout << "Ingrese la cantidad de faltas: ";
        cin >> amountOfFaults;
        if (grades >= 15 && amountOfFaults == 0) {
            cout << "Aplicas para la beca" << endl;
        } else {
            cout << "No aplicas para la beca" << endl;
        }
    }

    void exercise_13() {
        int number;
        cout << "Ingrese un numero: ";
        cin >> number;
        if (number < 100) {
            cout << "Numero incorrecto" << endl;
        } else {
            int firstDigit = number / 100;
            int secondDigit = (number % 100) / 10;
            int thirdDigit = number % 10;
            cout << thirdDigit << secondDigit << firstDigit << endl;
        }
    }

    void exercise_14() {
        int number;
        cout << "Ingrese un numero: ";
        cin >> number;
        if (number < 100) {
            cout << "Numero incorrecto" << endl;
        } else {
            // check if numbers is capicua
            int firstDigit = number / 100;
            int secondDigit = (number % 100) / 10;
            int thirdDigit = number % 10;
            int capicua = thirdDigit * 100 + secondDigit * 10 + firstDigit;
            if (number == capicua) {
                cout << "El numero es capicua" << endl;
            } else {
                cout << "El numero no es capicua" << endl;
            }
        }
    }

    void exercise_15() {
        int number;
        cout << "Ingrese un numero: ";
        cin >> number;
        if (number >= 1 && number <= 100) {
            if (number >= 1 && number <= 9) {
                cout << "El numero tiene 1 digito" << endl;
            } else if (number >= 10 && number <= 99) {
                cout << "El numero tiene 2 digitos" << endl;
            } else {
                cout << "El numero tiene 3 digitos" << endl;
            }
        } else {
            cout << "Numero incorrecto" << endl;
            exercise_15();
        }
    }

    void exercise_16() {
        int studentCode;
        cout << "Ingrese el codigo del estudiante: ";
        cout << "Ingrese el codigo del estudiante: ";
        cin >> studentCode;
        if (studentCode <= 0) {
            cout << "Codigo incorrecto" << endl;
            exercise_16();
            return;
        }
        double grade_1, grade_2, grade_3;
        cout << "Ingrese las tres notas del alumno " << studentCode << ": ";
        cin >> grade_1 >> grade_2 >> grade_3;
        if (grade_1 < 0 || grade_1 > 20 || grade_2 < 0 || grade_2 > 20 || grade_3 < 0 || grade_3 > 20) {
            cout << "Notas incorrectas" << endl;
            exercise_16();
            return;
        }
        double average = 0.3 * grade_1 + 0.3 * grade_2 + 0.4 * grade_3;
        // happy face
        string happyFace = "\342\230\272";
        if (average < 13) {
            cout << "Estudia" << endl;
        } else if (average >= 13 && average < 15) {
            cout << "Felicitaciones " << happyFace << endl;
        } else if (average >= 15 && average < 20) {
            cout << "Felicitaciones " << happyFace << " " << happyFace << endl;
        } else {
            cout << "Felicitaciones " << happyFace << " " << happyFace << " " << happyFace << " " << happyFace << " "
                 << happyFace << endl;
        }
    }

    void exercise_17() {
        double x, y;
        cout << "Ingresa las coordenadas de X >> ";
        cin >> x;
        cout << "Ingresa las coordenadas de Y >> ";
        cin >> y;
        if (x == 0 && y == 0) {
            cout << "El punto de encuentra en el punto de origen.";
            return;
        }
        if (x == 0) {
            cout << "El punto de encuentra en el punto Y " << y;
            return;
        }
        if (y == 0) {
            cout << "El punto de encuentra en el punto X " << x;
            return;
        }
        int cuadrante = (x > 0 && y > 0) ? 1 : (x < 0 && y > 0) ? 2 : (x < 0 && y < 0) ? 3 : 4;
        cout << "El punto se encuentra en el cuadrante " << cuadrante;
    }

    void exercise_18() {
        int position;
        cout << "Ingrese la posición del equipo en la tabla: ";
        cin >> position;
        if (position <= 0) {
            cout << "Posición incorrecta" << endl;
            exercise_18();
            return;
        }
        if (position >= 1 && position <= 4) {
            cout << "El equipo seleccionado irá al mundial !!!!" << endl;
        } else if (position == 5) {
            cout << "El quinto va al repechaje" << endl;
        } else {
            cout << "Cómprate una TV LED para ver el mundial !!!" << endl;
        }
    }

    void exercise_19() {
        double grade;
        cout << "Ingrese la nota del estudiante: ";
        cin >> grade;
        if (grade < 0 || grade > 20) {
            cout << "Nota incorrecta" << endl;
            exercise_19();
            return;
        }
        if (grade < 5) {
            cout << "Necesita estudiar" << endl;
        } else if (grade >= 5 && grade < 13) {
            cout << "Jalado" << endl;
        } else if (grade >= 13 && grade < 15) {
            cout << "Raspando" << endl;
        } else if (grade >= 15 && grade < 20) {
            cout << "Sobresaliente" << endl;
        } else {
            cout << "Matrícula de honor" << endl;
        }
    }

    void exercise_20() {
        int credits;
        cout << "Ingrese la cantidad de créditos acumulados: ";
        cin >> credits;
        if (credits < 0) {
            cout << "Cantidad de créditos incorrecta" << endl;
            exercise_20();
            return;
        }
        string message = "CUARTO AÑO";
        if (credits < 32) {
            message = "PRIMER AÑO";
        } else if (credits >= 32 && credits <= 63) {
            message = "SEGUNDO AÑO";
        } else if (credits >= 64 && credits <= 95) {
            message = "TERCER AÑO";
        }
        cout << "El alumno se encuentra en el " << message << endl;
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
