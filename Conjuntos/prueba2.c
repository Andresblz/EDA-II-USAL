#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"


int main(){
    particion P;

    crea(P);
    printf("Situacion INICIAL: ");
    verParticion(P);

    // Se forman las siguientes clases de equivalencia haciendo al primer elemento del conjunto su representante:
    // {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}

    /* {7,0,13,15} */
    if (unir1(13,15,P) && unir1(7,0,P) && unir1(7,13,P))
        printf( "Formada clase de equivalencia {7,0,13,15}\n");
    else
        printf(" No puede formase la clase de equivalencia {7,0,13,15}\n");

    /* {2,3,8,12} */
    if (unir1(8,12,P) && unir1(3,8,P) && unir1(2,3,P))
        printf( "Formada clase de equivalencia {2,3,8,12}\n");
    else
        printf(" No puede formase la clase de equivalencia {2,3,8,12}\n");

    /* {11,1,4,6,14} */
    if (unir1(6,1,P) && unir1(6,4,P) && unir1(11,14,P) && unir1(11,6,P))
        printf( "Formada clase de equivalencia {11,1,4,6,14}\n");
    else
        printf(" No puede formase la clase de equivalencia {11,1,4,6,14}\n");

    /* {9,5,10} */
    if (unir1(5,10,P) && unir1(9,5,P))
        printf( "Formada clase de equivalencia {5,9,10}\n");
    else
        printf(" No puede formase la clase de equivalencia {5,9,10}\n");


    printf("Situacion FINAL:   ");
    verParticion(P);
    printf("\n\nEl elemento 5 pertenence a la clase de equivalencia con representante %d\n",buscar(5,P));

    #ifdef LISTAS
    verClaseEquivalencia(5,P);
    #endif

    // Que operacion seria necesaria para relacionar el elemento 12 con el 15?
}
