#pragma once
#include "Funciones.h"



class Domicilio{
protected:
    char _calle [30];
    int _numeracion;
    int _codigoPostal;
public:
    char* getCalle();
    int getNumeracion();
    int getCodigoPostal();

    void setCalle(const char* calle);
    void setNumeracion(int num);
    void setCodigoPostal(int codPostal);

    void Cargar();
    void Mostrar();
    void Mostrar(int i);
    void MostrarReparacion();
    void Mostrar(int i, int y);

};
