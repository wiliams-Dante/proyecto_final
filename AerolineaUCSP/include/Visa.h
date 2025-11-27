#ifndef AEROLINEAUCSP_VISA_H
#define AEROLINEAUCSP_VISA_H

#include "Documentos.h"
#include <string>
using namespace std;

class VISA : public Documentos {
private:
    string tipo;
    string paisDestino;
    string fechaEmision;
    string fechaVencimiento;

public:
    VISA();
    VISA(const string&, const string&, const string&, const string&, const string&);

    string getPaisDestino() const;
    string getTipo() const;
};

#endif //AEROLINEAUCSP_VISA_H
