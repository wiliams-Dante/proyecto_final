#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class DNI
{
private:
    string nombres[5];
    string apellidos[5];
    string nacionalidades[5];
    string sexos[5];
    string codigos[5];

public:
    DNI()
    {
        nombres[0] = "Gustavo Alonso";
        apellidos[0] = "Moreno Ojeda";
        nacionalidades[0] = "peruana";
        sexos[0] = "M";
        codigos[0] = "72385379";

        nombres[1] = "Manuel Eduardo";
        apellidos[1] = "Loaiza Fernadez";
        nacionalidades[1] = "peruana";
        sexos[1] = "M";
        codigos[1] = "123";

        nombres[2] = "Alvaro Henry";
        apellidos[2] = "Mamani Aliaga";
        nacionalidades[2] = "peruana";
        sexos[2] = "M";
        codigos[2] = "321";

        nombres[3] = "Wiliams Yeferson";
        apellidos[3] = "Taipe Huanca";
        nacionalidades[3] = "peruana";
        sexos[3] = "M";
        codigos[3] = "456";

        nombres[4] = "Luis Carlos";
        apellidos[4] = "Unancha Chavez";
        nacionalidades[4] = "peruana";
        sexos[4] = "M";
        codigos[4] = "4321";
    }

    bool verificarDatos(string nombre, string apellido, string dni_codigo)
    {
        for(int i = 0; i < 5; i++)
        {
            if(nombres[i] == nombre && apellidos[i] == apellido && codigos[i] == dni_codigo)
            {
                return true;
            }
        }
        return false;
    }
};

class Pasaporte: public DNI
{
public:

    bool solicitarPasaporte()
    {
        string nombre, apellido, dni_codigo;

        cout << "\n=== VERIFICACION DE PASAPORTE ===" << endl;
        cout << "Ingrese nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese apellido: ";
        getline(cin, apellido);
        cout << "Ingrese numero de DNI: ";
        cin >> dni_codigo;

        if(verificarDatos(nombre, apellido, dni_codigo))
        {
            cout << "Datos verificados correctamente..." << endl;
            return true;

        } else{
            cout << "ERROR: Los datos ingresados no coinciden con los registros" << endl;
            return false;
        }
    }
};

class VISA: public DNI
{
    // pendiente de implementar
};

// -------------------------
// Clase Horario con matriz de asientos
// -------------------------
class Horario
{
private:
    static const int FILAS = 10;     // puedes cambiar el tamaño
    static const int COLUMNAS = 6;   // columnas tipo A-F, pero usaremos 1-6
    char asientos[FILAS][COLUMNAS];  // 'O' libre, 'X' ocupado

    string horaSalida;
    string horaLlegada;
    int asientosTotales;
    int asientosDisponibles;

    void inicializarAsientosAleatorios()
    {
        // Inicialmente todos libres
        for(int i = 0; i < FILAS; i++)
        {
            for(int j = 0; j < COLUMNAS; j++)
            {
                asientos[i][j] = 'O';
            }
        }

        // Ocupamos al azar parte de los asientos (por ejemplo, 20% del total)
        int total = FILAS * COLUMNAS;
        int ocupar = total / 5; // 20%

        int ocupados = 0;
        while(ocupados < ocupar)
        {
            int f = rand() % FILAS;
            int c = rand() % COLUMNAS;

            if(asientos[f][c] == 'O')
            {
                asientos[f][c] = 'X';
                ocupados++;
            }
        }

        asientosTotales = total;
        asientosDisponibles = total - ocupados;
    }

public:

    Horario(string salida = "", string llegada = "", int totalIgnorado = 0)
    {
        horaSalida = salida;
        horaLlegada = llegada;
        inicializarAsientosAleatorios();
    }

    void mostrarHorario(int num) {
        cout << num << ". " << horaSalida
             << " -> " << horaLlegada
             << " | Asientos disponibles: " << asientosDisponibles
             << endl;
    }

    // Mostrar mapa de asientos tipo cine
    void mostrarMapaAsientos()
    {
        cout << "\nMapa de asientos (O = libre, X = ocupado)" << endl;
        cout << "    ";
        for(int c = 0; c < COLUMNAS; c++)
        {
            cout << c+1 << "  ";
        }
        cout << endl;

        for(int i = 0; i < FILAS; i++)
        {
            if(i+1 < 10) cout << " ";
            cout << i+1 << "  ";
            for(int j = 0; j < COLUMNAS; j++)
            {
                cout << asientos[i][j] << "  ";
            }
            cout << endl;
        }
    }

