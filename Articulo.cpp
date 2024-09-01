#include <iostream>
#include <cstring>
#include "Articulo.h"
#include "Funciones.h"
#include "rlutil.h"



int Articulo::getIdArticulo() const
{
    return _idArticulo;
}
int Articulo::getSku() const
{
    return _sku;
}
const char* Articulo::getArticulo() const
{
    return _articulo;
}
const char* Articulo::getMarca() const
{
    return _marca;
}
const char* Articulo::getModelo() const
{
    return _modelo;
}
int Articulo::getSerie() const
{
    return _numSerie;
}
int Articulo::getTipoArticulo() const
{
    return _tipoArticulo;
}
bool Articulo::getEstado() const
{
    return _estado;
}


void Articulo::setIdArticulo(int idArticulo)
{
    _idArticulo=idArticulo;
}
void Articulo::setSku(int sku)
{
    _sku=sku;
}
void Articulo::setArticulo(const char* articulo)
{
    strncpy(_articulo, articulo, sizeof(_articulo) - 1);
    _articulo[sizeof(_articulo) - 1] = '\0';
}
void Articulo::setMarca(const char* marca)
{
    strcpy(_marca, marca);
}
void Articulo::setModelo(const char* modelo)
{
    strcpy(_modelo, modelo);
}
void Articulo::setSerie(int serie)
{
    _numSerie=serie;
}
void Articulo::setTipoArticulo(int tipoArticulo)
{
    _tipoArticulo=tipoArticulo;
}
void Articulo::setEstado(bool estado)
{
    _estado=estado;
}

int Articulo::_idArtContador=100;

