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

  cout<<"\n  Tablero\n  Pequeño[1] Mediano[2] Grande[3]:\t ";
  cin>>m_int_tablero;

  cout<<"\n  Dificultad\n  Fácil[1] Normal[2] Difícil[3]:\t ";
  cin>>m_int_dificultad;

}

void Juego::MinarTablero()
{
srand (time(NULL));

  switch (m_int_tablero)
  {
    case (1):

     for(int i=0;i<5;i++)
     {
      for(int j=0;j<5;j++)
      {
       m_arr_tPequenio[i][j]=77;
      }
     }

     cout<<"\nTablero limpio\n";
       for(int i=0;i<5;i++)
       {
        for(int j=0;j<5;j++)
        {
         cout<<"  "<<m_arr_tPequenio[i][j]<<" ";
       } cout<<endl<<endl;
       }



     cout<<endl;
     int count = 0;
     int minas = 2;

     while(minas>0)
     {

       cout<<"Paso "<<count<<" ";
       count++;

       int lugar1,lugar2;
       lugar1 = rand() % 5;
       lugar2 = rand() % 5;

       if(m_arr_tPequenio[lugar1][lugar2]==77)
       {
        m_arr_tPequenio[lugar1][lugar2]=88;
        cout<<"Mina "<<minas<<" en puesto "<<lugar1<<lugar2<<endl;

        minas--;

       }
        else
        {
         cout<<"Mina "<<minas<<" repetida "<<lugar1<<lugar2<<endl;

        }


     }

  }//Fin switch

cout<<"\nTablero minado\n";
  for(int i=0;i<5;i++)
  {
   for(int j=0;j<5;j++)
   {
    cout<<"  "<<m_arr_tPequenio[i][j]<<" ";
  } cout<<endl<<endl;
  }


}


int Juego::ObtenerPuntaje()
{
    return m_int_puntajeTotal;
}
