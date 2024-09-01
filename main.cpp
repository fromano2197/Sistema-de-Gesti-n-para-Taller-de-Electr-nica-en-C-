#include <iostream>
#include "Login.h"
#include "Menu.h"
#include "rlutil.h"
#include "Funciones.h"



int main()
{
    Login l;
    Menu menu;
    l.iniciarSesion();
    if(l.getPudoIngresar()==true){

        menu.mostrarMenu();
    }
    rlutil::locate(44, 30);
    return 0;
}
