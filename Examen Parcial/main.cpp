#include <iostream>
#include <math.h>

using namespace std;

void ejercicio_1();

void ejercicio_2();

void ejercicio_3();

double calcularFactorial(double number) {
    double result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

#include <iostream>

using namespace std;

int main() {
    ejercicio_1();
    ejercicio_2();
    ejercicio_3();
    return 0;
}

void ejercicio_1() {
    int n;
    double total = 0;
    do {
        cout << "Ingresa N: ";
        cin >> n;
    } while (n < 6 || n > 15);
    cout << "Los términos son: " << endl;
    for (int i = 1; i <= n; i++) {
        double num = (3 * i) / (calcularFactorial(i) * pow((i + 1), 2));
        cout << num << " ";
        total += num;
    }
    cout << endl;
    cout << "Suma de términos: " << total << endl;
    system("pause");
}

void ejercicio_2() {
// Variables para el porcentaje de casos recuperados
    int casosTotales = 0, casosRecuperados = 0;
    // Promedio varones fallecidos
    int edadVaron = 0, casosFallecidosVaron = 0;
    // Numero de casos por regiones
    int casosRegionCosta = 0, casosRegionSierra = 0, casosRegionSelva = 0;
    // Mujer con caso positivo mas joven
    int edadCasoPositivoMasJoven = 0;
    while (true) {
        char tipoDeCaso, sexo, region;
        int edad;
        do {
            cout << "Tipo de Caso (P: Positivas; R: Recuperadas: F: Fallecidas): ";
            cin >> tipoDeCaso;
            tipoDeCaso = toupper(tipoDeCaso);
        } while (!(tipoDeCaso == 'P' || tipoDeCaso == 'R' || tipoDeCaso == 'F' || tipoDeCaso == 'T'));
        if (tipoDeCaso == 'T') { // Acabo con el loop y no quiero ingresar mas datos
            break;
        }
        if (tipoDeCaso == 'R') { // Caso recuperado
            casosRecuperados++;
        }
        casosTotales++;
        do {
            cout << "Edad: ";
            cin >> edad;
        } while (edad < 0);
        do {
            cout << "Sexo (F: Femenino; M: Masculino): ";
            cin >> sexo;
            sexo = toupper(sexo);
        } while (!(sexo == 'F' || sexo == 'M'));
        if (sexo == 'M' && tipoDeCaso == 'F') {
            edadVaron += edad;
            casosFallecidosVaron++;
        }
        if (sexo == 'F' && tipoDeCaso == 'P') {
            if (edadCasoPositivoMasJoven == 0 || edadCasoPositivoMasJoven > edad) {
                edadCasoPositivoMasJoven = edad;
            }
        }
        do {
            cout << "Región (C: Costa; S: Sierra; O: Selva): ";
            cin >> region;
            region = toupper(region);
        } while (!(region == 'C' || region == 'S' || region == 'O'));
        if (region == 'C') {
            casosRegionCosta++;
        } else if (region == 'S') {
            casosRegionSierra++;
        } else {
            casosRegionSelva++;
        }
    }
    cout << "RESULTADOS" << endl;
    double porcentajeRecuperados = (double) casosRecuperados / casosTotales * 100;
    cout << "Porcentaje de casos recuperados: " << porcentajeRecuperados << "%" << endl;
    int promedioEdadVaron = edadVaron / casosFallecidosVaron;
    cout << "Promedio de edad de los varones fallecidos: " << promedioEdadVaron << endl;
    cout << "Regiones que tienen la menor frecuencia de casos: " << endl;

    if (casosRegionCosta == casosRegionSierra && casosRegionCosta == casosRegionSelva) {
        cout << "Costa" << endl;
        cout << "Sierra" << endl;
        cout << "Selva" << endl;
    } else {
        if (casosRegionCosta < casosRegionSierra && casosRegionCosta < casosRegionSelva) {
            cout << "Costa" << endl;
        } else if (casosRegionSierra < casosRegionCosta && casosRegionSierra < casosRegionSelva) {
            cout << "Sierra" << endl;
        } else {
            cout << "Selva" << endl;
        }
        if (casosRegionSierra < casosRegionCosta && casosRegionSierra < casosRegionSelva) {
            cout << "Sierra" << endl;
        } else if (casosRegionCosta < casosRegionSierra && casosRegionCosta < casosRegionSelva) {
            cout << "Costa" << endl;
        } else {
            cout << "Selva" << endl;
        }
        if (casosRegionSelva < casosRegionCosta && casosRegionSelva < casosRegionSierra) {
            cout << "Selva" << endl;
        } else if (casosRegionCosta < casosRegionSelva && casosRegionCosta < casosRegionSierra) {
            cout << "Costa" << endl;
        } else {
            cout << "Sierra" << endl;
        }
    }
    if (edadCasoPositivoMasJoven == 0) {
        cout << "Edad de la mujer más joven cuyo caso es positivo: No hubo" << endl;
    } else {
        cout << "Edad de la mujer más joven cuyo caso es positivo: " << edadCasoPositivoMasJoven << endl;
    }
    system("pause");
}

void ejercicio_3() {
    int ancho, altura, espaciado;
    do {
        cout << "Introduce el ancho: ";
        cin >> ancho;
    } while (!(ancho > 0 && ancho < 71));
    do {
        cout << "Introduce la altura: ";
        cin >> altura;
    } while (!(altura > 0 && altura < 19));
    do {
        cout << "Introduce el espaciado: ";
        cin >> espaciado;
    } while (!(espaciado > 0 && espaciado < altura));
    int nextLine = 1 + espaciado;
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= ancho; j++) {
            if (i == 1 || i == altura || j == 1 || j == ancho || j == nextLine) {
                cout << "* ";
                if (j == nextLine) {
                    nextLine += espaciado;
                }
                if (nextLine == ancho) {
                    nextLine = 1 + espaciado;
                }
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    system("pause");
}
