#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;


class Jugador
{
private:
    string m_string_nombre;

public:
    Jugador(string nombre);
    string ObtenerNombre();
};
#endif