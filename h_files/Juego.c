/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.c
 * Author: Dani
 * 
 * Created on October 9, 2021, 7:26 PM
 */

#include "../h_files/Juego.h"
#include "Jugador.h"

Ficha *fichas;
Jugador *jugadores[2];

void iniciarJuego()
{
    iniciarFichasRevueltas();
    iniciarJugadores();
    inicializarTablero();
    
    //imprimirFichas();
    
    repartirFichas();
    
    menu();
    
    //imprimirFichasJugador(jugadores[0]);
    
    //imprimirFichasJugador(jugadores[1]);
    
    liberarJugadores();
    liberarFichas();
    liberarMemoriaTablero();
}

void iniciarFichasRevueltas()
{
    srand(time(NULL));
    
    int posiciones_seteadas[28];
    int random;
    
    for(int i = 0; i < 28; i++)
    {
        posiciones_seteadas[i] = 0;
    }
    
    fichas = (Ficha*) malloc(sizeof(Ficha) * 28);
    
    int contador = 0;
    
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            random = rand() % 28;
            
            while(posiciones_seteadas[random] == 1)
            {
                random = rand() % 28;
            }
            
            fichas[random].valores[0] = i;
            fichas[random].valores[1] = j;
            
            fichas[random].estado = 1;
            
            posiciones_seteadas[random] = 1;
            
            contador++;
            
            if(contador == 28)
            {
                break;
            }
        }
    }
}

void iniciarJugadores()
{
    jugadores[0] = (Jugador *) malloc(sizeof(Jugador));
    jugadores[1] = (Jugador *) malloc(sizeof(Jugador));
    
    jugadores[0]->numero_fichas = 0;
    jugadores[1]->numero_fichas = 0;
}

void imprimirFichas()
{
    for(int i = 0; i < 28; i++)
    {
        printf("(%i) [%i | %i]\n", i, fichas[i].valores[0], fichas[i].valores[1]);
    }
}

void imprimirFichasJugador(Jugador *jugador)
{
    printf("Sus fichas: \n\n");

    for(int i = 0; i < jugador->numero_fichas; i++)
    {
        printf("(%i) : [%i | %i] \t", i, jugador->fichas[i]->valores[0], jugador->fichas[i]->valores[1]);
    }
    
    printf("\n\n");
}

void imprimirTablero()
{
    printf("\t");
    
    for(int i = 0; i < table.total; i++)
    {
        if(i == 0)
        {
            if(i == table.total - 1)
            {
                printf(" <-P[%i | %i]U-> ", table.tablero[i]->valores[0], table.tablero[i]->valores[1]);
            }
            else
            {
                printf(" <-P[%i | %i] ", table.tablero[i]->valores[0], table.tablero[i]->valores[1]);
            }
        }
        else if(i == table.total - 1)
        {
            printf(" [%i | %i]U-> ", table.tablero[i]->valores[0], table.tablero[i]->valores[1]);
        }
        else
        {
            printf(" [%i | %i] ", table.tablero[i]->valores[0], table.tablero[i]->valores[1]);
        }
    }
    
    printf("\n \n");
}

void comerDelPozo(Jugador *jugador)
{
    int random;
    
    random = rand() % 28;

    while(fichas[random].estado != 1)
    {
        random = rand() % 28;
    }
    
    fichas[random].estado = 2;
    jugador->fichas[jugador->numero_fichas] = &fichas[random];
    jugador->numero_fichas++;
}

/*
 * Retorna -1 si no esta vacio;
 * Retrona 1 si lo esta
 */
int checkIfPozoVacio()
{
    int contador = 0;
    
    for(int i = 0; i < 28; i++)
    {
        if(fichas[i].estado == 1)
        {
            contador++;
        }
        
        if(contador != 0)
            return -1;
    }
    
    if(contador == 0)
    {
        return 1;
    }
	else
	{
		return -1;
	}
}

void repartirFichas()
{
    int posiciones_seteadas[28];
    int random;
    
    for(int i = 0; i < 28; i++)
    {
        posiciones_seteadas[i] = 0;
    }
    
    for(int i = 0; i < 7; i++)
    {
        random = rand() % 28;
            
        while(posiciones_seteadas[random] == 1)
        {
            random = rand() % 28;
        }
        
        //printf("%i\n", random);
        
        fichas[random].estado = 2;
        jugadores[0]->fichas[jugadores[0]->numero_fichas] = &fichas[random];
        jugadores[0]->numero_fichas++;
        
        posiciones_seteadas[random] = 1;
    }
    
    //printf("\n");
    
    for(int i = 0; i < 7; i++)
    {
        random = rand() % 28;
            
        while(posiciones_seteadas[random] == 1)
        {
            random = rand() % 28;
        }
        
        //printf("%i\n", random);
        
        jugadores[1]->fichas[jugadores[1]->numero_fichas] = &fichas[random];
        jugadores[1]->numero_fichas++;
        
        posiciones_seteadas[random] = 1;
    }
}

void liberarJugadores()
{
    free(jugadores[0]);
    free(jugadores[1]);
}

void liberarFichas()
{
    free(fichas);
}

