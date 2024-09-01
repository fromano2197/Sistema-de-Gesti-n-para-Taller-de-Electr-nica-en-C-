#pragma once
#include "Cliente.h"

class Menu{
private:

public:

void mostrarMenu();
void seleccionarItem(const char* text, int posx, int posy, bool selected);
void gestionarClientes();
void gestionarRefaccion();
void gestionarReparaciones();
void gestionarConsultas();
void gestionarTecnicos();
void gestionarReportes();
void gestionarInformes();
void gestionarRespaldos();
void consultaClientes();
void consultaRefacciones();
void consultaReparaciones();
void consultaTecnicos();
void reporteClientes();
void reporteRefacciones() ;
void reporteReparaciones();
void reporteTecnicos();
void opcionesModificarCliente(Cliente cliente);
};
