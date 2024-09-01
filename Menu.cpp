
#include <iostream>
#include "Menu.h"
#include "rlutil.h"
#include "Funciones.h"
#include "ArchivoCliente.h"
#include "ArchivoInventario.h"
#include "ArchivoReparacion.h"
#include "ArchivoTecnico.h"

void Menu::seleccionarItem(const char* text, int posx, int posy, bool seleccionado) {
    if(seleccionado) {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::CYAN);
    }
    else {
        rlutil::setColor(rlutil::CYAN);
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
    rlutil::locate(posx, posy);
    std::cout << text;
    rlutil::setColor(rlutil::CYAN);
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Menu::mostrarMenu() {
    dibujarCuadro(1, 1, 119, 30);
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        seleccionarItem("CLIENTES", 48, 11, y == 0);
        seleccionarItem("REFACCIONES", 48, 12, y == 1);
        seleccionarItem("REPARACIONES", 48, 13, y == 2);
        seleccionarItem("TECNICOS", 48, 14, y == 3);
        seleccionarItem("REPORTES", 48, 15, y == 4);
        seleccionarItem("INFORMES", 48, 16, y == 5);
        seleccionarItem("RESPALDOS", 48, 17, y == 6);
        seleccionarItem("SALIR", 48, 18, y == 7);
        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 7;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 7) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                     case 0:
                        rlutil::cls();
                        gestionarClientes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        gestionarRefaccion();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 2:
                        rlutil::cls();
                        gestionarReparaciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 3:
                        rlutil::cls();
                        gestionarTecnicos();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 4:
                        rlutil::cls();
                        gestionarReportes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 5:
                        rlutil::cls();
                        gestionarInformes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 6:
                        rlutil::cls();
                        gestionarRespaldos();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 7:

                        rlutil::locate(48, 19);
                        std::cout<<"Quiere salir del sistema? (S/N):  ";
                        char op;
                        std::cin>>op;
                        if(op=='S' || op=='s'){
                           opcion = 0;
                        }
                        else {
                            rlutil::cls();
                            dibujarCuadro(1, 1, 119, 30);
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}



void Menu::gestionarClientes() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoCliente arch;
    int id;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTAS DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("AGREGAR CLIENTE", 48, 12, y == 1);
        seleccionarItem("MODIFICAR CLIENTE", 48, 13, y == 2);
        seleccionarItem("ELIMINAR CLIENTE", 48, 14, y == 3);
        seleccionarItem("REACTIVAR CLIENTE", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 5;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 5) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        consultaClientes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        arch.altaCliente();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.modificarCampoCliente();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.eliminarCliente();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 4:
                        rlutil::cls();
                        arch.reactivarCliente();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 5:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}


void Menu::gestionarRefaccion() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoInventario arch;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTAS DE REFACCIONES", 48, 11, y == 0);
        seleccionarItem("AGREGAR REFACCION AL INVENTARIO", 48, 12, y == 1);
        seleccionarItem("MODIFICAR REFACCION", 48, 13, y == 2);
        seleccionarItem("ELIMINAR REFACCION DEL INVENTARIO", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 4;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 4) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        consultaRefacciones();
                        rlutil::cls();
                        dibujarCuadro(1,1,119,30);
                        break;
                    case 1:
                        rlutil::cls();
                        arch.altaInventario();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.modificarRefaccion();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.eliminarRefaccion();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 4:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::gestionarReparaciones() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoReparacion arch;
    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTAS DE REPARACION", 48, 11, y == 0);
        seleccionarItem("REGISTRAR ORDEN DE REPARACION", 48, 12, y == 1);
        seleccionarItem("ACTUALIZAR/MODIFICAR REPARACION", 48, 13, y == 2);
        seleccionarItem("ENTREGA DE ORDEN", 48, 14, y == 3);
        seleccionarItem("ELIMINAR REPARACION", 48, 15, y == 4);
        seleccionarItem("REACTIVAR ORDEN DE REPARACION", 48, 16, y == 5);
        seleccionarItem("VOLVER", 48, 17, y == 6);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 6;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 6) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        consultaReparaciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        arch.altaReparacion();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 2:
                        rlutil::cls();
                        arch.modificarCampoReparacion();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 3:
                        rlutil::cls();
                        arch.salidaOrden();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 4:
                        rlutil::cls();
                        arch.eliminarReparacion();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 5:
                        rlutil::cls();
                        arch.reactivarReparacion();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 6:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}