void darVueltaAFicha(Jugador *jugador, int numero_ficha)
{
    int auxiliar;
    auxiliar = jugador->fichas[numero_ficha]->valores[0];
    jugador->fichas[numero_ficha]->valores[0] = jugador->fichas[numero_ficha]->valores[1];
    jugador->fichas[numero_ficha]->valores[1] = auxiliar;
}

/*
 * Retorna 1 si hay fichas jugables;
 * Retrona -1 si no.
 */
int verificarSiHayFichasJugables(Jugador *jugador)
{
    int contador = 0;
    
    for(int i = 0; i < jugador->numero_fichas; i++)
    {
        if(table.primero->valores[0] == jugador->fichas[i]->valores[0] || table.primero->valores[0] == jugador->fichas[i]->valores[1])
        {
            contador++;
            if(contador > 0)
                return 1;
        }
        else if(table.ultimo->valores[1] == jugador->fichas[i]->valores[0] || table.ultimo->valores[1] == jugador->fichas[i]->valores[1])
        {
            contador++;
            if(contador > 0)
                return 1;
        }
    }
    
    if(contador == 0)
        return -1;
}

void menu()
{
    int jugadorActivo;
    
    int resultado;
    
    int fichaPar = -1;

    Ficha * fichaAltaJugador1 = getDobleAlta(jugadores[0]);
    Ficha * fichaAltaJugador2 = getDobleAlta(jugadores[1]);
    
    if(fichaAltaJugador1 != NULL && fichaAltaJugador2 == NULL)
    {
        printf("Ficha mas alta del jugador 1: [%i | %i]\n\n", fichaAltaJugador1->valores[0], fichaAltaJugador1->valores[1]);
        printf("El jugador 2 no tiene una ficha doble y por ende no tiene nada que comparar\n\n");
        
        resultado = 1;
        
        fichaPar = 1;
    }
    else if(fichaAltaJugador1 == NULL && fichaAltaJugador2 != NULL)
    {
        printf("El jugador 1 no tiene una ficha doble y por ende no tiene nada que comparar\n\n");
        printf("Ficha mas alta del jugador 2: [%i | %i]\n\n", fichaAltaJugador2->valores[0], fichaAltaJugador2->valores[1]);
        
        resultado = -1;
        
        fichaPar = 1;
    }
    else if(fichaAltaJugador1 != NULL && fichaAltaJugador2 != NULL)
    {
        printf("Ficha mas alta del jugador 1: [%i | %i]\n\n", fichaAltaJugador1->valores[0], fichaAltaJugador1->valores[1]);
    
        printf("Ficha mas alta del jugador 2: [%i | %i]\n\n", fichaAltaJugador2->valores[0], fichaAltaJugador2->valores[1]);
        
        resultado = fichaMasAltaEntre(fichaAltaJugador1, fichaAltaJugador2);
        
        fichaPar = 1;
    }
    else
    {
        printf("Ningun jugador tiene una ficha doble, buscando la ficha normal mas alta entre los jugadores...\n\n");
        
        fichaAltaJugador1 = getFichaAlta(jugadores[0]);
        fichaAltaJugador2 = getFichaAlta(jugadores[1]);
        
        printf("Ficha mas alta del jugador 1: [%i | %i]\n\n", fichaAltaJugador1->valores[0], fichaAltaJugador1->valores[1]);
    
        printf("Ficha mas alta del jugador 2: [%i | %i]\n\n", fichaAltaJugador2->valores[0], fichaAltaJugador2->valores[1]);
        
        resultado = fichaMasAltaEntre(fichaAltaJugador1, fichaAltaJugador2);
    }
    
    printf("Determinando el ganador");
    fflush(stdout);
    sleep(1);
    printf(".");
    fflush(stdout); // Force the output to be printed
    sleep(1);
    printf(".");
    fflush(stdout); // Force the output to be printed
    sleep(1);
    printf(".\n\n");
        
    if(resultado == 1)
    {
        jugadorActivo = 0;
        printf("El ganador es el jugador 1, este empieza el juego y pone su ficha alta para empezar\n");
        fflush(stdout);
        sleep(3);
        
        if(fichaPar == 1)
        {
            Ficha *fichaAJugar = getAndPopDobleAlta(jugadores[jugadorActivo]);
            fichaAJugar->estado = 3;
            insertarFicha(fichaAJugar, 0);
        }
        else
        {
            Ficha *fichaAJugar = getAndPopFichaAlta(jugadores[jugadorActivo]);
            fichaAJugar->estado = 3;
            insertarFicha(fichaAJugar, 0);
        }
    }
    else if(resultado == -1)
    {
        jugadorActivo = 1;
        printf("El ganador es el jugador 2, este empieza el juego y pone su ficha alta para empezar\n");
        fflush(stdout);
        sleep(3);
        
        if(fichaPar == 1)
        {
            Ficha *fichaAJugar = getAndPopDobleAlta(jugadores[jugadorActivo]);
            fichaAJugar->estado = 3;
            insertarFicha(fichaAJugar, 0);
        }
        else
        {
            Ficha *fichaAJugar = getAndPopFichaAlta(jugadores[jugadorActivo]);
            fichaAJugar->estado = 3;
            insertarFicha(fichaAJugar, 0);
        }
    }
    else
    {
        return;
    }
    
    while(pedirAccion(jugadores[jugadorActivo], jugadorActivo) != 1)
    {
        if(jugadorActivo == 1)
        {
            jugadorActivo = 0;
        }
        else
        {
            jugadorActivo = 1;
        }   
    }
    
    printf("\n\nEl ganador es el jugador %i!!!\n", jugadorActivo + 1);
    printf("Saliendo en 3 ");
    fflush(stdout);
    sleep(1);
    printf("2 ");
    fflush(stdout); // Force the output to be printed
    sleep(1);
    printf("1 ");
    fflush(stdout); // Force the output to be printed
}

