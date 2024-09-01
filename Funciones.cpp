#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Funciones.h"
#include "ArchivoCliente.h"
#include "ArchivoReparacion.h"
#include "Tecnico.h"
#include "Inventario.h"
#include "Cliente.h"
#include "rlutil.h"
#include "Reparacion.h"
#include "Fecha.h"


void cargarCadena(char *palabra, int tamano)
{

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++)
    {

        palabra[i]=std::cin.get();

        if (palabra[i]=='\n')
        {

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

void cargarContrasena(char* cadena, int longitud)
{
    char caracter;
    int i = 0;

    do
    {
        caracter = getch();

        if (caracter != 8 && caracter != 13 && i < longitud - 1)
        {
            cadena[i] = caracter;
            std::cout << '*';
            i++;
        }
        else if (caracter == 8 && i > 0)
        {
            std::cout << "\b \b";
            i--;
        }
    }
    while (caracter != 13);
    cadena[i] = '\0';
}

void dibujarSubrayado(int x1, int y1, int x2)
{
    for (int i = x1; i < x2; i++)
    {
        rlutil::locate(i, y1);
        std::cout << char(205);
    }
}
void dibujarCuadro(int x1, int y1, int x2, int y2)
{

    for (int i = x1 + 1; i < x2; i++)
    {
        rlutil::locate(i, y1);
        std::cout << char(205);
        rlutil::locate(i, y2);
        std::cout << char(205);
    }


    for (int i = y1 + 1; i < y2; i++)
    {
        rlutil::locate(x1, i);
        std::cout << char(186);
        rlutil::locate(x2, i);
        std::cout << char(186);
    }


    rlutil::locate(x1, y1);
    std::cout << char(201);
    rlutil::locate(x1, y2);
    std::cout << char(200);
    rlutil::locate(x2, y1);
    std::cout << char(187);
    rlutil::locate(x2, y2);
    std::cout << char(188);
}


void dibujarTabla(int x1, int y1, int x2, int y2, int alturaFila1)
{
    int yCentral = y1 + alturaFila1;

    for (int i = x1; i <= x2; i++)
    {
        rlutil::locate(i, y1);
        std::cout << char(205);
        rlutil::locate(i, yCentral);
        std::cout << char(205);
        rlutil::locate(i, y2);
        std::cout << char(205);
    }


    for (int i = y1; i <= y2; i++)
    {
        rlutil::locate(x1, i);
        std::cout << char(186);
        rlutil::locate(x2, i);
        std::cout << char(186);
    }

    rlutil::locate(x1, y1);
    std::cout << char(201);
    rlutil::locate(x2, y1);
    std::cout << char(187);
    rlutil::locate(x1, y2);
    std::cout << char(200);
    rlutil::locate(x2, y2);
    std::cout << char(188);


    rlutil::locate(x1, yCentral);
    std::cout << char(204);
    rlutil::locate(x2, yCentral);
    std::cout << char(185);
}

void ReparacionesCSV()
{
    std::ofstream archivo("reparaciones.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "OrdenReparacion;NumCliente;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Articulo;Marca;Modelo;TipoArticulo;PrecioReparacion;FechaEntrada;FechaSalida;Falla;Reparacion;TipoReparacion;Tecnico;Status;Estado" << std::endl;

    FILE *p;
    p = fopen("reparaciones.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    Reparacion reparacion;
    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {
        Cliente cliente = reparacion.getCliente();
        Articulo articulo = reparacion.getArticulo();

        archivo << reparacion.getOrdenReparacion() << ";"
                << cliente.getId() << ";"
                << cliente.getNombre() << ";"
                << cliente.getApellido() << ";"
                << cliente.getDni() << ";"
                << cliente.getNacimiento().ToString() << ";"
                << cliente.getDatos().getDomicilio().getCalle() << ";"
                << cliente.getDatos().getDomicilio().getNumeracion() << ";"
                << cliente.getDatos().getDomicilio().getCodigoPostal() << ";"
                << cliente.getDatos().getTelefono() << ";"
                << cliente.getDatos().getEmail() << ";"
                << articulo.getArticulo() << ";"
                << articulo.getMarca() << ";"
                << articulo.getModelo() << ";"
                << articulo.getTipoArticulo() << ";"
                << reparacion.getPrecioReparacion() << ";"
                << reparacion.getFechaEntrada().ToString() << ";"
                << reparacion.getFechaSalida().ToString() << ";"
                << reparacion.getFalla() << ";"
                << reparacion.getReparacion() << ";"
                << reparacion.getTipoReparacion() << ";"
                << reparacion.getTecnico() << ";"
                << reparacion.getStatus() << ";"
                << reparacion.getEstado() << std::endl;
    }

    fclose(p);
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ReparacionesPorStatusCSV(int status)
{
    std::ofstream archivo("reparacionesPorStatus.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "OrdenReparacion;NumCliente;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Articulo;Marca;Modelo;TipoArticulo;PrecioReparacion;FechaEntrada;FechaSalida;Falla;Reparacion;TipoReparacion;Tecnico;Status;Estado" << std::endl;

    FILE *p;
    p = fopen("reparaciones.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    Reparacion reparacion;
    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {
        if (reparacion.getStatus() == status)
        {
            Cliente cliente = reparacion.getCliente();
            Articulo articulo = reparacion.getArticulo();

            archivo << reparacion.getOrdenReparacion() << ";"
                    << cliente.getId() << ";"
                    << cliente.getNombre() << ";"
                    << cliente.getApellido() << ";"
                    << cliente.getDni() << ";"
                    << cliente.getNacimiento().ToString() << ";"
                    << cliente.getDatos().getDomicilio().getCalle() << ";"
                    << cliente.getDatos().getDomicilio().getNumeracion() << ";"
                    << cliente.getDatos().getDomicilio().getCodigoPostal() << ";"
                    << cliente.getDatos().getTelefono() << ";"
                    << cliente.getDatos().getEmail() << ";"
                    << articulo.getArticulo() << ";"
                    << articulo.getMarca() << ";"
                    << articulo.getModelo() << ";"
                    << articulo.getTipoArticulo() << ";"
                    << reparacion.getPrecioReparacion() << ";"
                    << reparacion.getFechaEntrada().ToString() << ";"
                    << reparacion.getFechaSalida().ToString() << ";"
                    << reparacion.getFalla() << ";"
                    << reparacion.getReparacion() << ";"
                    << reparacion.getTipoReparacion() << ";"
                    << reparacion.getTecnico() << ";"
                    << reparacion.getStatus() << ";"
                    << reparacion.getEstado() << std::endl;
        }
    }

    fclose(p);
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ReparacionesPorTecnicoCSV(int numeroTecnico)
{
    std::ofstream archivo("reparacionesPorTecnico.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "OrdenReparacion;NumCliente;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Articulo;Marca;Modelo;TipoArticulo;PrecioReparacion;FechaEntrada;FechaSalida;Falla;Reparacion;TipoReparacion;Tecnico;Status;Estado" << std::endl;

    FILE *p;
    p = fopen("reparaciones.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    Reparacion reparacion;
    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {

        if (reparacion.getTecnico() == numeroTecnico)
        {
            Cliente cliente = reparacion.getCliente();
            Articulo articulo = reparacion.getArticulo();

            archivo << reparacion.getOrdenReparacion() << ";"
                    << cliente.getId() << ";"
                    << cliente.getNombre() << ";"
                    << cliente.getApellido() << ";"
                    << cliente.getDni() << ";"
                    << cliente.getNacimiento().ToString() << ";"
                    << cliente.getDatos().getDomicilio().getCalle() << ";"
                    << cliente.getDatos().getDomicilio().getNumeracion() << ";"
                    << cliente.getDatos().getDomicilio().getCodigoPostal() << ";"
                    << cliente.getDatos().getTelefono() << ";"
                    << cliente.getDatos().getEmail() << ";"
                    << articulo.getArticulo() << ";"
                    << articulo.getMarca() << ";"
                    << articulo.getModelo() << ";"
                    << articulo.getTipoArticulo() << ";"
                    << reparacion.getPrecioReparacion() << ";"
                    << reparacion.getFechaEntrada().ToString() << ";"
                    << reparacion.getFechaSalida().ToString() << ";"
                    << reparacion.getFalla() << ";"
                    << reparacion.getReparacion() << ";"
                    << reparacion.getTipoReparacion() << ";"
                    << reparacion.getTecnico() << ";"
                    << reparacion.getStatus() << ";"
                    << reparacion.getEstado() << std::endl;
        }
    }

    fclose(p);
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ReparacionesDesdeFechaCSV(const Fecha& fechaEntrada)
{
    std::ofstream archivo("reparacionesDesdeFecha.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "OrdenReparacion;NumCliente;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Articulo;Marca;Modelo;TipoArticulo;PrecioReparacion;FechaEntrada;FechaSalida;Falla;Reparacion;TipoReparacion;Tecnico;Status;Estado" << std::endl;

    FILE *p = fopen("reparaciones.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    Reparacion reparacion;
    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {

        if (reparacion.getFechaEntrada() >= fechaEntrada)
        {
            Cliente cliente = reparacion.getCliente();
            Articulo articulo = reparacion.getArticulo();

            archivo << reparacion.getOrdenReparacion() << ";"
                    << cliente.getId() << ";"
                    << cliente.getNombre() << ";"
                    << cliente.getApellido() << ";"
                    << cliente.getDni() << ";"
                    << cliente.getNacimiento().ToString() << ";"
                    << cliente.getDatos().getDomicilio().getCalle() << ";"
                    << cliente.getDatos().getDomicilio().getNumeracion() << ";"
                    << cliente.getDatos().getDomicilio().getCodigoPostal() << ";"
                    << cliente.getDatos().getTelefono() << ";"
                    << cliente.getDatos().getEmail() << ";"
                    << articulo.getArticulo() << ";"
                    << articulo.getMarca() << ";"
                    << articulo.getModelo() << ";"
                    << articulo.getTipoArticulo() << ";"
                    << reparacion.getPrecioReparacion() << ";"
                    << reparacion.getFechaEntrada().ToString() << ";"
                    << reparacion.getFechaSalida().ToString() << ";"
                    << reparacion.getFalla() << ";"
                    << reparacion.getReparacion() << ";"
                    << reparacion.getTipoReparacion() << ";"
                    << reparacion.getTecnico() << ";"
                    << reparacion.getStatus() << ";"
                    << reparacion.getEstado() << std::endl;
        }
    }

    fclose(p);
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ClientesCSV()
{
    std::ofstream archivo("clientes.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Estado" << std::endl;

    FILE *p = fopen("clientes.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, p) == 1)
    {
        archivo << cliente.getId() << ";"
                << cliente.getNombre() << ";"
                << cliente.getApellido() << ";"
                << cliente.getDni() << ";"
                << cliente.getNacimiento().ToString() << ";"
                << cliente.getDatos().getDomicilio().getCalle() << ";"
                << cliente.getDatos().getDomicilio().getNumeracion() << ";"
                << cliente.getDatos().getDomicilio().getCodigoPostal() << ";"
                << cliente.getDatos().getTelefono() << ";"
                << cliente.getDatos().getEmail() << ";"
                << (cliente.getEstado() ? "Activo" : "Inactivo") << std::endl;
    }

    fclose(p);
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}




void ClientesOrdenadoPorApellidoCSV()
{
    std::ofstream archivo("clientes_por_apellido.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Estado" << std::endl;

    FILE *p = fopen("clientes.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Cliente);
    fseek(p, 0, SEEK_SET);


    Cliente* clientes = new Cliente[cantidadRegistros];
    fread(clientes, sizeof(Cliente), cantidadRegistros, p);
    fclose(p);


    for (int i = 0; i < cantidadRegistros - 1; i++)
    {
        for (int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if (strcmp(clientes[j].getApellido(), clientes[j + 1].getApellido()) > 0)
            {
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < cantidadRegistros; i++)
    {
        Cliente& c = clientes[i];
        archivo << c.getId() << ";"
                << c.getNombre() << ";"
                << c.getApellido() << ";"
                << c.getDni() << ";"
                << c.getNacimiento().ToString() << ";"
                << c.getDatos().getDomicilio().getCalle() << ";"
                << c.getDatos().getDomicilio().getNumeracion() << ";"
                << c.getDatos().getDomicilio().getCodigoPostal() << ";"
                << c.getDatos().getTelefono() << ";"
                << c.getDatos().getEmail() << ";"
                << (c.getEstado() ? "Activo" : "Inactivo") << std::endl;
    }

    delete[] clientes;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ClientesOrdenadoPorNombreCSV()
{
    std::ofstream archivo("clientes_por_nombre.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Nombre;Apellido;DNI;FechaNacimiento;Calle;Numeracion;CodigoPostal;Telefono;Mail;Estado" << std::endl;

    FILE *p = fopen("clientes.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Cliente);
    fseek(p, 0, SEEK_SET);


    Cliente* clientes = new Cliente[cantidadRegistros];
    fread(clientes, sizeof(Cliente), cantidadRegistros, p);
    fclose(p);


    for (int i = 0; i < cantidadRegistros - 1; i++)
    {
        for (int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if (strcmp(clientes[j].getNombre(), clientes[j + 1].getNombre()) > 0)
            {
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < cantidadRegistros; i++)
    {
        Cliente& c = clientes[i];
        archivo << c.getId() << ";"
                << c.getNombre() << ";"
                << c.getApellido() << ";"
                << c.getDni() << ";"
                << c.getNacimiento().ToString() << ";"
                << c.getDatos().getDomicilio().getCalle() << ";"
                << c.getDatos().getDomicilio().getNumeracion() << ";"
                << c.getDatos().getDomicilio().getCodigoPostal() << ";"
                << c.getDatos().getTelefono() << ";"
                << c.getDatos().getEmail() << ";"
                << (c.getEstado() ? "Activo" : "Inactivo") << std::endl;
    }

    delete[] clientes;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}


void RefaccionPorTipoCSV()
{

    int tipoArticulo;

    std::cout << "Ingrese el tipo de artículo: ";
    std::cin >> tipoArticulo;

    std::ofstream archivo("refacciones_por_tipo.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Articulo;Marca;Modelo;Tipo;Existencia;Estado" << std::endl;

    FILE *p = fopen("inventarios.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Inventario);
    fseek(p, 0, SEEK_SET);


    Inventario* inventario = new Inventario[cantidadRegistros];
    fread(inventario, sizeof(Inventario), cantidadRegistros, p);
    fclose(p);


    for (int i = 0; i < cantidadRegistros; i++)
    {
        if (inventario[i].getArticulo().getTipoArticulo() == tipoArticulo)
        {
            Inventario& refaccion = inventario[i];
            archivo << refaccion.getArticulo().getIdArticulo() << ";"
                    << refaccion.getArticulo().getArticulo() << ";"
                    << refaccion.getArticulo().getMarca() << ";"
                    << refaccion.getArticulo().getModelo() << ";"
                    << refaccion.getArticulo().getTipoArticulo() << ";"
                    << refaccion.getExistencia() << ";"
                    << (refaccion.getEstado() ? "Activo" : "Inactivo") << std::endl;
        }
    }

    delete[] inventario;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}


void ExportarInventarioCSV()
{
    std::ofstream archivo("refacciones.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Articulo;Marca;Modelo;Serie;TipoArticulo;Estado;Existencia" << std::endl;

    FILE *p = fopen("inventarios.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Inventario);
    fseek(p, 0, SEEK_SET);


    Inventario* inventario = new Inventario[cantidadRegistros];
    fread(inventario, sizeof(Inventario), cantidadRegistros, p);
    fclose(p);

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Inventario& refaccion = inventario[i];
        archivo << refaccion.getArticulo().getIdArticulo() << ";"
                << refaccion.getArticulo().getArticulo() << ";"
                << refaccion.getArticulo().getMarca() << ";"
                << refaccion.getArticulo().getModelo() << ";"
                << refaccion.getArticulo().getSerie() << ";"
                << refaccion.getArticulo().getTipoArticulo() << ";"
                << (refaccion.getArticulo().getEstado() ? "Activo" : "Inactivo") << ";"
                << refaccion.getExistencia() << std::endl;
    }

    delete[] inventario;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void RefaccionesOrdenadasPorArticuloCSV()
{
    std::ofstream archivo("refacciones_por_articulos.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Articulo;Marca;Modelo;Serie;TipoArticulo;Estado;Existencia" << std::endl;

    FILE *p = fopen("inventarios.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Inventario);
    fseek(p, 0, SEEK_SET);


    Inventario* inventarios = new Inventario[cantidadRegistros];
    fread(inventarios, sizeof(Inventario), cantidadRegistros, p);
    fclose(p);


    for (int i = 0; i < cantidadRegistros - 1; i++)
    {
        for (int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if (strcmp(inventarios[j].getArticulo().getArticulo(), inventarios[j + 1].getArticulo().getArticulo()) > 0)
            {
                Inventario temp = inventarios[j];
                inventarios[j] = inventarios[j + 1];
                inventarios[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < cantidadRegistros; i++)
    {
        Inventario& inv = inventarios[i];
        const Articulo& art = inv.getArticulo();
        archivo << art.getIdArticulo() << ";"
                << art.getArticulo() << ";"
                << art.getMarca() << ";"
                << art.getModelo() << ";"
                << art.getSerie() << ";"
                << art.getTipoArticulo() << ";"
                << (art.getEstado() ? "Activo" : "Inactivo") << ";"
                << inv.getExistencia() << std::endl;
    }

    delete[] inventarios;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void RefaccionesOrdenadasPorMarcaCSV()
{
    std::ofstream archivo("refacciones_por_marcas.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Id;Articulo;Marca;Modelo;Serie;TipoArticulo;Estado;Existencia" << std::endl;

    FILE *p = fopen("inventarios.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }


    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Inventario);
    fseek(p, 0, SEEK_SET);

    Inventario* inventarios = new Inventario[cantidadRegistros];
    fread(inventarios, sizeof(Inventario), cantidadRegistros, p);
    fclose(p);

    for (int i = 0; i < cantidadRegistros - 1; i++)
    {
        for (int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if (strcmp(inventarios[j].getArticulo().getMarca(), inventarios[j + 1].getArticulo().getMarca()) > 0)
            {
                Inventario temp = inventarios[j];
                inventarios[j] = inventarios[j + 1];
                inventarios[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Inventario& inv = inventarios[i];
        const Articulo& art = inv.getArticulo();
        archivo << art.getIdArticulo() << ";"
                << art.getArticulo() << ";"
                << art.getMarca() << ";"
                << art.getModelo() << ";"
                << art.getSerie() << ";"
                << art.getTipoArticulo() << ";"
                << (art.getEstado() ? "Activo" : "Inactivo") << ";"
                << inv.getExistencia() << std::endl;
    }

    delete[] inventarios;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}


void generarReporteRecaudacion()
{
    archivoReparacion arch;
    Fecha fechaInicio, fechaFin;

    rlutil::cls();
    dibujarCuadro(32,14,78,19);
    rlutil::locate(44,15);
    std::cout << "INGRESE FECHA DESDE";
    fechaInicio.Cargar();
    system("cls");
    rlutil::cls();
    dibujarCuadro(32,14,78,19);
    rlutil::locate(44,15);
    std::cout << "INGRESE FECHA HASTA";
    fechaFin.Cargar();
    system("cls");
    float recaudacionTotal = arch.calcularRecaudacionEntreFechas(fechaInicio, fechaFin);
    rlutil::cls();
    dibujarCuadro(30,14,101,16);
    rlutil::locate(35,15);
    std::cout << "LA RECAUDACION TOTAL ENTRE LAS FECHAS INGRESADAS ES DE: $" << recaudacionTotal << std::endl;
}


void generarReporteRecaudacionDiaria()
{
    archivoReparacion arch;
    float recaudacionDia = arch.calcularRecaudacionDelDia();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(39,15);
    std::cout << "LA RECAUDACION DEL DIA ES DE: $" << recaudacionDia << std::endl;
}


void ExportarTecnicosCSV()
{
    std::ofstream archivo("tecnicos.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Nombre;Apellido;DNI;NumTecnico;Estado" << std::endl;

    FILE *p = fopen("tecnicos.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Tecnico);
    fseek(p, 0, SEEK_SET);

    Tecnico* tecnicos = new Tecnico[cantidadRegistros];
    fread(tecnicos, sizeof(Tecnico), cantidadRegistros, p);
    fclose(p);

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Tecnico& tecnico = tecnicos[i];
        archivo << tecnico.getNombre() << ";"
                << tecnico.getApellido() << ";"
                << tecnico.getDni() << ";"
                << tecnico.getNumTecnico() << ";"
                << (tecnico.getEstado() ? "Activo" : "Inactivo") << std::endl;
    }

    delete[] tecnicos;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(43,15);
    std::cout << "SE EXPORTO EL ARCHIVO CON EXITO" << std::endl;
}

void ExportarTecnicosPorOrdenDeNumCSV()
{
    std::ofstream archivo("tecnicos_por_numTec.csv");
    if (!archivo.is_open())
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return;
    }

    archivo << "Nombre;Apellido;DNI;NumTecnico;Estado" << std::endl;

    FILE *p = fopen("tecnicos.dat", "rb");
    if (p == nullptr)
    {
        rlutil::cls();
        dibujarCuadro(39,14,75,16);
        rlutil::locate(49,15);
        std::cout << "ERROR DE ARCHIVO" << std::endl;
        return;
    }

    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Tecnico);
    fseek(p, 0, SEEK_SET);

    Tecnico* tecnicos = new Tecnico[cantidadRegistros];
    fread(tecnicos, sizeof(Tecnico), cantidadRegistros, p);
    fclose(p);

    for (int i = 0; i < cantidadRegistros - 1; i++)
    {
        for (int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if (tecnicos[j].getNumTecnico() > tecnicos[j + 1].getNumTecnico())
            {
                Tecnico temp = tecnicos[j];
                tecnicos[j] = tecnicos[j + 1];
                tecnicos[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Tecnico& tecnico = tecnicos[i];
        archivo << tecnico.getNombre() << ";"
                << tecnico.getApellido() << ";"
                << tecnico.getDni() << ";"
                << tecnico.getNumTecnico() << ";"
                << (tecnico.getEstado() ? "Activo" : "Inactivo") << std::endl;
    }

    delete[] tecnicos;
    archivo.close();
    rlutil::cls();
    dibujarCuadro(34,14,82,16);
    rlutil::locate(39,15);
    std::cout << "SE EXPORTO ARCHIVO CON EXITO" << std::endl;
}

void informeOrdenesPendientes()
{
    archivoReparacion arch;
    int cantPendientes = arch.contarReparacionesPendientes();
    rlutil::cls();
    dibujarCuadro(20,14,102,16);
    rlutil::locate(25,15);
    std::cout << "LA CANTIDAD DE REPARACIONES PENDIENTES DE REVISION EN EL TALLER ES DE: " << cantPendientes << std::endl;
}
