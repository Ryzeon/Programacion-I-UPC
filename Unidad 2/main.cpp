#include <iostream>
#include <map>
#include "Sheet_1.h"
#include "Sheet_2.h"
#include "Sheet_3.h"
#include "Sheet_4.h"
#include "Sheet_5.h"
#include "Sheet_6.h"
#include "Sheet_7.h"
#include "Sheet_8.h"
#include "Sheet_9.h"
#include "Sheet_10.h"

using namespace std;

int main() {
    cout << "---------------------" << endl;
    int amountOfSheets = 10;
    for (int i = 0; i < amountOfSheets; i++) {
        cout << (i + 1) << ".- Hoja " << (i + 1) << endl;
    }
    cout << "Selecciona una opcion >> ";
    int choise;
    cin >> choise;
    if (choise <= amountOfSheets && choise >= 1) {
        map<int, int> exercises = {
                {1, 30},
                {2, 6},
                {3, 4},
                {4, 3},
                {5, 3},
                {6, 17},
                {7, 9},
                {8, 7},
                {9, 1},
                {10, 12}
        };
        int numberOfExercises = exercises[choise];
        int exerciseChoise;
        cout << "Elije el ejercicios [1-" << numberOfExercises << "] >> ";
        cin >> exerciseChoise;
        switch (choise) {
            case 1:
                new Sheet_1(exerciseChoise);
                break;
            case 2:
                new Sheet_2(exerciseChoise);
                break;
            case 3:
                new Sheet_3(exerciseChoise);
                break;
            case 4:
                new Sheet_4(exerciseChoise);
                break;
            case 5:
                new Sheet_5(exerciseChoise);
                break;
            case 6:
                new Sheet_6(exerciseChoise);
                break;
            case 7:
                new Sheet_7(exerciseChoise);
                break;
            case 8:
                new Sheet_8(exerciseChoise);
                break;
            case 9:
                new Sheet_9(exerciseChoise);
                break;
            case 10:
                new Sheet_10(exerciseChoise);
                break;
        }
    } else {
        cout << "Opcion invalida" << endl;
    }
    return 0;
}
