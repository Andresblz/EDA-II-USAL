#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "grafos.h"


tipoGrafo *creaGrafoT47();

int main(void){
    tipoGrafo *vGrafo;
      int ciclico,distancia,vIni,vFin;
  
    vGrafo = creaGrafoT47();
    iniciar(vGrafo);
    verGrafo(vGrafo);
    // Si no has implementado funciones ProfundidadMejorado, AmplitudMejorado y Oredenación topológica
    // comenta dede línea 19 hasta 28 incluido. Esto no se pide pero debería estar hecho
      printf("\nProfundidad: ");
      profundidadMejorado(5,vGrafo);     // Se necesita profundidad mejorado!!!
     printf("\nAmplitud : ");
     amplitudMejorado(5,vGrafo);    // Se necesita amplitud mejorado!!
    ciclico = ordenTop2(vGrafo);
    if (ciclico==-1)
        printf("\nGrafo ciclico ¡ No es posible la ordenación topológica !");
    else
        verGrafo(vGrafo);

    // A partir de aquí es obligatorio
    vIni=2;
    vFin=8;
      printf("\n\nVersión básica Dijkstra: caminos mínimos desde %d",vIni);
      dijkstra1(vIni,vGrafo);
    verGrafo(vGrafo);
        // Interpretación algoritmo de Dijkstra!!!
    printf("Trayectoria desde %d hasta %d:", vIni,vFin);
    distancia = costeyTrayectoria(vIni,vFin,vGrafo); // Debe mostrar la secuencia de vértices en el camino mínimo!!!!
    if (distancia!=INF) printf("Camino de coste %d \n\n", distancia);
    else printf("No existe camino de %d a %d \n\n",vIni,vFin);

    printf("Todas las trayectorias desde %d:\n", vIni);
    todosCaminosMin(vIni,vGrafo);
    

      printf("\nVersión mejorada Dijkstra: caminos mínimos desde %d",vIni);

      dijkstra2(vIni,vGrafo);
    verGrafo(vGrafo);
        // Interpretación algoritmo de Dijkstra!!!
    printf("\nCaminos Mínimos desde %d\n",vIni);
    todosCaminosMin(vIni,vGrafo);
    
    // A partir de aquí es obligatorio
       vIni=10;
       vFin=1;
         printf("\n\nVersión básica Dijkstra: caminos mínimos desde %d",vIni);
         dijkstra1(vIni,vGrafo);
       verGrafo(vGrafo);
           // Interpretación algoritmo de Dijkstra!!!
       printf("Trayectoria desde %d hasta %d:", vIni,vFin);
       distancia = costeyTrayectoria(vIni,vFin,vGrafo); // Debe mostrar la secuencia de vértices en el camino mínimo!!!!
       if (distancia!=INF) printf("Camino de coste %d \n\n", distancia);
       else printf("No existe camino de %d a %d \n\n",vIni,vFin);

       printf("Todas las trayectorias desde %d:\n", vIni);
       todosCaminosMin(vIni,vGrafo);
       

         printf("\nVersión mejorada Dijkstra: caminos mínimos desde %d",vIni);

         dijkstra2(vIni,vGrafo);
       verGrafo(vGrafo);
           // Interpretación algoritmo de Dijkstra!!!
       printf("\nCaminos Mínimos desde %d\n",vIni);
       todosCaminosMin(vIni,vGrafo);

//    Podéis probar con otros vértices de inicio y fin, con otros grafos ...

//    liberarListas(g);
//    free(g);
}
/************************************************************/
/* Creación del grafo ponderado de la  1 (transparencia 47) */
/************************************************************/
tipoGrafo *creaGrafoT47(){
    pArco  p,aux;
    tipoGrafo *g;

    g=(tipoGrafo *)calloc(1,sizeof(tipoGrafo));

    g->orden=10;
    
    /* 1 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 2;
        p->peso = 13;
        g->directorio[1].lista = p;
        aux = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 6;
        p->peso = 2;
        g->directorio[1].lista->sig = p;
        p->sig = NULL;
    
    /* 2 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 3;
        p->peso = 15;
        g->directorio[2].lista = p;
        p->sig = NULL;
    
    /* 3 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 6;
        p->peso = 4;
        g->directorio[2].lista = p;
        aux = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 11;
        p->peso = 5;
        g->directorio[2].lista->sig = p;
        p->sig = NULL;
    
    /* 4 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 1;
        p->peso = 25;
        g->directorio[3].lista = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 5;
        p->peso = 2;
        g->directorio[3].lista->sig = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 8;
        p->peso = 10;
        g->directorio[3].lista->sig->sig = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 9;
        p->peso = 4;
        g->directorio[3].lista->sig->sig->sig = p;
        p->sig = NULL;
    
    /* 5 */
    g->directorio[4].lista = NULL;
    
    /* 6 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 2;
        p->peso = 3;
        g->directorio[5].lista = p;
        aux = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 5;
        p->peso = 2;
        g->directorio[5].lista->sig = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 7;
        p->peso = 30;
        g->directorio[5].lista->sig->sig = p;
        p->sig = NULL;
    
    /* 7 */
    g->directorio[6].lista = NULL;
    
    /* 8 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 9;
        p->peso = 6;
        g->directorio[7].lista = p;
        p->sig = NULL;
    
    /* 9 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 6;
        p->peso = 13;
        g->directorio[8].lista = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 10;
        p->peso = 2;
        g->directorio[8].lista->sig = p;
        p->sig = NULL;
    
    /* 10 */
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 7;
        p->peso = 1;
        g->directorio[9].lista = p;
    p = (arco *)calloc(1,sizeof(arco));
    //if(!p) liberarListas(g);
        p->v = 11;
        p->peso = 2;
        g->directorio[9].lista->sig = p;
        p->sig = NULL;
    
    /* 11 */
    g->directorio[10].lista = NULL;
    
    return g;
}
