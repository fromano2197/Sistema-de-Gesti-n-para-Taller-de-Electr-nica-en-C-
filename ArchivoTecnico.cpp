#include <iostream>
#include "archivoTecnico.h"
#include "rlutil.h"
#include "Menu.h"
#include "Contacto.h"

bool archivoTecnico::grabarRegistro (Tecnico obj)
{
    bool escribio;
    FILE *p;
    p=fopen(_nombre, "ab");
    if (p==NULL)
    {
        return false;
    }
    escribio=fwrite (&obj, sizeof (Tecnico), 1, p);
    fclose(p);
    return escribio;
}

void archivoTecnico::altaTecnico()
{
    Tecnico obj;
    rlutil::locate(44, 12);
    obj.Cargar();
    if (obj.getEstado() == true)
    {
        grabarRegistro(obj);
        std::cout << "SE CARGO CORRECTAMENTE..." << std::endl;
    }
    else
    {
        std::cout << "SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO" << std::endl;
    }
}

Tecnico archivoTecnico::leerRegistro(int pos)
{
    Tecnico obj;
    FILE *p;
    p=fopen(_nombre, "rb");
    obj.setId(-5);
    if (p==NULL)
    {
        return obj;
    }
    fseek (p,pos * sizeof (Tecnico),0);
    fread (&obj, sizeof (Tecnico), 1, p);
    fclose(p);
    return obj;
}

int archivoTecnico::buscarRegistro (int num)
{
    Tecnico obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    int pos=0;
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&obj, sizeof (Tecnico), 1,p)==1)
    {
        if (obj.getNumTecnico()==num)
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

int archivoTecnico::contarRegistro ()
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
    return tam/sizeof (Tecnico);

}

bool archivoTecnico::modificarRegistro (Tecnico obj, int pos)
{
    FILE *p;
    p=fopen (_nombre,"rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek (p,pos*sizeof (Tecnico),0);
    bool escribio=fwrite (&obj,sizeof (Tecnico), 1,p);
    fclose(p);
    return escribio;
}

void archivoTecnico::listarRegistro ()
{
    Tecnico obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    if (p==NULL)
    {
        return;
    }
    int i = 0;
    while (fread(&obj, sizeof (Tecnico), 1,p)==1)
    {
        if (obj.getEstado() == true)
        {
            obj.Mostrar(i);
            i++;
        }
    }
    fclose(p);
}

bool archivoTecnico::listarPorNumTecnico()
{
    Tecnico reg;
    archivoTecnico archiCli;
    int numTecnico;
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
        std::cout<<"INGRESE ID DE TECNICO A BUSCAR: ";
        rlutil::locate(77,15);
        std::cin>>numTecnico;
        system("cls");
        for(int i=0; i<cantReg; i++)
        {
            reg=archiCli.leerRegistro(i);
            if(reg.getNumTecnico()==numTecnico)
            {
                reg.MostrarTecnico();
                bandera =true;
                break;
            }
        }
        if (!bandera)
        {
            dibujarCuadro(26,14,101,16);
            rlutil::locate(28,15);
            std::cout << "EL NUMERO DE TECNICO INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
            return  false;
        }
    }
}

bool archivoTecnico::listarPorNombre()
{
    Tecnico reg;
    archivoTecnico archiCli;
    char nombre[30];
    int cantReg = archiCli.contarRegistro();
    bool bandera = false;
    int pos=0;
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    dibujarCuadro(32,14,90,16);
    rlutil::locate(44,15);
    std::cout<<"INGRESE NOMBRE DE TECNICO A BUSCAR: ";
    rlutil::locate(81,15);
    cargarCadena(nombre, 29);
    int y=3;
    system("cls");
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getNombre(), nombre) == 0)
        {
            reg.MostrarTecnico(i,y);
            y++;
            bandera = true;

        }
    }
    if (!bandera)
    {
        dibujarCuadro(32,14,94,16);
        rlutil::locate(33,15);
        std::cout << "EL NOMBRE INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
        return  false;
    }
}


