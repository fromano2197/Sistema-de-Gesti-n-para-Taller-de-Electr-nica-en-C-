#pragma once
#include "Fecha.h"

void cargarCadena(char *palabra, int tamano);
void cargarContrasena(char* cadena, int longitud);
void dibujarCuadro(int x1, int y1, int x2, int y2);
void dibujarSubrayado(int x1, int y1, int x2);
void dibujarTabla(int x1, int y1, int x2, int y2, int alturaFila1);
void gestionarClientes();
void ReparacionesCSV();
void ReparacionesPorStatusCSV(int status);
void ReparacionesPorTecnicoCSV(int numeroTecnico);
void ReparacionesDesdeFechaCSV(const Fecha& fechaEntrada);
void ClientesCSV();
void ClientesOrdenadoPorApellidoCSV();
void ClientesOrdenadoPorNombreCSV();
void RefaccionPorTipoCSV();
void RefaccionesOrdenadasPorArticuloCSV();
void RefaccionesOrdenadasPorMarcaCSV();
void ExportarInventarioCSV();
void ExportarTecnicosCSV();
void ExportarTecnicosPorOrdenDeNumCSV();
void generarReporteRecaudacion();
void generarReporteRecaudacionDiaria();
void informeOrdenesPendientes();

