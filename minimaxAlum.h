/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

tNodo *jugadaAdversario(tNodo *t);
tNodo *PSEUDOminimax(tNodo *Nodo);
tNodo *minimax(tNodo *nodo, int jugador);
int valorMin(tNodo *nodo);
int valorMax(tNodo *nodo);
int minimo(int a,int b);
int maximo(int a, int b);
