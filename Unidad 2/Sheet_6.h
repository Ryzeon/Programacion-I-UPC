//
// Created by ryzeon on 28/04/22.
//

#ifndef EJERCICIOS_SHEET_6_H
#define EJERCICIOS_SHEET_6_H


class Sheet_6 {
public:
    Sheet_6(int choice) {
        switch (choice) {
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
            case 13:
                exercise_13();
                break;
            case 14:
                exercise_14();
                break;
            case 15:
                exercise_15();
                break;
            case 16:
                exercise_16();
                break;
            case 17:
                exercise_17();
                break;
        }
    }

private:

    void exercise_1() {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i;
        }
        cout << "La suma de los 10 primeros números positivos es " << sum << endl;
    }

    void exercise_2() {
        int n;
        cout << "Ingrese un número: ";
        cin >> n;
        // find odd numbers in the range 1 to n and print them and their sum
        int sum = 0;
        int *numbers = new int[n / 2];
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                numbers[i / 2] = i;
                sum += i;
            }
        }
        cout << "Los números impares del 1 al " << n << " son: ";
        for (int i = 0; i < n / 2; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        cout << "La suma de los números impares del 1 al " << n << " es: " << sum << endl;
    }

    void exercise_3() {
        int n;
        cout << "Ingrese un número: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_3();
            return;
        }
        // find all multiplues of 3 in the range 1 to n and print them and their sum
        cout << "Los multiplos de son: ";
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void exercise_4() {
        int n;
        cout << "Ingrese un número: ";
        cin >> n;
        if (n < 0 || n > 9) {
            cout << "Numero invalido" << endl;
            exercise_4();
            return;
        }
        for (int i = 1; i <= 10; i++) {
            cout << n << " x " << i << " = " << n * i << endl;
        }
    }

    void exercise_5() {
        int amountOfOdd, amountOfEven;
        cout << "Ingrese la cantidad de números pares: ";
        cin >> amountOfEven;
        cout << "Ingrese la cantidad de números impares: ";
        cin >> amountOfOdd;
        int *evenNumbers = getOddOrEvenNumebers(amountOfEven, true);
        int *oddNumbers = getOddOrEvenNumebers(amountOfOdd, false);
        int numEven = 0, numOdd = 0;
        for (int i = 0; i < amountOfEven; i++) {
            numEven += evenNumbers[i];
        }
        for (int i = 0; i < amountOfOdd; i++) {
            numOdd += oddNumbers[i];
        }
        cout << "La suma de los números pares es: " << numEven << endl;
        cout << "La suma de los números impares es: " << numOdd << endl;
    }

    int *getOddOrEvenNumebers(int amount, bool even) {
        int *numbers = new int[amount];
        int found = 1;
        int number = 1;
        while (found <= amount) {
            if (even) {
                if (number % 2 == 0) {
                    numbers[found - 1] = number;
                    found++;
                }
            } else {
                if (number % 2 != 0) {
                    numbers[found - 1] = number;
                    found++;
                }
            }
            number++;
        }
        return numbers;
    }

    void exercise_6() {
        int n;
        cout << "Ingrese un número: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_6();
            return;
        }
        // elevar al cuadrado el numero n
        int *numbers = getOddOrEvenNumebers(n, false);
        string result;
        int total = 0;
        // result if with this formar n + n +n = sumNumbers
        for (int i = 0; i < n; i++) {
            result += to_string(numbers[i]) + " + ";
            total += numbers[i];
        }
        result += " = " + to_string(total);
        cout << "El cuadrado del valor ingresado es: " << result << endl;
    }

    void exercise_7() {
        int amountOfStudents;
        cout << "Ingrese la cantidad de alumnos: ";
        cin >> amountOfStudents;
        if (amountOfStudents < 0) {
            cout << "Numero invalido" << endl;
            exercise_7();
            return;
        }
        for (int i = 0; i < amountOfStudents; ++i) {
            double ef, ep, tf;
            cout << "Ingrese el EF del Alumno " << i + 1 << ": ";
            cin >> ef;
            cout << "Ingrese el EP del Alumno " << i + 1 << ": ";
            cin >> ep;
            cout << "Ingrese el TF del Alumno " << i + 1 << ": ";
            cin >> tf;
            double promedio = (ef * 0.55) + (ep * 0.3) + (tf * 0.15);
            cout << "El promedio del alumno " << i + 1 << " es: " << promedio << endl;
        }
    }

    void exercise_8() {
        int amount;
        cout << "Ingrese el numero de alumnos: ";
        cin >> amount;
        if (amount < 0 || amount > 50) {
            cout << "Numero invalido" << endl;
            exercise_9();
            return;
        }
        int *numbers = new int[amount];
        for (int i = 1; i <= amount; ++i) {
            cout << "Ingrese el peso del alumno " << i << ": ";
            cin >> numbers[i - 1];
        }
        int lessThan40 = 0;
        int between40And50 = 0;
        int between50And60 = 0;
        int moreThan60 = 0;
        for (int i = 0; i < amount; ++i) {
            if (numbers[i] < 40) {
                lessThan40++;
            } else if (numbers[i] >= 40 && numbers[i] <= 50) {
                between40And50++;
            } else if (numbers[i] > 50 && numbers[i] <= 60) {
                between50And60++;
            } else {
                moreThan60++;
            }
        }
        cout << "Alumnos de menos de 40 kg: " << lessThan40 << endl;
        cout << "Alumnos entre 40 y 50 kg: " << between40And50 << endl;
        cout << "Alumnos de más de 50 y menos de 60 kg: " << between50And60 << endl;
        cout << "Alumnos de más o igual a 60 kg: " << moreThan60 << endl;
    }

    void exercise_9() {
        bool found0 = false;
        int numbersReads = 0, negativeNumbers = 0, positiveNumbers = 0, max = 0, min = 0, total = 0;
        do {
            int number;
            cout << "Ingrese un numero: ";
            cin >> number;
            if (number == 0) {
                found0 = true;
            }
            numbersReads++;
            total += number;
            if (number < 0) {
                negativeNumbers++;
            } else if (number > 0) {
                positiveNumbers++;
            }
            if (number > max) {
                max = number;
            }
            if (number < min) {
                min = number;
            }
        } while (!found0);
        cout << "Cantidad de numeros leidos: " << numbersReads << endl;
        cout << "Mayor: " << max << endl;
        cout << "Menor: " << min << endl;
        cout << "Cantidad de numeros positivos: " << positiveNumbers << endl;
        cout << "Cantidad de numeros negativos: " << negativeNumbers << endl;
        cout << "Promedio: " << total / numbersReads << endl;
    }

    void exercise_10() {
        bool done = false;
        int randomNumber = rand() % 100 + 1;
        int tries = 0;
        while (!done) {
            int number;
            cout << "Ingrese un numero: ";
            cin >> number;
            tries++;
            if (number == randomNumber) {
                if (tries >= 1 && tries <= 3) {
                    cout << "Fue pura suerte!!!" << endl;
                } else if (tries >= 4 && tries <= 6) {
                    cout << "Eres bueno!" << endl;
                } else if (tries == 7) {
                    cout << "No está mal" << endl;
                } else if (tries == 8) {
                    cout << "Se puede mejorar" << endl;
                } else {
                    cout << "Que mal estas !!!!" << endl;
                }
                done = true;
            } else if (number < randomNumber) {
                cout << "El numero es mayor" << endl;
            } else {
                cout << "El numero es menor" << endl;
            }
        }
    }

    void exercise_11() {
        int n;
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_11();
            return;
        }
        double sum = 1;
        double nextToSum = 2;
        // I make a for to sum the sequence but reduce 1 loop  because first loop its 1
        for (int i = 0; i < (n - 1); ++i) {
            sum += 1.0 / nextToSum;
            nextToSum = nextToSum * 2;
        }
        cout << "La suma es: " << sum << endl;
    }

    void exercise_12() {
        int n;
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_12();
            return;
        }
        double sum = 1;
        double nextToSum = 2;
        // I make a for to sum the sequence but reduce 1 loop  because first loop its 1
        for (int i = 0; i < (n - 1); ++i) {
            if (i % 2 == 0) {
                sum -= 1.0 / nextToSum;
            } else {
                sum += 1.0 / nextToSum;
            }
            nextToSum = nextToSum * 2;
        }
        cout << "La suma es: " << sum << endl;
    }

    void exercise_13() {
        int n;
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_13();
            return;
        }

        // para poder imprimir y reformatear decimales
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);

        double sum = 1;
        double dividend = 2, divider = 1;
        // I make a for to sum the sequence but reduce 1 loop  because first loop its 1
        for (int i = 0; i < (n - 1); ++i) {
            sum += dividend / divider;
            dividend += 2;
            divider += 2;
        }
        cout << "La suma es: " << sum << endl;
    }

    void exercise_14() {
        int n;
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_14();
            return;
        }
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n = n / 10;
        }
        cout << "El numero al reves es: " << reversed << endl;
    }

    void exercise_15() {
        int n;
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_15();
            return;
        }
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) {
                sum += i;
            }
        }
        if (sum == n) {
            cout << "El numero es perfecto" << endl;
        } else {
            cout << "El numero no es perfecto" << endl;
        }
    }

    void exercise_16() {
        int n;
        cout << "Ingrese N: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_16();
            return;
        }
        // a = seria el primer numero y b el siguiente para sumar
        int a = 1, b = 0;
        for (int i = 0; i < n; ++i) {
            cout << a << (i + 1 == n ? "" : ",") << " ";
            // a = la suma de a y b // ejemplo a = 1 + 0 = 1
            // siguiente a = 1 + 1 = 2
            a = a + b;
            // b = la resta de a y b // ejemplo b = 1 - 0 = 1
            // siguiente b = 2 - 1 = 1
            b = a - b;
        }
    }

    void exercise_17() {
        int n;
        cout << "Ingrese N: ";
        cin >> n;
        if (n < 0) {
            cout << "Numero invalido" << endl;
            exercise_16();
            return;
        }
        int sum = 0;
        int a = 1, b = 0;
        for (int i = 0; i < n; ++i) {
            sum += a;
            a = a + b;
            b = a - b;
        }
        cout << "La suma es: " << sum << endl;
    }
};


#endif //EJERCICIOS_SHEET_6_H
