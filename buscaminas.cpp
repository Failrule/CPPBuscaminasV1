/**
 * Clase principal Buscaminas.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "jugador.cpp"
#include "juego.cpp"

using namespace std;



int main()
{
   




string nombrejugador;

    cout<<"Nombre:\t";
    cin>>nombrejugador;

    Jugador Jugador1(nombrejugador);

    system("clear");

    cout << endl << "\t\t===========================" << endl;
    cout << "\t\t\tBuscaminas" << endl;
    cout << "  Jugador: "<< Jugador1.ObtenerNombre()<< endl << endl; 


  

    Juego Juego1;

    Juego1.CargarPuntaje(Jugador1.ObtenerNombre());

    cout<<"Puntaje:\t"<<Juego1.ObtenerPuntaje()<< endl;
    int puntajeObt;
    cout << "Ganaste:\t";cin>>puntajeObt;
    Juego1.Guardar(puntajeObt,nombrejugador);
    cout<<"Puntaje:\t"<<Juego1.ObtenerPuntaje()<< endl;
    
    return 0;
}