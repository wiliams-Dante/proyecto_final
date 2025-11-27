#ifndef AEROLINEAUCSP_DIA_H
#define AEROLINEAUCSP_DIA_H

#include "Horario.h"
#include <string>
using namespace std;

class Dia {
private:
    string fecha;
    Horario horarios[3];
    int numHorarios;

public:
    Dia(string f="", Horario h1=Horario(), Horario h2=Horario(), Horario h3=Horario());

    void mostrarDia();
    bool reservar(int indice, int cant);

    string getFecha();
};

#endif //AEROLINEAUCSP_DIA_H
