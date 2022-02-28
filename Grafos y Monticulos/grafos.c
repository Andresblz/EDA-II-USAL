#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafos.h"
#include "monticulo.h"
#include "cola.h"
#include "pila.h"

/* Recorrido en PROFUNDIDAD de un grafo. (Depende del vertice inicial y del tipo de grafo) */
void profundidad(int v_inicio, tipoGrafo * grafo){
    int w;
    pArco  p;
    printf("%d ",v_inicio);
    grafo->directorio[v_inicio].alcanzado = 1;
    p = grafo->directorio[v_inicio].lista;
    while (p != NULL){
        w = p->v;
        if (!grafo->directorio[w].alcanzado)
            profundidad(w,grafo);
        p = p->sig;
    }
}

/*
 *  Recorrido en PROFUNDIDAD de un grafo. (Depende del vertice inicial y del tipo de grafo)
 *  MEJORADO
 */
void profundidadMejorado(int v_inicio, tipoGrafo *grafo){
    iniciar(grafo);
    profundidad(v_inicio, grafo);
    
    for(int i = 1; i <= grafo->orden; i++){
        if(!grafo->directorio[i].alcanzado){
            profundidad(i, grafo);
        }
    }
}


/* Recorrido en AMPLITUD de un grafo. (Depende del vertice inicial y del tipo de grafo) */
void amplitud(int v_inicio, tipoGrafo *grafo){
    int w;
    pArco p;
    Cola c;

    colaCreaVacia(&c);
    colaInserta(&c,v_inicio);
    while (!colaVacia(&c)){
        w = colaSuprime(&c);
        if (!grafo->directorio[w].alcanzado){
            printf("%d ",w);
	        grafo->directorio[w].alcanzado = 1;
        	p = grafo->directorio[w].lista;
            while (p!=NULL){
                w = p->v;
                colaInserta(&c,w);
                p = p->sig;
            }
        }
    }
}

/*
 *  Recorrido en AMPLITUD de un grafo. (Depende del vertice inicial y del tipo de grafo)
 *  MEJORADO
 */
void amplitudMejorado(int v_inicio, tipoGrafo *grafo){
    iniciar(grafo);
    amplitud(v_inicio, grafo);
    
    for(int i = 1; i <= grafo->orden; i++){
        if(!grafo->directorio[i].alcanzado){
            profundidad(i, grafo);
        }
    }
}


/* Función auxiliar para ver el contenido de la estructura que representa un grafo en memoria */
void verGrafo(tipoGrafo *g){
    int i;
    pArco p;

    printf("\nGrafo  (Orden %d)\n\n",g->orden);
    printf("       alc gEnt oTop dist peso ant \n");
    printf("     +----+----+----+----+----+----+\n");

    for(i = 1; i <= g->orden; i++){
        printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado,
                       g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);
        
        if (g->directorio[i].distancia == INF) printf("  * |");
        
        else   printf(" %2d |", g->directorio[i].distancia);
        
        if (g->directorio[i].peso == INF) printf("  * |");
       
        else   printf(" %2d |", g->directorio[i].peso);
        
        printf(" %2d |",g->directorio[i].anterior);
        p = g->directorio[i].lista;
        
        while (p != NULL){
            printf(" ->%2d", p->v);	// Grafos no ponderados
            //printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
            p = p->sig;
        }
        printf("\n");
    }
    printf("     +----+----+----+----+----+----+\n\n");
}


/* EJERCICIO 1 */
void iniciar(tipoGrafo *g){
    int i;
    pArco p;
    
    for(i = 0; i <= g->orden; i++){
        g->directorio[i].alcanzado = 0;
        g->directorio[i].gradoEntrada = 0;
        g->directorio[i].ordenTop = 0;
        g->directorio[i].distancia = INF;
        g->directorio[i].peso = INF;
        g->directorio[i].anterior = 0;
    }
    
    for(i = 0; i <= g->orden; i++){
        p = g->directorio[i].lista;
        while(p != NULL){
            g->directorio[p->v].gradoEntrada++;
            p = p->sig;
        }
    }
}


/* EJERCICIO 2 */
int ordenTop1(tipoGrafo *grafo){
    int i,
        j,
        orden;
    pArco aux;
    
    iniciar(grafo);
    
    orden = 1;
    for(i = 1; i <= grafo->orden; i++){
        j = 1;
        while(j <= grafo->orden && !(grafo->directorio[j].ordenTop == 0 && grafo->directorio[j].gradoEntrada == 0)){
            j++;
        }
        if(j > grafo->orden){
            return -1;
        }
        
        grafo->directorio[j].ordenTop = orden++;
        aux = grafo->directorio[j].lista;
        while(aux != NULL){
            grafo->directorio[aux->v].gradoEntrada--;
            aux = aux->sig;
        }
    }
    return 0;
}

