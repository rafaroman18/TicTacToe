/*******************************************/
/* 		    tictactoe.c                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9
#include "tictactoe.h"

tNodo *nodoInicial()
{
   return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N])
{
   tNodo *Nodo = (tNodo *) malloc(sizeof(tNodo));
   int i, c;
   Nodo->vacias=0;
   for (i=0;i<N;i++){
         c=celdas[i];
         Nodo->celdas[i]=c;
         if (c==0)
	      Nodo->vacias=Nodo->vacias+1;
      }
   return Nodo;
}


tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
{
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    memcpy(nuevo,actual,sizeof(tNodo));
    nuevo->celdas[jugada]=jugador;
    nuevo->vacias--;  // marca la posici�n que indica pone la marca del jugador
    return nuevo;
}
int esValida(tNodo *actual, int jugada){
    return (jugada>=0 && jugada<9 && actual->celdas[jugada]==0) ;  // si est� vac�a la posici�n, la jugada es v�lido
}
int opuesto( int jugador){
    return (jugador * -1);//Jugador 1 y Jugador -1
}

int lleno(tNodo *tablero){
    return (tablero->vacias != 0);
}

int terminal(tNodo *Nodo, int jugador)
{
    unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i=0,res=0;
    while (res==0 && i<8) {
      if(Nodo->celdas[opciones[i][0]] != 0 &&
         Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][1]] &&
         Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][2]])
           res=Nodo->celdas[opciones[i][2]];  //indica que jugador ocupa las casillas ganadoras
      i++;
    }
    return res*100;
}

//NUMERO DE COLUMNAS,FILAS Y DIAGONALES CON X SIN O
//NUMERO DE COLUMNAS,FILAS Y DIAGONALES CON O SIN X
int heuristica(tNodo *nodo)
{
int h,i,contX=0,contO=0;

    int posibilidades[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(i=0;i<N;i++)
    {
        if(nodo->celdas[posibilidades[i][0]]!=-1 && nodo->celdas[posibilidades[i][1]]!=-1 && nodo->celdas[posibilidades[i][2]]!=-1                 //COMPROBAR RAZONAMIENTOS LOGICOS
           && (nodo->celdas[posibilidades[i][0]] || nodo->celdas[posibilidades[i][1]] || nodo->celdas[posibilidades[i][2]]))
        {
            contX++;
        }
    }
    for(i=0;i<N;i++)
    {
        if(nodo->celdas[posibilidades[i][0]]!=1 && nodo->celdas[posibilidades[i][1]]!=1 && nodo->celdas[posibilidades[i][2]]!=1                 //COMPROBAR RAZONAMIENTOS LOGICOS
           && (nodo->celdas[posibilidades[i][0]] || nodo->celdas[posibilidades[i][1]] || nodo->celdas[posibilidades[i][2]])==-1)
        {
            contO++;
        }
    }
    h=contX-contO;
    return h;
}

////////////////////////////////////////
//  VISUALIZACI�N DE NodoS
////////////////////////////////////////

char marca(int i) {
   switch(i) {
     case 1:
          return 'X';
     case 0:
           return ' ';
     case -1:
          return 'O';
     default: return ' ';}
}

void dispNodo(tNodo *b) {
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[0]),marca(b->celdas[1]),marca(b->celdas[2]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[3]),marca(b->celdas[4]),marca(b->celdas[5]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[6]),marca(b->celdas[7]),marca(b->celdas[8]));
     printf("---+---+---\n\n");
}






