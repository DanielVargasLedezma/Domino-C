/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: Dani
 *
 * Created on October 9, 2021, 7:25 PM
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <stdio.h>
#include <stdlib.h>
#include "Ficha.h"

typedef struct Tablero
{
    Ficha **tablero;
    Ficha *primero;
    Ficha *ultimo;
    int total;
} Tablero;

extern Tablero table;

extern void inicializarTablero();

/*
 * -1 para al lado del primero;
 * 1 para al lado de ultimo
 */
extern void insertarFicha(Ficha *ficha, int lado);

/*
 * Retorna 1 si es una ficha correcta;
 * Retorna -1 si no es una ficha correcta.
 * Lado => 1 para al lado del primero (la izquierda), 2 para al lado del ultimo (la derecha)
 */
extern int verificarFichaCorrecta(Ficha *ficha, int lado);

/*
 * Retorna 1 si es una ficha con el lado correcto;
 * Retorna -1 si no es una ficha con el lado correcto.
 * Lado => 1 para al lado del primero (la izquierda), 2 para al lado del ultimo (la derecha)
 */
extern int verificarFichaLadoCorrecto(Ficha *ficha, int lado);

extern void liberarMemoriaTablero();

#endif /* TABLERO_H */
