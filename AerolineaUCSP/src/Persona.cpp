#include "Persona.h"

Persona::Persona() {}

Persona::Persona(const string& nom, const string& ape, const DNI& d)
{
    nombres = nom;
    apellidos = ape;
    dni = d;
}

string Persona::getNombres() const { return nombres; }
string Persona::getApellidos() const { return apellidos; }
DNI Persona::getDNI() const { return dni; }
