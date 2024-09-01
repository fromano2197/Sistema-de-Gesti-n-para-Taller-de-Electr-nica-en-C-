#pragma once
#include <cstring>
#include "Reparacion.h"

class archivoReparacion {
private:
     char _nombre[30];
public:
    archivoReparacion (const char *n="reparaciones.dat"){strcpy(_nombre,n);}
    bool grabarRegistro (Reparacion obj);
    Reparacion leerRegistro(int pos);
    int buscarRegistro (int num);
    int contarRegistro ();
    bool modificarRegistro (Reparacion obj, int pos);
    bool listarRegistro ();
    void altaReparacion();
    int leerUltimOrden();
    void guardarUltimOrden(int ultimaOrden);
    int leerUltimoIdCliente();
    void guardarUltimoIdCliente(int ultimoID);
    bool buscarOrden();
    void listarPorTecnico();
    void listarPorStatus();
    void listarPorFecha();
    void listarPorFechaSalida();
    void modificarCampoReparacion();
    void salidaOrden();
    void eliminarReparacion();
    void reactivarReparacion();
    float calcularRecaudacionEntreFechas(Fecha fechaInicio, Fecha fechaFin);
    float calcularRecaudacionDelDia();
    void hacerRespaldoReparaciones();
    void restaurarReparacionesDesdeBackup();
    int contarReparacionesPendientes();
};

