#include <iostream>
#include "ArchivoReparacion.h"
#include "rlutil.h"
#include "ArchivoCliente.h"
#include "Menu.h"
bool archivoReparacion::grabarRegistro (Reparacion obj)
{
    bool escribio;
    FILE *p;
    p=fopen(_nombre, "ab");
    if (p==NULL)
    {
        return false;
    }
    escribio=fwrite (&obj, sizeof (Reparacion), 1, p);
    fclose(p);
    return escribio;
}

Reparacion archivoReparacion::leerRegistro(int pos)
{
    Reparacion obj;
    FILE *p;
    p=fopen(_nombre, "rb");
    obj.setOrdenReparacion(-5);
    if (p==NULL)
    {
        return obj;
    }
    fseek (p,pos * sizeof (Reparacion),0);
    fread (&obj, sizeof (Reparacion), 1, p);
    fclose(p);
    return obj;
}

int archivoReparacion::buscarRegistro (int num)
{
    Reparacion obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    int pos=0;
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&obj, sizeof (Reparacion), 1,p)==1)
    {
        if (obj.getOrdenReparacion()==num)
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

int archivoReparacion::contarRegistro ()
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
    return tam/sizeof (Reparacion);

}

bool archivoReparacion::modificarRegistro (Reparacion obj, int pos)
{
    FILE *p;
    p=fopen (_nombre,"rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek (p,pos*sizeof (Reparacion),0);
    bool escribio=fwrite (&obj,sizeof (Reparacion), 1,p);
    fclose(p);
    return escribio;
}

bool archivoReparacion::listarRegistro ()
{
    Reparacion obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    if (p==NULL)
    {
        return false;
    }
    int i = 0;
    while (fread(&obj, sizeof (Reparacion), 1,p)==1)
    {
        if (obj.getEstado() == true)
        {
            obj.Mostrar(i);
            i++;
        }
    }
    fclose(p);
    return true;
}
int archivoReparacion::leerUltimOrden()
{
    FILE *p = fopen("ultimaOrdenReparacion.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    int ultimaOrden;
    fread(&ultimaOrden, sizeof(int), 1, p);
    fclose(p);
    return ultimaOrden;
}

void archivoReparacion::guardarUltimOrden(int ultimaOrden)
{
    FILE *p = fopen("ultimaOrdenReparacion.dat", "wb");
    fwrite(&ultimaOrden, sizeof(int), 1, p);
    fclose(p);
}


int archivoReparacion::leerUltimoIdCliente()
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

void archivoReparacion::guardarUltimoIdCliente(int ultimoID)
{
    FILE *p = fopen("ultimoIdCliente.dat", "wb");
    fwrite(&ultimoID, sizeof(int), 1, p);
    fclose(p);
}

void archivoReparacion::altaReparacion()
{
    Reparacion obj;
    rlutil::locate(44, 12);
    obj.Cargar();
    system("cls");
    if (obj.getEstado() == true)
    {
        int ultimaOrden = leerUltimOrden();
        obj.setOrdenReparacion(ultimaOrden + 1);

        Cliente cliente = obj.getCliente();
        archivoCliente archivoClientes;

        int ultimoIdCliente = archivoClientes.leerUltimoIdCliente();
        cliente.setId(ultimoIdCliente + 1);
        archivoClientes.grabarRegistro(cliente);
        archivoClientes.guardarUltimoIdCliente(ultimoIdCliente + 1);

        obj.setCliente(cliente);

        if (grabarRegistro(obj))
        {
            guardarUltimOrden(ultimaOrden + 1);
            obj.MostrarCarga();
            rlutil::locate(45, 28);
            std::cout << "SE CARGO CORRECTAMENTE..." << std::endl;
            rlutil::locate(38, 29);
            system("pause");
        }
        else
        {
            std::cout << "ERROR AL GRABAR EL REGISTRO" << std::endl;
        }
    }
    else
    {
        std::cout << "SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO" << std::endl;
    }
}


bool archivoReparacion::buscarOrden()
{
    Reparacion reg;
    archivoReparacion archi;
    int orden;
    bool bandera=false;
    int cantReg=archi.contarRegistro();
    if(cantReg<=0)
    {
        std::cout<<"PROBLEMAS CON ARCHIVO O ACHIVO INEXISTENTE"<<std::endl;
        return false;
    }



    while (!bandera)
    {
        dibujarCuadro(40,14,83,16);
        rlutil::locate(44,15);
        std::cout<<"INGRESE NUMERO DE ORDEN A BUSCAR: ";
        rlutil::locate(79,15);
        std::cin>>orden;
        system("cls");
        for(int i=0; i<cantReg; i++)
        {
            reg=archi.leerRegistro(i);
            if(reg.getOrdenReparacion()==orden)
            {
                reg.MostrarReparacion();
                bandera =true;
                break;
            }
        }
        if (!bandera)
        {
            dibujarCuadro(32,14,90,16);
            rlutil::locate(40,15);
            std::cout << "EL NUMERO DE ORDEN INGRESADO ES INCORRECTO.";
            return  false;
        }
    }
}


void archivoReparacion::listarPorTecnico()
{
    Reparacion reg;
    archivoReparacion archi;
    int tipo;
    int cantReg = archi.contarRegistro();
    bool bandera = false;
    int pos = 0;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32, 14, 97, 16);
        rlutil::locate(41, 15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }
    while (!bandera)
    {
        dibujarCuadro(40, 14, 76, 16);
        rlutil::locate(44, 15);
        std::cout << "INGRESE NUMERO DE TECNICO: ";
        rlutil::locate(71, 15);
        std::cin >> tipo;
        system("cls");

        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getTecnico() == tipo)
            {
                reg.MostrarReparacion(pos);
                pos++;
                bandera = true;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(32, 14, 97, 16);
            rlutil::locate(41, 15);
            std::cout << "EL NUMERO DE TECNICO INGRESADO NO FUE ENCONTRADO." << std::endl;
            rlutil::locate(45, 18);
            system("pause");
            break;
        }
    }
}


