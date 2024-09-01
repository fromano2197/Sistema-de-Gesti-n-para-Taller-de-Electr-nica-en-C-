#include <iostream>
#include "ArchivoCliente.h"
#include "rlutil.h"
#include "Menu.h"
#include "Contacto.h"

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
    rlutil::locate(44, 12);
    obj.Cargar();
    if (obj.getEstado() == true)
    {
        int ultimoID = leerUltimoIdCliente();
        obj.setId(ultimoID + 1);
        grabarRegistro(obj);
        guardarUltimoIdCliente(ultimoID + 1);
        std::cout << "SE CARGO CORRECTAMENTE..." << std::endl;
    }
    else
    {
        std::cout << "SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO" << std::endl;
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
        if (obj.getEstado() == true)
        {
            obj.Mostrar(i);
            i++;
        }
    }
    fclose(p);
}

bool archivoCliente::listarPorID()
{
    Cliente reg;
    archivoCliente archiCli;
    int id;
    bool bandera=false;
    int cantReg=archiCli.contarRegistro();
    if(cantReg<=0)
    {
        std::cout<<"PROBLEMAS CON ARCHIVO O ACHIVO INEXISTENTE"<<std::endl;
        return false;
    }



    while (!bandera)
    {
        dibujarCuadro(32,14,87,16);
        rlutil::locate(44,15);
        std::cout<<"INGRESE ID DE CLIENTE A BUSCAR: ";
        rlutil::locate(77,15);
        std::cin>>id;
        system("cls");
        for(int i=0; i<cantReg; i++)
        {
            reg=archiCli.leerRegistro(i);
            if(reg.getId()==id)
            {
                reg.Mostrar();
                bandera =true;
                break;
            }
        }
        if (!bandera)
        {
            dibujarCuadro(32,14,90,16);
            rlutil::locate(33,15);
            std::cout << "EL ID INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
            return  false;
        }
    }
}

bool archivoCliente::listarPorNombre()
{
    Cliente reg;
    archivoCliente archiCli;
    char nombre[30];
    int cantReg = archiCli.contarRegistro();
    bool bandera = false;
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    dibujarCuadro(32,14,90,16);
    rlutil::locate(40,15);
    std::cout<<"INGRESE NOMBRE DE CLIENTE A BUSCAR: ";
    rlutil::locate(77,15);
    cargarCadena(nombre, 29);
    system("cls");
    int y=3;
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getNombre(), nombre) == 0)
        {
            reg.Mostrar(i,y);
            y++;
            bandera = true;

        }
    }
    if (!bandera)
    {
        dibujarCuadro(32,14,94,16);
        rlutil::locate(34,15);
        std::cout << "EL NOMBRE INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
        return  false;
    }
}

int archivoCliente::leerUltimoIdCliente()
{
    FILE *p = fopen("ultimoIdCLiente.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    int ultimoID;
    fread(&ultimoID, sizeof(int), 1, p);
    fclose(p);
    return ultimoID;
}

void archivoCliente::guardarUltimoIdCliente(int ultimoID)
{
    FILE *p = fopen("ultimoIdCliente.dat", "wb");
    fwrite(&ultimoID, sizeof(int), 1, p);
    fclose(p);
}





bool archivoCliente::listarPorApellido()
{
    Cliente reg;
    archivoCliente archiCli;
    char apellido[30];
    bool bandera = false;
    int cantReg = archiCli.contarRegistro();
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    dibujarCuadro(32,14,96,16);
    rlutil::locate(41,15);
    std::cout<<"INGRESE APELLIDO DE CLIENTE A BUSCAR: ";
    rlutil::locate(79,15);
    cargarCadena(apellido, 29);
    system("cls");
    int y=3;
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getApellido(), apellido) == 0)
        {
            reg.Mostrar(i,y);
            y++;
            bandera = true;

        }
    }
    if (!bandera)
    {
        dibujarCuadro(32,14,96,16);
        rlutil::locate(34,15);
        std::cout << "EL APELLIDO INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
        return  false;
    }
}



void archivoCliente::listarPorDNI()
{
    Cliente reg;
    archivoCliente archiCli;
    int dni;
    int cantReg = archiCli.contarRegistro();
    bool bandera = false;

    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }

    while (!bandera)
    {
        dibujarCuadro(32,14,90,16);
        rlutil::locate(39,15);
        std::cout<<"INGRESE DNI DEL CLIENTE A BUSCAR: ";
        rlutil::locate(73,15);
        std::cin >> dni;

        for (int i = 0; i < cantReg; i++)
        {
            reg = archiCli.leerRegistro(i);
            if (reg.getDni() == dni)
            {
                system("cls");
                reg.Mostrar();
                bandera = true;
                break;
            }
        }

        if (!bandera)
        {
            dibujarCuadro(32,14,90,16);
            rlutil::locate(34,15);
            std::cout << "EL DNI INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
            return;
        }

    }
}
int archivoCliente::buscarRegistroPorDni (int dni)
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
        if (obj.getDni()==dni)
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

