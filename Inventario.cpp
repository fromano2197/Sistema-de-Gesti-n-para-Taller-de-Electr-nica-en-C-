#include "Inventario.h"
#include "Funciones.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>



Articulo Inventario::getArticulo()
{
    return _articulo;
}
int Inventario::getExistencia()
{
    return _existencia;
}
bool Inventario::getEstado()
{
    return _estado;
}

void Inventario::setArticulo (Articulo idArticulo)
{
    _articulo=idArticulo;
}
void Inventario::setExistencia (int existencia)
{
    _existencia=existencia;
}

void Inventario::setEstado (bool estado)
{
    _estado=estado;
}

void Inventario::setArticuloId(int id)
{
    _articulo.setIdArticulo(id);
}
void Inventario::setSku(int sku)
{
    _articulo.setSku(sku);
}
void Inventario::setArticulo (const char* articulo)
{
    _articulo.setArticulo(articulo);
}
void Inventario::setMarca (const char* marca)
{
    _articulo.setMarca(marca);
}
void Inventario::setModelo (const char* modelo)
{
    _articulo.setModelo(modelo);
}
void Inventario::setTipo(int tipo)
{
    _articulo.setTipoArticulo(tipo);
}

void Inventario::Cargar()
{
    _articulo.CargarRefaccion();

    dibujarCuadro(49,14,73,16);
    rlutil::locate(52,15);
    std::cout << "EXISTENCIA: ";
    rlutil::locate(66,15);
    std::cin >> _existencia;
    system("cls");
    _estado=true;
}

void Inventario::Mostrar()
{
    if(_estado==true)
    {
        _articulo.MostrarRefaccion();
        rlutil::locate(49, 21);
        std::cout << "EXISTENCIA:";
        rlutil::locate(64, 21);
        std::cout<< _existencia;
    }
}

void Inventario::Mostrar(int i)
{
    int y=3+i;
    if(_estado==true)
    {
        dibujarSubrayado(0,2,105);
        _articulo.MostrarRefaccion(i);
        rlutil::locate(75, 1);
        std::cout << "EXISTENCIA";
        rlutil::locate(80, y);
        std::cout <<_existencia << std::endl;
    }
}

void Inventario::Mostrar(int i, int y)
{
    if(_estado==true)
    {
        dibujarSubrayado(0,2,105);
        _articulo.Mostrar(i,y);
        rlutil::locate(91, 1);
        std::cout << "EXISTENCIA";
        rlutil::locate(95, y);
        std::cout <<_existencia << std::endl;
    }
}

