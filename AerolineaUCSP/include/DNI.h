#ifndef AEROLINEAUCSP_DNI_H
#define AEROLINEAUCSP_DNI_H

#include "Documentos.h"
#include <string>
using namespace std;

class DNI : public Documentos {
private:
    string nombres;
    string apellidos;
    string nacionalidad;
    string sexo;

public:
    DNI();
    DNI(const string& nom,
        const string& ape,
        const string& nac,
        const string& sx,
        const string& num);

    string getNombres() const;
    string getApellidos() const;
    string getNacionalidad() const;
    string getSexo() const;
};

#endif // AEROLINEAUCSP_DNI_H
