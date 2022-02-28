#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"

int main(){
    particion P;

    crea(P);
    printf("Situacion INICIAL: ");
    verParticion(P);

    // Se forman las siguientes clases de equivalencia haciendo al primer elemento del conjunto su representante:
    // {5,1,7,8,9,13}, {11,3,4,14,15}, {2,6,12,10,0}

    /* {5,1,7,8,9,13} */
    if (unir1(9,8,P) && unir1(7,1,P) && unir1(5,13,P) && unir1(5,9,P) && unir1(5,7,P))
        printf("Formada clase de equivalencia {5,1,7,8,9,13}\n");
    else
        printf("No puede formase la clase de equivalencia {5,1,7,8,9,13}\n");

    /* {11,3,4,14,15} */
    if (unir1(14,4,P) && unir1(14,3,P) && unir1(11,15,P) && unir1(11,14,P))
        printf("Formada clase de equivalencia {11,3,4,14,15}\n");
    else
        printf("No puede formase la clase de equivalencia {11,3,4,14,15}\n");

    /* {2,6,12,10,0} */
    if (unir1(10,6,P) && unir1(10,12,P) && unir1(2,0,P) && unir1(2,10,P))
        printf("Formada clase de equivalencia {2,6,12,10,0}\n");
    else
        printf("No puede formase la clase de equivalencia {2,6,12,10,0}\n");

    printf("Situacion FINAL:   ");
    verParticion(P);
    printf("\n\nEl elemento 5 pertenence a la clase de equivalencia con representante %d\n",buscar(5,P));

    #ifdef LISTAS
    verClaseEquivalencia(5,P);
    #endif
}
