#include <iostream>
#include <map>

using namespace std;

#include "Sheet_1.h"

int main() {
    cout << "---------------------" << endl;
    int maxSize = 1;
    for (int i = 1; i <= maxSize; i++) {
        cout << i << ".- Hoja " << i << endl;
    }
    cout << "---------------------" << endl;
    int choise;
    do {
        cout << "Selecciona una opcion >> ";
        cin >> choise;
    } while (!(choise >= 1 && choise <= maxSize));
    map<int, int> exercises = {
            {1, 41}
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

    return 0;
}