void Menu::gestionarTecnicos() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoTecnico arch;
    int id;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTAS DE TECNICOS", 48, 11, y == 0);
        seleccionarItem("AGREGAR TECNICO", 48, 12, y == 1);
        seleccionarItem("MODIFICAR TECNICO", 48, 13, y == 2);
        seleccionarItem("ELIMINAR TECNICO", 48, 14, y == 3);
        seleccionarItem("REACTIVAR TECNICO", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 5;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 5) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        consultaTecnicos();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        arch.altaTecnico();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.modificarCampoTecnico();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.eliminarTecnico();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 4:
                        rlutil::cls();
                        arch.reactivarTecnico();
                        rlutil::cls();
                        rlutil::anykey();
                        break;
                    case 5:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}




void Menu::gestionarReportes() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("GENERAR REPORTE DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("GENERAR REPORTE DE REFACCIONES", 48, 12, y == 1);
        seleccionarItem("GENERAR REPORTE DE REPARACIONES", 48, 13, y == 2);
        seleccionarItem("GENERAR REPORTE DE TECNICOS", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 4;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 4) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        reporteClientes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        reporteRefacciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 2:
                        rlutil::cls();
                        reporteReparaciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 3:
                        rlutil::cls();
                        reporteTecnicos();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 4:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}


