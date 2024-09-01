#pragma once
#include "Domicilio.h"

class Contacto {
private:
    Domicilio _domicilio;
    char _telefono[30];
    char _email[50];

public:
    Domicilio& getDomicilio();
    char* getTelefono();
    char* getEmail();

    void setDomicilio(Domicilio domicilio);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setCalleDomicilio(const char* calle);
    void Cargar();
    void Mostrar();
    void Mostrar(int i);
    void MostrarReparacion();
    void Mostrar(int i, int y);
};