bool archivoTecnico::listarPorApellido()
{
    Tecnico reg;
    archivoTecnico archiCli;
    char nombre[30];
    int cantReg = archiCli.contarRegistro();
    bool bandera = false;
    int pos=0;
    if (cantReg <= 0)
    {
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return false;
    }
    dibujarCuadro(32,14,90,16);
    rlutil::locate(44,15);
    std::cout<<"INGRESE APELLIDO DE TECNICO A BUSCAR: ";
    rlutil::locate(81,15);
    cargarCadena(nombre, 29);
    int y=3;
    system("cls");
    for (int i = 0; i < cantReg; i++)
    {
        reg = archiCli.leerRegistro(i);
        if (strcmp(reg.getApellido(), nombre) == 0)
        {
            reg.MostrarTecnico(i,y);
            y++;
            bandera = true;

        }
    }
    if (!bandera)
    {
        dibujarCuadro(32,14,94,16);
        rlutil::locate(33,15);
        std::cout << "EL NOMBRE INGRESADO NO FUE ENCONTRADO, VUELVA A INTENTARLO.";
        return  false;
    }
}



void archivoTecnico::listarPorDNI()
{
    Tecnico reg;
    archivoTecnico archiCli;
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
        rlutil::locate(44,15);
        std::cout<<"INGRESE DNI DEL TECNICO A BUSCAR: ";
        rlutil::locate(78,15);
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
int archivoTecnico::buscarRegistroPorDni (int dni)
{
    Tecnico obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    int pos=0;
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&obj, sizeof (Tecnico), 1,p)==1)
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

