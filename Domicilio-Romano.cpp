#include <iostream>
#include <cstring>
#include "Domicilio.h"
#include "rlutil.h"


char* Domicilio::getCalle()
{
    return _calle;
}
int Domicilio::getNumeracion()
{
    return _numeracion;
}
int Domicilio::getCodigoPostal()
{
    return _codigoPostal;
}

void Domicilio::setCalle(const char* calle)
{
    strcpy(_calle, calle);
}
void Domicilio::setNumeracion(int num)
{
    _numeracion=num;
}
void Domicilio::setCodigoPostal(int codPostal)
{
    _codigoPostal=codPostal;
}



void Domicilio::Cargar()
{
    std::cout << "Calle: ";
    cargarCadena (_calle,29);
    std::cout << "Numeracion: ";
    std::cin >> _numeracion;
    std::cout << "Codigo postal: ";
    std::cin >> _codigoPostal;
}

void Domicilio::Mostrar(int i)
{
    int y=3+i;
    rlutil::locate(55, 1);
    std::cout << "Calle";
    rlutil::locate(55, y);
    std::cout <<_calle;
    rlutil::locate(62, 1);
    std::cout << "Numeracion";
    rlutil::locate(65, y);
    std::cout <<_numeracion;
    rlutil::locate(75, 1);
    std::cout << "Codigo postal";
    rlutil::locate(79, y);
    std::cout <<_codigoPostal;
}

void Domicilio::Mostrar()
{

    rlutil::locate(55, 8);
    std::cout << "Calle";
    rlutil::locate(55, 10);
    std::cout <<_calle;
    rlutil::locate(62, 8);
    std::cout << "Numeracion";
    rlutil::locate(65, 10);
    std::cout <<_numeracion;
    rlutil::locate(75, 8);
    std::cout << "Codigo postal";
    rlutil::locate(79, 10);
    std::cout <<_codigoPostal;
}
