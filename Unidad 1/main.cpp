#include <iostream>
#include <map>
#include "Sheet_1.h"
#include "Sheet_2.h"
#include "Sheet_3.h"
#include "Sheet_4.h"
#include "Sheet_5.h"
#include "Sheet_6.h"

using namespace std;

int main() {
    cout << "---------------------" << endl;
    for (int i = 0; i < 6; i++) {
        cout << (i + 1) << ".- Hoja " << (i + 4) << endl;
    }
    cout << "Selecciona una opcion >> ";
    int choise;
    cin >> choise;
    if (choise <= 6 && choise >= 1) {
        map<int, int> exercises = {
                {1, 5},
                {2, 3},
                {3, 3},
                {4, 8},
                {5, 3},
                {6, 3}
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
        }
    } else {
        cout << "Opcion invalida" << endl;
    }
    return 0;
}
