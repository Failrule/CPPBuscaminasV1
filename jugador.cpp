#include "jugador.h"

using namespace std;

Jugador::Jugador(const string &nombre)
{
    m_string_nombre = nombre;
}

string Jugador::ObtenerNombre()
{
    return m_string_nombre;
}
