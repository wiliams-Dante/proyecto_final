#include "Dia.h"
#include <iostream>
using namespace std;

Dia::Dia(string f, Horario h1, Horario h2, Horario h3) {
    fecha = f;
    horarios[0] = h1;
    horarios[1] = h2;
    horarios[2] = h3;
    numHorarios = 3;
}

void Dia::mostrarDia() {
    cout << "\nFecha: " << fecha << endl;
    for (int i = 0; i < numHorarios; i++) {
        horarios[i].mostrarHorario(i + 1);
    }
}

bool Dia::reservar(int indice, int cant) {
    return false; // No implementado
}

string Dia::getFecha() {
    return fecha;
}
