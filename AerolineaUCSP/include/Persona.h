#ifndef AEROLINEAUCSP_PERSONA_H
#define AEROLINEAUCSP_PERSONA_H

#include "DNI.h"
#include <string>
using namespace std;

class Persona {
protected:
    string nombres;
    string apellidos;
    DNI dni;

public:
    Persona();
    Persona(const string&, const string&, const DNI&);

    string getNombres() const;
    string getApellidos() const;
    DNI getDNI() const;
};

#endif //AEROLINEAUCSP_PERSONA_H
