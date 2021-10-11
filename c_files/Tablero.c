/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.c
 * Author: Dani
 * 
 * Created on October 9, 2021, 7:25 PM
 */

#include "../h_files/Tablero.h"

Tablero table;

void inicializarTablero()
{
    table.tablero = (Ficha**) malloc(28 * sizeof(Ficha*));

    for (int i = 0; i < 28; i++)
    {
        table.tablero[i] = NULL;
    }
    
    table.total = 0;
    
    table.primero = NULL;
    table.ultimo = NULL;
}

/*
 * 1 para al lado del primero;
 * 2 para al lado de ultimo
 */
void insertarFicha(Ficha *ficha, int lado)
{
    if(!table.primero)
    {
        table.tablero[table.total] = ficha;
        table.primero = table.tablero[table.total];
        table.ultimo = table.tablero[table.total];
        table.total++;
        
        return;
    }
    
    if(lado == 2)
    {
        table.tablero[table.total] = ficha;
        
        table.ultimo = table.tablero[table.total];
        
        table.total++;
                
        return;
    }
    else if(lado == 1)
    {        
        for(int j = table.total; j > 0; j--)
        {
            table.tablero[j] = table.tablero[j - 1];
        }
        
        table.tablero[0] = ficha;
        
        table.primero = table.tablero[0];
        
        table.total++;
                
        return;
    }
}


/*
 * Retorna 1 si es una ficha correcta;
 * Retorna -1 si no es una ficha correcta.
 * Lado => 1 para al lado del primero (la izquierda), 2 para al lado del ultimo (la derecha)
 */
int verificarFichaCorrecta(Ficha *ficha, int lado)
{
    if(lado == 1)
    {
        if(table.primero->valores[0] == ficha->valores[1] || table.primero->valores[0] == ficha->valores[0])
        {
            return 1;
        }
        
        return -1;
    }
    else if(lado == 2)
    {
        if(table.ultimo->valores[1] == ficha->valores[0] || table.ultimo->valores[1] == ficha->valores[1])
        {
            return 1;
        }
        
        return -1;
    }
    else
    {
        return -1;
    }
}


/*
 * Retorna 1 si es una ficha con el lado correcto;
 * Retorna -1 si no es una ficha con el lado correcto.
 * Lado => 1 para al lado del primero (la izquierda), 2 para al lado del ultimo (la derecha)
 */
int verificarFichaLadoCorrecto(Ficha *ficha, int lado)
{
    if(lado == 1)
    {
        if(table.primero->valores[0] == ficha->valores[1])
        {
            return 1;
        }
        
        return -1;
    }
    else if(lado == 2)
    {
        if(table.ultimo->valores[1] == ficha->valores[0])
        {
            return 1;
        }
        
        return -1;
    }
    else
    {
        return -1;
    }
}

void liberarMemoriaTablero()
{   
    free(table.tablero);
}