void Menu::gestionarRespaldos() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoCliente archiCli;
    archivoReparacion archiRep;
    archivoInventario archiInv;
    archivoTecnico archiTec;
    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("REALIZAR BACKUP DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("REALIZAR BACKUP DE REPARACIONES", 48, 12, y == 1);
        seleccionarItem("REALIZAR BACKUP DE REFACCIONES", 48, 13, y == 2);
        seleccionarItem("REALIZAR BACKUP DE TECNICOS", 48, 14, y == 3);
        seleccionarItem("RESTAURAR BACKUP DE CLIENTES", 48, 15, y == 4);
        seleccionarItem("RESTAURAR BACKUP DE REPARACIONES", 48, 16, y == 5);
        seleccionarItem("RESTAURAR BACKUP DE REFACCIONES", 48, 17, y == 6);
        seleccionarItem("RESTAURAR BACKUP DE TECNICOS", 48, 18, y == 7);
        seleccionarItem("VOLVER", 48, 19, y == 8);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 8;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 8) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        archiCli.hacerRespaldoCliente();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 1:
                        rlutil::cls();
                        archiRep.hacerRespaldoReparaciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 2:
                        rlutil::cls();
                        archiInv.hacerRespaldoRefacciones();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 3:
                        rlutil::cls();
                        archiTec.hacerRespaldoTecnicos();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 4:
                        rlutil::cls();
                        archiCli.restaurarClientesDesdeBackup();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 5:
                        rlutil::cls();
                        archiRep.restaurarReparacionesDesdeBackup();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 6:
                        rlutil::cls();
                        archiInv.restaurarRefaccionesDesdeBackup();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 7:
                        rlutil::cls();
                        archiTec.restaurarTecnicosDesdeBackup();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    case 8:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::gestionarInformes() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("RECAUDACION HISTORICA", 48, 11, y == 0);
        seleccionarItem("RECAUDACION DEL DIA", 48, 12, y == 1);
        seleccionarItem("CANTIDAD DE REPARACIONES PENDIENTES DE REVISION", 48, 13, y == 2);
        seleccionarItem("VOLVER", 48, 14, y == 3);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 3;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 3) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        {
                        rlutil::cls();
                        generarReporteRecaudacion();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                        }
                    case 1:
                        {
                        rlutil::cls();
                        generarReporteRecaudacionDiaria();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                        }
                   case 2:
                        {
                        rlutil::cls();
                        informeOrdenesPendientes();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                        }
                    case 3:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::consultaClientes() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoCliente arch;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("LISTADO DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR NUMERO DE CLIENTE", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR NOMBRE", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR APELLIDO", 48, 14, y == 3);
        seleccionarItem("BUSCAR POR DNI", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 5;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 5) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        arch.listarRegistro();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        arch.listarPorID();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.listarPorNombre();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.listarPorApellido();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 4:
                        rlutil::cls();
                        arch.listarPorDNI();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 5:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::consultaTecnicos() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoTecnico arch;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("LISTADO DE TECNICOS", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR NUMERO DE TECNICO", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR NOMBRE", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR APELLIDO", 48, 14, y == 3);
        seleccionarItem("BUSCAR POR DNI", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 5;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 5) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        arch.listarRegistro();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        arch.listarPorNumTecnico();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.listarPorNombre();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.listarPorApellido();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 4:
                        rlutil::cls();
                        arch.listarPorDNI();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 5:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::consultaRefacciones() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoInventario archi;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("LISTADO DE REPUESTOS", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR ID DE ARTICULO", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR TIPO DE ARTICULO", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR NUMERO DE SERIE", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 4;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 4) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        archi.listarRegistro();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        archi.buscarIdArticulo();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        archi.listarPorTipo();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        rlutil::cls();
                        archi.buscarSerie();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 4:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::consultaReparaciones() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoReparacion arch;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("LISTADO DE REPARACIONES", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR ORDEN DE REPARACION", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR TECNICO ASIGNADO", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR STATUS", 48, 14, y == 3);
        seleccionarItem("BUSCAR POR FECHA DE ENTRADA", 48, 15, y == 4);
        seleccionarItem("BUSCAR POR FECHA DE SALIDA", 48, 16, y == 5);
        seleccionarItem("VOLVER", 48, 17, y == 6);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 6;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 6) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        arch.listarRegistro();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        arch.buscarOrden();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        arch.listarPorTecnico();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        rlutil::cls();
                        arch.listarPorStatus();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 4:
                        rlutil::cls();
                        arch.listarPorFecha();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 5:
                        rlutil::cls();
                        arch.listarPorFechaSalida();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 6:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}


void Menu::reporteClientes() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("EXPORTAR CLIENTES", 48, 11, y == 0);
        seleccionarItem("EXPORTAR POR APELLIDO", 48, 12, y == 1);
        seleccionarItem("EXPORTAR POR NOMBRE", 48, 13, y == 2);
        seleccionarItem("VOLVER", 48, 14, y == 3);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 3;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 3) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        ClientesCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        ClientesOrdenadoPorApellidoCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        ClientesOrdenadoPorNombreCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::reporteRefacciones() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("EXPORTAR REFACCIONES", 48, 11, y == 0);
        seleccionarItem("EXPORTAR POR TIPO DE REFACCION", 48, 12, y == 1);
        seleccionarItem("EXPORTAR ORDENADO POR DESCRIPCION DE REFACCION", 48, 13, y == 2);
        seleccionarItem("EXPORTAR ORDENADO POR MARCA", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 4;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 4) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        ExportarInventarioCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        RefaccionPorTipoCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        RefaccionesOrdenadasPorArticuloCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:
                        rlutil::cls();
                        RefaccionesOrdenadasPorMarcaCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 4:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::reporteReparaciones() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoReparacion arch;

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("EXPORTAR POR NUMERO DE ORDEN", 48, 11, y == 0);
        seleccionarItem("EXPORTAR POR STATUS DE REPARACION", 48, 12, y == 1);
        seleccionarItem("EXPORTAR POR TECNICO ASIGNADO", 48, 13, y == 2);
        seleccionarItem("EXPORTAR POR FECHA DE INGRESO", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 4;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 4) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        ReparacionesCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        int status;
                        dibujarCuadro(41,14,79,16);
                        rlutil::locate(44,15);
                        std::cout<<"INGRESE EL STATUS A BUSCAR:";
                        rlutil::locate(73,15);
                        std::cin>>status;
                        ReparacionesPorStatusCSV(status);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        rlutil::cls();
                        int tec;
                        dibujarCuadro(41,14,85,16);
                        rlutil::locate(44,15);
                        std::cout<<"INGRESE NUMERO DE TECNICO A BUSCAR: ";
                        rlutil::locate(80,15);
                        std::cin>>tec;
                        ReparacionesPorTecnicoCSV(tec);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 3:{
                        rlutil::cls();
                        Fecha f;
                        dibujarCuadro(33,11,77,13);
                        rlutil::locate(36,12);
                        std::cout<<"INGRESE FECHA DESDE DONDE DESEA BUSCAR";
                        f.Cargar();
                        ReparacionesDesdeFechaCSV(f);
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                        }
                    case 4:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}

void Menu::reporteTecnicos() {
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("EXPORTAR TECNICOS", 48, 11, y == 0);
        seleccionarItem("EXPORTAR ORDENADOS POR NUMERO DE TECNICO", 48, 12, y == 1);
        seleccionarItem("VOLVER", 48, 13, y == 2);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if(y < 0) {
                    y = 2;
                }
                break;
            case 15:
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if(y > 2) {
                    y = 0;
                }
                break;
            case 1:
                switch(y) {
                    case 0:
                        rlutil::cls();
                        ExportarTecnicosCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 1:
                        rlutil::cls();
                        ExportarTecnicosPorOrdenDeNumCSV();
                        rlutil::anykey();
                        rlutil::cls();
                        break;
                    case 2:
                        opcion = 0;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    } while(opcion != 0);
}
