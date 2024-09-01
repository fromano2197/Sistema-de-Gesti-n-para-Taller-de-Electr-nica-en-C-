#include <iostream>
#include <cstring>
#include "Reparacion.h"
#include "Funciones.h"
#include "rlutil.h"




int Reparacion::getOrdenReparacion()
{
    return _ordenReparacion;
}
Cliente Reparacion::getCliente()
{
    return _cliente;
}
Articulo& Reparacion::getArticulo()
{
    return _articulo;
}
float Reparacion::getPrecioReparacion()
{
    return _precioReparacion;
}
Fecha& Reparacion::getFechaEntrada()
{
    return _fechaEntrada;
}
Fecha& Reparacion::getFechaSalida()
{
    return _fechaSalida;
}
char* Reparacion::getFalla()
{
    return _falla;
}
char* Reparacion::getReparacion()
{
    return _reparacion;
}
int Reparacion::getTipoReparacion()
{
    return _tipoReparacion;
}
int Reparacion::getTecnico()
{
    return _numTecnico;
}
int Reparacion::getStatus()
{
    return _status;
}
bool Reparacion::getEstado()
{
    return _estado;
}

void Reparacion::setOrdenReparacion(int ordRep)
{
    _ordenReparacion=ordRep;
}
void Reparacion::setCliente(Cliente cliente)
{
    _cliente=cliente;
}
void Reparacion::setArticulo(const Articulo& art)
{
    _articulo = art;
}
void Reparacion::setPrecioReparacion(float precioRep)
{
    _precioReparacion=precioRep;
}
void Reparacion::setFechaEntrada(Fecha fechaIn)
{
    _fechaEntrada=fechaIn;
}
void Reparacion::setFechaSalida(Fecha fechaOut)
{
    _fechaSalida=fechaOut;
}
void Reparacion::setFalla(const char* falla)
{
    strcpy(_falla,falla);
}
void Reparacion::setReparacion(const char* reparacion)
{
    strcpy(_reparacion,reparacion);
}
void Reparacion::setTipoReparacion(int tipoRep)
{
    _tipoReparacion=tipoRep;
}
void Reparacion::setTecnico(int tec)
{
    _numTecnico=tec;
}
void Reparacion::setStatus(int status)
{
    _status=status;
}
void Reparacion::setEstado(bool estado)
{
    _estado=estado;
}

int Reparacion::_ordenReparacionContador=1;

void Reparacion::Cargar()
{
    _ordenReparacion=_ordenReparacionContador++;
    _cliente.CargarReparacion();
    _articulo.CargarReparacion();
    std::cout<<"Falla: ";
    cargarCadena(_falla,49);
    _fechaEntrada.GrabarFechaSistema();
    _fechaSalida;
    strcpy(_reparacion,"-");
    _tipoReparacion=0;
    _status=1;
    int tipoArticulo= _articulo.getTipoArticulo();
    switch (tipoArticulo)
    {
    case 1:
        _numTecnico = 101;
        break;
    case 2:
        _numTecnico = 201;
        break;
    case 3:
        _numTecnico = 301;
        break;
    case 4:
        _numTecnico = 401;
        break;
    case 5:
        _numTecnico = 501;
        break;
    default:
        _numTecnico = 0;
        break;
    }
    std::cout<<"Precio de reparacion: ";
    std::cin>>_precioReparacion;
    _estado=true;

}

void Reparacion::Mostrar()
{
    if(_estado==true)
    {
        std::cout<<"Orden de reparacion: "<<_ordenReparacion<<std::endl;
        _articulo.Mostrar();
        std::cout<<"Precio de reparacion: "<<_precioReparacion<<std::endl;
        _fechaEntrada.Mostrar();
        _fechaSalida.Mostrar();
        std::cout<<"Falla: "<<_falla<<std::endl;
        std::cout<<"Reparacion: "<<_reparacion<<std::endl;
        std::cout<<"Tipo de reparacion: "<<_tipoReparacion<<std::endl;
        std::cout<<"Status: "<<_status<<std::endl;
    }
}