    bool reservarAsientoPosicion(int fila, int columna)
    {
        // fila y columna vienen 1-based del usuario
        int f = fila - 1;
        int c = columna - 1;

        if(f < 0 || f >= FILAS || c < 0 || c >= COLUMNAS)
        {
            cout << "Posicion fuera de rango." << endl;
            return false;
        }

        if(asientos[f][c] == 'X')
        {
            cout << "Ese asiento ya esta ocupado." << endl;
            return false;
        }

        asientos[f][c] = 'X';
        asientosDisponibles--;
        cout << "Asiento (" << fila << "," << columna << ") reservado correctamente." << endl;
        return true;
    }

    // por si necesitas estos getters
    string getHoraSalida()  const { return horaSalida; }
    string getHoraLlegada() const { return horaLlegada; }
    int getAsientosDisponibles() const { return asientosDisponibles; }
};

// -------------------------
// Clase Dia (no usada en el flujo actual, pero lista)
// -------------------------
class Dia
{
private:
    string fecha;
    Horario horarios[3];
    int numHorarios;

public:
    Dia(string f = "",
        Horario h1 = Horario(),
        Horario h2 = Horario(),
        Horario h3 = Horario())
    {
        fecha = f;
        horarios[0] = h1;
        horarios[1] = h2;
        horarios[2] = h3;
        numHorarios = 3;
    }

    void mostrarDia()
    {
        cout << "\nFecha: " << fecha << endl;
        for(int i=0; i < numHorarios; i++)
            horarios[i].mostrarHorario(i+1);
    }

    bool reservar(int indice, int cant)
    {
        // pendiente adaptar si quieres manejar por día
        return false;
    }

    string getFecha() {
        return fecha;
    }
};


// -------------------------
// Clase Pais
// -------------------------
class Pais
{
    private:
        string nombre;
        string aerolinea1;
        string aerolinea2;
        string aerolinea3;
        Horario horarios[3];

    public:

        Pais(string n = "", string a1 = "", string a2 = "", string a3 = "",
             Horario h1 = Horario(), Horario h2 = Horario(), Horario h3 = Horario())
        {
            nombre = n;
            aerolinea1 = a1;
            aerolinea2 = a2;
            aerolinea3 = a3;
            horarios[0] = h1;
            horarios[1] = h2;
            horarios[2] = h3;
        }

        string getNombre()        { return nombre; }
        string getAerolinea1()    { return aerolinea1; }
        string getAerolinea2()    { return aerolinea2; }
        string getAerolinea3()    { return aerolinea3; }

        void mostrarAerolineas()
        {
            cout << "\nAerolineas disponibles para " << nombre << ":" << endl;
            cout << "1. " << aerolinea1 << endl;
            cout << "2. " << aerolinea2 << endl;
            cout << "3. " << aerolinea3 << endl;
        }

        void mostrarHorarios()
        {
            cout << "\nHorarios disponibles para " << nombre << ":" << endl;
            for(int i = 0; i < 3; i++)
            {
                horarios[i].mostrarHorario(i+1);
            }
        }

        Horario& getHorario(int indice) {
            return horarios[indice];
        }
};

// -------------------------
// Clase Vuelo (boleto / reserva)
// -------------------------
class Vuelo
{
private:
    string paisDestino;
    string aerolinea;
    string horaSalida;
    string horaLlegada;
    int cantidadAsientos;

public:
    Vuelo(string p = "", string a = "",
          string hs = "", string hl = "",
          int cant = 0)
    {
        paisDestino = p;
        aerolinea = a;
        horaSalida = hs;
        horaLlegada = hl;
        cantidadAsientos = cant;
    }

    void mostrarBoleto()
    {
        cout << "\n=========== BOLETO DE VUELO ===========" << endl;
        cout << "Destino:       " << paisDestino << endl;
        cout << "Aerolinea:     " << aerolinea << endl;
        cout << "Hora salida:   " << horaSalida << endl;
        cout << "Hora llegada:  " << horaLlegada << endl;
        cout << "Asientos:      " << cantidadAsientos << endl;
        cout << "---------------------------------------" << endl;
        cout << "  ¡Gracias por su compra, buen viaje!  " << endl;
        cout << "=======================================\n" << endl;
    }
};

// -------------------------
// Clase Menu
// -------------------------
class Menu
{
    private:
        Pais paises[7];
        Pasaporte pasaporte;

    public:
        Menu();

        void buscar_vuelo();
        void comprar_vuelo();
        void modificar_voleto();
        void menuPrincipal();
};


