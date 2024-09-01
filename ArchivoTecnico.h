#pragma once
#include <cstring>
#include "Tecnico.h"

class archivoTecnico {
private:
     char _nombre[30];
public:
    archivoTecnico (const char *n="tecnicos.dat"){strcpy(_nombre,n);}
    bool grabarRegistro (Tecnico obj);
    Tecnico leerRegistro(int pos);
    int buscarRegistro (int num);
    int contarRegistro ();
    bool modificarRegistro (Tecnico obj, int pos);
    void listarRegistro ();
    void altaTecnico();
    bool listarPorNumTecnico();
    bool listarPorNombre();
    bool listarPorApellido();
    void listarPorDNI();
    int buscarRegistroPorDni (int dni);
    void modificarTecnico();
    void modificarCampoTecnico();
    void eliminarTecnico();
    void reactivarTecnico();
    void hacerRespaldoTecnicos();
    void restaurarTecnicosDesdeBackup();



};
