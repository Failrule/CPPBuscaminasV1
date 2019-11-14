/**
 * Clase principal Buscaminas.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Jugador
{
private:
	string m_string_nombre;

public:
	Jugador(string nombre);
	~Jugador();
	string ObtenerNombre();
};


//Comentario de la clase
class Juego 
{
private:
	///Puntaje acumulado del jugador
	int m_int_puntajeTotal; 
	///Puntaje del juego actual
	int m_int_puntajeJuego; 
	///Tamaño del tablero
	int m_int_tablero;
	///Dificultad de minas
	int m_int_dificultad;


public:
	Juego();
	~Juego();

	string CargarJugadores(ifstream &a);

	/**
	* @param jugador del juego actual
	*/
	void CargarPuntaje(string jugador);

	/**
	* @param puntajeObtenido del juego actual
	*/
	void Guardar(int puntajeObtenido, string jugador);

	/**
	* Juego
	*/
	void Jugar();

    
     /**
	* @param tablero dimensiones del tablero de juego
	* @param dificultad nivel de dificultad del tablero
	*/
	void ConfigurarNivel(int tablero, int dificultad);


	/**
	* Mostrar Meú
	*/
	void MostrarMenu();

	/**
	* @return puntajeObtenido de todas las partidas realizadas por el jugador
	*/
	int ObtenerPuntaje();


};




Jugador::Jugador(string nombre)
{
	m_string_nombre = nombre;
}

Jugador::~Jugador()
{

}


string Jugador::ObtenerNombre()
{
	return m_string_nombre;
}

Juego::Juego()
{

}

Juego::~Juego()
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
	if (!jugadores.is_open()) {
		//cout << "Error cargando jugadores" << endl;
		ofstream lista ("jugadores");
			lista.close();
		//exit(1);
	} else { 

		listaJugadores = CargarJugadores(jugadores);
			if (listaJugadores.find(jugador) != string::npos){
				cout << "Bienvenido de nuevo " <<jugador <<"!"<< endl;
				string puntajeJugador;
				ifstream puntaje;
				puntaje.open(jugador);

				puntajeJugador = CargarJugadores(puntaje);
				int puntos = atoi(puntajeJugador.c_str());
				
				m_int_puntajeTotal = puntos; //Todo para esto jaja

			} else {
			
			ofstream jugadores;
			jugadores.open("jugadores",ios::app);
			jugadores << jugador<<"\n";
			jugadores.close();
			ofstream puntaje (jugador);
			puntaje.close();
			m_int_puntajeTotal = 0;
			cout << jugador<<" es un nuevón."<< endl;
			
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


	cout << "Tablero nivel: " << dimension << endl;

}


void Juego::MostrarMenu()
{
	
string nombrejugador;

	cout<<"Nombre:\t";

	cin>>nombrejugador;

	Jugador Jugador1(nombrejugador);

	cout<<"Jugador:\t"<<Jugador1.ObtenerNombre()<<endl;

	

	Juego1.CargarPuntaje(Jugador1.ObtenerNombre());
	cout << "===========================" << endl;
	cout << "Jugador: "<< Jugador1.ObtenerNombre()<< endl; 

	


}


int Juego::ObtenerPuntaje()
{
	return m_int_puntajeTotal;
}


int main()
{

	Juego Juego1;


/**

	string nombrejugador;

	cout<<"Nombre:\t";

	cin>>nombrejugador;

	Jugador Jugador1(nombrejugador);

	cout<<"Jugador:\t"<<Jugador1.ObtenerNombre()<<endl;

	Juego Juego1;

	Juego1.CargarPuntaje(Jugador1.ObtenerNombre());

	cout<<"Puntaje:\t"<<Juego1.ObtenerPuntaje()<< endl;
	int puntajeObt;
	cout << "Ganaste:\t";cin>>puntajeObt;
	Juego1.Guardar(puntajeObt,nombrejugador);
	cout<<"Puntaje:\t"<<Juego1.ObtenerPuntaje()<< endl;
**/
	
	return 0;
}