void archivoReparacion::listarPorStatus()
{
    Reparacion reg;
    archivoReparacion archi;
    int tipo;
    int cantReg = archi.contarRegistro();
    bool bandera = false;
    int pos = 0;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32, 14, 97, 16);
        rlutil::locate(41, 15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }
    while (!bandera)
    {
        dibujarCuadro(41, 14, 63, 16);
        rlutil::locate(44, 15);
        std::cout << "INGRESE STATUS: ";
        rlutil::locate(60, 15);
        std::cin >> tipo;
        system("cls");

        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getStatus() == tipo)
            {
                reg.MostrarReparacion(pos);
                pos++;
                bandera = true;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(32, 14, 97, 16);
            rlutil::locate(41, 15);
            std::cout << "EL NUMERO DE STATUS INGRESADO NO FUE ENCONTRADO." << std::endl;
            rlutil::locate(46, 18);
            system("pause");
            break;
        }
    }
}


void archivoReparacion::listarPorFecha()
{
    Reparacion reg;
    archivoReparacion archi;
    Fecha tipo;
    int cantReg = archi.contarRegistro();
    bool bandera = false;
    int pos = 0;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32, 14, 97, 16);
        rlutil::locate(41, 15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }
    while (!bandera)
    {
        dibujarCuadro(32, 14, 80, 19);
        rlutil::locate(50, 15);
        std::cout << "INGRESE FECHA";
        rlutil::locate(70, 15);
        tipo.Cargar();
        system("cls");

        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getFechaEntrada() == tipo)
            {
                reg.MostrarReparacion(pos);
                pos++;
                bandera = true;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(39, 14, 90, 16);
            rlutil::locate(47, 15);
            std::cout << "LA FECHA INGRESADA NO FUE ENCONTRADA." << std::endl;
            rlutil::locate(46, 18);
            system("pause");
            break;
        }
    }
}

void archivoReparacion::listarPorFechaSalida()
{
    Reparacion reg;
    archivoReparacion archi;
    Fecha tipo;
    int cantReg = archi.contarRegistro();
    bool bandera = false;
    int pos = 0;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32, 14, 97, 16);
        rlutil::locate(41, 15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }
    while (!bandera)
    {
        dibujarCuadro(32, 14, 80, 19);
        rlutil::locate(50, 15);
        std::cout << "INGRESE FECHA";
        rlutil::locate(70, 15);
        tipo.Cargar();
        system("cls");

        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getFechaSalida() == tipo)
            {
                reg.MostrarReparacion(pos);
                pos++;
                bandera = true;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(39, 14, 90, 16);
            rlutil::locate(47, 15);
            std::cout << "LA FECHA INGRESADA NO FUE ENCONTRADA." << std::endl;
            rlutil::locate(46, 18);
            system("pause");
            break;
        }
    }
}


