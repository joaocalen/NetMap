/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaRoteador.c
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
 */

//#include <cstdlib>
#include "Roteador.h"
#include "Enlace.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

// subclasse de Item

ListaRoteadores* inicializaListaRoteadores() {
    ListaRoteadores* lista;
    lista = (ListaRoteadores*) malloc(sizeof (ListaRoteadores));
    lista -> prim = NULL;
    lista -> tam = 0;
    return lista;
}

void insereRoteador(Roteador* roteador, ListaRoteadores* lista) {
    CelulaRoteador* celulaRoteador = (CelulaRoteador*) malloc(sizeof (CelulaRoteador));
    celulaRoteador -> roteador = roteador;
    celulaRoteador -> prox = lista -> prim;
    lista -> prim = celulaRoteador;
    lista -> tam++;
}

// retira o roteador da lista, mas não o destroi.

Roteador* retiraRoteador(ListaRoteadores* lista, char* nome) {
    CelulaRoteador* aux;
    CelulaRoteador* ant;

    ant = buscaRoteadorAnterior(nome, lista);
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
    Roteador* roteador = aux -> roteador;
    roteador -> listaEnlaces = liberaEnlaces(roteador -> listaEnlaces, roteador);
    free(aux);
    return roteador;

}

CelulaRoteador* buscaRoteadorAnterior(char* nome, ListaRoteadores* lista) {
    CelulaRoteador* aux;
    CelulaRoteador* ant = NULL;
    aux = lista -> prim;
    while ((aux != NULL) && (strcmp(aux -> roteador -> nome, nome))) {
        ant = aux;
        aux = aux -> prox;
    }
    return ant;
}

CelulaRoteador* buscaRoteador(char* nome, ListaRoteadores* lista) {
    CelulaRoteador* aux;
    CelulaRoteador* ant = NULL;
    aux = lista -> prim;
    while ((aux != NULL) && (strcmp(aux -> roteador -> nome, nome))) {
        ant = aux;
        aux = aux -> prox;
    }
    return aux;
}

ListaRoteadores* liberaRoteadores(ListaRoteadores* lista) {
    if (lista != NULL) {
        CelulaRoteador* p = lista -> prim;
        CelulaRoteador* aux;
        while (p != NULL) {
            aux = p->prox;
            destroiRoteador(p->roteador);
            free(p);
            p = aux;
        }
        free(lista);
    }
    return NULL;
}

Roteador* inicializaRoteador(char* nome, char* operadora) {
    Roteador* roteador = (Roteador*) malloc(sizeof (Roteador));
    roteador -> nome = (char*) malloc((strlen(nome) + 1) * sizeof (char));
    strcpy(roteador->nome, nome);
    roteador -> operadora = (char*) malloc((strlen(operadora) + 1) * sizeof (char));
    strcpy(roteador -> operadora, operadora);
    roteador -> listaEnlaces = inicializaListaEnlaces();
    roteador -> visto = naoVerificado;
    return roteador;
}

void destroiRoteador(Roteador* roteador) {
    if (roteador != NULL) {
        if (roteador -> listaEnlaces != NULL) {
            roteador -> listaEnlaces = liberaEnlaces(roteador -> listaEnlaces, roteador);
        }
        free(roteador -> operadora);
        free(roteador -> nome);
        free(roteador);
    }    
}

void imprimeRoteadores(ListaRoteadores* lista) {
    if (lista != NULL) {
        CelulaRoteador* p = lista -> prim;
        while (p != NULL) {
            imprimeEnlaces(p->roteador->listaEnlaces, p->roteador);
            p = p -> prox;
        }
    }
}

// jogar para lista de listaEnlaces

// Roteador anterior pode ser NULL, ajeitar sapoha

void conectaRot(Roteador* roteador1, Roteador* roteador2, ListaRoteadores* lista) {
    if (buscaEnlace(roteador1 -> nome, roteador2 -> listaEnlaces) == NULL) {
        insereEnlace(buscaRoteador(roteador1 -> nome, lista), roteador2 -> listaEnlaces);
        insereEnlace(buscaRoteador(roteador2 -> nome, lista), roteador1 -> listaEnlaces);
    }
}

void desconectaRot(Roteador* roteador1, Roteador* roteador2) {
    if (roteador1 != NULL && roteador2 != NULL) {
        retiraEnlace(roteador1 -> listaEnlaces, roteador2 -> nome);
        retiraEnlace(roteador2 -> listaEnlaces, roteador1 -> nome);
    }
}

int frequenciaRoteador(char* operadora, ListaRoteadores* lista) {
    int i = 0;
    if (lista == NULL) {
        printf("NENHUM ROTEADOR");
    } else {
        CelulaRoteador* p = lista -> prim;
        while (p != NULL) {
            if (!strcmp(p-> roteador-> operadora, operadora)) {
                i++;
            }
            p = p -> prox;
        }
    }
    return i;
}

//Utilizando uma lista de enlaces como uma pilha de caminhos

int procuraCaminho(Roteador* roteador1, Roteador* roteador2, ListaRoteadores* lista) {
    return procuraEnlace1Nivel(roteador1, roteador2, lista);
}

// Seta atual para o início e muda flags para naoVerificado
