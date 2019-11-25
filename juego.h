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


    std::string CargarJugadores(std::ifstream &a);

    /**
    * @param jugador del juego actual
    */
    void CargarPuntaje(std::string jugador);

    /**
    * @param puntajeObtenido del juego actual
    */
    void Guardar(int puntajeObtenido, std::string jugador);

    /**
    * Juego
    */
    void Jugar();

     /**
    */
    void ConfigurarNivel();

    /**
    * @return puntajeObtenido de todas las partidas realizadas por el jugador
    */
    int ObtenerPuntaje();


};
#endif
