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
    dibujarCuadro(50,14,76,16);
    rlutil::locate(54,15);
    std::cout << "CALLE: ";
    rlutil::locate(61,15);
    cargarCadena (_calle,29);
    system("cls");
   dibujarCuadro(50,14,76,16);
    rlutil::locate(54,15);
    std::cout << "NUMERACION: ";
     rlutil::locate(67,15);
    std::cin >> _numeracion;
    system("cls");
    dibujarCuadro(50,14,76,16);
    rlutil::locate(54,15);
    std::cout << "CODIGO POSTAL: ";
    rlutil::locate(69,15);
    std::cin >> _codigoPostal;
    system("cls");
}

void Domicilio::Mostrar(int i)
{
    int y=3+i;
    rlutil::locate(52, 1);
    std::cout << "CALLE";
    rlutil::locate(52, y);
    std::cout <<_calle;
    rlutil::locate(65, 1);
    std::cout << "NUMERACION";
    rlutil::locate(68, y);
    std::cout <<_numeracion;
    rlutil::locate(79, 1);
    std::cout << "C.P.";
    rlutil::locate(79, y);
    std::cout <<_codigoPostal;
}

void Domicilio::Mostrar()
{

    rlutil::locate(49, 17);
    std::cout << "CALLE";
    rlutil::locate(64, 17);
    std::cout <<_calle;
    rlutil::locate(49, 19);
    std::cout << "NUMERACION:";
    rlutil::locate(64, 19);
    std::cout <<_numeracion << std::endl;
    rlutil::locate(49, 21);
    std::cout << "C.P:";
    rlutil::locate(64, 21);
    std::cout <<_codigoPostal << std::endl;
}

void Domicilio::MostrarReparacion()
{

    rlutil::locate(72, 2);
    std::cout << "CALLE:";
    rlutil::locate(94, 2);
    std::cout <<_calle;
    rlutil::locate(72, 4);
    std::cout << "NUMERACION:";
    rlutil::locate(94, 4);
    std::cout <<_numeracion << std::endl;
    rlutil::locate(72, 6);
    std::cout << "C.P:";
    rlutil::locate(94, 6);
    std::cout <<_codigoPostal << std::endl;
}

void Domicilio::Mostrar(int i, int y)
{

    rlutil::locate(52, 1);
    std::cout << "CALLE";
    rlutil::locate(52, y);
    std::cout <<_calle;
    rlutil::locate(60, 1);
    std::cout << "NUMERACION";
    rlutil::locate(63, y);
    std::cout <<_numeracion;
    rlutil::locate(74, 1);
    std::cout << "C.P.";
    rlutil::locate(74, y);
    std::cout <<_codigoPostal;
}



