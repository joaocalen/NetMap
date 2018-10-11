/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



//#include <cstdlib>
#include "Enlace.h"
#include "Roteador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

struct celulaEnlace {
    CelulaEnlace* prox;
    CelulaRoteador* roteador;
};

ListaEnlaces* inicializaListaEnlaces() {
    ListaEnlaces* lista;
    lista = (ListaEnlaces*) malloc(sizeof (ListaEnlaces));
    lista -> prim = NULL;
    lista -> atual = NULL;
    return lista;
}

void insereEnlace(void* roteador, ListaEnlaces* lista) {
    CelulaEnlace* celulaEnlace = (CelulaEnlace*) malloc(sizeof (CelulaEnlace));
    celulaEnlace -> roteador = (CelulaRoteador*) roteador;
    celulaEnlace -> prox = lista -> prim;
    lista -> prim = celulaEnlace;
    lista -> atual = lista -> prim;
}

void insereEnlaceFim(void* roteador, ListaEnlaces* lista) {
    CelulaEnlace* celulaEnlace = (CelulaEnlace*) malloc(sizeof (CelulaEnlace));
    celulaEnlace -> roteador = (CelulaRoteador*) roteador;
    //celulaEnlace -> roteador -> roteador -> visto = verificado;
    if (lista == NULL || lista -> atual == NULL) {
        celulaEnlace -> prox = NULL;
        lista -> atual = lista -> prim = celulaEnlace;
        printf("TROXINHA\n");
    } else {
        celulaEnlace -> prox = NULL;
        lista -> atual -> prox = celulaEnlace;
        lista -> atual = lista -> atual -> prox;
        printf("TROXAO\n");
    }
}

// retira o enlace da lista, mas não o destroi.

CelulaEnlace* retiraEnlace(ListaEnlaces* lista, char* nome) {
    CelulaEnlace* aux;
    CelulaEnlace* ant;
    ant = buscaEnlaceAnterior(nome, lista);
    if (lista -> prim == NULL) {
        return NULL;
    } else if (ant == NULL) {
        aux = lista -> prim;
        lista -> prim = lista -> prim -> prox;
    } else if (ant -> prox == NULL) {
        return NULL;
    } else {
        aux = ant -> prox;
        ant -> prox = aux -> prox;
    }
    CelulaEnlace* enlace = aux;
    free(aux);
    return enlace;
}

CelulaEnlace* retiraUltimoEnlace(ListaEnlaces* lista, char* nome) {
    if (lista != NULL) {
        CelulaEnlace* aux;
        CelulaEnlace* ant;
        ant = buscaEnlaceAnterior(nome, lista);
        if (lista -> prim == NULL) {
            return NULL;
        } else if (lista -> prim == lista -> atual) {
            aux = lista -> prim;
            lista -> prim = NULL;
        } else if (ant -> prox == NULL) {
            return NULL;
        } else {
            aux = ant -> prox;
            ant -> prox = aux -> prox;
            lista -> atual = ant;
        }
        free(aux);
        return ant;
    }
    return NULL;
}

CelulaEnlace* buscaEnlaceAnterior(char* nome, ListaEnlaces* lista) {
    if (lista != NULL) {
        CelulaEnlace* aux;
        CelulaEnlace* ant = NULL;
        aux = lista -> prim;
        while ((aux != NULL) && (aux -> roteador -> roteador -> nome != nome)) {
            ant = aux;
            aux = aux -> prox;
        }
        return ant;
    }
    return NULL;
}

CelulaEnlace* buscaEnlace(char* nome, ListaEnlaces* lista) {
    if (lista != NULL) {
        CelulaEnlace* aux;
        CelulaEnlace* ant = NULL;
        aux = lista -> prim;
        while ((aux != NULL) && (aux -> roteador -> roteador -> nome != nome)) {
            ant = aux;
            aux = aux -> prox;
        }
        return aux;
    }
    return NULL;
}

