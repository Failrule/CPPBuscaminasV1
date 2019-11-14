#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <fstream>
#include <string>

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
    * @return puntajeObtenido de todas las partidas realizadas por el jugador
    */
    int ObtenerPuntaje();


};
#endif