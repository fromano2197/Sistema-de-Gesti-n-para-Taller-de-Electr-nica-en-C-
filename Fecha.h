#pragma once
#include <string>
class Fecha
{
private:
    int _dia, _mes,_anio;
public:
    Fecha();
    Fecha(int d, int m, int a);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia (int dia);
    void setMes(int mes);
    void setAnio(int anio);
    bool operator==(const Fecha& aux) const;
    bool operator>=(const Fecha& otra) const;
    bool operator<=(const Fecha& aux) const;
    void GrabarFechaSistema ();
    void Cargar();
    void Mostrar();
    std::string ToString() const;

};
