#ifndef AEROLINEAUCSP_DOCUMENTOS_H
#define AEROLINEAUCSP_DOCUMENTOS_H

#include <string>
using namespace std;

class Documentos {
protected:
    string numero;

public:
    Documentos();
    Documentos(const string& num);

    void setNumero(const string& num);
    string getNumero() const;
};

#endif //AEROLINEAUCSP_DOCUMENTOS_H
