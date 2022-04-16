#include <iostream>
#include <map>
#include "Sheet_1.h"

using namespace std;

int main() {
    cout << "---------------------" << endl;
    int amountOfSheets = 1;
    for (int i = 0; i < amountOfSheets; i++) {
        cout << (i + 1) << ".- Hoja " << (i + 1) << endl;
    }
    cout << "Selecciona una opcion >> ";
    int choise;
    cin >> choise;
    if (choise <= 6 && choise >= 1) {
        map<int, int> exercises = {
                {1, 30}
        };
        int numberOfExercises = exercises[choise];
        int exerciseChoise;
        cout << "Elije el ejercicios [1-" << numberOfExercises << "] >> ";
        cin >> exerciseChoise;
        switch (choise) {
            case 1:
                new Sheet_1(exerciseChoise);
                break;
        }
    } else {
        cout << "Opcion invalida" << endl;
    }
    return 0;
}