int pedirAccion(Jugador *jugador, int numeroJugador)
{
    printf("\e[1;1H\e[2J");

    printf("Jugador n°%i\n\n", numeroJugador + 1);
    
    printf("El tablero es: \n\n");
    
    imprimirTablero();
    
    imprimirFichasJugador(jugador);
    
    int opcion = 0, invertir = 0, lado = 0;
    
    if(verificarSiHayFichasJugables(jugador) == 1)
    {
        //Elegir de las fichas que tiene
        printf("Digite cual ficha es la que desea jugar.\n");
        printf("Recuerde que la ficha debe tener el valor en el lateral opuesto de donde desea conectarla y poseer el mismo valor.\n");
        printf("Si no tiene el valor en el lateral correcto puede rotar la ficha, para ello digite el valor '404'.\n");
        printf("Rango valido (0 - %i) o 404 para invertir\n", jugador->numero_fichas - 1);
        printf("-> ");
        scanf("%i", &opcion);
        
        if(opcion == 404)
        {
            printf("Digite cual ficha es la que desea invertir.\n");
            printf("Rango valido (0 - %i)\n", jugador->numero_fichas - 1);
            printf("-> ");
            scanf("%i", &invertir);
            
            if(invertir > jugador->numero_fichas || invertir < 0)
            {
                printf("Se ha digitado una ficha que no esta en el rango contemplado, volviendo a la eleccion de ficha...");
                fflush(stdout);
                sleep(2);
                
                return pedirAccion(jugador, numeroJugador);
            }
            
            darVueltaAFicha(jugador, invertir);
            
            return pedirAccion(jugador, numeroJugador);
        }
        else
        {
            if(opcion < 0 || opcion > jugador->numero_fichas)
            {
                printf("Se ha digitado una ficha que no esta en el rango contemplado, volviendo a la eleccion de ficha...");
                fflush(stdout);
                sleep(2);
                
                return pedirAccion(jugador, numeroJugador);
            }
            else
            {
                printf("Digite el lado por el cual desea poner la ficha.\n");
                printf("1) Al lado del primero (la izquierda de este)\n");
                printf("2) Al lado del ultimo (la derecha de este)\n");
                printf("-> ");
                scanf("%i", &lado);
                
                if(lado < 0 || lado > 2)
                {
                    printf("Se ha digitado un lado que no esta en el rango contemplado, volviendo a la eleccion de ficha...");
                    fflush(stdout);
                    sleep(2);
                    
                    return pedirAccion(jugador, numeroJugador);
                }
                
                if(verificarFichaCorrecta(getFichaEnNumero(jugador, opcion), lado) != 1)
                {
                    printf("Se ha digitado una ficha que no posee ningun valor lateral que pueda conectar con el lado que se selecciono, volviendo a la eleccion de ficha...");
                    fflush(stdout);
                    sleep(2);
                    
                    return pedirAccion(jugador, numeroJugador);
                }
                
                if(verificarFichaLadoCorrecto(getFichaEnNumero(jugador, opcion), lado) != 1)
                {
                    printf("Se ha digitado una ficha que no posee el valor en el lateral que se puede conectar con el lado que se selecciono, volviendo a la eleccion de ficha...");
                    fflush(stdout);
                    sleep(2);
                    
                    return pedirAccion(jugador, numeroJugador);
                }
                
                Ficha *fichaAInsertar = getFichaAndPopEnNumero(jugador, opcion);
                
                fichaAInsertar->estado = 3;
                
                insertarFicha(fichaAInsertar, lado);
            }
        }
    }
    else
    {
        //Comer del pozo
        char anything = '\0';
        
        if(checkIfPozoVacio() != 1)
        {
            printf("Usted no tiene fichas para poner. Por eso debe comer del pozo.\n");
            printf("Digite cualquier caracter para comer del pozo.\n");
            printf("-> ");
            scanf("%c", &anything);
            fflush(stdout);
            sleep(1);
            
            if(anything != '\0')
            {
                comerDelPozo(jugador);
            }

            return pedirAccion(jugador, numeroJugador);
        }
        else
        {
            printf("Usted no tiene fichas para poner. Por eso debe comer del pozo, pero el pozo se encuentra vacio....\n");
            printf("Por eso se saltara su turno.\n");

            fflush(stdout);
            sleep(3);
            
            return -1;
        }
    }
    
    if(jugador->numero_fichas == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
    //return 1;
}