void archivoReparacion::modificarCampoReparacion()
{
    int num;
    Menu m;
    dibujarCuadro(42,14,85,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE ORDEN A MODIFICAR: ";
    rlutil::locate(81,15);
    std::cin >> num;
    system("cls");
    int pos = buscarRegistro(num);
    int cont = 0;
    while (pos < 0)
    {
        dibujarCuadro(38,14,70,16);
        rlutil::locate(44,15);
        std::cout << "ORDEN NO ENCONTRADA" << std::endl;
        rlutil::locate(36,18);
        system("pause");
        system("cls");
        dibujarCuadro(35,14,95,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE ORDEN A MODIFICAR: ";
        rlutil::locate(89,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(41,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR LA ORDEN" << std::endl;
            rlutil::locate(44,18);
            system("pause");
            system("cls");
            return;
        }
    }
    Reparacion obj = leerRegistro(pos);
    obj.MostrarReparacion();
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
        m.seleccionarItem("ORDEN", 48, 11, y == 0);
        m.seleccionarItem("DESCRIPCION DE ARTICULO", 48, 12, y == 1);
        m.seleccionarItem("MARCA", 48, 13, y == 2);
        m.seleccionarItem("MODELO", 48, 14, y == 3);
        m.seleccionarItem("TIPO DE ARTICULO", 48, 15, y == 4);
        m.seleccionarItem("FECHA DE ENTRADA", 48, 16, y == 5);
        m.seleccionarItem("FECHA DE SALIDA", 48, 17, y == 6);
        m.seleccionarItem("FALLA", 48, 18, y == 7);
        m.seleccionarItem("REPARACION REALIZADA", 48, 19, y == 8);
        m.seleccionarItem("TIPO DE REPARACION", 48, 20, y == 9);
        m.seleccionarItem("TECNICO ASIGNADO", 48, 21, y == 10);
        m.seleccionarItem("STATUS", 48, 22, y == 11);
        m.seleccionarItem("PRECIO DE REPARACION", 48, 23, y == 12);
        m.seleccionarItem("VOLVER", 48, 24, y == 13);

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
                y = 13;
            }
            break;
        case 15:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if (y > 13)
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
                dibujarCuadro(40,14,82,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE ORDEN:";
                rlutil::locate(78,15);
                std::cin >> id;
                system("cls");
                obj.setOrdenReparacion(id);
                break;
            }
            case 1:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(32, 14, 97, 16);
                rlutil::locate(34, 15);
                std::cout << "INGRESE LA NUEVA DESCRIPCION DEL ARTICULO: ";
                rlutil::locate(77, 15);
                cargarCadena(nombre, 29);
                system("cls");
                obj.getArticulo().setArticulo(nombre);
                break;
            }
            case 2:
            {
                rlutil::cls();
                char marca[30];
                dibujarCuadro(43,14,79,16);
                rlutil::locate(47,15);
                std::cout << "INGRESE LA MARCA: ";
                rlutil::locate(66,15);
                cargarCadena(marca,29);
                system("cls");
                obj.getArticulo().setMarca(marca);
                break;
            }
            case 3:
            {
                rlutil::cls();
                char modelo[30];
                dibujarCuadro(43,14,80,16);
                rlutil::locate(46,15);
                std::cout << "INGRESE EL MODELO: ";
                rlutil::locate(66,15);
                cargarCadena(modelo,29);
                system("cls");
                obj.getArticulo().setModelo(modelo);
                break;
            }
            case 4:
            {
                rlutil::cls();
                int tipo;
                dibujarCuadro(38, 14, 80, 16);
                rlutil::locate(42, 15);
                std::cout << "INGRESE EL NUEVO TIPO DE ARTICULO: ";
                rlutil::locate(77, 15);
                std::cin >> tipo;
                system("cls");
                obj.getArticulo().setTipoArticulo(tipo);
                break;
            }
            case 5:
            {
                rlutil::cls();
                Fecha nuevaFecha;
                dibujarCuadro(40,14,85,19);
                rlutil::locate(44,15);
                std::cout<<"INGRESE NUEVA FECHA DE ENTRADA:";
                nuevaFecha.Cargar();
                obj.setFechaEntrada(nuevaFecha);
                break;
            }
            case 6:
            {
                rlutil::cls();
                Fecha nuevaFecha;
                dibujarCuadro(40,14,85,19);
                rlutil::locate(44,15);
                std::cout<<"INGRESE NUEVA FECHA DE SALIDA:";
                nuevaFecha.Cargar();
                obj.setFechaSalida(nuevaFecha);
                break;
            }
            case 7:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(43,14,80,16);
                rlutil::locate(47,15);
                std::cout << "INGRESE FALLA: ";
                rlutil::locate(63,15);
                cargarCadena(nombre,49);
                system("cls");
                obj.setFalla(nombre);
                break;
            }
            case 8:
            {
                rlutil::cls();
                char nombre[30];
                dibujarCuadro(32,14,97,16);
                rlutil::locate(36,15);
                std::cout << "INGRESE REPARACION REALIZADA: ";
                rlutil::locate(66,15);
                cargarCadena(nombre,49);
                system("cls");
                obj.setReparacion(nombre);
                break;
            }
            case 9:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(45,14,81,16);
                rlutil::locate(47,15);
                std::cout << "INGRESE EL TIPO DE REPARACION:";
                rlutil::locate(78,15);
                std::cin >> id;
                system("cls");
                obj.setTipoReparacion(id);
                break;
            }
            case 10:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(42,14,84,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE TECNICO:";
                rlutil::locate(80,15);
                std::cin >> id;
                system("cls");
                obj.setTecnico(id);
                break;
            }
            case 11:
            {
                rlutil::cls();
                int id;
                dibujarCuadro(45,14,75,16);
                rlutil::locate(47,15);
                std::cout << "INGRESE EL NUEVO STATUS:";
                rlutil::locate(72,15);
                std::cin >> id;
                system("cls");
                obj.setStatus(id);
                break;
            }
            case 12:
            {
                rlutil::cls();
                float id;
                dibujarCuadro(41,14,92,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO PRECIO DE REPARACION:";
                rlutil::locate(83,15);
                std::cin >> id;
                system("cls");
                obj.setPrecioReparacion(id);
                break;
            }


            case 13:
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

        rlutil::cls();
        dibujarCuadro(41,14,92,16);
        rlutil::locate(44,15);
        std::cout << "CLIENTE MODIFICADO CORRECTAMENTE" << std::endl;
        system("cls");
    }
    else
    {
        rlutil::cls();
        dibujarCuadro(41,14,92,16);
        rlutil::locate(44,15);
        std::cout << "ERROR AL MODIFICAR EL CLIENTE" << std::endl;
        system("cls");
    }
}

