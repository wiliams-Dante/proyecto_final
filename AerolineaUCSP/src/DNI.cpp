#include "DNI.h"

DNI::DNI() : Documentos() {}

DNI::DNI(const string& nom, const string& ape,
         const string& nac, const string& sx,
         const string& num)
        : Documentos(num)
{
    nombres = nom;
    apellidos = ape;
    nacionalidad = nac;
    sexo = sx;
}

string DNI::getNombres() const { return nombres; }
string DNI::getApellidos() const { return apellidos; }
string DNI::getNacionalidad() const { return nacionalidad; }
string DNI::getSexo() const { return sexo; }