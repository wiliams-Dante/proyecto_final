#include "Documentos.h"

Documentos::Documentos() {}

Documentos::Documentos(const string& num) {
    numero = num;
}

void Documentos::setNumero(const string& num) {
    numero = num;
}

string Documentos::getNumero() const {
    return numero;
}
