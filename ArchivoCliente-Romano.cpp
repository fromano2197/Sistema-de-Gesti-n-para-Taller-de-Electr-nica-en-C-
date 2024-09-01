#include <iostream>
#include "ArchivoCliente.h"
#include "rlutil.h"
#include "Menu.h"
#include "Cliente.h"

bool archivoCliente::grabarRegistro (Cliente obj)
{
    bool escribio;
    FILE *p;
    p=fopen(_nombre, "ab");
    if (p==NULL)
    {
        return false;
    }
    escribio=fwrite (&obj, sizeof (Cliente), 1, p);
    fclose(p);
    return escribio;
}

void archivoCliente::altaCliente()
{
    Cliente obj;
    obj.Cargar();
    if(obj.getEstado()==true)
    {
        grabarRegistro(obj);

        std::cout<< "SE CARGO CORRECTAMENTE..."<<std::endl;
    }
    else
    {
        std::cout<<"SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO"<<std::endl;
    }
}

Cliente archivoCliente::leerRegistro(int pos)
{
    Cliente obj;
    FILE *p;
    p=fopen(_nombre, "rb");
    obj.setId(-5);
    if (p==NULL)
    {
        return obj;
    }
    fseek (p,pos * sizeof (Cliente),0);
    fread (&obj, sizeof (Cliente), 1, p);
    fclose(p);
    return obj;
}

int archivoCliente::buscarRegistro (int num)
{
    Cliente obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    int pos=0;
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&obj, sizeof (Cliente), 1,p)==1)
    {
        if (obj.getId()==num)
        {
            fclose (p);
            return pos;
        }
        else
        {
            pos++;
        }
    }
    fclose(p);
    return -2;
}

int archivoCliente::contarRegistro ()
{
    int tam;
    FILE *p;
    p=fopen (_nombre,"rb");
    if (p==NULL)
    {
        return -1;
    }
    fseek (p,0,2);
    tam=ftell(p);
    fclose (p);
    return tam/sizeof (Cliente);

}

bool archivoCliente::modificarRegistro (Cliente obj, int pos)
{
    FILE *p;
    p=fopen (_nombre,"rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek (p,pos*sizeof (Cliente),0);
    bool escribio=fwrite (&obj,sizeof (Cliente), 1,p);
    fclose(p);
    return escribio;
}

void archivoCliente::listarRegistro ()
{
    Cliente obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    if (p==NULL)
    {
        return;
    }
    int i = 0;
    while (fread(&obj, sizeof (Cliente), 1,p)==1)
    {
        obj.Mostrar (i);
        i++;
    }
    fclose(p);
}

bool archivoCliente::listarPorID()
{
    Cliente reg;
    archivoCliente archiCli;
    int id;
    int cantReg=archiCli.contarRegistro();
    if(cantReg<=0)
    {
        std::cout<<"PROBLEMAS CON ARCHIVO O ACHIVO INEXISTENTE"<<std::endl;
        return false;
    }
    std::cout<<"Ingrese ID de cliente a buscar: ";
    std::cin>>id;
    for(int i=0; i<cantReg; i++)
    {
        reg=archiCli.leerRegistro(i);
        if(reg.getId()==id)
        {
            reg.Mostrar();
        }
    }
}

bool archivoCliente::listarPorNombre()
{
    Cliente reg;
    archivoCliente archiCli;
    char nombre[30];
    int cantReg = archiCli.contarRegistro();
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    std::cout << "Ingrese nombre de cliente a buscar: ";
    cargarCadena(nombre, 29);
    system("cls");
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getNombre(), nombre) == 0)
        {
            reg.Mostrar();
        }
    }
    return true;
}


bool archivoCliente::listarPorApellido()
{
    Cliente reg;
    archivoCliente archiCli;
    char apellido[30];
    int cantReg = archiCli.contarRegistro();
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    std::cout << "Ingrese apellido de cliente a buscar: ";
    cargarCadena(apellido, 29);
    system("cls");
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getApellido(), apellido) == 0)
        {
            reg.Mostrar();
        }
    }
    return true;
}


void archivoCliente::listarPorDNI()
{
    Cliente reg;
    archivoCliente archiCli;
    int id;
    int cantReg = archiCli.contarRegistro();
    bool bandera = false;

    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }

    while (!bandera)
    {
        std::cout << "INGRESE DNI: ";
        std::cin >> id;

        for (int i = 0; i < cantReg; i++)
        {
            reg = archiCli.leerRegistro(i);
            if (reg.getDni() == id)
            {
                system("cls");
                reg.Mostrar();
                bandera = true;
                break;
            }
        }

        if (!bandera)
        {
            std::cout << "EL DNI INGRESADO NO FUE ENCONTRADO, VUELVA A INGRESARLO." << std::endl;
        }
    }
}

