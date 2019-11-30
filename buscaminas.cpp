/**
 * Clase principal Buscaminas.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "jugador.h"
#include "juego.h"

using namespace std;

int main()
{

    string nombrejugador;
    int tablero, dificultad;

    cout<<"  Nombre:\t";
    cout.flush();
    //cin>>nombrejugador;
    nombrejugador="a";

    Jugador Jugador1(nombrejugador);

    //system("clear");

    cout << endl << "\t\t===========================" << endl;
    cout << "\t\t\tBuscaminas" << endl;

    Juego Juego1;

    Juego1.CargarPuntaje(Jugador1.ObtenerNombre());



    cout<<"  Puntaje actual:\t"<<Juego1.ObtenerPuntaje()<< endl;
    cout << endl << "\t\t===========================" << endl;
    cout << "\t\t\tNuevo juego:" << endl;
    cout << endl << "\t\t===========================" << endl;



    Juego1.ConfigurarNivel();
    Juego1.MinarTablero();
    Juego1.RastrearMinas();



  //  int puntajeObt;
  //  cout << "Ganaste:\t";cin>>puntajeObt;
  //  Juego1.Guardar(puntajeObt,nombrejugador);
  //  cout<<"Puntaje:\t"<<Juego1.ObtenerPuntaje()<< endl << endl;



    return 0;
}
