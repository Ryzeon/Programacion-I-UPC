//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_2_H
#define EJERCICIOS_SHEET_2_H

#include <iostream>

using namespace std;

class Sheet_2 {
public:
    Sheet_2(int choise) {
        switch (choise) {
            case 1:
                Sheet_2::exercise_1();
                break;
            case 2:
                Sheet_2::exercise_2();
                break;
            case 3:
                Sheet_2::exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        int a, b, c;
        cout << "Ingresa los lados del triangulo >> ";
        cin >> a >> b >> c;
        bool equilatero = a == b && a == c && b == c;
        bool isoceles =
                (a == b && (a != c || b != c)) || (b == c && (b != a || c != a)) || (c == a && (c != b || b != a));
        bool escaleno = a != b && b != c && a != c;
        cout << "Equilátero: " << (equilatero ? "V" : "F") << endl;
        cout << "Isósceles: " << (isoceles ? "V" : "F") << endl;
        cout << "Escaleno: " << (escaleno ? "V" : "F") << endl;
    }

    void exercise_2() {
        int month;
        cout << "Ingresa el numero del mes >> ";
        cin >> month;
        int days = month == 2 ? 28 : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
        cout << "El mes " << month << " tiene " << days << " dias.";
    }

    void exercise_3() {
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
};


#endif //EJERCICIOS_SHEET_2_H
