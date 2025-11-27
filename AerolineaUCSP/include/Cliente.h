#ifndef AEROLINEAUCSP_CLIENTE_H
#define AEROLINEAUCSP_CLIENTE_H

#include "Persona.h"
#include "Visa.h"
#include "Vuelo.h"

class Cliente : public Persona {
private:
    string usuario;
    string password;

    bool tieneVisa;
    VISA visa;

    Vuelo* boletos;
    int numBoletos;
    int capacidadBoletos;

public:
    Cliente();
    Cliente(const string&, const string&, const DNI&, const string&, const string&);
    ~Cliente();

    bool verificarLogin(const string&, const string&) const;

    void registrarVisa(const VISA&);
    bool tieneVisaPara(const string&) const;

    void agregarBoleto(const Vuelo&);
    void mostrarBoletos() const;

    int getNumBoletos() const;
    Vuelo* obtenerBoleto(int indice);
};

#endif //AEROLINEAUCSP_CLIENTE_H