void Reparacion::Mostrar(int i)
{
    int y = 3 + (i * 4);
    int z = y + 1;
    int x = z + 1;
    int w = x + 1;

    if (_estado == true)
    {
        rlutil::locate(1, y);
        std::cout << "ORDEN:";
        rlutil::locate(7, y);
        std::cout <<"#"<< _ordenReparacion;

        _cliente.MostrarReparacion(i);
        _articulo.MostrarReparacion(i);

        rlutil::locate(1, z);
        std::cout << "F.ENTRADA:";
        rlutil::locate(12, z);
        _fechaEntrada.Mostrar();

        rlutil::locate(25, z);
        std::cout << "F.SALIDA:";
        rlutil::locate(35, z);
        _fechaSalida.Mostrar();

        rlutil::locate(49, z);
        std::cout << "FALLA:";
        rlutil::locate(57, z);
        std::cout << _falla;

        rlutil::locate(80, z);
        std::cout << "REPARACION:";
        rlutil::locate(92, z);
        std::cout << _reparacion;

        rlutil::locate(1, x);
        std::cout << "TIPO.REP:";
        rlutil::locate(12, x);
        std::cout << _tipoReparacion;

        rlutil::locate(25, x);
        std::cout << "STATUS:";
        rlutil::locate(33, x);
        std::cout << _status;

        rlutil::locate(45, x);
        std::cout << "PRECIO.REP:";
        rlutil::locate(57, x);
        std::cout << "$" << _precioReparacion;

        dibujarSubrayado(1, w, 114);
    }
}


void Reparacion::MostrarCarga()
{
    if(_estado==true)
    {
        rlutil::locate(45, 12);
        std::cout<<"ORDEN DE REPARACION: ";
        rlutil::locate(67, 12);
        std::cout<<"#"<<_ordenReparacion;
        _cliente.MostrarReparacion();
        _articulo.MostrarReparacion();
        rlutil::locate(13, 22);
        std::cout<<"FALLA: ";
        rlutil::locate(26, 22);
        std::cout<<_falla;
        rlutil::locate(72, 14);
        std::cout<<"FECHA DE ENTRADA";
        rlutil::locate(94, 14);
        _fechaEntrada.Mostrar();
        rlutil::locate(72, 16);
        std::cout<<"FALLA DE SALIDA:";
        rlutil::locate(94, 16);
        _fechaSalida.Mostrar();
        rlutil::locate(72, 18);
        std::cout<<"STATUS: ";
        rlutil::locate(94, 18);
        std::cout<<_status;
        rlutil::locate(72, 20);
        std::cout<<"TECNICO ASIGNADO:";
        rlutil::locate(94, 20);
        std::cout<<_numTecnico;
        rlutil::locate(72, 22);
        std::cout<<"PRECIO DE REPARACION:";
        rlutil::locate(94, 22);
        std::cout<<"$"<<_precioReparacion;
    }
}


void Reparacion::MostrarReparacion()
{
    if(_estado==true)
    {
        rlutil::locate(45, 12);
        std::cout<<"ORDEN DE REPARACION: ";
        rlutil::locate(67, 12);
        std::cout<<"#"<<_ordenReparacion;
        _cliente.MostrarReparacion();
        _articulo.MostrarReparacion();
        rlutil::locate(13, 22);
        std::cout<<"FALLA: ";
        rlutil::locate(26, 22);
        std::cout<<_falla;
        rlutil::locate(13, 24);
        std::cout << "REPARACION:";
        rlutil::locate(26, 24);
        std::cout << _reparacion;
        rlutil::locate(72, 14);
        std::cout<<"FECHA DE ENTRADA";
        rlutil::locate(94, 14);
        _fechaEntrada.Mostrar();
        rlutil::locate(72, 16);
        std::cout<<"FALLA DE SALIDA:";
        rlutil::locate(94, 16);
        _fechaSalida.Mostrar();
        rlutil::locate(72, 18);
        std::cout<<"STATUS: ";
        rlutil::locate(94, 18);
        std::cout<<_status;
        rlutil::locate(72, 20);
        std::cout<<"TECNICO ASIGNADO:";
        rlutil::locate(94, 20);
        std::cout<<_numTecnico;
        rlutil::locate(72, 22);
        std::cout<<"PRECIO DE REPARACION:";
        rlutil::locate(94, 22);
        std::cout<<"$"<<_precioReparacion;
        rlutil::locate(72, 24);
        std::cout << "TIPO.REP:";
        rlutil::locate(94, 24);
        std::cout << _tipoReparacion;
    }
}


