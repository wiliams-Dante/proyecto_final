#include "Horario.h"
#include <iostream>
using namespace std;

void Horario::inicializarAsientos() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            asientos[i][j] = 'O';
        }
    }
    int total = FILAS * COLUMNAS;
    asientosTotales = total;
    asientosDisponibles = total;
}

Horario::Horario(string salida, string llegada, int ignorado) {
    horaSalida = salida;
    horaLlegada = llegada;
    inicializarAsientos();
}

void Horario::mostrarHorario(int num) {
    cout << num << ". "
         << horaSalida << " -> " << horaLlegada
         << " | Disponibles: " << asientosDisponibles << endl;
}

void Horario::mostrarMapaAsientos() {
    cout << "\nMapa de asientos   (O = libre, X = ocupado)\n";
    cout << "    ";
    for (int c = 0; c < COLUMNAS; c++) cout << c + 1 << "  ";
    cout << endl;

    for (int i = 0; i < FILAS; i++) {
        if (i + 1 < 10) cout << " ";
        cout << i + 1 << "  ";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << asientos[i][j] << "  ";
        }
        cout << endl;
    }
}

bool Horario::reservarAsientoPosicion(int fila, int columna) {
    int f = fila - 1;
    int c = columna - 1;
    if (f < 0 || f >= FILAS || c < 0 || c >= COLUMNAS) {
        cout << "Posición fuera de rango.\n";
        return false;
    }
    if (asientos[f][c] == 'X') {
        cout << "Ese asiento ya está ocupado.\n";
        return false;
    }
    asientos[f][c] = 'X';
    asientosDisponibles--;
    cout << "Asiento (" << fila << "," << columna << ") reservado.\n";
    return true;
}

bool Horario::liberarAsientoPosicion(int fila, int columna) {
    int f = fila - 1;
    int c = columna - 1;
    if (f < 0 || f >= FILAS || c < 0 || c >= COLUMNAS) return false;
    if (asientos[f][c] == 'X') {
        asientos[f][c] = 'O';
        asientosDisponibles++;
        return true;
    }
    return false;
}

string Horario::getHoraSalida() const { return horaSalida; }
string Horario::getHoraLlegada() const { return horaLlegada; }
int Horario::getAsientosDisponibles() const { return asientosDisponibles; }
