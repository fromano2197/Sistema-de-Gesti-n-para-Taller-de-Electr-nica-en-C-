#pragma once
#include "Persona.h"

class Tecnico: public Persona{
    protected:
        int _numTecnico;
        bool _estado;
    public:
        int getNumTecnico();
        bool getEstado();

        void setNumTecnico(int numTecnico);
        void setEstado(bool estado);

        void Cargar();
        void Mostrar(int i);
        void MostrarTecnico(int i, int y);
        void Mostrar();
        void MostrarTecnico();
        void MostrarBajaTecnico();
};
