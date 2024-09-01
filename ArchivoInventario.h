#pragma once
#include <cstring>
#include "Inventario.h"

class archivoInventario {
private:
     char _nombre[30];
public:
    archivoInventario (const char *n="inventarios.dat"){strcpy(_nombre,n);}
    bool grabarRegistro (Inventario obj);
    Inventario leerRegistro(int pos);
    void altaInventario();
    int buscarRegistro (int num);
    int contarRegistro ();
    bool modificarRegistro (Inventario obj, int pos);
    int leerUltimoIdRefaccion();
    void guardarUltimoIdRefaccion(int ultimoID);
    void listarRegistro ();
    void buscarIdArticulo();
    void listarPorTipo();
    void buscarSerie();
    void eliminarRefaccion();
    void modificarRefaccion();
    void hacerRespaldoRefacciones();
    void restaurarRefaccionesDesdeBackup();

};
