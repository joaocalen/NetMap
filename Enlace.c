/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaEnlace.c
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
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
    } else {
        celulaEnlace -> prox = NULL;
        lista -> atual -> prox = celulaEnlace;
        lista -> atual = lista -> atual -> prox;
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
    CelulaEnlace* aux;
    CelulaEnlace* ant;
    ant = buscaEnlaceAnterior(nome, lista);
    if (lista -> prim == NULL) {
        return NULL;
    } else if (lista -> prim = lista -> atual) {
        aux = lista -> prim;
        lista -> prim = NULL;
    } else if (ant -> prox == NULL) {
        return NULL;
    } else {
        aux = ant -> prox;
        ant -> prox = aux -> prox;
        lista -> atual = ant;
    }
    CelulaEnlace* enlace = aux;
    free(aux);
    return enlace;
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
    if (lista != NULL) {
        CelulaEnlace* p = lista -> prim;
        CelulaEnlace* aux;
        Roteador* roteador = (Roteador*) rot;
        while (p != NULL) {
            aux = p->prox;
            desconectaRot(roteador, p->roteador -> roteador);
            p = aux;
        }
        free(lista);
    }
    return NULL;
}

void imprimeEnlaces(ListaEnlaces* lista) {
    if (lista == NULL) {
        printf("NENHUM Enlace");
    } else {
        CelulaEnlace* p = lista -> prim;
        printf("\n Lista de Enlaces:\n");
        while (p != NULL) {
            printf("Roteador: %s \n", p-> roteador -> roteador -> nome);
            printf("Operadora: %s \n", p-> roteador -> roteador -> operadora);
            printf("\n\n");
            p = p->prox;
        }
    }
}

int procuraEnlace1Nivel(void* roteador1, void* roteador2, void* lista) {
    CelulaRoteador* celulaRoteador = buscaRoteador(((Roteador*) roteador1)->nome, (ListaRoteadores*) lista);
    ListaEnlaces* caminho = inicializaListaEnlaces();
    insereEnlaceFim(celulaRoteador, caminho);
    ((Roteador*) roteador1) -> visto = verificado;
    return procuraEnlace(((Roteador*) roteador1), ((Roteador*) roteador2), caminho);
}

int procuraEnlace(void* roteador10, void* roteador20, ListaEnlaces* caminho) {
    Roteador* roteador2 = ((Roteador*) roteador20);
    Roteador* roteador1 = ((Roteador*) roteador10);
    if (roteador2 -> listaEnlaces != NULL && caminho != NULL) {
        CelulaEnlace* aux;
        if (caminho -> atual -> roteador -> roteador -> listaEnlaces != NULL) {
            aux = roteador1 -> listaEnlaces -> atual;
        }
        // pode dar sg fault
        while (aux != NULL && aux -> roteador -> roteador != roteador2 && aux -> roteador -> roteador -> visto == verificado) {
            aux = aux -> prox;
        }
        if (aux == NULL && caminho -> atual == caminho -> prim) {
            return 0;
        } else if (aux == NULL) {
            retiraUltimoEnlace(caminho, caminho -> atual -> roteador -> roteador -> nome);
            caminho -> atual -> roteador -> roteador -> listaEnlaces -> atual = caminho -> atual -> roteador -> roteador -> listaEnlaces -> atual -> prox;
            procuraEnlace(caminho-> atual-> roteador-> roteador, roteador2, caminho);
        } else if (aux -> roteador -> roteador -> visto != verificado) {
            insereEnlaceFim(aux -> roteador -> roteador, caminho);
            aux ->roteador->roteador->visto = verificado;
            procuraEnlace(caminho -> atual -> roteador -> roteador, roteador2, caminho);
        } else if (aux -> roteador -> roteador == roteador2) {
            return 1;
        }
    }
    return 0;
}
//criar outro arquivo para essas funções

