/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ficha.h
 * Author: Dani
 *
 * Created on October 9, 2021, 7:23 PM
 */

#ifndef FICHA_H
#define FICHA_H

typedef struct Ficha
{
    int valores[2];
    
    /*1 para en pozo, 2 para en manos de un jugador, 3 para puesta en el tablero*/
    int estado;
} Ficha;

/*
 * Retorna 1 si la ficha f1 es mas alta;
 * Retorna -1 si la ficha f2 es mas alta
 */
extern int fichaMasAltaEntre(Ficha *f1, Ficha *f2);

#endif /* FICHA_H */
