#ifndef AEROLINEAUCSP_HORARIO_H
#define AEROLINEAUCSP_HORARIO_H

#include <string>
using namespace std;

class Horario {
private:
    static const int FILAS = 10;
    static const int COLUMNAS = 6;

    char asientos[FILAS][COLUMNAS];

    string horaSalida;
    string horaLlegada;

    int asientosTotales;
    int asientosDisponibles;

    void inicializarAsientos();

public:
    Horario(string salida="", string llegada="", int ignorado=0);

    void mostrarHorario(int num);
    void mostrarMapaAsientos();

    bool reservarAsientoPosicion(int fila, int columna);
    bool liberarAsientoPosicion(int fila, int columna);

    string getHoraSalida() const;
    string getHoraLlegada() const;
    int getAsientosDisponibles() const;
};

#endif //AEROLINEAUCSP_HORARIO_H
