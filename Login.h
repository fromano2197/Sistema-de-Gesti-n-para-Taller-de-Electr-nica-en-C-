#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"


#define USUARIO "admin"
#define PASS "1234"

class Login
{
private:
    char usuario[20];
    char pass[20];
    int cantidadIntentos=1;
    bool pudoIngresar=false;

public:
    char *getUsuario();
    char *getPass();
    bool getPudoIngresar();

    void setPudoIngresar(bool i);

    void cargarLogin();
    void iniciarSesion ();

};