void archivoCliente::modificarCliente()
{
    int num;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE CLIENTE A MODIFICAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont=0;

    while(pos<0)
    {
        std::cout << "CLIENTE NO ENCONTRADO" << std::endl;
        system("pause");
        system("cls");
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE CLIENTE A MODIFICAR: ";
        std::cin >> num;
        pos = buscarRegistro(num);
        Cliente obj = leerRegistro(pos);
        system("cls");
        cont++;
        if (cont==2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(44,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL CLIENTE" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }
    Cliente obj = leerRegistro(pos);
    std::cout << "DATOS ACTUALES DEL CLIENTE:" << std::endl;
    obj.Mostrar();

    std::cout << "INGRESE NUEVOS DATOS DEL CLIENTE:" << std::endl;
    obj.Cargar();

    if (modificarRegistro(obj, pos))
    {
        std::cout << "CLIENTE MODIFICADO CORRECTAMENTE" << std::endl;
    }
    else
    {
        std::cout << "ERROR AL MODIFICAR EL CLIENTE" << std::endl;
    }
}


void archivoCliente::modificarCampoCliente()
{
    int num;
    Menu m;
    dibujarCuadro(37,14,92,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE CLIENTE A MODIFICAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");
    int pos = buscarRegistro(num);
    int cont = 0;
    while (pos < 0)
    {
        dibujarCuadro(46,14,72,16);
        rlutil::locate(49,15);
        std::cout << "CLIENTE NO ENCONTRADO" << std::endl;
        rlutil::locate(41,18);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE CLIENTE A MODIFICAR: ";
        rlutil::locate(91,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(41,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL CLIENTE" << std::endl;
            rlutil::locate(44,18);
            system("pause");
            system("cls");
            return;
        }
    }
    Cliente obj = leerRegistro(pos);
    obj.Mostrar();
    rlutil::locate(45,29);
    system("pause");
    system("cls");
    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();
    do
    {
        dibujarCuadro(1, 1, 119, 30);
        dibujarCuadro(32,5,87,7);
        rlutil::locate(44,6);
        std::cout<<"ELIJA EL CAMPO A MODIFICAR"<<std::endl;
        m.seleccionarItem("ID", 48, 11, y == 0);
        m.seleccionarItem("NOMBRE", 48, 12, y == 1);
        m.seleccionarItem("APELLIDO", 48, 13, y == 2);
        m.seleccionarItem("FECHA DE NACIMIENTO", 48, 14, y == 3);
        m.seleccionarItem("DNI", 48, 15, y == 4);
        m.seleccionarItem("CALLE", 48, 16, y == 5);
        m.seleccionarItem("NUMERACION", 48, 17, y == 6);
        m.seleccionarItem("CODIGO POSTAL", 48, 18, y == 7);
        m.seleccionarItem("TELEFONO", 48, 19, y == 8);
        m.seleccionarItem("EMAIL", 48, 20, y == 9);
        m.seleccionarItem("VOLVER", 48, 21, y == 10);

        rlutil::locate(46, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if (y < 0)
            {
                y = 10;
            }
            break;
        case 15:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if (y > 10)
            {
                y = 0;
            }
            break;
        case 1:
            switch (y)
            {
            case 0:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(37,14,83,16);
                rlutil::locate(42,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE ID: ";
                rlutil::locate(75,15);
                std::cin >> id;
                system("cls");
                obj.setId(id);
                break;
            }
            case 1:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(37,14,87,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO NOMBRE: ";
                rlutil::locate(72,15);
                cargarCadena(nombre,29);
                system("cls");
                obj.setNombre(nombre);
                break;
            }
            case 2:
            {
                rlutil::cls();
                char apellido[30];
                dibujarCuadro(37,14,87,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO APELLIDO: ";
                rlutil::locate(72,15);
                cargarCadena(apellido,29);
                system("cls");
                obj.setApellido(apellido);
                break;
            }
            case 3:
            {
                rlutil::cls();
                Fecha nuevaFecha;
                dibujarCuadro(40,14,85,19);
                rlutil::locate(44,15);
                std::cout<<"INGRESE NUEVA FECHA DE NACIMIENTO:";
                nuevaFecha.Cargar();
                obj.setFecha(nuevaFecha);
                break;
            }
            case 4:
            {
                rlutil::cls();
                int dni;
                dibujarCuadro(37,14,84,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO DNI: ";
                rlutil::locate(69,15);
                std::cin >> dni;
                system("cls");
                obj.setDni(dni);
                break;
            }
            case 5:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(37, 14, 84, 16);
                rlutil::locate(44, 15);
                std::cout << "INGRESE LA NUEVA CALLE: ";
                rlutil::locate(67, 15);
                cargarCadena(nombre, 29);
                system("cls");
                obj.getDatos().setCalleDomicilio(nombre);
                break;
            }
            case 6:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(37,14,84,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE LA NUEVA NUMERACION: ";
                rlutil::locate(74,15);
                std::cin >> id;
                system("cls");
                obj.getDatos().getDomicilio().setNumeracion(id);
                break;
            }
            case 7:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(37,14,83,16);
                rlutil::locate(42,15);
                std::cout << "INGRESE EL NUEVO CODIGO POSTAL: ";
                rlutil::locate(75,15);
                std::cin >> id;
                system("cls");
                obj.getDatos().getDomicilio().setCodigoPostal(id);
                break;
            }
            case 8:
            {
                rlutil::cls();
                char tel[30];
                dibujarCuadro(35,14,90,16);
                rlutil::locate(40,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE TELEFONO: ";
                rlutil::locate(77,15);
                cargarCadena(tel,29);
                system("cls");
                obj.getDatos().setTelefono(tel);
                break;
            }
            case 9:
            {
                rlutil::cls();
                char tel[30];
                dibujarCuadro(37,14,89,16);
                rlutil::locate(40,15);
                std::cout << "INGRESE EL NUEVO EMAIL: ";
                rlutil::locate(64,15);
                cargarCadena(tel,29);
                system("cls");
                obj.getDatos().setEmail(tel);
                break;
            }

            case 10:
                opcion = 0;
                break;
            default:
                break;
            }
            if (opcion != 0)
            {
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                rlutil::locate(44,10);
                std::cout << "LA MODIFICACION SE REALIZO CON EXITO" << std::endl;
                rlutil::locate(44,12);
                system("pause");
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
            }
            opcion = 0;
            break;
        default:
            break;
        }

    }
    while (opcion != 0);

    if (modificarRegistro(obj, pos))
    {
        std::cout << "CLIENTE MODIFICADO CORRECTAMENTE" << std::endl;
    }
    else
    {
        std::cout << "ERROR AL MODIFICAR EL CLIENTE" << std::endl;
    }
}

void archivoCliente::eliminarCliente()
{
    int num;
    Menu m;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE CLIENTE A ELIMINAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "CLIENTE NO ENCONTRADO" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(34,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE CLIENTE A ELIMINAR: ";
        rlutil::locate(88,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,92,16);
            rlutil::locate(39,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL CLIENTE" << std::endl;
            rlutil::locate(45,29);
            system("pause");
            system("cls");
            return;
        }
    }

    Cliente obj = leerRegistro(pos);
    obj.Mostrar();
    rlutil::locate(45,29);
    system("pause");
    system("cls");


    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        dibujarCuadro(32,5,87,7);
        rlutil::locate(44,6);
        std::cout<<"DESEA ELIMINAR ESTE CLIENTE?"<<std::endl;
        m.seleccionarItem("SI", 56, 11, y == 0);
        m.seleccionarItem("NO", 56, 12, y == 1);
        m.seleccionarItem("VOLVER", 56, 13, y == 2);

        rlutil::locate(54, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if (y < 0)
            {
                y = 2;
            }
            break;
        case 15:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if (y > 2)
            {
                y = 0;
            }
            break;
        case 1:
            switch (y)
            {
            case 0:
                rlutil::cls();
                obj.setEstado(false);
                if (modificarRegistro(obj, pos))
                {
                    system("cls");
                    dibujarCuadro(41,14,82,16);
                    rlutil::locate(45,15);
                    std::cout << "CLIENTE ELIMINADO CORRECTAMENTE" << std::endl;
                    rlutil::locate(43,17);
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    rlutil::cls();
                    dibujarCuadro(41, 14, 82, 16);
                    rlutil::locate(45,15);
                    std::cout << "ERROR AL ELIMINAR CLIENTE" << std::endl;
                    rlutil::locate(443,17);
                    system("pause");
                    rlutil::cls();
                    return;
                }
                opcion = 0;
                break;
            case 1:
                system("cls");
                dibujarCuadro(44,14,79,16);
                rlutil::locate(52,15);
                std::cout<<"OPERACION CANCELADA";
                rlutil::locate(43,17);
                system("pause");
                system("cls");
                opcion = 0;
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
    while (opcion != 0);


}

void archivoCliente::reactivarCliente()
{
    int num;
    Menu m;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE EL DNI DEL CLIENTE A REACTIVAR: ";
    rlutil::locate(85,15);
    std::cin >> num;


    system("cls");

    int pos = buscarRegistroPorDni(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "CLIENTE NO ENCONTRADO" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL DNI DEL CLIENTE A REACTIVAR: ";
        rlutil::locate(90,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistroPorDni(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,92,16);
            rlutil::locate(39,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL CLIENTE" << std::endl;
            rlutil::locate(45,17);
            system("pause");
            system("cls");
            return;
        }
    }

    Cliente obj = leerRegistro(pos);
    if (obj.getEstado() == true)
    {
        dibujarCuadro(37, 14, 85, 16);
        rlutil::locate(47, 15);
        std::cout << "EL CLIENTE YA ESTA ACTIVO" << std::endl;
        rlutil::locate(44, 17);
        system("pause");
        system("cls");
        return;
    }
    obj.MostrarBaja();
    rlutil::locate(45,29);
    system("pause");
    system("cls");


    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        dibujarCuadro(32,5,87,7);
        rlutil::locate(44,6);
        std::cout<<"DESEA REACTIVAR ESTE CLIENTE?"<<std::endl;
        m.seleccionarItem("SI", 54, 11, y == 0);
        m.seleccionarItem("NO", 54, 12, y == 1);
        m.seleccionarItem("VOLVER", 54, 13, y == 2);

        rlutil::locate(52, 11 + y);
        std::cout << (char)175;

        int key = rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y--;
            if (y < 0)
            {
                y = 2;
            }
            break;
        case 15:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if (y > 2)
            {
                y = 0;
            }
            break;
        case 1:
            switch (y)
            {
            case 0:
            {
                rlutil::cls();
                obj.setEstado(true);
                if (modificarRegistro(obj, pos))
                {
                    system("cls");
                    dibujarCuadro(41,14,82,16);
                    rlutil::locate(45,15);
                    std::cout << "CLIENTE REACTIVADO CORRECTAMENTE" << std::endl;
                    rlutil::locate(43,17);
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    rlutil::cls();
                    dibujarCuadro(41, 14, 82, 16);
                    rlutil::locate(45,15);
                    std::cout << "ERROR AL REACTIVAR CLIENTE" << std::endl;
                    rlutil::locate(443,17);
                    system("pause");
                    rlutil::cls();
                    return;
                }
                opcion = 0;
                break;
            }
            case 1:
            {
                system("cls");
                dibujarCuadro(44,14,79,16);
                rlutil::locate(52,15);
                std::cout<<"OPERACION CANCELADA";
                rlutil::locate(43,17);
                system("pause");
                system("cls");
                opcion = 0;
                break;
            }

            case 2:
            {
                opcion = 0;
                break;
            }
            }

        }
        break;
    }

    while (opcion != 0);

}



void archivoCliente::hacerRespaldoCliente()
{
    FILE *archivoOriginal, *archivoRespaldo;
    archivoOriginal = fopen("clientes.dat", "rb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo clientes.dat" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoRespaldo = fopen("clientes.bkp", "wb");
    if (archivoRespaldo == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo clientes.bkp" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        fclose(archivoOriginal);
        return;
    }

    char buffer[1024];
    size_t bytesLeidos;

    while ((bytesLeidos = fread(buffer, 1, sizeof(buffer), archivoOriginal)) > 0)
    {
        fwrite(buffer, 1, bytesLeidos, archivoRespaldo);
    }

    fclose(archivoOriginal);
    fclose(archivoRespaldo);

    rlutil::cls();
    dibujarCuadro(1, 1, 119, 30);
    rlutil::locate(44,12);
    std::cout << "RESPALDO REALIZADO CON EXITO" << std::endl;
    rlutil::locate(42,14);
    system("pause");
    rlutil::cls();
    dibujarCuadro(1, 1, 119, 30);
}

void archivoCliente::restaurarClientesDesdeBackup()
{
    FILE *archivoBackup, *archivoOriginal;
    archivoBackup = fopen("clientes.bkp", "rb");
    if (archivoBackup == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo clientes.bkp" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoOriginal = fopen("clientes.dat", "wb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo clientes.dat" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        fclose(archivoBackup);
        return;
    }

    char buffer[1024];
    size_t bytesLeidos;

    while ((bytesLeidos = fread(buffer, 1, sizeof(buffer), archivoBackup)) > 0)
    {
        fwrite(buffer, 1, bytesLeidos, archivoOriginal);
    }

    fclose(archivoBackup);
    fclose(archivoOriginal);

    rlutil::cls();
    dibujarCuadro(1, 1, 119, 30);
    rlutil::locate(44,12);
    std::cout << "RESTAURACION REALIZADA CON EXITO" << std::endl;
    rlutil::locate(42,14);
    system("pause");
    rlutil::cls();
    dibujarCuadro(1, 1, 119, 30);
}




