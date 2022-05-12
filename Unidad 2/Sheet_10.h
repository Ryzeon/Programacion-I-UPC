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
        int n = 5;
        int a = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");

        for (int i = 0; i < n; i++) {
            for (int z = 0; z < a; z++) {
                if (z != 0) {
                    cout << "          ";
                }
                for (int j = 0; j < n; j++) {
                    if (i == j || i == n - 1 || j == 0) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }

    void exercise_8() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        int centerIndex = 1;
        for (int i = 1; i <= n; ++i) {
            for (int ga = 0; ga < (n - centerIndex); ga++) {
                cout << " ";
            }
            for (int j = 1; j <= i; ++j) {
                if (j == centerIndex) {
                    for (int k = j; k >= 1; --k) {
                        cout << k;
                    }
                    break;
                } else {
                    cout << j;
                }
            }
            cout << endl;
            centerIndex++;
        }
    }

    void exercise_9() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");

        int centerIndex = 1;
        for (int i = 1; i <= (n * 2) - 1; ++i) {
            for (int ga = 0; ga < (n - centerIndex); ga++) {
                cout << " ";
            }
            int numberToLoop = i;
            if (i > n) {
                numberToLoop = (n * 2) - i;
            }
            for (int j = 1; j <= numberToLoop; ++j) {
                if (j == centerIndex) {
                    for (int k = 0; k < j; k++) {
                        cout << (j + k);
                    }
                    break;
                } else {
                    cout << j;
                }
            }
            cout << endl;
            if ((i + 1) > n) {
                centerIndex--;
            } else {
                centerIndex++;
            }
        }
    }

    void exercise_10() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > +2 && v <= 10; }),
                                "El valor debe ser mayor a 2 y menor que 10");
        for (int i = 0; i < n; i++) {
            int repeat = 0;
            int spaces = (n * 2 - 2);
            spaces -= i;
            // - 2 para quitarle el ultimo y el primero
            int numberToLoop = (n - i);
            for (int j = n; j >= numberToLoop; j--) {
                cout << j;
                repeat++;
                spaces--;
                if (j == 1) {
                    // reset
                    repeat = 0;
                    // reset
                    spaces = 0;
                    for (int k = 2; k <= n; k++) {
                        cout << k;
                    }
                }
            }
            for (int z = 0; z < spaces; z++) {
                cout << " ";
            }
            for (int k = repeat; k > 0; k--) {
                cout << (n - k + 1);
            }
            cout << endl;
        }

        // lo mismo pero invertido xd
        for (int i = (n - 2); i >= 0; i--) {
            int repeat = 0;
            int spaces = (n * 2 - 2);
            spaces -= i;
            // - 2 para quitarle el ultimo y el primero
            int numberToLoop = (n - i);
            for (int j = n; j >= numberToLoop; j--) {
                cout << j;
                repeat++;
                spaces--;
            }
            for (int z = 0; z < spaces; z++) {
                cout << " ";
            }
            for (int k = repeat; k > 0; k--) {
                cout << (n - k + 1);
            }
            cout << endl;
        }
    }

    void exercise_11() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");
        int rowReversed = n;
        int columnReversed = n;
        for (int row = 1; row <= (n * 2 - 1); row++) {
            int reversed = n;
            for (int column = 1; column <= (n * 2 - 1); column++) {
//                if (row == 1 || column == 1 || row == (n * 2 - 1) || column == (n * 2  - 1)) {
                if (row == 1 || row == (n * 2 - 1) || column == 1 || column == (n * 2 - 1)) {
                    int toPrint = row == 1 || row == (n * 2 - 1) ? column : row;
                    if (toPrint > n) {
                        if (toPrint == column) {
                            reversed--;
                            toPrint = reversed;
                        } else {
                            if (column == 1) {
                                columnReversed--;
                                toPrint = columnReversed;
                            } else {
                                rowReversed--;
                                toPrint = rowReversed;
                            }
                        }
                    }
                    cout << " " << toPrint;
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

    void exercise_12() {
        int n = utils::ask<int>("Ingrese N: ", ([](int v) { return v > 0 && v < 10; }),
                                "El valor debe ser mayor a 0 y menor que 10");

        int centerIndex = 1;
        for (int i = 1; i <= (n * 2) - 1; ++i) {
            for (int ga = 0; ga < (n - centerIndex); ga++) {
                cout << " ";
            }
            int numberToLoop = i;
            if (i > n) {
                numberToLoop = (n * 2) - i;
            }
            for (int j = 1; j <= numberToLoop; ++j) {
                if (j == centerIndex) {
                    for (int k = 0; k < j; k++) {
                        cout << (char) ((j + k) + 64);
                    }
                    break;
                } else {
                    cout << (char) (j + 64);
                }
            }
            cout << endl;
            if ((i + 1) > n) {
                centerIndex--;
            } else {
                centerIndex++;
            }
        }
    }
};


#endif //EJERCICIOS_SHEET_10_H
