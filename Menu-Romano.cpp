#include <iostream>
#include "Cliente.h"
#include "Menu.h"
#include "rlutil.h"
#include "Funciones.h"
#include "ArchivoCliente.h"
#include "ArchivoInventario.h"

void Menu::seleccionarItem(const char* text, int posx, int posy, bool seleccionado)
{
    if(seleccionado)
    {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::CYAN);
    }
    else
    {
        rlutil::setColor(rlutil::CYAN);
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
    rlutil::locate(posx, posy);
    std::cout << text;
    rlutil::setColor(rlutil::CYAN);
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Menu::mostrarMenu()
{
    dibujarCuadro(1, 1, 119, 30); // Cuadro grande
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        // Dibujar todas las opciones del menú
        seleccionarItem("GESTION DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("GESTION DE INVENTARIO DE REFACCIONES", 48, 12, y == 1);
        seleccionarItem("GESTION DE REPARACIONES", 48, 13, y == 2);
        seleccionarItem("CONSULTAS", 48, 14, y == 3);
        seleccionarItem("REPORTES", 48, 15, y == 4);
        seleccionarItem("GESTIONAR RESPALDOS", 48, 16, y == 5);
        seleccionarItem("SALIR", 48, 17, y == 6);
        // Dibujar el indicador en la posición actual
        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            // Borrar el indicador de la posición actual
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 6;
            }
            break;
        case 15: // Flecha abajo
            // Borrar el indicador de la posición actual
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 6)
            {
                y = 0;
            }
            break;
        case 1: // Enter
            switch(y)
            {
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
                gestionarConsultas();
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
                gestionarRespaldos();
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                break;
            case 6:

                rlutil::locate(48, 19);
                std::cout<<"Quiere salir del sistema? (S/N):  ";
                char op;
                std::cin>>op;
                if(op=='S' || op=='s')
                {
                    opcion = 0;
                }
                else
                {
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

    }
    while(opcion != 0);
}



void Menu::gestionarClientes()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoCliente arch;
    int id;

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTAS DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("AGREGAR CLIENTE", 48, 12, y == 1);
        seleccionarItem("MODIFICAR CLIENTE", 48, 13, y == 2);
        seleccionarItem("ELIMINAR CLIENTE", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 4;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 0;
            }
            break;
        case 1: // Enter
            switch(y)
            {
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
                arch.modificarCliente();
                rlutil::cls();
                rlutil::anykey();
                break;
            case 3:
                // Implementar lógica para eliminar cliente
                std::cout << "Eliminar Cliente" << std::endl;
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

    }
    while(opcion != 0);
}


void Menu::gestionarRefaccion()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoInventario arch;

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("AGREGAR REFACCION AL INVENTARIO", 48, 11, y == 0);
        seleccionarItem("BUSCAR REFACCION", 48, 12, y == 1);
        seleccionarItem("MODIFICAR REFACCION", 48, 13, y == 2);
        seleccionarItem("ELIMINAR REFACCION DEL INVENTARIO", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                arch.altaInventario();
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                // Implementar lógica para modificar cliente
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                // Implementar lógica para eliminar cliente
                std::cout << "Modificar REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 3:
                // Implementar lógica para eliminar cliente
                std::cout << "Eliminar REFACCION" << std::endl;
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

    }
    while(opcion != 0);
}

void Menu::gestionarReparaciones()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("REGISTRAR ORDEN DE REPARACION", 48, 11, y == 0);
        seleccionarItem("BUSCAR ORDEN DE REPARACION", 48, 12, y == 1);
        seleccionarItem("ACTUALIZAR STATUS DE REPARACION", 48, 13, y == 2);
        seleccionarItem("MODIFICAR ORDEN DE REPARACION", 48, 14, y == 3);
        seleccionarItem("ELIMINAR REPARACION", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 5)
            {
                y = 5;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                // Implementar lógica para modificar cliente
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                // Implementar lógica para eliminar cliente
                std::cout << "Modificar REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 3:
                // Implementar lógica para eliminar cliente
                std::cout << "Eliminar REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 4:
                // Implementar lógica para eliminar cliente
                std::cout << "Eliminar REFACCION" << std::endl;
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

    }
    while(opcion != 0);
}


void Menu::gestionarConsultas()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("CONSULTA DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("CONSULTA DE REFACCIONES", 48, 12, y == 1);
        seleccionarItem("CONSULTA DE REPARACIONES", 48, 13, y == 2);
        seleccionarItem("CONSULTA DE TECNICOS", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                consultaClientes();
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                break;
            case 1:
                rlutil::cls();
                consultaRefacciones();
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                break;
            case 2:
                rlutil::cls();
                consultaReparaciones();
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                break;
            case 3:
                // Implementar lógica para eliminar cliente
                std::cout << "Eliminar REFACCION" << std::endl;
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

    }
    while(opcion != 0);
}



