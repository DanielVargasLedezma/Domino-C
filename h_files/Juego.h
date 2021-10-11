/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: Dani
 *
 * Created on October 9, 2021, 7:26 PM
 */

#ifndef JUEGO_H
#define JUEGO_H
#include <time.h>
#include <ctype.h>
#include <unistd.h>  
#include "Tablero.h"
#include "Jugador.h"

extern Ficha *fichas;

extern Jugador *jugadores[2];

extern void iniciarJuego();

extern void iniciarFichasRevueltas();

extern void iniciarJugadores();

extern void imprimirFichas();

extern void imprimirFichasJugador(Jugador *jugador);

extern void imprimirTablero();

extern void comerDelPozo(Jugador *jugador);

/*
 * Retorna 1 si esta vacio;
 * Retrona -1 si no lo esta
 */
extern int checkIfPozoVacio();

extern void repartirFichas();

extern void liberarJugadores();

extern void liberarFichas();

extern void darVueltaAFicha(Jugador *jugador, int numero_ficha);

/*
 * Retorna 1 si hay fichas jugables;
 * Retrona -1 si no.
 */
extern int verificarSiHayFichasJugables(Jugador *jugador);

extern void menu();

extern int pedirAccion(Jugador *jugador, int numeroJugador);

#endif /* JUEGO_H */
