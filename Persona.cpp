#include "Persona.h"
#include "Funciones.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>


Persona::Persona()
{
    _id=0;
    strcpy(_nombre, " ");
    strcpy(_apellido, " ");
    _dni=0;
    _estado=false;
}

int Persona:: getId()
{
    return _id;
}
const char* Persona::getNombre()
{
    return _nombre;
}
const char* Persona::getApellido()
{
    return _apellido;
}
Fecha Persona::getNacimiento()
{
    return _nacimiento;
}
int Persona::getDni()
{
    return _dni;
}
bool Persona::getEstado()
{
    return _estado;
}

void Persona::setId(int id)
{
    _id=id;
}
void Persona::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}
void Persona::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}
void Persona::setFecha(Fecha nacimiento)
{
    _nacimiento=nacimiento;
}
void Persona::setDni(int dni)
{
    _dni=dni;
}
void Persona::setEstado(bool estado)
{
    _estado=estado;
}

int Persona::_idContador=100;

void Persona::Cargar()
{
    _id=_idContador++;
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE NOMBRE: ";
    rlutil::locate(70,15);
    cargarCadena(_nombre, 29);
    system("cls");
    dibujarCuadro(50,14,85,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE APELLIDO: ";
    rlutil::locate(73,15);
    cargarCadena(_apellido, 29);
    system("cls");
    dibujarCuadro(40,14,85,19);
    rlutil::locate(44,15);
    std::cout<<"INGRESE FECHA DE NACIMIENTO: DD/MM/AAAA";
    _nacimiento.Cargar();
    system("cls");
    dibujarCuadro(50,14,70,16);
    rlutil::locate(54,15);
    std::cout << "DNI: ";
    std::cin >> _dni;
    system("cls");
    _estado = true;
}

void Persona::CargarTecnico()
{
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE NOMBRE: ";
    rlutil::locate(70,15);
    cargarCadena(_nombre, 29);
    system("cls");
    dibujarCuadro(50,14,85,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE APELLIDO: ";
    rlutil::locate(73,15);
    cargarCadena(_apellido, 29);
    system("cls");
    dibujarCuadro(40,14,85,19);
    rlutil::locate(44,15);
    std::cout<<"INGRESE FECHA DE NACIMIENTO: DD/MM/AAAA";
    _nacimiento.Cargar();
    system("cls");
    dibujarCuadro(50,14,70,16);
    rlutil::locate(54,15);
    std::cout << "DNI: ";
    std::cin >> _dni;
    system("cls");
    _estado = true;
}
void Persona::Mostrar(int i)
{
    int y;
    if(_estado==true)
    {
        y=3+i;
        dibujarSubrayado(1,2,114);
        rlutil::locate(1, 1);
        std::cout << "ID";
        rlutil::locate(1, y);
        std::cout<<_id;
        rlutil::locate(5, 1);
        std::cout << "NOMBRE";
        rlutil::locate(5, y);
        std::cout<<_nombre;
        rlutil::locate(15, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(15, y);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, y);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, y);
        std::cout<<_dni;
    }
}

void Persona::MostrarTecnico(int i)
{
    int y=3+i;
    if(_estado==true)
    {
        y=3+i;
        dibujarSubrayado(1,2,73);
        rlutil::locate(2, 1);
        std::cout << "NOMBRE";
        rlutil::locate(2, y);
        std::cout<<_nombre;
        rlutil::locate(13, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(13, y);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, y);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, y);
        std::cout<<_dni;
    }
}

void Persona::MostrarTecnico(int i, int y)
{

    if(_estado==true)
    {

        dibujarSubrayado(1,2,73);
        rlutil::locate(2, 1);
        std::cout << "NOMBRE";
        rlutil::locate(2, y);
        std::cout<<_nombre;
        rlutil::locate(13, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(13, y);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, y);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, y);
        std::cout<<_dni;
    }
}

void Persona::MostrarTecnico()
{

    if(_estado==true)
    {

        dibujarSubrayado(1,2,73);
        rlutil::locate(2, 1);
        std::cout << "NOMBRE";
        rlutil::locate(2, 3);
        std::cout<<_nombre;
        rlutil::locate(13, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(13, 3);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, 3);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, 3);
        std::cout<<_dni;
    }
}

void Persona::Mostrar()
{

    if(_estado)
    {
        dibujarTabla(44,4,83,27,2);
        rlutil::locate(61, 5);
        std::cout<<"CLIENTE";
        rlutil::locate(49, 7);
        std::cout << "ID:";
        rlutil::locate(64, 7);
        std::cout<<"#"<<_id;
        rlutil::locate(49, 9);
        std::cout << "NOMBRE:";
        rlutil::locate(64, 9);
        std::cout<<_nombre;
        rlutil::locate(49, 11);
        std::cout << "APELLIDO:" ;
        rlutil::locate(64, 11);
        std::cout<<_apellido;
        rlutil::locate(49, 13);
        std::cout << "FECHA NAC:";
        rlutil::locate(64, 13);
        _nacimiento.Mostrar();
        std::cout<<std::endl;
        rlutil::locate(49, 15);
        std::cout << "DNI";
        rlutil::locate(64, 15);
        std::cout<<_dni << std::endl;
    }
}

