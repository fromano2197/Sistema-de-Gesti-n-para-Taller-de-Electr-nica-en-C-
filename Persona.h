#pragma once
#include "Fecha.h"

class Persona{
protected:
    static int _idContador;
    int _id;
    char _nombre[30];
    char _apellido[30];
    Fecha _nacimiento;
    int _dni;
    bool _estado;
public:
    Persona();

    int getId();
    const char* getNombre();
    const char* getApellido();
    Fecha getNacimiento();
    int getDni();
    bool getEstado();

    void setId(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setFecha(Fecha nacimiento);
    void setDni(int dni);
    void setEstado(bool estado);


    void Cargar();
    void CargarReparacion();
    void CargarTecnico();
    void Mostrar();
    void Mostrar(int i);
    void MostrarBaja();
    void MostrarBajaTecnico();
    void MostrarReparacion();
    void MostrarReparacion(int i);
    void MostrarTecnico(int i);
    void MostrarTecnico(int i, int y);
    void MostrarTecnico();
    void MostrarReparacionBaja();
    void Mostrar(int i, int y);

};
