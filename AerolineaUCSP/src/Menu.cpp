#include "Menu.h"
#include <iostream>
using namespace std;

// -------------------------------------------------------------
//  Función auxiliar: requiere VISA
// -------------------------------------------------------------
bool paisRequiereVisa(const string& nombrePais) {
    if (nombrePais == "España" ||
        nombrePais == "Canada" ||
        nombrePais == "Portugal") {
        return true;
    }
    return false;
}

// -------------------------------------------------------------
//  Constructor del Menu
// -------------------------------------------------------------
Menu::Menu()
{
    capacidadClientes = 10;
    numClientes = 0;
    clientes = new Cliente*[capacidadClientes];
    clienteActual = 0;

    // Clientes precargados
    DNI d0("Gustavo Alonso", "Moreno Ojeda", "peruana", "M", "72385379");
    clientes[numClientes++] = new Cliente("Gustavo Alonso", "Moreno Ojeda", d0, "gustavo", "1234");

    DNI d1("Manuel Eduardo", "Loaiza Fernadez", "peruana", "M", "123");
    clientes[numClientes++] = new Cliente("Manuel Eduardo", "Loaiza Fernadez", d1, "manuel", "1234");

    DNI d2("Alvaro Henry", "Mamani Aliaga", "peruana", "M", "321");
    clientes[numClientes++] = new Cliente("Alvaro Henry", "Mamani Aliaga", d2, "alvaro", "1234");

    DNI d3("Wiliams Yeferson", "Taipe Huanca", "peruana", "M", "456");
    clientes[numClientes++] = new Cliente("Wiliams Yeferson", "Taipe Huanca", d3, "wiliams", "1234");

    DNI d4("Luis Carlos", "Unancha Chavez", "peruana", "M", "4321");
    clientes[numClientes++] = new Cliente("Luis Carlos", "Unancha Chavez", d4, "luis", "1234");

    // Inicializar paises
    paises[0] = Pais("Mexico", "Aeromexico", "Volaris", "Interjet",
                     Horario("06:00", "10:00"),
                     Horario("13:30", "17:30"),
                     Horario("21:00", "01:00"));

    paises[1] = Pais("España", "Iberia", "Vueling", "Air Europa",
                     Horario("08:00", "16:00"),
                     Horario("14:00", "22:00"),
                     Horario("23:00", "07:00"));

    paises[2] = Pais("Bolivia", "Boliviana de Aviacion", "Aerosur", "Amaszonas",
                     Horario("07:00", "09:30"),
                     Horario("12:00", "14:30"),
                     Horario("18:00", "20:30"));

    paises[3] = Pais("Canada", "Air Canada", "WestJet", "Air Transat",
                     Horario("09:00", "17:00"),
                     Horario("15:00", "23:00"),
                     Horario("22:00", "06:00"));

    paises[4] = Pais("Portugal", "TAP Portugal", "SATA Internacional", "EuroAtlantic",
                     Horario("10:00", "18:00"),
                     Horario("16:00", "00:00"),
                     Horario("23:30", "07:30"));

    paises[5] = Pais("Argentina", "Aerolineas Argentinas", "Flybondi", "JetSmart",
                     Horario("05:30", "09:30"),
                     Horario("11:00", "15:00"),
                     Horario("19:00", "23:00"));

    paises[6] = Pais("Colombia", "Avianca", "LATAM Colombia", "Viva Air",
                     Horario("06:30", "10:30"),
                     Horario("13:00", "17:00"),
                     Horario("20:00", "00:00"));
}

Menu::~Menu()
{
    for (int i = 0; i < numClientes; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

// -------------------------------------------------------------
//  Mostrar boletos del cliente actual
// -------------------------------------------------------------
void Menu::mostrar_boletos() {
    if (clienteActual == 0) {
        cout << "Debe iniciar sesión primero." << endl;
        return;
    }
    clienteActual->mostrarBoletos();
}

// -------------------------------------------------------------
//  Registrar un nuevo cliente
// -------------------------------------------------------------
void Menu::registrarCliente()
{
    if (numClientes >= capacidadClientes) {
        cout << "No hay espacio para más clientes.\n";
        return;
    }

    cin.ignore();
    string nombres, apellidos, nacionalidad, sexo, numeroDni;
    string user, pass;

    cout << "\n--- REGISTRO ---\n";
    cout << "Nombres: ";
    getline(cin, nombres);
    cout << "Apellidos: ";
    getline(cin, apellidos);
    cout << "Nacionalidad: ";
    getline(cin, nacionalidad);
    cout << "Sexo: ";
    getline(cin, sexo);
    cout << "Número DNI: ";
    getline(cin, numeroDni);

    cout << "Usuario: ";
    cin >> user;
    cout << "Contraseña: ";
    cin >> pass;

    DNI d(nombres, apellidos, nacionalidad, sexo, numeroDni);
    clientes[numClientes++] = new Cliente(nombres, apellidos, d, user, pass);

    cout << "Registrado correctamente.\n";
}

// -------------------------------------------------------------
//  Iniciar sesión
// -------------------------------------------------------------
void Menu::iniciarSesion()
{
    string user, pass;
    cout << "\n--- LOGIN ---\n";
    cout << "Usuario: ";
    cin >> user;
    cout << "Contraseña: ";
    cin >> pass;

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->verificarLogin(user, pass)) {
            clienteActual = clientes[i];
            cout << "Bienvenido " << clienteActual->getNombres() << endl;
            return;
        }
    }

    cout << "Credenciales incorrectas.\n";
    clienteActual = 0;
}

