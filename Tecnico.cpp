#include <iostream>
#include "Funciones.h"
#include "rlutil.h"
#include "Tecnico.h"

int Tecnico::getNumTecnico(){return _numTecnico;}
bool Tecnico::getEstado(){return _estado;}

void Tecnico::setNumTecnico(int numTecnico){_numTecnico=numTecnico;}
void Tecnico::setEstado(bool estado){_estado=estado;}

void Tecnico::Cargar(){
    Persona::CargarTecnico();
    dibujarCuadro(50,14,80,16);
    rlutil::locate(54,15);
    std::cout<<"Numero de tecnico: ";
    std::cin>>_numTecnico;
    system("cls");

    _estado=true;
}
void Tecnico::Mostrar(int i){
    int y=3+i;
    if (_estado==true){
    rlutil::locate(55, 1);
    std::cout << "NUMERO DE TECNICO";
    rlutil::locate(62, y);
    std::cout<<_numTecnico;
    Persona::MostrarTecnico(i);
    }
}
void Tecnico::MostrarTecnico(int i, int y){

    if (_estado==true){
    rlutil::locate(55, 1);
    std::cout << "NUMERO DE TECNICO";
    rlutil::locate(62, y);
    std::cout<<_numTecnico;
    Persona::MostrarTecnico(i,y);
    }
}

void Tecnico::Mostrar(){
    if (_estado==true){
    rlutil::locate(55, 1);
    std::cout << "NUMERO DE TECNICO";
    rlutil::locate(62, 3);
    std::cout<<_numTecnico;
    Persona::MostrarTecnico();
    }
}
void Tecnico::MostrarBajaTecnico(){
    if (_estado==false){
    rlutil::locate(55, 1);
    std::cout << "NUMERO DE TECNICO";
    rlutil::locate(62, 3);
    std::cout<<_numTecnico;
    Persona::MostrarTecnico();
    }
}
void Tecnico::MostrarTecnico(){
    if (_estado==true){
    rlutil::locate(55, 1);
    std::cout << "NUMERO DE TECNICO";
    rlutil::locate(62, 3);
    std::cout<<_numTecnico;
    Persona::MostrarTecnico();
    }
}
