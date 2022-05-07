//
// Created by ryzeon on 3/05/22.
//

#ifndef EJERCICIOS_SHEET_10_H
#define EJERCICIOS_SHEET_10_H

#include "utils.h"

class Sheet_10 {
public:
    Sheet_10(int choise) {
        switch (choise) {
            case 1:
                exercise_1();
                break;
            case 2:
                exercise_2();
                break;
            case 3:
                exercise_3();
                break;
            case 4:
                exercise_4();
                break;
            case 5:
                exercise_5();
                break;
            case 6:
                exercise_6();
                break;
            case 7:
                exercise_7();
                break;
            case 8:
                exercise_8();
                break;
            case 9:
                exercise_9();
                break;
            case 10:
                exercise_10();
                break;
            case 11:
                exercise_11();
                break;
            case 12:
                exercise_12();
                break;
        }
    }

private:

    void exercise_1() {
        int n = utils::ask<int>("Ingrese un número: ", ([](int v) { return v > 0; }),
                                "El valor debe ser mayor a 0");
        string sb;
        for (int i = 1; i <= n; i++) {
            sb += to_string(i);
            cout << sb << endl;
        }
    }

    void exercise_2() {
        int row = utils::ask<int>("Ingrese un número: ", ([](int v) { return v > 0; }),
                                  "El valor debe ser mayor a 0");
        char character = utils::ask<char>("Ingrese un caracter: ", ([](char v) { return v != '\0'; }),
                                          "El valor debe ser diferente de nulo");
        string sb;
        for (int i = 0; i < row; i++) {
            sb += character;
        }
        for (int i = 0; i < row; i++) {
            cout << sb << endl;
            sb = sb.substr(0, sb.length() - 1);
        }
    }

    void exercise_3() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        // show a square with n rows, only border
        // i = row
        // j = column
        for (int i = 0; i < n; i++) {
            cout << setw(50);
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    cout << "* "; // borde
                } else {
                    cout << "  "; // 2 espacios en blanco
                }
            }
            cout << endl;
        }
    }

    void exercise_4() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        // show a square with n rows, only border
        for (int i = 0; i < n; i++) {
            cout << setw(50);
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    cout << "* "; // borde
                } else {
                    // now make a diagonal in the middle
                    if (i == j) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }

    void exercise_5() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        //make a triangle with n rows
        for (int i = 0; i < n; i++) {
            cout << setw(50);
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - 1 || j == 0) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

    void exercise_6() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        //make a triangle with n rows
        for (int i = 0; i < n; i++) {
            cout << setw(50);
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - 1 || j == 0) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            cout << setw(50);
            for (int j = 0; j < n; j++) {
                if (j == i || j == n - 1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

    void exercise_7() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - 1 || j == 0) {
                    row += "* ";
                } else {
                    row += "  ";
                }
            }
            string sb = row;
            sb += add_spaces(10);
            sb += row;
            sb += add_spaces(10);
            sb += row;
            cout << setw(50);
            cout << sb << endl;
        }
    }

    string add_spaces(int spaces) {
        string output = "";
        for (int i = 0; i < spaces; i++) {
            output += " ";
        }
        return output;
    }

    void exercise_8() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        string *rows = new string[n];
        int centerIndex = 1;
        for (int i = 1; i <= n; ++i) {
            string row;
            // cout << "NUMERO DE FILA " << i << endl;
            for (int j = 1; j <= i; ++j) {
                // cout << "NUMERO DE  J " << j << endl;
                if(j  == centerIndex) {
                 //   cout << "----------- COMIENZA REVERSA CUANDO J ES " << j << " ------------" << endl;
                    for (int k = j; k >= 1; --k) {
                   //     cout << "VALOR DE K" <<  k << endl;
                        row +=to_string(k);
                    }
                //    cout << "-----------  TERMINA REVERSA -----------" << endl;
                    break;
                } else {
                    row +=to_string(j);
                }
            }
            rows[i - 1] = add_spaces(n - centerIndex) + row;
            centerIndex++;
        }
        for (int i = 0; i < n; ++i) {
            cout << rows[i] << endl;
        }
    }

    void exercise_9() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 11");
        string *rows = new string[  (n * 2) -1];
        int centerIndex = 1;
        for (int i = 1; i <= n; ++i) {
            string row;
            // cout << "NUMERO DE FILA " << i << endl;
            for (int j = 1; j <= i; ++j) {
                // cout << "NUMERO DE  J " << j << endl;
                if(j  == centerIndex) {
                    //   cout << "----------- COMIENZA REVERSA CUANDO J ES " << j << " ------------" << endl;
                    for (int k = j; k >= 1; --k) {
                        //     cout << "VALOR DE K" <<  k << endl;
                        row +=to_string(k);
                    }
                    //    cout << "-----------  TERMINA REVERSA -----------" << endl;
                    break;
                } else {
                    row +=to_string(j);
                }
            }
            rows[i - 1] = add_spaces(n - centerIndex) + row;
            centerIndex++;
        }
        for (int i = (n * 2) -2; i >= n; ++i) {
            string row = rows[i];
            row = row.substr(0, row.length() - 1);
            cout << rows->size() << " SIZE" << endl;
            cout << rows->length() << " LEGHT" << endl;
            rows[i] = row;
            cout << rows->size() << " SIZE" << endl;
            cout << rows->length() << " LEGHT" << endl;
        }
        for (int i = 0; i < rows->length(); ++i) {
            cout << rows[i] << endl;
        }
    }

    void exercise_10() {

    }

    void exercise_11() {

    }

    void exercise_12() {

    }
};


#endif //EJERCICIOS_SHEET_10_H