void Articulo::Cargar()
{
    _idArticulo=_idArtContador++;
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "SKU: ";
    rlutil::locate(65,15);
    std::cin >> _sku;
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "ARTICULO: ";
    rlutil::locate(65,15);
    cargarCadena (_articulo, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "MARCA: ";
    rlutil::locate(65,15);
    cargarCadena (_marca, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "MODELO: ";
    rlutil::locate(65,15);
    cargarCadena (_modelo, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "NUMERO DE SERIE: ";
    rlutil::locate(70,15);
    std::cin >> _numSerie;
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "TIPO DE ARTICULO: ";
    rlutil::locate(70,15);
    std::cin >> _tipoArticulo;
    system("cls");
    _estado=true;
}

void Articulo::CargarReparacion()
{
    rlutil::locate(54,15);
    std::cout << "ARTICULO: ";
    rlutil::locate(65,15);
    cargarCadena (_articulo, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "MARCA: ";
    rlutil::locate(65,15);
    cargarCadena (_marca, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "MODELO: ";
    rlutil::locate(65,15);
    cargarCadena (_modelo, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "NUMERO DE SERIE: ";
    rlutil::locate(70,15);
    std::cin >> _numSerie;
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout << "TIPO DE ARTICULO: ";
    rlutil::locate(70,15);
    std::cin >> _tipoArticulo;
    system("cls");
    _estado=true;
}
void Articulo::CargarRefaccion()
{
    _idArticulo=_idArtContador++;
    dibujarCuadro(53,14,73,16);
    rlutil::locate(57,15);
    std::cout << "SKU: ";
    rlutil::locate(63,15);
    std::cin >> _sku;
    system("cls");
    dibujarCuadro(50,14,83,16);
    rlutil::locate(54,15);
    std::cout << "ARTICULO: ";
    rlutil::locate(65,15);
    cargarCadena (_articulo, 29);
    system("cls");
    dibujarCuadro(50,14,75,16);
    rlutil::locate(53,15);
    std::cout << "MARCA: ";
    rlutil::locate(62,15);
    cargarCadena (_marca, 29);
    system("cls");
    dibujarCuadro(50,14,75,16);
    rlutil::locate(54,15);
    std::cout << "MODELO: ";
    rlutil::locate(65,15);
    cargarCadena (_modelo, 29);
    system("cls");
    dibujarCuadro(50,14,80,16);
    rlutil::locate(55,15);
    std::cout << "TIPO DE ARTICULO: ";
    rlutil::locate(75,15);
    std::cin >> _tipoArticulo;
    system("cls");
    _estado=true;
}

void Articulo::Mostrar()
{
    dibujarTabla(44,4,76,25,2);
    rlutil::locate(57, 5);
    std::cout<<"ARTICULO";
    rlutil::locate(49, 9);
    std::cout << "ID: ";
    rlutil::locate(64, 9);
    std::cout <<"#"<<_idArticulo;
    rlutil::locate(49, 11);
    std::cout << "SKU:";
    rlutil::locate(64, 11);
    std::cout << _sku;
    rlutil::locate(49, 13);
    std::cout << "ARTICULO:";
    rlutil::locate(64, 13);
    std::cout <<_articulo;
    rlutil::locate(49, 15);
    std::cout << "MARCA:";
    rlutil::locate(64, 15);
    std::cout << _marca;
    rlutil::locate(49, 17);
    std::cout << "MODELO:";
    rlutil::locate(64, 17);
    std::cout <<_modelo;
    rlutil::locate(49, 19);
    std::cout << "SERIE:";
    rlutil::locate(64, 19);
    std::cout <<_numSerie;
    rlutil::locate(49, 21);
    std::cout << "TIPO ART:";
    rlutil::locate(64, 21);
    std::cout <<_tipoArticulo;
}

void Articulo::MostrarRefaccion()
{
    dibujarTabla(44,4,76,23,2);
    rlutil::locate(57, 5);
    std::cout<<"ARTICULO";
    rlutil::locate(49, 9);
    std::cout << "ID: ";
    rlutil::locate(64, 9);
    std::cout <<"#"<<_idArticulo;
    rlutil::locate(49, 11);
    std::cout << "SKU:";
    rlutil::locate(64, 11);
    std::cout << _sku;
    rlutil::locate(49, 13);
    std::cout << "ARTICULO:";
    rlutil::locate(64, 13);
    std::cout <<_articulo;
    rlutil::locate(49, 15);
    std::cout << "MARCA:";
    rlutil::locate(64, 15);
    std::cout << _marca;
    rlutil::locate(49, 17);
    std::cout << "MODELO:";
    rlutil::locate(64, 17);
    std::cout <<_modelo;
    rlutil::locate(49, 19);
    std::cout << "TIPO:";
    rlutil::locate(64, 19);
    std::cout <<_tipoArticulo;
}

void Articulo::Mostrar(int i)
{
    int y=3+i;
    if(_estado)
    {
        rlutil::locate(1, 1);
        std::cout << "ID";
        rlutil::locate(1, y);
        std::cout << _idArticulo;
        rlutil::locate(7, 1);
        std::cout << "SKU";
        rlutil::locate(5, y);
        std::cout <<_sku;
        rlutil::locate(15, 1);
        std::cout << "ARTICULO";
        rlutil::locate(15, y);
        std::cout <<_articulo;
        rlutil::locate(32, 1);
        std::cout << "MARCA";
        rlutil::locate(32, y);
        std::cout <<_marca;
        rlutil::locate(45, 1);
        std::cout << "MODELO";
        rlutil::locate(45, y);
        std::cout <<_modelo;
        rlutil::locate(62, 1);
        std::cout << "SERIE";
        rlutil::locate(60, y);
        std::cout <<_numSerie;
        rlutil::locate(80, 1);
        std::cout << "TIPO";
        rlutil::locate(81, y);
        std::cout <<_tipoArticulo;
    }
}
void Articulo::MostrarRefaccion(int i)
{
    int y=3+i;
    if(_estado)
    {
        rlutil::locate(1, 1);
        std::cout << "ID";
        rlutil::locate(1, y);
        std::cout << _idArticulo;
        rlutil::locate(7, 1);
        std::cout << "SKU";
        rlutil::locate(5, y);
        std::cout <<_sku;
        rlutil::locate(15, 1);
        std::cout << "ARTICULO";
        rlutil::locate(15, y);
        std::cout <<_articulo;
        rlutil::locate(32, 1);
        std::cout << "MARCA";
        rlutil::locate(32, y);
        std::cout <<_marca;
        rlutil::locate(45, 1);
        std::cout << "MODELO";
        rlutil::locate(45, y);
        std::cout <<_modelo;
        rlutil::locate(62, 1);
        std::cout << "TIPO";
        rlutil::locate(64, y);
        std::cout <<_tipoArticulo;
    }
}

void Articulo::Mostrar(int i, int y)
{
    if(_estado)
    {
        dibujarSubrayado(0,2,105);
        rlutil::locate(1, 1);
        std::cout << "ID";
        rlutil::locate(1, y);
        std::cout <<"#"<< _idArticulo;
        rlutil::locate(7, 1);
        std::cout << "SKU";
        rlutil::locate(5, y);
        std::cout <<_sku;
        rlutil::locate(18, 1);
        std::cout << "ARTICULO";
        rlutil::locate(15, y);
        std::cout <<_articulo;
        rlutil::locate(36, 1);
        std::cout << "MARCA";
        rlutil::locate(35, y);
        std::cout <<_marca;
        rlutil::locate(50, 1);
        std::cout << "MODELO";
        rlutil::locate(50, y);
        std::cout <<_modelo;
        rlutil::locate(65, 1);
        std::cout << "SERIE";
        rlutil::locate(65, y);
        std::cout <<_numSerie;
        rlutil::locate(78, 1);
        std::cout << "TIPO";
        rlutil::locate(80, y);
        std::cout <<_tipoArticulo;
    }
}


void Articulo::MostrarReparacion()
{
    rlutil::locate(13, 14);
    std::cout<<"ARTICULO:";
    rlutil::locate(26, 14);
    std::cout <<_articulo;
    rlutil::locate(13, 16);
    std::cout << "MARCA:";
    rlutil::locate(26, 16);
    std::cout << _marca;
    rlutil::locate(13, 18);
    std::cout << "MODELO:";
    rlutil::locate(26, 18);
    std::cout <<_modelo;
    rlutil::locate(13, 20);
    std::cout << "TIPO:";
    rlutil::locate(26, 20);
    std::cout <<_tipoArticulo;
}



void Articulo::MostrarReparacion(int i)
{
    int y = 3 + (i * 4);
    rlutil::locate(32, y);
    std::cout << "ARTICULO:";
    rlutil::locate(42, y);
    std::cout << _articulo;
    rlutil::locate(61, y);
    std::cout << "MARCA:";
    rlutil::locate(68, y);
    std::cout << _marca;
    rlutil::locate(80, y);
    std::cout << "MODELO:";
    rlutil::locate(88, y);
    std::cout << _modelo;
    rlutil::locate(105, y);
    std::cout << "TIPO:";
    rlutil::locate(112, y);
    std::cout << _tipoArticulo;
}
