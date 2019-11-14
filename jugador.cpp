#include "jugador.h"



Jugador::Jugador(string nombre)
{
    m_string_nombre = nombre;
}



string Jugador::ObtenerNombre()
{
    return m_string_nombre;
}