//
// Created by ryzeon on 10/04/22.
//

#ifndef EJERCICIOS_SHEET_6_H
#define EJERCICIOS_SHEET_6_H


class Sheet_6 {
public:
    Sheet_6(int choise) {
        switch (choise) {
            case 1:
                Sheet_6::exercise_1();
                break;
            case 2:
                Sheet_6::exercise_2();
                break;
            case 3:
                Sheet_6::exercise_3();
                break;
        }
    }

private:
    void exercise_1() {
        string code;
        cout << "Ingrese un código de salida: ";
        cin >> code;
        code = code.substr(0, 4);
        map<int, string> departaments = {
                {1, "Piura"},
                {2, "Ica"},
                {3, "Ayacucho"}
        };
        int
                departament = stoi(code.substr(0, 1)),
                hour = stoi(code.substr(1, 2)),
                stops = stoi(code.substr(3, 1));
        cout << "Departamento de destino: " << departaments[departament] << endl;
        cout << "Hora de salida: " << hour << endl;
        cout << "Realizan paradas: " << (stops == 1 ? "Sí" : "No") << endl;
    }

    void exercise_2() {
        string code;
        cout << "Ingrese un código de salida: ";
        code = code.substr(0, 4);
        map<int, string> departaments = {
                {1, "P"},
                {2, "I"},
                {3, "A"}
        };
        int
                departament = stoi(code.substr(0, 1)),
                hour = stoi(code.substr(1, 2)),
                stops = stoi(code.substr(3, 1));
        cout << "Departamento de destino: " << departaments[departament] << endl;
        cout << "Hora de salida: " << hour << endl;
        cout << "Realizan paradas: " << (stops == 1 ? "S" : "N") << endl;
    }

    void exercise_3() {
        map<char, map<char, double>> prices = {
                {'B', {
                              {'P', 1300},
                              {'M', 1000},
                      }},
                {'M', {
                              {'P', 1350},
                              {'M', 2500},
                      }},
                {'O', {
                              {'P', 900},
                              {'M', 3200},
                      }}
        };
        char brand, king;
        cout << "Marca (B: Best; M: Monark; O: Oxford): ";
        cin >> brand;
        cout << "Categoría (P: Paseo; M: Montañera): ";
        cin >> king;
        // to upper
        brand = toupper(brand);
        king = toupper(king);
        cout << "Monto a pagar: " << prices[brand][king];
    }
};


#endif //EJERCICIOS_SHEET_6_H
