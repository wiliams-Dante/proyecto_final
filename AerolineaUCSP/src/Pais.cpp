#include "Pais.h"
#include <iostream>
using namespace std;

Pais::Pais(string n, string a1, string a2, string a3,
           Horario h1, Horario h2, Horario h3)
{
    nombre = n;
    aerolinea1 = a1;
    aerolinea2 = a2;
    aerolinea3 = a3;

    horarios[0] = h1;
    horarios[1] = h2;
    horarios[2] = h3;
}

string Pais::getNombre() { return nombre; }
string Pais::getAerolinea1() { return aerolinea1; }
string Pais::getAerolinea2() { return aerolinea2; }
string Pais::getAerolinea3() { return aerolinea3; }

void Pais::mostrarAerolineas() {
    cout << "\nAerolineas disponibles para " << nombre << ":\n";
    cout << "1. " << aerolinea1 << endl;
    cout << "2. " << aerolinea2 << endl;
    cout << "3. " << aerolinea3 << endl;
}

void Pais::mostrarHorarios() {
    cout << "\nHorarios disponibles para " << nombre << ":\n";
    for (int i = 0; i < 3; i++) {
        horarios[i].mostrarHorario(i + 1);
    }
}

Horario& Pais::getHorario(int indice) {
    return horarios[indice];
}
