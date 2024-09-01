#pragma once
#include "Persona.h"
#include "Contacto.h"
class Cliente: public Persona{
    protected:
        Contacto _datos;
        bool _estado;
    public:
        Contacto& getDatos();
        bool getEstado();

        void setDatos(Contacto contacto);
        void setEstado(bool estado);
        void setCalle(const char* calle);
        void Cargar();
        void CargarReparacion();
        void Mostrar();
        void MostrarReparacion();
        void Mostrar(int i);
        void MostrarBaja();
        void MostrarReparacion(int i);
        void MostrarReparacionBaja();
        void Mostrar(int i, int y);

};
