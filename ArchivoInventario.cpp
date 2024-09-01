#include <iostream>
#include "ArchivoInventario.h"
#include "rlutil.h"
#include "Funciones.h"
#include "Menu.h"
bool archivoInventario::grabarRegistro (Inventario obj)
{
    bool escribio;
    FILE *p;
    p=fopen(_nombre, "ab");
    if (p==NULL)
    {
        return false;
    }
    escribio=fwrite (&obj, sizeof (Inventario), 1, p);
    fclose(p);
    return escribio;
}

void archivoInventario::altaInventario()
{
    Inventario obj;
    rlutil::locate(44, 12);
    obj.Cargar();
    if(obj.getEstado()==true)
    {
        int ultimoID = leerUltimoIdRefaccion();
        obj.setArticuloId(ultimoID + 1);
        grabarRegistro(obj);
        guardarUltimoIdRefaccion(ultimoID + 1);
        dibujarCuadro(38,14,78,16);
        rlutil::locate(41,15);
        std::cout<< "SE DIO DE ALTA UNA NUEVA REFACCION!"<<std::endl;
        rlutil::locate(41,18);
        system ("pause");
    }
    else
    {
        dibujarCuadro(32,14,97,16);
        rlutil::locate(41,15);
        std::cout<<"SE CANCELO LA CARGA DEL REGISTRO EN EL ARCHIVO"<<std::endl;
        rlutil::locate(46,18);
        system ("pause");
    }
}

Inventario archivoInventario::leerRegistro(int pos)
{
    Inventario obj;
    FILE *p;
    p=fopen(_nombre, "rb");
    if (p==NULL)
    {
        return obj;
    }
    fseek (p,pos * sizeof (Inventario),0);
    fread (&obj, sizeof (Inventario), 1, p);
    fclose(p);
    return obj;
}

int archivoInventario::buscarRegistro (int num)
{
    Inventario obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    int pos=0;
    if (p==NULL)
    {
        return -1;
    }
    while (fread(&obj, sizeof (Inventario), 1,p)==1)
    {
        if (obj.getArticulo().getIdArticulo()==num)
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

int archivoInventario::contarRegistro ()
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
    return tam/sizeof (Inventario);

}

bool archivoInventario::modificarRegistro (Inventario obj, int pos)
{
    FILE *p;
    p=fopen (_nombre,"rb+");
    if (p==NULL)
    {
        return false;
    }
    fseek (p,pos*sizeof (Inventario),0);
    bool escribio=fwrite (&obj,sizeof (Inventario), 1,p);
    fclose(p);
    return escribio;
}

void archivoInventario::listarRegistro ()
{
    Inventario obj;
    FILE *p;
    p=fopen (_nombre,"rb");
    if (p==NULL)
    {
        return;
    }
    int i = 0;
    while (fread(&obj, sizeof (Inventario), 1,p)==1)
    {
        if (obj.getEstado() == true)
        {
            obj.Mostrar(i);
            i++;
        }

    }
    fclose(p);
}

void archivoInventario::buscarIdArticulo()
{
    Inventario reg;
    archivoInventario archi;
    int id;
    int cantReg = archi.contarRegistro();
    bool bandera = false;

    if (cantReg <= 0)
    {
        dibujarCuadro(32,14,97,16);
        rlutil::locate(41,15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }

    while (!bandera)
    {
        dibujarCuadro(37,14,75,16);
        rlutil::locate(44,15);
        std::cout << "INGRESE ID DE ARTICULO:";
        rlutil::locate(68,15);
        std::cin >> id;
        system("cls");
        int y=3;
        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getArticulo().getIdArticulo()== id)
            {

                reg.Mostrar(i,y);
                y++;
                bandera = true;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(32,14,97,16);
            rlutil::locate(37,15);
            std::cout << "EL ID INGRESADO NO FUE ENCONTRADO, VUELVA A INGRESARLO." << std::endl;
            rlutil::locate(46,18);
            system ("pause");
            system ("cls");
            break;
        }
    }
}

int archivoInventario::leerUltimoIdRefaccion()
{
    FILE *p = fopen("ultimoIdRefaccion.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    int ultimoID;
    fread(&ultimoID, sizeof(int), 1, p);
    fclose(p);
    return ultimoID;
}

void archivoInventario::guardarUltimoIdRefaccion(int ultimoID)
{
    FILE *p = fopen("ultimoIdRefaccion.dat", "wb");
    fwrite(&ultimoID, sizeof(int), 1, p);
    fclose(p);
}

void archivoInventario::listarPorTipo()
{
    Inventario reg;
    archivoInventario archi;
    int tipo;
    int cantReg = archi.contarRegistro();
    bool bandera = false;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(41,15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }

    while (!bandera)
    {

        dibujarCuadro(37,14,77,16);
        rlutil::locate(44,15);
        std::cout << "INGRESE TIPO DE ARTICULO: ";
        rlutil::locate(71,15);
        std::cin >> tipo;
        system("cls");

        int y=3;
        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getArticulo().getTipoArticulo()== tipo)
            {
                reg.Mostrar(i,y);
                y++;
                bandera = true;
            }
        }

        if (!bandera)
        {

            system("cls");
            dibujarCuadro(32,14,97,16);
            rlutil::locate(37,15);
            std::cout << "EL TIPO INGRESADO NO FUE ENCONTRADO, VUELVA A INGRESARLO." << std::endl;
            rlutil::locate(46,18);
            system ("pause");
            system ("cls");
            break;

        }
    }
}

