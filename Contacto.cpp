#include <iostream>
#include <cstring>
#include "Contacto.h"
#include "Funciones.h"
#include "rlutil.h"


Domicilio& Contacto::getDomicilio() { return _domicilio; }
char* Contacto::getTelefono() { return _telefono; }
char* Contacto::getEmail() { return _email; }

void Contacto::setDomicilio(Domicilio domicilio) { _domicilio = domicilio; }
void Contacto::setTelefono(const char* telefono) {
    strncpy(_telefono, telefono, sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}
void Contacto::setEmail(const char* email) {
    strncpy(_email, email, sizeof(_email) - 1);
    _email[sizeof(_email) - 1] = '\0';
}
void Contacto::setCalleDomicilio(const char* calle) {
    _domicilio.setCalle(calle);
}



void Contacto::Cargar()
{
    _domicilio.Cargar();

    dibujarCuadro(50,14,76,16);
    rlutil::locate(54,15);
    std::cout << "TELEFONO: ";
    rlutil::locate(64,15);
    cargarCadena(_telefono, 29);
    system("cls");
    dibujarCuadro(50,14,85,16);
    rlutil::locate(54,15);
    std::cout << "EMAIL: ";
    rlutil::locate(62,15);
    cargarCadena(_email, 49);
    system("cls");
}




void Contacto::Mostrar(int i)
{
    int y=3+i;
    _domicilio.Mostrar(i);
    rlutil::locate(85, 1);
    std::cout << "TELEFONO";
    rlutil::locate(85, y);
    std::cout<< _telefono;
    rlutil::locate(102, 1);
    std::cout << "EMAIL";
    rlutil::locate(97, y);
    std::cout<< _email ;
}

void Contacto::Mostrar()
{
    _domicilio.Mostrar();
    rlutil::locate(49, 23);
    std::cout << "TELEFONO";
    rlutil::locate(64, 23);
    std::cout<< _telefono << std::endl;
    rlutil::locate(49, 25);
    std::cout << "EMAIL";
    rlutil::locate(64, 25);
    std::cout<< _email << std::endl;
}
void Contacto::MostrarReparacion()
{
    _domicilio.MostrarReparacion();
    rlutil::locate(72, 8);
    std::cout << "TELEFONO:";
    rlutil::locate(94, 8);
    std::cout<< _telefono << std::endl;
    rlutil::locate(72, 10);
    std::cout << "EMAIL:";
    rlutil::locate(94, 10);
    std::cout<< _email << std::endl;
}

void Contacto::Mostrar(int i, int y)
{

    _domicilio.Mostrar(i, y);
    rlutil::locate(85, 1);
    std::cout << "TELEFONO";
    rlutil::locate(85, y);
    std::cout<< _telefono;
    rlutil::locate(102, 1);
    std::cout << "EMAIL";
    rlutil::locate(98, y);
    std::cout<< _email ;
}


