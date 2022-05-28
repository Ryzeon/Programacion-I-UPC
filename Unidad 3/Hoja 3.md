<details>
  <summary><strong>Ejercicio 1</strong></summary>
</details>
<details>
  <summary><strong>Ejercicio 2</strong></summary>
> Remove CC:color(text)

```c++
#include <iostream>

using namespace std;

#include "CC.h" // CC

int askForNumber(const string &question) {
    int n;
    do {
        cout << question;
        cin >> n;
    } while (n <= 0);
    return n;
}

void menu();

void numerosComplejos(const bool &sum) {
    int *numeroReal_1, *numeroReal_2;
    int *numeroImaginario_1, *numeroImaginario_2;
    cout << CC::color("&3Número 1") << endl;

    numeroReal_1 = new int; // Allocate memory
    *numeroReal_1 = askForNumber("Parte Real:  "); // Initialize

    numeroImaginario_1 = new int; // Allocate memory
    *numeroImaginario_1 = askForNumber("Parte Imaginaria:  "); // Initialize

    cout << " " << endl;
    cout << CC::color("&3Número 2") << endl;

    numeroReal_2 = new int; // Allocate memory
    *numeroReal_2 = askForNumber("Parte Real:  "); // Initialize

    numeroImaginario_2 = new int; // Allocate memory
    *numeroImaginario_2 = askForNumber("Parte Imaginaria:  "); // Initialize

    int *resultadoNumeroReal, *resultadoNumeroImaginario;
    resultadoNumeroReal = new int; // Allocate memory
    resultadoNumeroImaginario = new int; // Allocate memory

    // To avoid make a large repetitive  if xd
    *numeroReal_2 *= sum ? 1 : -1;
    *numeroImaginario_2 *= sum ? 1 : -1;

    *resultadoNumeroReal = *numeroReal_1 + *numeroReal_2; // Initialize
    *resultadoNumeroImaginario = *numeroImaginario_1 + *numeroImaginario_2; // Initialize

    cout << " " << endl;
    cout << CC::color("&3(") << *numeroReal_1 << "+" << *numeroImaginario_1 << CC::color("i&3)")
         << (sum ? " + " : " - ")
         << CC::color("&6(") << *numeroReal_2 << "+" << *numeroImaginario_2 << CC::color("i&6)")
         << " = "
         << CC::color("&2(") << *resultadoNumeroReal << (*resultadoNumeroImaginario > 0 ? "+" : "")
         << (*resultadoNumeroImaginario != 1 ? to_string(*resultadoNumeroImaginario) : "") << CC::color("i&2)")
         << endl;
    cout << " " << endl;
    cout << " " << endl;

    // Clean variables
    delete numeroReal_1;
    delete numeroReal_2;
    delete numeroImaginario_1;
    delete numeroImaginario_2;
    delete resultadoNumeroReal;
    delete resultadoNumeroImaginario;
    menu();
}

void menu() {
    char *choose;
    choose = new char;
    do {
        cout << CC::color("             &3MENU") << endl;
        cout << CC::color("             ====") << endl;
        cout << CC::color("&3A. &2Sumar 2 Números Complejos.") << endl;
        cout << CC::color("&3B. &2Restar 2 Números Complejos.") << endl;
        cout << CC::color("&3X. &1Salir del Programa") << endl;
        cout << CC::color("&6>> ");
        cin >> choose;
        *choose = toupper(*choose);
        if (*choose == 'X') {
            cout << CC::color("&1Saliendo del Programa...") << endl;
            break;
        }
    } while (!(*choose == 'A' || *choose == 'B'));
    if (*choose != 'X') {
        numerosComplejos(*choose == 'A');
    }
    delete choose; // Delete the pointer
}

int main() {
    menu();
    return 0;
}


```
</details>