void Reparacion::MostrarReparacion(int i)
{
    int y = 3 + (i * 4);
    int z = y + 1;
    int x = z + 1;
    int w = x + 1;

    if (_estado == true)
    {
        rlutil::locate(1, y);
        std::cout << "ORDEN:";
        rlutil::locate(7, y);
        std::cout <<"#"<< _ordenReparacion;

        _cliente.MostrarReparacion(i);
        _articulo.MostrarReparacion(i);

        rlutil::locate(1, z);
        std::cout << "F.ENTRADA:";
        rlutil::locate(12, z);
        _fechaEntrada.Mostrar();

        rlutil::locate(25, z);
        std::cout << "F.SALIDA:";
        rlutil::locate(35, z);
        _fechaSalida.Mostrar();

        rlutil::locate(49, z);
        std::cout << "FALLA:";
        rlutil::locate(57, z);
        std::cout << _falla;

        rlutil::locate(80, z);
        std::cout << "REPARACION:";
        rlutil::locate(92, z);
        std::cout << _reparacion;

        rlutil::locate(1, x);
        std::cout << "TIPO.REP:";
        rlutil::locate(12, x);
        std::cout << _tipoReparacion;

        rlutil::locate(25, x);
        std::cout << "STATUS:";
        rlutil::locate(33, x);
        std::cout << _status;

        rlutil::locate(45, x);
        std::cout << "PRECIO.REP:";
        rlutil::locate(57, x);
        std::cout << "$" << _precioReparacion;

        rlutil::locate(80, x);
        std::cout << "TECNICO:";
        rlutil::locate(89, x);
        std::cout << _numTecnico;

        dibujarSubrayado(1, w, 114);
    }
}


void Reparacion::MostrarReparacionBaja()
{
    if(_estado==true)
    {
        rlutil::locate(45, 12);
        std::cout<<"ORDEN DE REPARACION: ";
        rlutil::locate(67, 12);
        std::cout<<"#"<<_ordenReparacion;
        _cliente.MostrarReparacionBaja();
        _articulo.MostrarReparacion();
        rlutil::locate(13, 22);
        std::cout<<"FALLA: ";
        rlutil::locate(26, 22);
        std::cout<<_falla;
        rlutil::locate(13, 24);
        std::cout << "REPARACION:";
        rlutil::locate(26, 24);
        std::cout << _reparacion;
        rlutil::locate(72, 14);
        std::cout<<"FECHA DE ENTRADA";
        rlutil::locate(94, 14);
        _fechaEntrada.Mostrar();
        rlutil::locate(72, 16);
        std::cout<<"FALLA DE SALIDA:";
        rlutil::locate(94, 16);
        _fechaSalida.Mostrar();
        rlutil::locate(72, 18);
        std::cout<<"STATUS: ";
        rlutil::locate(94, 18);
        std::cout<<_status;
        rlutil::locate(72, 20);
        std::cout<<"TECNICO ASIGNADO:";
        rlutil::locate(94, 20);
        std::cout<<_numTecnico;
        rlutil::locate(72, 22);
        std::cout<<"PRECIO DE REPARACION:";
        rlutil::locate(94, 22);
        std::cout<<"$"<<_precioReparacion;
        rlutil::locate(72, 24);
        std::cout << "TIPO.REP:";
        rlutil::locate(94, 24);
        std::cout << _tipoReparacion;
    }
}




