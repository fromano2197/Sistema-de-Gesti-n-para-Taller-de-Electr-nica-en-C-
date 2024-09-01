#include <iostream>
#include "Cliente.h"

Contacto& Cliente::getDatos()
{
    return _datos;
}
bool Cliente::getEstado()
{
    return _estado;
}

void Cliente::setDatos(Contacto datos)
{
    _datos=datos;
}
void Cliente::setEstado(bool estado)
{
    _estado=estado;
}

void Cliente::Cargar()
{

    Persona::Cargar();
    _datos.Cargar();
    _estado=true;
}
void Cliente::Mostrar(int i)
{
    if(_estado==true)
    {
        Persona::Mostrar(i);
        _datos.Mostrar(i);
    }

}

void Cliente::Mostrar()
{
    if(_estado==true)
    {
        Persona::Mostrar();
        _datos.Mostrar();
    }
}

void Cliente::MostrarBaja()
{
    Persona::MostrarBaja();
    _datos.Mostrar();
}

void Cliente::CargarReparacion()
{

    Persona::Cargar();
    _datos.Cargar();
    _estado=true;
}

void Cliente::MostrarReparacion()
{
    if(_estado==true)
    {
        Persona::MostrarReparacion();
        _datos.MostrarReparacion();
    }
}

void Cliente::MostrarReparacion(int i)
{
    Persona::MostrarReparacion(i);
}

void Cliente::MostrarReparacionBaja()
{
    Persona::MostrarReparacionBaja();
    _datos.MostrarReparacion();
}

void Cliente::Mostrar(int i, int y)
{
    if(_estado==true){
    if(_estado==true)
    {
        dibujarSubrayado(0,2,116);
        Persona::Mostrar(i, y);
        _datos.Mostrar(i,y);
    }
    }
}
