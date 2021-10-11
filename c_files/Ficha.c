/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ficha.c
 * Author: Dani
 * 
 * Created on October 9, 2021, 7:23 PM
 */

#include "../h_files/Ficha.h"

/*
 * Retorna 1 si la ficha f1 es mas alta;
 * Retorna -1 si la ficha f2 es mas alta
 */
int fichaMasAltaEntre(Ficha *f1, Ficha *f2)
{
    if(f1->valores[0] > f2->valores[0])
    {
        return 1;
    }
    else if(f2->valores[0] > f1->valores[0])
    {
        return -1;
    }
    else
    {
        if(f1->valores[1] > f2->valores[1])
        {
            return 1;
        }
        else if(f2->valores[1] > f1->valores[1])
        {
            return -1;
        }
    }
    
    return 100;
}