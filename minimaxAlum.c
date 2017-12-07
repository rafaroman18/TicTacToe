/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe.h"
#define LIMITE 2
tNodo *minimax(tNodo *, int );
int valorMin(tNodo *, int);
int valorMax(tNodo *,int);
int min(int , int );
int max(int , int );


/*tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < N; ++i){
      if (esValida(t,i)) {
            intento=aplicaJugada(t,1,i); //Intenta jugada
            temp =terminal(intento,-1); // Calcula el valor minimax
            if(temp > puntos) {
              puntos = temp;
              mejorJugada = i;
            }
      }}//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}*/


tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}


tNodo *minimax(tNodo *nodo, int jugador)
{
    int max,max_actual,jugada,mejorJugada;
    int contador;
    tNodo *intento= malloc(sizeof(tNodo));
    max=-10000;
    for(jugada=0;jugada<9;jugada++)
    {
        contador=0;
        if(esValida(nodo,jugada))
        {
            intento = aplicaJugada(nodo, jugador, jugada);
            max_actual = valorMin(intento,contador);
            if(max_actual>max)
            {
                max=max_actual;
                mejorJugada=jugada;

    }}}
    nodo=aplicaJugada(nodo,jugador,mejorJugada);
    return nodo;
}

int valorMin(tNodo *nodo,int contador)
{
    int valor_min, jugada, jugador = -1, ganador;
    ganador = terminal(nodo, jugador);
        if (ganador == 0 && nodo->vacias > 0)
        {
            if (contador <= LIMITE)
            {
                valor_min = +10000;
                for (jugada = 0; jugada < 9; jugada++) {
                    if (esValida(nodo, jugada)) {
                        valor_min = min(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada), contador + 1));


                    }
                }
                ganador = valor_min;
            }
            else
            {
                ganador=heuristica(nodo);
            }
        }
        return ganador;

}
int valorMax(tNodo *nodo,int contador) {
    int valor_max, jugada, jugador = 1, ganador;
    ganador = terminal(nodo, jugador);
        if (ganador == 0 && nodo->vacias > 0)
        {
            if (contador <= LIMITE)
            {
                valor_max = -10000;
            for (jugada = 0; jugada < 9; jugada++) {
                if (esValida(nodo, jugada)) {
                    valor_max = max(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada), contador+1));
                }
            }
            ganador = valor_max;
            }
            else
            {
                ganador=heuristica(nodo);
            }
        }
        dispNodo(nodo);
        return ganador;

}
int min(int a, int b)
{
    if(a<b){
        return a;}
    else
        return b;

}

int max(int a, int b)
{
    if(a>b){
        return a;}
    else
        return b;
}