Menu::Menu()
{
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

void Menu::buscar_vuelo()
{
    cout << "Funcion buscar_vuelo() (pendiente de implementar)" << endl;
}

void Menu::comprar_vuelo()
{
    int opcionPais, opcionAerolinea;

    cout << "\n--- COMPRAR VUELO ---" << endl;
    cout << "\nSeleccione el pais de destino:" << endl;

    cout << "\n 1. Mexico" << endl;
    cout << " 2. España" << endl;
    cout << " 3. Bolivia" << endl;
    cout << " 4. Canada" << endl;
    cout << " 5. Portugal" << endl;
    cout << " 6. Argentina" << endl;
    cout << " 7. Colombia" << endl;
    cout << endl;

    cout << "Opcion: ";
    cin >> opcionPais;

    if(opcionPais < 1 || opcionPais > 7)
    {
        cout << "Opcion de pais no valida!" << endl;
        return;
    }

    Pais &paisSeleccionado = paises[opcionPais - 1];

    paisSeleccionado.mostrarAerolineas();

    cout << endl;
    cout << "Seleccione la aerolinea (1-3): ";
    cin >> opcionAerolinea;

    if(opcionAerolinea < 1 || opcionAerolinea > 3) {
        cout << "Opcion de aerolinea no valida!" << endl;
        return;
    }

    string aerolineaSeleccionada;
    switch(opcionAerolinea) {
        case 1:
            aerolineaSeleccionada = paisSeleccionado.getAerolinea1();
            break;
        case 2:
            aerolineaSeleccionada = paisSeleccionado.getAerolinea2();
            break;
        case 3:
            aerolineaSeleccionada = paisSeleccionado.getAerolinea3();
            break;
    }

    cout << "\nSeleccion confirmada!" << endl;
    cout << "Pais: " << paisSeleccionado.getNombre() << endl;
    cout << "Aerolinea: " << aerolineaSeleccionada << endl;

    if (!pasaporte.solicitarPasaporte())
    {
        cout << "\nNo se pudo completar la compra debido a problemas con la verificacion." << endl;
        return;
    }

    cout << "\nPuede continuar con su compra." << endl;

    paisSeleccionado.mostrarHorarios();

    int opcionHorario;
    cout << "\nSeleccione el horario (1-3): ";
    cin >> opcionHorario;

    if(opcionHorario < 1 || opcionHorario > 3)
    {
        cout << "Opcion de horario no valida!" << endl;
        return;
    }

    Horario &hSel = paisSeleccionado.getHorario(opcionHorario - 1);

    int cantidadAsientos;
    cout << "Ingrese la cantidad de asientos a reservar: ";
    cin >> cantidadAsientos;

    if(cantidadAsientos <= 0) {
        cout << "Cantidad invalida." << endl;
        return;
    }

    if(cantidadAsientos > hSel.getAsientosDisponibles())
    {
        cout << "No hay suficientes asientos disponibles en este horario." << endl;
        return;
    }

    // Mostrar mapa de asientos
    hSel.mostrarMapaAsientos();

    cout << "\nAhora seleccione la posicion de cada asiento (fila y columna)." << endl;

    int reservados = 0;
    while(reservados < cantidadAsientos)
    {
        int fila, columna;
        cout << "\nAsiento " << (reservados+1) << " de " << cantidadAsientos << endl;
        cout << "Fila (1-10): ";
        cin >> fila;
        cout << "Columna (1-6): ";
        cin >> columna;

        if(hSel.reservarAsientoPosicion(fila, columna))
        {
            reservados++;
            hSel.mostrarMapaAsientos();
        }
        else
        {
            cout << "Intente con otra posicion." << endl;
        }
    }

    cout << "\nCompra realizada con exito!" << endl;

    Vuelo vuelo(
        paisSeleccionado.getNombre(),
        aerolineaSeleccionada,
        hSel.getHoraSalida(),
        hSel.getHoraLlegada(),
        cantidadAsientos
    );

    vuelo.mostrarBoleto();
}

void Menu::modificar_voleto()
{
    cout << "Opcion no disponible por el momento." << endl;
}

void Menu::menuPrincipal()
{
    int opcion;

    do {
        cout << "\n--- AEROLINEA UCSP ---" << endl;
        cout << endl;
        cout << "1. BUSCAR VUELO" << endl;
        cout << "2. COMPRAR VUELO" << endl;
        cout << "3. MODIFICAR VOLETO" << endl;
        cout << "4. SALIR" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;hyrjyfhfhfbnh

        switch(opcion) {
        case 1:
            buscar_vuelo();
            break;
        case 2:
            comprar_vuelo();
            break;
        case 3:
            modificar_voleto();
            break;
        case 4:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion no valida!" << endl;
            break;
        }
    } while (opcion != 4);
}

//-----------------------------------------
int main()
{
    srand(time(nullptr)); // semilla para rand()
    Menu s1;
    s1.menuPrincipal();
    return 0;
}