void archivoInventario::buscarSerie()
{
    Inventario reg;
    archivoInventario archi;
    int serie;
    int cantReg = archi.contarRegistro();
    bool bandera = false;

    if (cantReg <= 0)
    {
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(41,15);
        std::cout << "PROBLEMAS CON ARCHIVO O ARCHIVO INEXISTENTE" << std::endl;
        return;
    }

    while (!bandera)
    {
        dibujarCuadro(37,14,78,16);
        rlutil::locate(44,15);
        std::cout << "INGRESE NUMERO DE SERIE:";
        rlutil::locate(70,15);
        std::cin >> serie;
        system("cls");

        for (int i = 0; i < cantReg; i++)
        {
            reg = archi.leerRegistro(i);

            if (reg.getArticulo().getSerie()== serie)
            {

                reg.Mostrar();
                bandera = true;
                break;
            }
        }

        if (!bandera)
        {
            system("cls");
            dibujarCuadro(32,14,105,16);
            rlutil::locate(35,15);
            std::cout << "EL NUMERO DE SERIE INGRESADO NO FUE ENCONTRADO, VUELVA A INGRESARLO." << std::endl;
            rlutil::locate(48,18);
            system ("pause");
            system ("cls");
            break;
        }
    }
}

void archivoInventario::modificarRefaccion()
{
    int num;
    Menu m;
    dibujarCuadro(40,14,90,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE REFACCION A MODIFICAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");
    int pos = buscarRegistro(num);
    int cont = 0;
    while (pos < 0)
    {
        dibujarCuadro(38,14,70,16);
        rlutil::locate(43,15);
        std::cout << "REFACCION NO ENCONTRADA" << std::endl;
        rlutil::locate(36,18);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(38,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE REFACCION A MODIFICAR: ";
        rlutil::locate(94,15);
        std::cin >> num;
        system("cls");
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(41,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR A LA REFACCION" << std::endl;
            rlutil::locate(44,18);
            system("pause");
            system("cls");
            return;
        }
    }
    Inventario obj = leerRegistro(pos);
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
        m.seleccionarItem("SKU", 48, 12, y == 1);
        m.seleccionarItem("ARTICULO", 48, 13, y == 2);
        m.seleccionarItem("MARCA", 48, 14, y == 3);
        m.seleccionarItem("MODELO", 48, 15, y == 4);
        m.seleccionarItem("TIPO", 48, 16, y == 5);
        m.seleccionarItem("EXISTENCIA", 48, 17, y == 6);
        m.seleccionarItem("VOLVER", 48, 18, y == 7);

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
                y = 7;
            }
            break;
        case 15:
            rlutil::locate(46, 11 + y);
            std::cout << " ";
            y++;
            if (y > 7)
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
                dibujarCuadro(40,14,78,16);
                rlutil::locate(42,15);
                std::cout << "INGRESE EL NUEVO NUMERO DE ID: ";
                rlutil::locate(74,15);
                std::cin >> id;
                system("cls");
                obj.setArticuloId(id);
                break;
            }
            case 1:
            {
                rlutil::cls();
                int sku;
                dibujarCuadro(40,14,75,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO SKU: ";
                rlutil::locate(67,15);
                std::cin >> sku;
                system("cls");
                obj.setSku(sku);
                break;
            }
            case 2:
            {
                rlutil::cls();
                char articulo[30];
                dibujarCuadro(36,14,95,16);
                rlutil::locate(39,15);
                std::cout << "INGRESE EL NUEVO NOMBRE DEL ARTICULO: ";
                rlutil::locate(77,15);
                cargarCadena(articulo,29);
                system("cls");
                obj.setArticulo(articulo);
                break;
            }
            case 3:
            {
                rlutil::cls();
                char marca[30];
                dibujarCuadro(40,14,80,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE LA NUEVA MARCA: ";
                rlutil::locate(67,15);
                cargarCadena(marca,29);
                system("cls");
                obj.setMarca(marca);
                break;
            }
            case 4:
            {
                rlutil::cls();
                char modelo[30];
                dibujarCuadro(40,14,80,16);
                rlutil::locate(42,15);
                std::cout << "INGRESE EL NUEVO MODELO: ";
                rlutil::locate(67,15);
                cargarCadena(modelo,29);
                system("cls");
                obj.setModelo(modelo);
                break;
            }
            case 5:
            {
                rlutil::cls();
                int tipo;
                dibujarCuadro(40,14,78,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE EL NUEVO TIPO: ";
                rlutil::locate(69,15);
                std::cin >> tipo;
                system("cls");
                obj.setTipo(tipo);
                break;
            }
            case 6:
            {
                rlutil::cls();
                int existencia;
                dibujarCuadro(40,14,80,16);
                rlutil::locate(44,15);
                std::cout << "INGRESE LA NUEVA EXISTENCIA: ";
                rlutil::locate(73,15);
                std::cin >> existencia;
                system("cls");
                obj.setExistencia(existencia);
                break;
            }


            case 7:
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








void archivoInventario::eliminarRefaccion()
{
    int num;
    Menu m;
    dibujarCuadro(40,14,89,16);
    rlutil::locate(44,15);
    std::cout << "INGRESE NUMERO DE REFACCION A ELIMINAR: ";
    rlutil::locate(85,15);
    std::cin >> num;
    system("cls");

    int pos = buscarRegistro(num);
    int cont = 0;

    while (pos < 0)
    {
        dibujarCuadro(40,14,75,16);
        rlutil::locate(46,15);
        std::cout << "REFACCION NO ENCONTRADA" << std::endl;
        rlutil::locate(39,17);
        system("pause");
        system("cls");
        dibujarCuadro(32,14,97,16);
        rlutil::locate(37,15);
        std::cout << "INGRESE NUEVAMENTE EL NUMERO DE REFACCION A ELIMINAR: ";
        rlutil::locate(91,15);
        std::cin >> num;
        pos = buscarRegistro(num);
        cont++;
        if (cont == 2)
        {
            dibujarCuadro(32,14,97,16);
            rlutil::locate(44,15);
            std::cout << "SE AGOTARON LOS INTENTOS PARA BUSCAR LA REFACCION" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

    Inventario obj = leerRegistro(pos);
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
        std::cout<<"DESEA ELIMINAR ESTA REFACCION?"<<std::endl;
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
                    rlutil::cls();
                    dibujarCuadro(40,14,84,16);
                    rlutil::locate(44,15);
                    std::cout << "REFACCION ELIMINADA CORRECTAMENTE";
                    rlutil::locate(42,18);
                    system("pause");
                    return;
                }
                else
                {
                    rlutil::cls();
                    dibujarCuadro(40,14,80,16);
                    rlutil::locate(44,15);
                    std::cout << "ERROR AL ELIMINAR REFACCION";
                    rlutil::locate(42,18);
                    system("pause");
                    return;
                }
                opcion = 0;
                break;
            case 1:
                rlutil::cls();
                dibujarCuadro(37,14,70,16);
                rlutil::locate(44,15);
                std::cout<<"OPERACION CANCELADA";
                rlutil::locate(35,18);
                system("pause");
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

void archivoInventario::hacerRespaldoRefacciones()
{
    FILE *archivoOriginal, *archivoRespaldo;
    archivoOriginal = fopen("inventarios.dat", "rb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo inventarios.dat" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoRespaldo = fopen("inventarios.bkp", "wb");
    if (archivoRespaldo == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo inventarios.bkp" << std::endl;
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


void archivoInventario::restaurarRefaccionesDesdeBackup()
{
    FILE *archivoBackup, *archivoOriginal;
    archivoBackup = fopen("inventarios.bkp", "rb");
    if (archivoBackup == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo inventarios.bkp" << std::endl;
        rlutil::locate(42,14);
        system("pause");
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        return;
    }

    archivoOriginal = fopen("inventarios.dat", "wb");
    if (archivoOriginal == NULL)
    {
        rlutil::cls();
        dibujarCuadro(1, 1, 119, 30);
        rlutil::locate(44,12);
        std::cout << "Error al abrir el archivo inventarios.dat" << std::endl;
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