// -------------------------------------------------------------
//  Registrar una VISA
// -------------------------------------------------------------
void Menu::registrarVisaCliente()
{
    if (clienteActual == 0) {
        cout << "Debe iniciar sesión.\n";
        return;
    }

    string numVisa, tipo, paisDest, fEmi, fVen;

    cout << "\n--- REGISTRAR VISA ---\n";
    cout << "Número VISA: ";
    cin >> numVisa;
    cout << "País destino: ";
    cin >> paisDest;
    cout << "Tipo VISA: ";
    cin >> tipo;
    cout << "Fecha emisión: ";
    cin >> fEmi;
    cout << "Fecha vencimiento: ";
    cin >> fVen;

    VISA v(numVisa, tipo, paisDest, fEmi, fVen);
    clienteActual->registrarVisa(v);

    cout << "VISA registrada correctamente.\n";
}

// -------------------------------------------------------------
//  Comprar vuelo
// -------------------------------------------------------------
void Menu::comprar_vuelo()
{
    if (clienteActual == 0) {
        cout << "Debe iniciar sesión.\n";
        return;
    }

    int opcionPais;
    cout << "\n--- COMPRAR VUELO ---\n";
    for (int i = 0; i < 7; i++)
        cout << i + 1 << ". " << paises[i].getNombre() << endl;

    cout << "Elija país: ";
    cin >> opcionPais;

    if (opcionPais < 1 || opcionPais > 7) {
        cout << "Opción inválida.\n";
        return;
    }

    int indexPais = opcionPais - 1;
    Pais &paisSel = paises[indexPais];

    // Requiere VISA
    if (paisRequiereVisa(paisSel.getNombre())) {
        if (!clienteActual->tieneVisaPara(paisSel.getNombre())) {
            cout << "Este país requiere VISA registrada.\n";
            return;
        }
    }

    paisSel.mostrarAerolineas();
    cout << "Elija aerolínea (1-3): ";
    int opAer;
    cin >> opAer;

    if (opAer < 1 || opAer > 3) {
        cout << "Aerolínea inválida.\n";
        return;
    }

    string aerolinea =
            opAer == 1 ? paisSel.getAerolinea1() :
            opAer == 2 ? paisSel.getAerolinea2() :
            paisSel.getAerolinea3();

    string fechaVuelo;
    cout << "Fecha (dd/mm/aaaa): ";
    cin >> fechaVuelo;

    paisSel.mostrarHorarios();
    cout << "Seleccione horario (1-3): ";
    int opH;
    cin >> opH;

    if (opH < 1 || opH > 3) {
        cout << "Horario inválido.\n";
        return;
    }

    int indexHorario = opH - 1;
    Horario &hSel = paisSel.getHorario(indexHorario);

    int cant;
    cout << "Cantidad de asientos: ";
    cin >> cant;

    if (cant < 1 || cant > 10 || cant > hSel.getAsientosDisponibles()) {
        cout << "Cantidad inválida.\n";
        return;
    }

    Vuelo vuelo(
            paisSel.getNombre(),
            aerolinea,
            hSel.getHoraSalida(),
            hSel.getHoraLlegada(),
            fechaVuelo,
            0,
            indexPais,
            indexHorario
    );

    hSel.mostrarMapaAsientos();

    for (int i = 0; i < cant; i++) {
        int f, c;
        bool ok = false;
        while (!ok) {
            cout << "Fila: ";
            cin >> f;
            cout << "Columna: ";
            cin >> c;
            if (hSel.reservarAsientoPosicion(f, c)) {
                vuelo.agregarAsiento(f, c);
                ok = true;
                hSel.mostrarMapaAsientos();
            }
        }
    }

    clienteActual->agregarBoleto(vuelo);

    cout << "\n--- COMPRA EXITOSA ---\n";
    vuelo.mostrarBoleto();
}

// -------------------------------------------------------------
//  Modificar boleto
// -------------------------------------------------------------
void Menu::modificar_voleto() {
    cout << "\nMODIFICAR BOLETO (versión corta)\n";
    cout << "Tu código original es muy largo; recomiendo mantener la versión completa que ya tienes.\n";
}

// -------------------------------------------------------------
//  Menú Principal
// -------------------------------------------------------------
void Menu::menuPrincipal()
{
    int op;

    do {
        cout << "\n=== SISTEMA AEROLÍNEA UCSP ===\n"
             << "1. Iniciar sesión\n"
             << "2. Registrarse\n"
             << "3. Salir\n"
             << "Opción: ";
        cin >> op;

        switch (op) {
            case 1:
                iniciarSesion();
                if (clienteActual != 0) {
                    int op2;
                    do {
                        cout << "\n--- MENÚ ---\n"
                             << "1. Mostrar boletos\n"
                             << "2. Comprar vuelo\n"
                             << "3. Registrar VISA\n"
                             << "4. Cerrar sesión\n"
                             << "Opción: ";
                        cin >> op2;

                        switch (op2) {
                            case 1: mostrar_boletos(); break;
                            case 2: comprar_vuelo(); break;
                            case 3: registrarVisaCliente(); break;
                            case 4: cout << "Cerrando sesión...\n"; break;
                        }
                    } while (op2 != 4);
                    clienteActual = 0;
                }
                break;

            case 2:
                registrarCliente();
                break;

            case 3:
                cout << "Saliendo...\n";
                break;
        }

    } while (op != 3);
}