int ordenTop2(tipoGrafo *grafo){
    int i,
        v,
        orden;
    pArco p;
    Cola c;
    
    iniciar(grafo);
    colaCreaVacia(&c);
    
    for(i = 1; i <= grafo->orden; i++){
        if(grafo->directorio[i].gradoEntrada == 0){
            colaInserta(&c, i);
        }
    }
    
    orden = 1;
    while(!colaVacia(&c)){
        v = colaSuprime(&c);
        grafo->directorio[v].ordenTop = orden++;
        p = grafo->directorio[v].lista;
        while(p != NULL){
            grafo->directorio[p->v].gradoEntrada--;
            if(grafo->directorio[p->v].gradoEntrada == 0){
                colaInserta(&c, p->v);
            }
            p = p->sig;
        }
    }
    return (orden >= grafo->orden)? (0) : (-1);
}

/* EJERCICIO 3 */
/* PONDERADOS */
void dijkstra1(int vInicio, tipoGrafo *g){
    int i,j,v;
    pArco p;

    iniciar(g);
    g->directorio[vInicio].distancia = 0;
    g->directorio[vInicio].anterior = 0;

    for(i=0; i<g->orden; i++){
        v = -1;
        for(j=1;j<=g->orden; j++){
            if((v==-1 ||g->directorio[j].distancia < g->directorio[v].distancia) && g->directorio[j].alcanzado==0)
                v = j;
        }
        if(-1 != v){
            g->directorio[v].alcanzado = 1;
            p = g->directorio[v].lista;
            while(NULL != p){
                if(g->directorio[p->v].alcanzado == 0 && g->directorio[p->v].distancia > (g->directorio[v].distancia + p->peso)){
                    g->directorio[p->v].anterior = v;
                    g->directorio[p->v].distancia = g->directorio[v].distancia + p->peso;
                }
                p = p->sig;
            }
        }

    }
}


void dijkstra2(int vInicio, tipoGrafo *g){
    int v;
    Monticulo m;
    tipoElementoMonticulo e = {0,0};
    pArco p;
    
    iniciar(g);
    iniciaMonticulo(&m);

    g->directorio[vInicio].distancia = 0;
    g->directorio[vInicio].anterior = 0;

    e.clave = 0;
    e.informacion = vInicio;
    insertar(e,&m);

    while(!vacioMonticulo(m)){
        eliminarMinimo(&m,&e);
        v = e.informacion;

        g->directorio[v].alcanzado = 1;

        p = g->directorio[v].lista;
        while(NULL != p){
            if(g->directorio[p->v].alcanzado == 0 && g->directorio[p->v].distancia > g->directorio[v].distancia + p->peso){
                g->directorio[p->v].anterior = v;
                g->directorio[p->v].distancia = g->directorio[v].distancia + p->peso;
                    e.informacion = p->v;
                    e.clave = g->directorio[p->v].distancia;
                insertar(e,&m);
            }
            p = p->sig;
        }
    }
}

int costeyTrayectoria(int vIni, int vFin, tipoGrafo *g){
    int v,i,coste;
    Pila p;
    char string[100];
    memset(string,'\0',sizeof(string));

    v = vFin;
    pilaCreaVacia(&p);
    while(v != vIni && v != 0){
        pilaInserta(&p,v);
        v = g->directorio[v].anterior;
    }
    pilaInserta(&p,vIni);

    coste = 0;
    if(v == 0){
        printf("No hay");
        return -1;
    }else{
        i=0;
        while(!pilaVacia(&p)){
            v = pilaSuprime(&p);
            string[i++] = 'v';
            string[i++] = v+'0';
            string[i++] = ',';
            string[i] = ' ';
        }
        string[i] = string[i-1] = '\0';
        coste = g->directorio[vFin].distancia-g->directorio[vIni].distancia;
        printf("%-10s\tCoste:%d",string,coste);
        return coste;
    }
}

void todosCaminosMin(int vIni, tipoGrafo *g){
    int i;

    for(i=1; i<=g->orden; i++){
        printf("\nv%d: ",i);
        costeyTrayectoria(vIni,i,g);
    }
    printf("\n");
}
