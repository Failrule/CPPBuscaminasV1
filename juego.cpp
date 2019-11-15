#include "juego.h"

using namespace std;

Juego::Juego()
{

}


string Juego::CargarJugadores(ifstream &a)
{
    string s, contenido;
    while (getline(a, s))
        contenido += s + "\n";
    return contenido;
}

void Juego::CargarPuntaje(string jugador)
{
    string listaJugadores;
    ifstream jugadores;
    jugadores.open("jugadores");
    if (!jugadores.is_open())
    {
        cout << "  Error cargando archivo jugadores\n  Reinicie el juego." << endl;
        ofstream lista ("jugadores");
            lista.close();
        exit(1);
    }
    else
    {

        listaJugadores = CargarJugadores(jugadores);
            if (listaJugadores.find(jugador) != string::npos)
            {
                cout << "  ¡Bienvenido de nuevo " <<jugador <<"!"<< endl;
                string puntajeJugador;
                ifstream puntaje;
                puntaje.open(jugador);

                puntajeJugador = CargarJugadores(puntaje);
                int puntos = atoi(puntajeJugador.c_str());

                m_int_puntajeTotal = puntos; //Todo para esto jaja

            }
            else
            {

            ofstream jugadores;
            jugadores.open("jugadores",ios::app);
            jugadores << jugador<<"\n";
            jugadores.close();
            ofstream puntaje (jugador);
            puntaje.close();
            m_int_puntajeTotal = 0;
            cout << "  " << jugador<<" es un nuevo jugador."<< endl;

            }
    }

}

void Juego::Guardar(int puntajeObtenido, string jugador)
{

    m_int_puntajeJuego = puntajeObtenido;
    m_int_puntajeTotal = m_int_puntajeJuego + m_int_puntajeTotal;


    ofstream puntaje;
    puntaje.open(jugador,ios::out);
    puntaje << m_int_puntajeTotal;


}

void Juego::Jugar()
{
    // El buscaminas
}
void Juego::ConfigurarNivel(int tablero, int dificultad)
{

    int dimension;

    if (tablero == 1)
    {
        dimension = 5;
    }
    if (tablero == 2)
    {
        dimension = 10;
    }
    if (tablero == 3)
    {
        dimension = 15;
    }

    for(int i = 0; i <= dimension; i++ )
    {
      for(int j = 0; j <= dimension; j++)
      {
        // No se cómo más
      }
    }

}


int Juego::ObtenerPuntaje()
{
    return m_int_puntajeTotal;
}
