#include "Persona.h"
#include "Funciones.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>


Persona::Persona(){
_id=0;
strcpy(_nombre, " ");
strcpy(_apellido, " ");
_dni=0;
_estado=false;
}

int Persona:: getId(){return _id;}
const char* Persona::getNombre(){return _nombre;}
const char* Persona::getApellido(){return _apellido;}
Fecha Persona::getNacimiento(){return _nacimiento;}
int Persona::getDni(){return _dni;}
bool Persona::getEstado(){return _estado;}

void Persona::setId(int id){_id=id;}
void Persona::setNombre(const char* nombre){strcpy(_nombre, nombre);}
void Persona::setApellido(const char* apellido){strcpy(_apellido, apellido);}
void Persona::setFecha(Fecha nacimiento){_nacimiento=nacimiento;}
void Persona::setDni(int dni){_dni=dni;}
void Persona::setEstado(bool estado){_estado=estado;}

void Persona::Cargar(){
    std::cout << "Ingrese ID: ";
    std::cin >> _id;
    std::cout << "Nombre: ";
    cargarCadena(_nombre, 29);
    std::cout << "Apellido: ";
    cargarCadena(_apellido, 29);
    std::cout << "Fecha de nacimiento: ";
    _nacimiento.Cargar();
    std::cout << "Dni: ";
    std::cin >> _dni;
    _estado = true;
}
void Persona::Mostrar(int i) {
    int y=3+i;
    if(_estado==true){
        rlutil::locate(2, 1);
        std::cout << "ID";
        rlutil::locate(2, y);
        std::cout<<_id;
        rlutil::locate(5, 1);
        std::cout << "Nombre";
        rlutil::locate(5, y);
        std::cout<<_nombre;
        rlutil::locate(15, 1);
        std::cout << "Apellido" ;
        rlutil::locate(15, y);
        std::cout<<_apellido;
        rlutil::locate(25, 1);
        std::cout << "Fecha Nacimiento";
        rlutil::locate(28, y);
        _nacimiento.Mostrar();
        rlutil::locate(46, 1);
        std::cout << "DNI";
        rlutil::locate(44, y);
         std::cout<<_dni;
        }
    }


void Persona::Mostrar() {

    if(_estado==true){
        rlutil::locate(1, 8);
        std::cout << "ID";
        rlutil::locate(1, 10);
        std::cout<<_id;
        rlutil::locate(5, 8);
        std::cout << "Nombre";
        rlutil::locate(5, 10);
        std::cout<<_nombre;
        rlutil::locate(15, 8);
        std::cout << "Apellido" ;
        rlutil::locate(15, 10);
        std::cout<<_apellido;
        rlutil::locate(25, 8);
        std::cout << "Fecha Nacimiento";
        rlutil::locate(28, 10);
        _nacimiento.Mostrar();
        rlutil::locate(46, 8);
        std::cout << "DNI";
        rlutil::locate(43, 10);
        std::cout<<_dni;
        }
    }
