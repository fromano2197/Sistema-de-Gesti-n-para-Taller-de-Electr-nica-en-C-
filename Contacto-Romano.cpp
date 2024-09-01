#include <iostream>
#include <cstring>
#include "Contacto.h"
#include "Funciones.h"
#include "rlutil.h"

Domicilio Contacto::getDomicilio()
{
    return _domicilio;
}


char* Contacto::getTelefono()
{
    return _telefono;
}
char* Contacto::getEmail()
{
    return _email;
}

void Contacto::setDomicilio(Domicilio domicilio){
    _domicilio=domicilio;
}

void Contacto::setTelefono(const char* telefono)
{
    strcpy(_telefono, telefono);
}
void Contacto::setEmail (const char* email)
{
    strcpy (_email, email);
}

void Contacto::Cargar()
{
    _domicilio.Cargar();
    std::cout << "Telefono: ";
    cargarCadena(_telefono, 29);
    std::cout << "Email: ";
    cargarCadena(_email, 49);
}

void Contacto::Mostrar(int i)
{
    int y=3+i;
    _domicilio.Mostrar(i);
    rlutil::locate(90, 1);
    std::cout << "Telefono";
    rlutil::locate(90, y);
    std::cout<< _telefono;
    rlutil::locate(107, 1);
    std::cout << "Email";
    rlutil::locate(103, y);
    std::cout<< _email ;
}

void Contacto::Mostrar()
{
    _domicilio.Mostrar();
    rlutil::locate(90, 8);
    std::cout << "Telefono";
    rlutil::locate(90, 10);
    std::cout<< _telefono << std::endl;
    rlutil::locate(107, 8);
    std::cout << "Email";
    rlutil::locate(103, 10);
    std::cout<< _email << std::endl;
}