void archivoTecnico::modificarTecnico()
{
    int num;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE Tecnico A MODIFICAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont=0;

    while(pos<0)
    {
        std::cout << "Tecnico NO ENCONTRADO" << std::endl;
        system("pause");
        system("cls");
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE Tecnico A MODIFICAR: ";
        std::cin >> num;
        pos = buscarRegistro(num);
        Tecnico obj = leerRegistro(pos);
        system("cls");
        cont++;
        if (cont==2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(44,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL TECNICO" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }
    Tecnico obj = leerRegistro(pos);
    std::cout << "DATOS ACTUALES DEL TECNICO:" << std::endl;
    obj.Mostrar();

    std::cout << "INGRESE NUEVOS DATOS DEL TECNICO:" << std::endl;
    obj.Cargar();

    if (modificarRegistro(obj, pos))
    {
        std::cout << "TECNICO MODIFICADO CORRECTAMENTE" << std::endl;
    }
    else
    {
        std::cout << "ERROR AL MODIFICAR EL TECNICO" << std::endl;
    }
}


void archivoTecnico::modificarCampoTecnico()
{
    int num;
    Menu m;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE TECNICO A MODIFICAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");
    int pos = buscarRegistro(num);
    int cont = 0;
    while (pos < 0)
    {
        dibujarCuadro(38,14,70,16);
        rlutil::locate(44,15);
        std::cout << "TECNICO NO ENCONTRADO" << std::endl;
        rlutil::locate(36,18);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE TECNICO A MODIFICAR: ";
        rlutil::locate(91,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(41,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL TECNICO" << std::endl;
            rlutil::locate(44,18);
            system("pause");
            system("cls");
            return;
        }
    }
    Tecnico obj = leerRegistro(pos);
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
        m.seleccionarItem("NUMERO DE TECNICO", 48, 11, y == 0);
        m.seleccionarItem("NOMBRE", 48, 12, y == 1);
        m.seleccionarItem("APELLIDO", 48, 13, y == 2);
        m.seleccionarItem("FECHA DE NACIMIENTO", 48, 14, y == 3);
        m.seleccionarItem("DNI", 48, 15, y == 4);
        m.seleccionarItem("VOLVER", 48, 16, y == 5);

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
                dibujarCuadro(40,14,85,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE TECNICO: ";
                rlutil::locate(80,15);
                std::cin >> id;
                system("cls");
                obj.setNumTecnico(id);
                break;
            }
            case 1:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(39,14,79,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO NOMBRE: ";
                rlutil::locate(69,15);
                cargarCadena(nombre,29);
                system("cls");
                obj.setNombre(nombre);
                break;
            }
            case 2:
            {
                rlutil::cls();
                char apellido[30];
                dibujarCuadro(40,14,82,16);
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
                dibujarCuadro(39,14,77,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO DNI: ";
                rlutil::locate(64,15);
                std::cin >> dni;
                system("cls");
                obj.setDni(dni);
                break;
            }


            case 5:
                opcion = 0;
                break;
            default:
                break;
            }
            if (opcion != 0)
            {
                rlutil::cls();
                dibujarCuadro(1, 1, 119, 30);
                rlutil::locate(44,12);
                std::cout << "LA MODIFICACION SE REALIZO CON EXITO" << std::endl;
                rlutil::locate(44,14);
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
        std::cout << "TECNICO MODIFICADO CORRECTAMENTE" << std::endl;
    }
    else
    {
        std::cout << "ERROR AL MODIFICAR EL TECNICO" << std::endl;
    }
}

void archivoTecnico::eliminarTecnico()
{
    int num;
    Menu m;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE EL DNI DEL TECNICO A ELIMINAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistroPorDni(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "TECNICO NO ENCONTRADO" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(34,15);
        std::cout << "INGRESE NUEVAMENTE EL DNI DEL TECNICO A ELIMINAR: ";
        rlutil::locate(88,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistroPorDni(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,92,16);
            rlutil::locate(39,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL TECNICO" << std::endl;
            rlutil::locate(45,29);
            system("pause");
            system("cls");
            return;
        }
    }

    Tecnico obj = leerRegistro(pos);
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
        std::cout<<"DESEA ELIMINAR ESTE TECNICO?"<<std::endl;
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
                    std::cout << "TECNICO ELIMINADO CORRECTAMENTE" << std::endl;
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
                    std::cout << "ERROR AL ELIMINAR TECNICO" << std::endl;
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
void archivoTecnico::reactivarTecnico()
{
    int num;
    Menu m;
    dibujarCuadro(32,14,97,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE EL DNI DEL TECNICO A REACTIVAR: ";
    rlutil::locate(85,15);
    std::cin >> num;


    system("cls");

    int pos = buscarRegistroPorDni(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "TECNICO NO ENCONTRADO" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL DNI DEL TECNICO A REACTIVAR: ";
        rlutil::locate(90,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistroPorDni(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,92,16);
            rlutil::locate(39,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR AL TECNICO" << std::endl;
            rlutil::locate(45,17);
            system("pause");
            system("cls");
            return;
        }
    }

    Tecnico obj = leerRegistro(pos);
    if (obj.getEstado() == true)
    {
        dibujarCuadro(37, 14, 85, 16);
        rlutil::locate(47, 15);
        std::cout << "EL TECNICO YA ESTA ACTIVO" << std::endl;
        rlutil::locate(44, 17);
        system("pause");
        system("cls");
        return;
    }
    obj.MostrarBajaTecnico();
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
        std::cout<<"DESEA REACTIVAR ESTE TECNICO?"<<std::endl;
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
                    std::cout << "TECNICO REACTIVADO CORRECTAMENTE" << std::endl;
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
                    std::cout << "ERROR AL REACTIVAR TECNICO" << std::endl;
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
void archivoTecnico::hacerRespaldoTecnicos()
{
    FILE *archivoOriginal, *archivoRespaldo;
    archivoOriginal = fopen("tecnicos.dat", "rb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo tecnicos.dat" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoRespaldo = fopen("tecnicos.bkp", "wb");
    if (archivoRespaldo == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo tecnicos.bkp" << std::endl;
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

void archivoTecnico::restaurarTecnicosDesdeBackup()
{
    FILE *archivoBackup, *archivoOriginal;
    archivoBackup = fopen("tecnicos.bkp", "rb");
    if (archivoBackup == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo tecnicos.bkp" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoOriginal = fopen("tecnicos.dat", "wb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo tecnicos.dat" << std::endl;
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