void archivoCliente::modificarCliente() {
    int num;
    Menu m;
    std::cout << "INGRESE NUMERO DE CLIENTE A MODIFICAR: ";
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont = 0;

    while (pos < 0) {
        std::cout << "CLIENTE NO ENCONTRADO" << std::endl;
        system("pause");
        system("cls");
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE CLIENTE A MODIFICAR: ";
        std::cin >> num;
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2) {
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL CLIENTE" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

    Cliente obj = leerRegistro(pos);
    rlutil::locate(45, 4);
    std::cout << "DATOS ACTUALES DEL CLIENTE:" << std::endl;
    obj.Mostrar();
    rlutil::locate(43, 20);
    system("pause");
    system("cls");

    // Modificar los campos del cliente
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do {
        dibujarCuadro(1, 1, 119, 30);
        m.seleccionarItem("MODIFICAR ID", 48, 11, y == 0);
        m.seleccionarItem("MODIFICAR NOMBRE", 48, 12, y == 1);
        m.seleccionarItem("MODIFICAR APELLIDO", 48, 13, y == 2);
        m.seleccionarItem("MODIFICAR FECHA DE NACIMIENTO", 48, 14, y == 3);
        m.seleccionarItem("MODIFICAR DNI", 48, 15, y == 4);
        m.seleccionarItem("MODIFICAR CALLE", 48, 16, y == 5);
        m.seleccionarItem("MODIFICAR NUMERACION DEL DOMICILIO", 48, 17, y == 6);
        m.seleccionarItem("MODIFICAR CODIGO POSTAL", 48, 18, y == 7);
        m.seleccionarItem("MODIFICAR TELEFONO", 48, 19, y == 8);
        m.seleccionarItem("MODIFICAR EMAIL", 48, 20, y == 9);
        m.seleccionarItem("VOLVER", 48, 21, y == 10);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch(key) {
            case 14: // Flecha arriba
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y--;
                if (y < 0) {
                    y = 10;
                }
                break;
            case 15: // Flecha abajo
                rlutil::locate(46, 11 + y);
                std::cout << " ";
                y++;
                if (y > 10) {
                    y = 0;
                }
                break;
            case 1: // Enter
                switch(y) {
                    case 0: {
                        rlutil::cls();
                        int id;
                        std::cout << "Ingrese el nuevo numero de ID: ";
                        std::cin >> id;
                        obj.setId(id);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 1: {
                        rlutil::cls();
                        char nombre[30];
                        std::cout << "Ingrese el nuevo nombre: ";
                        cargarCadena(nombre,29);
                        obj.setNombre(nombre);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 2: {
                        rlutil::cls();
                        std::string apellido;
                        std::cout << "Ingrese el nuevo apellido: ";
                        std::cin.ignore();
                        std::getline(std::cin, apellido);
                        //obj.setApellido(apellido);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 3: {
                        rlutil::cls();
                        Fecha fechaNacimiento;
                        std::cout << "Ingrese la nueva fecha de nacimiento (DD MM AAAA): ";
                        int dia, mes, anio;
                        std::cin >> dia >> mes >> anio;
                        fechaNacimiento.setDia(dia);
                        fechaNacimiento.setMes(mes);
                        fechaNacimiento.setAnio(anio);
//                        obj.setFechaNacimiento(fechaNacimiento);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 4: {
                        rlutil::cls();
                        int dni;
                        std::cout << "Ingrese el nuevo DNI: ";
                        std::cin >> dni;
                        obj.setDni(dni);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 5: {
                        rlutil::cls();
                        std::string calle;
                        std::cout << "Ingrese la nueva calle: ";
                        std::cin.ignore();
                        std::getline(std::cin, calle);
//                        obj.setCalle(calle);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 6: {
                        rlutil::cls();
                        int numeracion;
                        std::cout << "Ingrese la nueva numeración del domicilio: ";
                        std::cin >> numeracion;
//                        obj.setNumeracion(numeracion);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 7: {
                        rlutil::cls();
                        int codigoPostal;
                        std::cout << "Ingrese el nuevo código postal: ";
                        std::cin >> codigoPostal;
//                        obj.setCodigoPostal(codigoPostal);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 8: {
                        rlutil::cls();
                        std::string telefono;
                        std::cout << "Ingrese el nuevo teléfono: ";
                        std::cin.ignore();
                        std::getline(std::cin, telefono);
//                        obj.setTelefono(telefono);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 9: {
                        rlutil::cls();
                        std::string email;
                        std::cout << "Ingrese el nuevo email: ";
                        std::cin.ignore();
                        std::getline(std::cin, email);
//                        obj.setEmail(email);
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                    }
                    case 10:
                        opcion = 0;
                        rlutil::cls();
                        m.gestionarClientes();
                        rlutil::cls();
                        dibujarCuadro(1, 1, 119, 30);
                        break;
                        break;
                    default:
                        break;
                }
                if (opcion != 0) {
                    rlutil::cls();
                    dibujarCuadro(1, 1, 119, 30);
                    rlutil::locate(45, 14);
                    std::cout << "LA MODIFICACION SE REALIZO CON EXITO" << std::endl;
                    rlutil::locate(45, 16);
                    system("pause");
                    rlutil::cls();
                    dibujarCuadro(1, 1, 119, 30);
                }
            default:
                break;
        }

    } while(opcion != 0);

    if (modificarRegistro(obj, pos)) {
        std::cout << "CLIENTE MODIFICADO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL MODIFICAR EL CLIENTE" << std::endl;
    }
}