void Persona::MostrarBaja()
{

    dibujarTabla(44,4,84,27,2);
    rlutil::locate(61, 5);
    std::cout<<"CLIENTE";
    rlutil::locate(49, 7);
    std::cout << "ID:";
    rlutil::locate(64, 7);
    std::cout<<"#"<<_id;
    rlutil::locate(49, 9);
    std::cout << "NOMBRE:";
    rlutil::locate(64, 9);
    std::cout<<_nombre;
    rlutil::locate(49, 11);
    std::cout << "APELLIDO:" ;
    rlutil::locate(64, 11);
    std::cout<<_apellido;
    rlutil::locate(49, 13);
    std::cout << "FECHA NAC:";
    rlutil::locate(64, 13);
    _nacimiento.Mostrar();
    std::cout<<std::endl;
    rlutil::locate(49, 15);
    std::cout << "DNI";
    rlutil::locate(64, 15);
    std::cout<<_dni << std::endl;
}
void Persona::MostrarBajaTecnico()
{
        dibujarSubrayado(1,2,73);
        rlutil::locate(2, 1);
        std::cout << "NOMBRE";
        rlutil::locate(2, 3);
        std::cout<<_nombre;
        rlutil::locate(13, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(13, 3);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, 3);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, 3);
        std::cout<<_dni;
}
void Persona::CargarReparacion()
{
    _id=_idContador++;
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE NOMBRE: ";
    rlutil::locate(70,15);
    cargarCadena(_nombre, 29);
    system("cls");
    dibujarCuadro(50,14,85,16);
    rlutil::locate(54,15);
    std::cout<<"INGRESE APELLIDO: ";
    rlutil::locate(73,15);
    cargarCadena(_apellido, 29);
    system("cls");
    dibujarCuadro(40,14,85,19);
    rlutil::locate(44,15);
    std::cout<<"INGRESE FECHA DE NACIMIENTO: DD/MM/AAAA";
    _nacimiento.Cargar();
    system("cls");
    dibujarCuadro(50,14,70,16);
    rlutil::locate(54,15);
    std::cout << "DNI: ";
    std::cin >> _dni;
    system("cls");
    _estado = true;
}
void Persona::MostrarReparacion()
{

    if(_estado)
    {
        dibujarTabla(5,1,114,27,10);
        rlutil::locate(13, 2);
        std::cout << "ID CLIENTE:";
        rlutil::locate(26, 2);
        std::cout<<"#"<<_id;
        rlutil::locate(13, 4);
        std::cout << "NOMBRE:";
        rlutil::locate(26, 4);
        std::cout<<_nombre;
        rlutil::locate(13, 6);
        std::cout << "APELLIDO:" ;
        rlutil::locate(26, 6);
        std::cout<<_apellido;
        rlutil::locate(13, 10);
        std::cout << "FECHA NAC:";
        rlutil::locate(26, 10);
        _nacimiento.Mostrar();
        std::cout<<std::endl;
        rlutil::locate(13, 8);
        std::cout << "DNI:";
        rlutil::locate(26, 8);
        std::cout<<_dni << std::endl;
    }
}

void Persona::MostrarReparacionBaja()
{

    dibujarTabla(5,1,114,27,10);
    rlutil::locate(13, 2);
    std::cout << "ID CLIENTE:";
    rlutil::locate(26, 2);
    std::cout<<"#"<<_id;
    rlutil::locate(13, 4);
    std::cout << "NOMBRE:";
    rlutil::locate(26, 4);
    std::cout<<_nombre;
    rlutil::locate(13, 6);
    std::cout << "APELLIDO:" ;
    rlutil::locate(26, 6);
    std::cout<<_apellido;
    rlutil::locate(13, 10);
    std::cout << "FECHA NAC:";
    rlutil::locate(26, 10);
    _nacimiento.Mostrar();
    std::cout<<std::endl;
    rlutil::locate(13, 8);
    std::cout << "DNI:";
    rlutil::locate(26, 8);
    std::cout<<_dni << std::endl;

}

void Persona::MostrarReparacion(int i)
{
    int y = 3 + (i * 4);
    rlutil::locate(14, y);
    std::cout << "CLIENTE:";
    rlutil::locate(22, y);
    std::cout <<"#"<< _id;
}

void Persona::Mostrar(int i, int y) {

    if(_estado==true){
        rlutil::locate(1, 1);
        std::cout << "ID";
        rlutil::locate(1, y);
        std::cout<<_id;
        rlutil::locate(5, 1);
        std::cout << "NOMBRE";
        rlutil::locate(5, y);
        std::cout<<_nombre;
        rlutil::locate(15, 1);
        std::cout << "APELLIDO" ;
        rlutil::locate(15, y);
        std::cout<<_apellido;
        rlutil::locate(28, 1);
        std::cout << "FECHA NAC.";
        rlutil::locate(28, y);
        _nacimiento.Mostrar();
        rlutil::locate(43, 1);
        std::cout << "DNI";
        rlutil::locate(41, y);

         std::cout<<_dni;
        }
}


