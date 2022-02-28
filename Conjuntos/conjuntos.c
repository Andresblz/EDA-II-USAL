#include <stdio.h>
#include "conjuntos.h"

/// Incluir aqui el código de las funciones solicitadas para el TAD Conjunto Disjunto
/// en la representación mediante ÁRBOLES añadiendo la mejora de unión por TAMAÑO. 
/// .........................................................................

/* FUNCIONES BASICAS */
void crea(particion P){
    tipoElemento i;

    for(i = 0; i < MAXIMO; i++) P[i] = -1;
}

tipoConjunto buscar(tipoElemento x, particion P){
    if(P[x] == 0) return x;
    else return (buscar(P[x],P));
}

void unir(tipoConjunto x, tipoConjunto y, particion P){
    P[y] = x;
}

/* FUNCION UNIR CON CONTROL DE REPRESENTANTE */
int unir1(tipoConjunto x, tipoConjunto y, particion P){
    
    if(x != -1 && y != -1 && x != y){
        if(P[x] <= P[y]){
            P[x] += P[y];
            P[y] = x;
        } else {
            P[y] += P[x];
            P[x] = y;
        }
        return 1;
    }
    return 0;
}
 
/* FUNCION BUSCAR CON COMPRESION DE CAMINOS */
tipoConjunto buscarCC(tipoElemento x, particion P){
    
    /*
     *  Version de buscar con Compresion de Caminos
     */

    if(P[x] < 0 || x >= MAXIMO) return -1;
    if(P[x] == x) return x;
    
    P[x] = buscarCC(P[x], P);
    return P[x];
    
}

/* FUNCION VER CONTENIDO DE LA PARTICION */
void verParticion(particion P)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%3d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("----");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %3d",i);
    printf("  índices vector\n\n");
}
