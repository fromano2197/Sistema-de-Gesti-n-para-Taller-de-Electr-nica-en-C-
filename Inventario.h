#pragma once
#include "Articulo.h"
class Inventario {
private:
    Articulo _articulo;
    int _existencia;
    bool _estado;
public:
    Articulo getArticulo();
    int getExistencia();
    bool getEstado();
    void setEstado(bool estado);
    void setArticulo (Articulo idArticulo);
    void setExistencia (int existencia);
    void setArticuloId(int id) ;
    void setSku(int sku) ;
    void setArticulo (const char* articulo);
    void setMarca (const char* marca);
    void setModelo (const char* modelo);
    void setTipo(int tipo) ;



    void Cargar();
    void Mostrar();
    void Mostrar(int i);
    void Mostrar(int i,int y);

};

