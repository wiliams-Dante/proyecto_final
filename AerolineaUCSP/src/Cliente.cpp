#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente() : Persona() {
    usuario = "";
    password = "";
    tieneVisa = false;
    numBoletos = 0;
    capacidadBoletos = 10;
    boletos = new Vuelo[capacidadBoletos];
}

Cliente::Cliente(const string& nom, const string& ape,
                 const DNI& d,
                 const string& user,
                 const string& pass)
        : Persona(nom, ape, d)
{
    usuario = user;
    password = pass;
    tieneVisa = false;
    numBoletos = 0;
    capacidadBoletos = 10;
    boletos = new Vuelo[capacidadBoletos];
}

Cliente::~Cliente() {
    delete[] boletos;
}

bool Cliente::verificarLogin(const string& user, const string& pass) const {
    return usuario == user && password == pass;
}

void Cliente::registrarVisa(const VISA& v) {
    visa = v;
    tieneVisa = true;
}

bool Cliente::tieneVisaPara(const string& pais) const {
    return tieneVisa && visa.getPaisDestino() == pais;
}

void Cliente::agregarBoleto(const Vuelo& v) {
    if (numBoletos < capacidadBoletos) {
        boletos[numBoletos] = v;
        numBoletos++;
    }
}

void Cliente::mostrarBoletos() const {
    if (numBoletos == 0) {
        cout << "\nNo tiene boletos comprados.\n";
        return;
    }

    cout << "\n--- BOLETOS ---\n";
    for (int i = 0; i < numBoletos; i++) {
        boletos[i].mostrarBoleto();
    }
}

int Cliente::getNumBoletos() const {
    return numBoletos;
}

Vuelo* Cliente::obtenerBoleto(int indice) {
    if (indice < 0 || indice >= numBoletos) return nullptr;
    return &boletos[indice];
}
