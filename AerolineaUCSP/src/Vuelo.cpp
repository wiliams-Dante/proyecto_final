#include "Vuelo.h"
#include <iostream>
using namespace std;

Vuelo::Vuelo(string p, string a, string hs, string hl,
             string f, int cant, int idxPais, int idxHor)
{
    paisDestino = p;
    aerolinea = a;
    horaSalida = hs;
    horaLlegada = hl;
    fecha = f;
    cantidadAsientos = 0;
    indexPais = idxPais;
    indexHorario = idxHor;
}

void Vuelo::agregarAsiento(int fila, int columna) {
    if (cantidadAsientos < MAX_ASIENTOS) {
        filas[cantidadAsientos] = fila;
        columnas[cantidadAsientos] = columna;
        cantidadAsientos++;
    }
}

void Vuelo::setAsiento(int indice, int fila, int columna) {
    if (indice >= 0 && indice < MAX_ASIENTOS) {
        filas[indice] = fila;
        columnas[indice] = columna;
    }
}

int Vuelo::getFilaAsiento(int indice) const {
    if (indice >= 0 && indice < cantidadAsientos)
        return filas[indice];
    return -1;
}

int Vuelo::getColumnaAsiento(int indice) const {
    if (indice >= 0 && indice < cantidadAsientos)
        return columnas[indice];
    return -1;
}

string Vuelo::getPaisDestino() const { return paisDestino; }
string Vuelo::getHoraSalida() const { return horaSalida; }
string Vuelo::getHoraLlegada() const { return horaLlegada; }
string Vuelo::getFecha() const { return fecha; }
int Vuelo::getCantidad() const { return cantidadAsientos; }
int Vuelo::getIndexPais() const { return indexPais; }
int Vuelo::getIndexHorario() const { return indexHorario; }

void Vuelo::setFecha(const string& f) { fecha = f; }
void Vuelo::setHoraSalida(const string& hs) { horaSalida = hs; }
void Vuelo::setHoraLlegada(const string& hl) { horaLlegada = hl; }
void Vuelo::setCantidadAsientos(int c) { cantidadAsientos = c; }
void Vuelo::setIndexPais(int ip) { indexPais = ip; }
void Vuelo::setIndexHorario(int ih) { indexHorario = ih; }

void Vuelo::mostrarBoleto() const {
    cout << "\n=========== BOLETO DE VUELO ===========" << endl;
    cout << "Destino:       " << paisDestino << endl;
    cout << "Fecha:         " << fecha << endl;
    cout << "Aerolinea:     " << aerolinea << endl;
    cout << "Hora salida:   " << horaSalida << endl;
    cout << "Hora llegada:  " << horaLlegada << endl;
    cout << "Asientos:      " << cantidadAsientos << endl;

    if (cantidadAsientos > 0) {
        cout << "Posiciones de asientos:" << endl;
        for (int i = 0; i < cantidadAsientos; i++) {
            cout << "   - Asiento " << (i + 1)
                 << ": fila " << filas[i]
                 << ", columna " << columnas[i] << endl;
        }
    }

    cout << "---------------------------------------" << endl;
    cout << "  ¡Gracias por su compra, buen viaje!  " << endl;
    cout << "=======================================\n" << endl;
}
