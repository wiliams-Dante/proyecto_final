#ifndef AEROLINEAUCSP_VUELO_H
#define AEROLINEAUCSP_VUELO_H

#include <string>
using namespace std;

class Vuelo {
private:
    string paisDestino;
    string aerolinea;
    string horaSalida;
    string horaLlegada;
    string fecha;
    int cantidadAsientos;

    static const int MAX_ASIENTOS = 10;
    int filas[MAX_ASIENTOS];
    int columnas[MAX_ASIENTOS];

    int indexPais;
    int indexHorario;

public:
    Vuelo(string p="", string a="", string hs="", string hl="",
          string f="", int cant=0, int idxPais=-1, int idxHor=-1);

    void agregarAsiento(int fila, int columna);
    void setAsiento(int indice, int fila, int columna);

    int getFilaAsiento(int indice) const;
    int getColumnaAsiento(int indice) const;

    string getPaisDestino() const;
    string getHoraSalida() const;
    string getHoraLlegada() const;
    string getFecha() const;
    int getCantidad() const;

    int getIndexPais() const;
    int getIndexHorario() const;

    void setFecha(const string&);
    void setHoraSalida(const string&);
    void setHoraLlegada(const string&);
    void setCantidadAsientos(int);
    void setIndexPais(int);
    void setIndexHorario(int);

    void mostrarBoleto() const;
};

#endif //AEROLINEAUCSP_VUELO_H
