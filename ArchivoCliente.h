#pragma once
#include <cstring>
#include "Cliente.h"

class archivoCliente {
private:
     char _nombre[30];
public:

    archivoCliente (const char *n="clientes.dat"){strcpy(_nombre,n);}
    bool grabarRegistro (Cliente obj);
    void altaCliente();
    Cliente leerRegistro(int pos);
    int buscarRegistro (int num);
    int buscarRegistroPorDni (int dni);
    int contarRegistro ();
    bool modificarRegistro (Cliente obj, int pos);
    void listarRegistro ();
    bool listarPorID();
    bool listarPorNombre();
    bool listarPorApellido();
    void listarPorDNI();
    void modificarCliente();
    void modificarCampoCliente();
    void eliminarCliente();
    void reactivarCliente();
    int leerUltimoIdCliente();
    void guardarUltimoIdCliente(int ultimoID);
    void hacerRespaldoCliente();
    void restaurarClientesDesdeBackup();

};
