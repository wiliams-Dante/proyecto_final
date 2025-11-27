#ifndef AEROLINEAUCSP_PAIS_H
#define AEROLINEAUCSP_PAIS_H

#include "Horario.h"
#include <string>
using namespace std;

class Pais {
private:
    string nombre;
    string aerolinea1;
    string aerolinea2;
    string aerolinea3;

    Horario horarios[3];

public:
    Pais(string n="", string a1="", string a2="", string a3="",
         Horario h1=Horario(), Horario h2=Horario(), Horario h3=Horario());

    string getNombre();
    string getAerolinea1();
    string getAerolinea2();
    string getAerolinea3();

    void mostrarAerolineas();
    void mostrarHorarios();

    Horario& getHorario(int indice);
};

#endif //AEROLINEAUCSP_PAIS_H
