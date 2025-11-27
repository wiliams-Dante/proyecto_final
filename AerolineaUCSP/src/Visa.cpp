#include "Visa.h"

VISA::VISA() : Documentos() {}

VISA::VISA(const string& num, const string& tipoVisa,
           const string& paisDest, const string& fEmi,
           const string& fVen)
        : Documentos(num)
{
    tipo = tipoVisa;
    paisDestino = paisDest;
    fechaEmision = fEmi;
    fechaVencimiento = fVen;
}

string VISA::getPaisDestino() const { return paisDestino; }
string VISA::getTipo() const { return tipo; }
