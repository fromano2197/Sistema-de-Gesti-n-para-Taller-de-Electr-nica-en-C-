#pragma once


class Articulo
{
private:
    static int _idArtContador;
    int _idArticulo;
    int _sku;
    char _articulo [30];
    char _marca [30];
    char _modelo [30];
    int _numSerie;
    int _tipoArticulo;
    bool _estado;
public:

    int getIdArticulo() const;
    int getSku() const;
    const char* getArticulo() const;
    const char* getMarca() const;
    const char* getModelo() const;
    int getSerie() const;
    int getTipoArticulo() const;
    bool getEstado() const;

    void setIdArticulo(int idArticulo);
    void setSku(int sku);
    void setArticulo(const char* articulo);
    void setMarca(const char* marca);
    void setModelo(const char* modelo);
    void setSerie(int serie);
    void setTipoArticulo(int tipoArticulo);
    void setEstado(bool estado);
    void Cargar();
    void CargarRefaccion();
    void CargarReparacion();
    void Mostrar();
    void Mostrar(int i);
    void Mostrar(int i, int y);
    void MostrarRefaccion();
    void MostrarReparacion();
    void MostrarRefaccion(int i);
    void MostrarReparacion(int i);
};