ListaEnlaces* liberaEnlaces(ListaEnlaces* lista, void* rot) {
    if (lista != NULL && rot != NULL) {
        CelulaEnlace* p = lista -> prim;
        CelulaEnlace* aux;
        Roteador* roteador = (Roteador*) rot;
        while (p != NULL) {
            aux = p->prox;
            desconectaRot(roteador, p->roteador -> roteador);
            p = aux;
        }
        free(lista);
    } else if (rot == NULL) {
        CelulaEnlace* p = lista -> prim;
        CelulaEnlace* aux;
        while (p != NULL) {
            aux = p->prox;
            free(p);
            p = aux;
        }
        free(lista);
    }
    return NULL;
}

void imprimeEnlaces(ListaEnlaces* lista, void* roteador1) {
    FILE *netMap;
    netMap = fopen("saida.dot", "a");
    Roteador* roteador = (Roteador*) roteador1;
    if (lista != NULL) {
        CelulaEnlace* p = lista -> prim;
        while (p != NULL) {
            fprintf(netMap, "    %s -- %s;\n", roteador -> nome, p-> roteador -> roteador -> nome);
            p = p->prox;
        }
    } else {
        fprintf(netMap, "    %s;\n", roteador -> nome);
    }
    fclose(netMap);
}

int procuraEnlace1Nivel(void* roteador10, void* roteador20, void* lista) {
    Roteador* roteador1 = ((Roteador*) roteador10);
    Roteador* roteador2 = ((Roteador*) roteador20);
    ListaRoteadores* listaRoteadores = (ListaRoteadores*) lista;
    CelulaRoteador* celulaRoteador = buscaRoteador(roteador1 -> nome, listaRoteadores);
    ListaEnlaces* caminho = inicializaListaEnlaces();
    insereEnlaceFim(celulaRoteador, caminho);
    return procuraEnlace(roteador1, roteador1, roteador2, caminho);
}

int procuraEnlace(void* roteadorInicio, void* roteadorAtual, void* roteadorFim, ListaEnlaces* caminho) {
    Roteador* roteador3 = ((Roteador*) roteadorInicio);
    Roteador* roteador2 = ((Roteador*) roteadorFim);
    Roteador* roteador1 = ((Roteador*) roteadorAtual);
    roteador3 -> visto = verificado;
    roteador1 -> visto = verificado;
    
    if (roteador2 -> listaEnlaces != NULL && caminho != NULL) {
        CelulaEnlace* aux;
        if (roteador1 -> listaEnlaces != NULL) {
            aux = roteador1 -> listaEnlaces -> atual;
        }
    
        while (aux != NULL && aux -> roteador -> roteador != roteador2 && aux -> roteador -> roteador -> visto == verificado) {
            aux = aux -> prox;
        }
        if (aux == NULL && !strcmp(roteador1->nome, roteador3->nome)) {
    
            FILE *saida;
            saida = fopen("saida.txt", "a");
            fprintf(saida, "NAO\n\n");
            fclose(saida);
            liberaEnlaces(caminho, NULL);
            return 0;
        } else if (aux == NULL) {
            Roteador* ant = retiraUltimoEnlace(caminho, roteador1->nome)->roteador->roteador;
            procuraEnlace(roteador3, ant, roteador2, caminho);            
        } else if (!strcmp(aux -> roteador -> roteador ->nome, roteador2->nome)) {
            FILE *saida;
            saida = fopen("saida.txt", "a");
            fprintf(saida, "SIM\n\n");
            fclose(saida);
            liberaEnlaces(caminho, NULL);
            return 1;
        } else if (aux -> roteador -> roteador -> visto != verificado) {
            insereEnlaceFim(aux -> roteador, caminho);
            aux -> roteador-> roteador-> visto = verificado;
            roteador1 -> listaEnlaces -> atual = aux;
            procuraEnlace(roteador3, aux ->roteador ->roteador, roteador2, caminho);
        }
    }
}
//criar outro arquivo para essas funções

