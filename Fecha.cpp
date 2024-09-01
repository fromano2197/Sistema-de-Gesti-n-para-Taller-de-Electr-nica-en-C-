#include <iostream>
#include <ctime>
#include "Fecha.h"
#include "rlutil.h"
#include "Menu.h"
Fecha::Fecha()
{
    _dia=1;
    _mes=1;
    _anio=1900;
}
Fecha::Fecha(int d, int m, int a)
{
    _dia=d;
    _mes=m;
    _anio=a;
}

int Fecha::getDia() const
{
    return _dia;
}
int Fecha::getMes() const
{
    return _mes;
}
int Fecha::getAnio() const
{
    return _anio;
}

void Fecha::setDia (int dia)
{
    _dia=dia;
}
void Fecha::setMes(int mes)
{
    _mes=mes;
}
void Fecha::setAnio(int anio)
{
    _anio=anio;
}

bool Fecha::operator==(const Fecha& aux) const
{
    return (_dia == aux.getDia() && _mes == aux.getMes() && _anio == aux.getAnio());
}
void Fecha::GrabarFechaSistema ()
{
    std::time_t ahora = std::time(nullptr);

    std::tm* tiempoLocal = std::localtime(&ahora);

    _anio = 1900 + tiempoLocal->tm_year;
    _mes = 1 + tiempoLocal->tm_mon;
    _dia = tiempoLocal->tm_mday;
}

void Fecha::Cargar()
{
    rlutil::locate(52,16);
    std::cout<<"DIA:";
    rlutil::locate(52,17);
    std::cout<<"MES:";
    rlutil::locate(52,18);
    std::cout<<"ANIO:";
    rlutil::locate(57,16);
    std::cin>>_dia;
    rlutil::locate(57,17);
    std::cin>>_mes;
    rlutil::locate(58,18);
    std::cin>>_anio;
    while(_anio<0)
    {
        rlutil::cls();
        dibujarCuadro(33,14,95,16);
        rlutil::locate(35,15);
        std::cout<<"Anio ingresado no valido, vuelva a ingresar un anio: ";
        std::cin>>_anio;
    }
    if(_anio%4==0 && _anio%100 !=0)
    {
        if(_mes>=1 && _mes<=12)
        {
            if(_mes==2)
            {
                if(_dia<1 || _dia>29)
                {
                    rlutil::cls();
                    dibujarCuadro(10,14,115,16);
                    rlutil::locate(13,15);
                    std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 29, vuelva ingresarlo por favor:"<<std::endl;
                    rlutil::locate(111,15);
                    std::cin>>_dia;
                }

            }
            if (_mes==1 || _mes==3 ||_mes==5 ||_mes==7 ||_mes==8 ||_mes==10 ||_mes==12)
            {
                if(_dia<1 || _dia>31)
                {
                    rlutil::cls();
                    dibujarCuadro(10,14,115,16);
                    rlutil::locate(13,15);
                    std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 31, vuelva ingresarlo por favor:"<<std::endl;
                    rlutil::locate(111,15);
                    std::cin>>_dia;
                }
            }
            if (_mes==4 || _mes==6 ||_mes==9 ||_mes==11)
            {
                if(_dia<1 || _dia>30)
                {
                    rlutil::cls();
                    dibujarCuadro(10,14,115,16);
                    rlutil::locate(13,15);
                    std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 30, vuelva ingresarlo por favor:"<<std::endl;
                    rlutil::locate(111,15);
                    std::cin>>_dia;



                }
            }
        }
        else
        {
            rlutil::cls();
            dibujarCuadro(10,14,115,16);
            rlutil::locate(13,15);
            std::cout<<"El mes ingresado es incorrecto asegurese que el mes sea entre 1 y 12, vuelva ingresarlo por favor:"<<std::endl;
            rlutil::locate(111,15);
            std::cin>>_mes;

        }

    }
    else
    {
        while(_mes<1 || _mes>12)
        {
            rlutil::cls();
            dibujarCuadro(10,14,115,16);
            rlutil::locate(13,15);
            std::cout<<"El mes ingresado es incorrecto asegurese que el mes sea entre 1 y 12, vuelva ingresarlo por favor:"<<std::endl;
            rlutil::locate(111,15);
            std::cin>>_mes;
        }
        if(_mes==2)
        {
            while(_dia<1 || _dia>29)
            {
                rlutil::cls();
                dibujarCuadro(10,14,115,16);
                rlutil::locate(13,15);
                std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 29, vuelva ingresarlo por favor:"<<std::endl;
                rlutil::locate(111,15);
                std::cin>>_dia;
            }

        }
        if (_mes==1 || _mes==3 ||_mes==5 ||_mes==7 ||_mes==8 ||_mes==10 ||_mes==12)
        {
            while(_dia<1 || _dia>31)
            {
                rlutil::cls();
                dibujarCuadro(10,14,115,16);
                rlutil::locate(13,15);
                std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 31, vuelva ingresarlo por favor:"<<std::endl;
                rlutil::locate(111,15);
                std::cin>>_dia;
            }
        }
        if (_mes==4 || _mes==6 ||_mes==9 ||_mes==11)
        {
            while(_dia<1 || _dia>30)
            {
                rlutil::cls();
                dibujarCuadro(10,14,115,16);
                rlutil::locate(13,15);
                std::cout<<"El dia ingresado es incorrecto asegurese que sean dias entre 1 a 30, vuelva ingresarlo por favor:"<<std::endl;
                rlutil::locate(111,15);
                std::cin>>_dia;
            }
        }

    }
}


void Fecha::Mostrar()
{
    if (_dia < 10)
    {
        std::cout << '0';
    }
    std::cout << _dia << '/';

    if (_mes < 10)
    {
        std::cout << '0';
    }
    std::cout << _mes << '/';

    std::cout << _anio;
}

std::string Fecha::ToString() const
{
    std::string fechaString;
    if (_dia < 10)
    {
        fechaString += '0';
    }
    fechaString += std::to_string(_dia) + '/';

    if (_mes < 10)
    {
        fechaString += '0';
    }
    fechaString += std::to_string(_mes) + '/';

    fechaString += std::to_string(_anio);

    return fechaString;
}


bool Fecha::operator>=(const Fecha& aux) const
{
    if (_anio > aux.getAnio()) return true;
    if (_anio == aux.getAnio() && _mes > aux.getMes()) return true;
    if (_anio == aux.getAnio() && _mes == aux.getMes() && _dia >= aux.getDia()) return true;
    return false;
}

bool Fecha::operator<=(const Fecha& aux) const
{
    if (_anio < aux.getAnio()) return true;
    if (_anio == aux.getAnio() && _mes < aux.getMes()) return true;
    if (_anio == aux.getAnio() && _mes == aux.getMes() && _dia <= aux.getDia()) return true;
    return false;
}
