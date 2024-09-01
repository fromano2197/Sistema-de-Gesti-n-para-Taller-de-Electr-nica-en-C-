#include <iostream>
#include "Login.h"
#include "Funciones.h"


char* Login :: getUsuario()
{
    return usuario;
}

char* Login :: getPass()
{
    return pass;
}

bool Login :: getPudoIngresar()
{
    return pudoIngresar;
}

void Login::setPudoIngresar(bool i){
    pudoIngresar=i;
}


void Login::cargarLogin()
{
    dibujarCuadro(1,1,119,30);
	dibujarCuadro(32,5,87,7);
    rlutil::locate(44,6);
    std::cout<<"BIENVENIDO AL SISTEMA DE GESTION"<<std::endl;
    rlutil::locate(51,10);
    std::cout<<"INGRESE USUARIO: ";
    cargarCadena(usuario,20);
    rlutil::locate(51,12);
    std::cout<<"INGRESE PASSWORD: ";
    cargarContrasena(pass,20);


}

void Login :: iniciarSesion ()
{
    bool inicio= false;
    while(cantidadIntentos<=3)
    {
        rlutil::setColor(rlutil::CYAN);

        cargarLogin();
        if ((strcmp(usuario, USUARIO) == 0) && (strcmp(pass, PASS) == 0))
        {
            pudoIngresar=true;
            int f = 67;
            int x = 1000;

            for (int i = 0; i < 3; i++)
            {
                rlutil::locate(57, 25);
                std::cout << "INGRESANDO";
                rlutil::locate(f, 25);
                std::cout << ".";
                f += 1;
                Sleep(x);
            }
            rlutil::cls();
            break;
        }
        else
        {
            int x = 1000;
            rlutil::setColor(rlutil::RED);
            rlutil::locate(48, 25);
            std::cout<<"CREDENCIALES INCORRECTAS";
            Sleep(x);
            rlutil::cls();
        }
        rlutil::cls();
        cantidadIntentos++;

        if(cantidadIntentos==4)
        {
            rlutil::setColor(rlutil::RED);
            dibujarCuadro(26,10,94,14);
            rlutil::locate(28, 12);
            std::cout << "SE AGOTARON LA CANTIDAD DE INTENTOS, VUELVA A INTENTAR MAS TARDE";
        }

    }

}

