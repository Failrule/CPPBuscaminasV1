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
                cout << "\n ¡Bienvenido de nuevo " <<jugador <<"!\n"<< endl;
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
void Juego::ConfigurarNivel()
{


int dificultad,tablero;


  cout<<"\n  Tablero\n  Pequeño[1] Mediano[2] Grande[3]: ";
  cin>>tablero;
  cout<<"\n  Dificultad\n  Fácil[1] Normal[2] Difícil[3]:   ";
  cin>>dificultad;

    switch (tablero)
    {
      case (1):
        cout << "  Pequeño\n";
        tablero = 3;
        break;
      case (2):
        cout << "  Mediano\n";
        tablero = 5;
        break;
      case (3):
        cout << "  Grande\n";
        tablero = 10;
        break;
      default:
        cout << "  Eso no es un tablero!\n";
        break;

    }

    switch (dificultad)
    {
      case (1):
        cout << "  Fácil\n";
        break;
      case (2):
        cout << "  Normal\n";
        break;
      case (3):
        cout << "  Difícil\n";
        break;
      default:
        cout << "  Eso no es una dificultad!\n";
        break;
}

cout << endl;

int matriz[tablero][tablero];

    for(int i=0; i<tablero; i++)
    {
      for(int j=0; j<tablero; j++)
      {
        matriz[i][j] = 0;
      }
    }

    for(int i=0; i<tablero; i++)
    {
      cout << "  ";
      for(int j=0; j<tablero; j++)
      {
        cout << matriz[i][j] << " " ;
      }      cout << endl;
    }

    cout << endl;


}


int Juego::ObtenerPuntaje()
{
    return m_int_puntajeTotal;
}
