/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.c
 * Author: Dani
 * 
 * Created on October 9, 2021, 8:16 PM
 */

#include "../h_files/Jugador.h"

Ficha *getFichaAlta(Jugador *jugador)
{
    Ficha *fichaAlta = NULL;

    int valoresAlta[2];
    valoresAlta[0] = -1;
    valoresAlta[1] = -1;

    for (int i = 0; i < jugador->numero_fichas; i++)
    {
        if (jugador->fichas[i]->valores[0] > valoresAlta[0])
        {
            valoresAlta[0] = jugador->fichas[i]->valores[0];
            valoresAlta[1] = jugador->fichas[i]->valores[1];
            fichaAlta = jugador->fichas[i];
        }
        else if(jugador->fichas[i]->valores[0] == valoresAlta[0])
        {
            if(jugador->fichas[i]->valores[1] > valoresAlta[1])
            {
                valoresAlta[0] = jugador->fichas[i]->valores[0];
                valoresAlta[1] = jugador->fichas[i]->valores[1];
                fichaAlta = jugador->fichas[i];
            }
        }
    }

    return fichaAlta;
}

Ficha *getAndPopFichaAlta(Jugador *jugador)
{
    Ficha *fichaAlta = NULL;

    int valoresAlta[2];
    valoresAlta[0] = -1;
    valoresAlta[1] = -1;
    
    int posFichaAlta = -1;

    for (int i = 0; i < jugador->numero_fichas; i++)
    {
        if (jugador->fichas[i]->valores[0] > valoresAlta[0])
        {
            valoresAlta[0] = jugador->fichas[i]->valores[0];
            valoresAlta[1] = jugador->fichas[i]->valores[1];
            fichaAlta = jugador->fichas[i];
            
            posFichaAlta = i;
        }
        else if(jugador->fichas[i]->valores[0] == valoresAlta[0])
        {
            if(jugador->fichas[i]->valores[1] > valoresAlta[1])
            {
                valoresAlta[0] = jugador->fichas[i]->valores[0];
                valoresAlta[1] = jugador->fichas[i]->valores[1];
                fichaAlta = jugador->fichas[i];
                
                posFichaAlta = i;
            }
        }
    }
    
    jugador->fichas[posFichaAlta] = NULL;

    shiftAllToLeft(jugador);
    
    jugador->numero_fichas--;

    return fichaAlta;
}

Ficha *getDobleAlta(Jugador *jugador)
{
    Ficha *fichaAlta = NULL;

    int valoresDobleAlta = -1;

    for (int i = 0; i < jugador->numero_fichas; i++)
    {
        if (jugador->fichas[i]->valores[0] == jugador->fichas[i]->valores[1])
        {
            if(jugador->fichas[i]->valores[0] > valoresDobleAlta)
            {
                valoresDobleAlta = jugador->fichas[i]->valores[0];
                fichaAlta = jugador->fichas[i]; 
            }
        }
    }

    return fichaAlta;
}

Ficha *getAndPopDobleAlta(Jugador *jugador)
{
    Ficha *fichaAlta = NULL;

    int valorDobleAlta = -1;
    
    int posFichaAlta = -1;

    for (int i = 0; i < jugador->numero_fichas; i++)
    {
        if (jugador->fichas[i]->valores[0] == jugador->fichas[i]->valores[1])
        {
            if(jugador->fichas[i]->valores[0] > valorDobleAlta)
            {
                valorDobleAlta = jugador->fichas[i]->valores[0];
                fichaAlta = jugador->fichas[i]; 
                
                posFichaAlta = i;
            }
        }
    }
    
    jugador->fichas[posFichaAlta] = NULL;

    shiftAllToLeft(jugador);
    
    jugador->numero_fichas--;

    return fichaAlta;
}

Ficha *getFichaEnNumero(Jugador *jugador, int numero)
{
    return jugador->fichas[numero];
}

Ficha *getFichaAndPopEnNumero(Jugador *jugador, int numero)
{
    Ficha *ficha = jugador->fichas[numero];
    
    jugador->fichas[numero] = NULL;
    
    shiftAllToLeft(jugador);
    
    jugador->numero_fichas--;
    
    return ficha;
}

void shiftAllToLeft(Jugador *jugador)
{
    for (int i = 0; i < jugador->numero_fichas; i++)
    {
        if(jugador->fichas[i] == NULL)
        {
            jugador->fichas[i] = jugador->fichas[i + 1];
            jugador->fichas[i + 1] = NULL;
        }
    }
}