//
// Created by ryzeon on 7/04/22.
//

#ifndef EJERCICIOS_SHEET_1_H
#define EJERCICIOS_SHEET_1_H

#include <iostream>

using namespace std;

class Sheet_1 {
public:
    Sheet_1(int choise) {
        switch (choise) {
            case 1:
                Sheet_1::exercise_1();
                break;
        }
    }

private:
    void exercise_1() {
    }
};


#endif //EJERCICIOS_SHEET_1_H
