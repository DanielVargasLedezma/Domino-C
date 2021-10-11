/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.h
 * Author: Dani
 *
 * Created on October 9, 2021, 8:16 PM
 */

#ifndef JUGADOR_H
#define JUGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ficha.h"

typedef struct Jugador
{
    Ficha *fichas[28];
    int numero_fichas;
} Jugador;

extern Ficha *getFichaAlta(Jugador *jugador);

extern Ficha *getAndPopFichaAlta(Jugador *jugador);

extern Ficha *getDobleAlta(Jugador *jugador);

extern Ficha *getAndPopDobleAlta(Jugador *jugador);

extern Ficha *getFichaEnNumero(Jugador *jugador, int numero);

extern Ficha *getFichaAndPopEnNumero(Jugador *jugador, int numero);

extern void shiftAllToLeft(Jugador *jugador);

#endif /* JUGADOR_H */