void Menu::gestionarReportes()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("GENERAR REPORTE DE CLIENTES", 48, 11, y == 0);
        seleccionarItem("GENERAR REPORTE DE REFACCIONES", 48, 12, y == 1);
        seleccionarItem("GENERAR REPORTE DE REPARACIONES", 48, 13, y == 2);
        seleccionarItem("GENERAR REPORTE DE TECNICOS", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;
        case 1: // Enter
            switch(y)
            {
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

    }
    while(opcion != 0);
}


void Menu::gestionarRespaldos()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("REALIZAR BACKUP", 48, 11, y == 0);
        seleccionarItem("RESTAURAR BACKUP", 48, 12, y == 1);
        seleccionarItem("VOLVER", 48, 13, y == 2);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 2)
            {
                y = 2;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                // Implementar lógica para modificar cliente
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
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

    }
    while(opcion != 0);
}

void Menu::consultaClientes()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoCliente arch;

    do
    {
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
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 5;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 5)
            {
                y = 0;
            }
            break;
        case 1: // Enter
            switch(y)
            {
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

    }
    while(opcion != 0);
}

void Menu::consultaRefacciones()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    archivoInventario archi;

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("LISTADO DE REPUESTOS", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR ID DE ARTICULO", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR TIPO DE ARTICULO", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR NUMERO DE SERIE", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;
        case 1: // Enter
            switch(y)
            {
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

    }
    while(opcion != 0);
}

void Menu::consultaReparaciones()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("INVENTARIO DE REPARACIONES", 48, 11, y == 0);
        seleccionarItem("BUSCAR POR ORDEN DE REPARACION", 48, 12, y == 1);
        seleccionarItem("BUSCAR POR TECNICO ASIGNADO", 48, 13, y == 2);
        seleccionarItem("BUSCAR POR STATUS", 48, 14, y == 3);
        seleccionarItem("BUSCAR POR FECHA DE INGRESO", 48, 15, y == 4);
        seleccionarItem("VOLVER", 48, 16, y == 5);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 5)
            {
                y = 5;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 3:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 4:
                std::cout << "BUSCAR REFACCION" << std::endl;
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

    }
    while(opcion != 0);
}


void Menu::reporteClientes()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("ORDENAR POR NUMERO DE CLIENTE", 48, 11, y == 0);
        seleccionarItem("ORDENAR POR APELLIDO", 48, 12, y == 1);
        seleccionarItem("ORDENAR POR FECHA DE ALTA", 48, 13, y == 2);
        seleccionarItem("VOLVER", 48, 14, y == 3);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 3)
            {
                y = 3;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
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

    }
    while(opcion != 0);
}

void Menu::reporteRefacciones()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("ORDENAR POR TIPO DE ARTICULO", 48, 11, y == 0);
        seleccionarItem("ORDENAR POR ARTICULO", 48, 12, y == 1);
        seleccionarItem("ORDENAR POR MARCA", 48, 13, y == 2);
        seleccionarItem("VOLVER", 48, 14, y == 3);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 3)
            {
                y = 3;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
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

    }
    while(opcion != 0);
}

void Menu::reporteReparaciones()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("ORDENAR POR NUMERO DE ORDEN", 48, 11, y == 0);
        seleccionarItem("ORDENAR POR STATUS DE REPARACION", 48, 12, y == 1);
        seleccionarItem("ORDENAR POR TECNICO ASIGNADO", 48, 13, y == 2);
        seleccionarItem("ORDENAR POR FECHA DE INGRESO", 48, 14, y == 3);
        seleccionarItem("VOLVER", 48, 15, y == 4);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 4)
            {
                y = 4;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 2:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
                break;
            case 3:
                std::cout << "BUSCAR REFACCION" << std::endl;
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

    }
    while(opcion != 0);
}

void Menu::reporteTecnicos()
{
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        seleccionarItem("ORDENAR POR NOMBRE", 48, 11, y == 0);
        seleccionarItem("ORDENAR POR ESPECIALIDAD", 48, 12, y == 1);
        seleccionarItem("VOLVER", 48, 13, y == 2);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key)
        {
        case 14: // Flecha arriba
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: // Flecha abajo
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if(y > 2)
            {
                y = 2;
            }
            break;
        case 1: // Enter
            switch(y)
            {
            case 0:
                rlutil::cls();
                std::cout << "Agregar REFACCION" << std::endl;
                rlutil::cls();
                rlutil::anykey();
                break;
            case 1:
                std::cout << "BUSCAR REFACCION" << std::endl;
                rlutil::anykey();
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

    }
    while(opcion != 0);
}



