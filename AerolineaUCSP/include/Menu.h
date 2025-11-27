#ifndef AEROLINEAUCSP_MENU_H
#define AEROLINEAUCSP_MENU_H

#include "Cliente.h"
#include "Pais.h"

class Menu {
private:
    Pais paises[7];

    Cliente** clientes;
    int numClientes;
    int capacidadClientes;

    Cliente* clienteActual;

public:
    Menu();
    ~Menu();

    void mostrar_boletos();
    void comprar_vuelo();
    void modificar_voleto();
    void registrarCliente();
    void iniciarSesion();
    void registrarVisaCliente();
    void menuPrincipal();
};

bool paisRequiereVisa(const string& nombrePais);

#endif //AEROLINEAUCSP_MENU_H