void archivoReparacion::salidaOrden()
{
    int num;
    Menu m;
    dibujarCuadro(40,14,85,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE ORDEN A ENTREGAR: ";
    rlutil::locate(80,15);
    std::cin >> num;
    system("cls");
    int pos = buscarRegistro(num);
    int cont = 0;
    while (pos < 0)
    {
        dibujarCuadro(38,14,70,16);
        rlutil::locate(44,15);
        std::cout << "ORDEN NO ENCONTRADA" << std::endl;
        rlutil::locate(36,18);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE ORDEN A MODIFICAR: ";
        rlutil::locate(91,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(41,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR LA ORDEN" << std::endl;
            rlutil::locate(44,18);
            system("pause");
            system("cls");
            return;
        }
    }
    Reparacion obj = leerRegistro(pos);
    obj.MostrarReparacion();
    rlutil::locate(45,29);
    system("pause");
    system("cls");

    char respuesta;

    dibujarCuadro(36,14,75,16);
    rlutil::locate(40,15);
    std::cout << "DESEA ENTREGAR LA ORDEN? (S/N): ";
    rlutil::locate(72,15);
    std::cin >> respuesta;
    system("cls");




    if (respuesta=='S'|| respuesta=='s')
    {
        int tipo;
        char rep[50];
        obj.setStatus(4);
        obj.getFechaSalida().GrabarFechaSistema();
        dibujarCuadro(12,14,108,16);
        rlutil::locate(15,15);
        std::cout << "TIPO DE REPARACION REALIZADA (1-REP.NORMAL | 2-REP.CON REPUESTO | 3- ART.NO REPARADO): " << std::endl;
        rlutil::locate(104,15);
        std::cin>>tipo;
        obj.setTipoReparacion(tipo);
        rlutil::cls();
        dibujarCuadro(40,14,90,16);
        rlutil::locate(46,15);
        std::cout << "REPARACION REALIZADA:" << std::endl;
        rlutil::locate(68,15);
        cargarCadena(rep,49);
        obj.setReparacion(rep);
        modificarRegistro(obj, pos);

        rlutil::cls();
        dibujarCuadro(40, 14, 83, 16);
        rlutil::locate(46,15);
        std::cout << "LA ENTREGA SE REALIZO CON EXITO" << std::endl;
        rlutil::locate(42,17);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
    }
    else
    {
        rlutil::cls();
        dibujarCuadro(40,14,71,16);
        rlutil::locate(46,15);
        std::cout << "SE CANCELO LA ENTREGA" << std::endl;
        rlutil::locate(37,17);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);

    }
}

void archivoReparacion::eliminarReparacion()
{
    int num;
    Menu m;
    dibujarCuadro(40,14,85,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE ORDEN A ELIMINAR: ";
    rlutil::locate(80,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "ORDEN NO ENCONTRADA" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(37,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE ORDEN A ELIMINAR: ";
        rlutil::locate(88,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,92,16);
            rlutil::locate(39,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR LA ORDEN" << std::endl;
            rlutil::locate(45,29);
            system("pause");
            system("cls");
            return;
        }
    }

    Reparacion obj = leerRegistro(pos);
    obj.MostrarReparacion();
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
        std::cout<<"DESEA ELIMINAR ESTA ORDEN?"<<std::endl;
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
                    std::cout << "ORDEN ELIMINADA CORRECTAMENTE" << std::endl;
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
                    std::cout << "ERROR AL ELIMINAR ORDEN" << std::endl;
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

void archivoReparacion::reactivarReparacion()
{
    int num;
    Menu m;
    dibujarCuadro(40,14,85,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE EL NUMERO ORDEN A REACTIVAR: ";
    rlutil::locate(81,15);
    std::cin >> num;


    system("cls");

    int pos = buscarRegistro(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(44,14,79,16);
        rlutil::locate(52,15);
        std::cout << "ORDEN NO ENCONTRADA" << std::endl;
        rlutil::locate(43,17);
        system("pause");
        system("cls");
        dibujarCuadro(37,14,85,16);
        rlutil::locate(40,15);
        std::cout << "INGRESE NUEVAMENTE LA ORDEN A REACTIVAR: ";
        rlutil::locate(81,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(37,14,90,16);
            rlutil::locate(42,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR LA ORDEN" << std::endl;
            rlutil::locate(44,17);
            system("pause");
            system("cls");
            return;
        }
    }

    Reparacion obj = leerRegistro(pos);
    if (obj.getEstado() == true)
    {
        dibujarCuadro(37, 14, 85, 16);
        rlutil::locate(47, 15);
        std::cout << "LA REPARACION YA ESTA ACTIVA" << std::endl;
        rlutil::locate(44, 17);
        system("pause");
        system("cls");
        return;
    }
    obj.MostrarReparacionBaja();
    rlutil::locate(45,29);
    system("cls");


    int opcion = -1;
    int y = 0;
    rlutil::hidecursor();

    do
    {
        dibujarCuadro(1, 1, 119, 30);
        dibujarCuadro(32,5,87,7);
        rlutil::locate(44,6);
        std::cout<<"DESEA REACTIVAR ESTA REPARACION?"<<std::endl;
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

float archivoReparacion:: calcularRecaudacionEntreFechas(Fecha fechaInicio, Fecha fechaFin)
{
    float recaudacionTotal = 0.0;
    Reparacion reparacion;

    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return recaudacionTotal;
    }

    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {
        Fecha fechaReparacion = reparacion.getFechaEntrada();

        if (fechaReparacion >= fechaInicio && fechaReparacion <= fechaFin)
        {
            recaudacionTotal += reparacion.getPrecioReparacion();
        }
    }

    fclose(p);
    return recaudacionTotal;
}


float archivoReparacion::calcularRecaudacionDelDia()
{
    float recaudacionTotal = 0.0;
    Reparacion reparacion;

    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir el archivo de reparaciones." << std::endl;
        return recaudacionTotal;
    }

    Fecha fechaActual;
    fechaActual.GrabarFechaSistema();
    while (fread(&reparacion, sizeof(Reparacion), 1, p) == 1)
    {
        Fecha fechaReparacion = reparacion.getFechaEntrada();

        if (fechaReparacion == fechaActual)
        {
            recaudacionTotal += reparacion.getPrecioReparacion();
        }
    }

    fclose(p);
    return recaudacionTotal;
}

void archivoReparacion::hacerRespaldoReparaciones()
{
    FILE *archivoOriginal, *archivoRespaldo;
    archivoOriginal = fopen("reparaciones.dat", "rb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo reparaciones.dat" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoRespaldo = fopen("reparaciones.bkp", "wb");
    if (archivoRespaldo == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo reparaciones.bkp" << std::endl;
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

void archivoReparacion::restaurarReparacionesDesdeBackup()
{
    FILE *archivoBackup, *archivoOriginal;
    archivoBackup = fopen("reparaciones.bkp", "rb");
    if (archivoBackup == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo reparaciones.bkp" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoOriginal = fopen("reparaciones.dat", "wb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo reparaciones.dat" << std::endl;
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

int archivoReparacion::contarReparacionesPendientes()
{
    int contador = 0;
    FILE *p;
    p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return -1;
    }
    Reparacion obj;
    while (fread(&obj, sizeof(Reparacion), 1, p) == 1)
    {
        if (obj.getStatus() == 1)
        {
            contador++;
        }
    }
    fclose(p);
    return contador;
}
