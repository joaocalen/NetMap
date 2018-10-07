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

    free(aux);
    roteador -> listaEnlaces = liberaEnlaces(roteador -> listaEnlaces, roteador);
    return roteador;
}

CelulaRoteador* buscaRoteadorAnterior(char* nome, ListaRoteadores* lista) {
    CelulaRoteador* aux;
    CelulaRoteador* ant = NULL;
    aux = lista -> prim;
    while ((aux -> roteador -> nome != nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    return ant;
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
    if (lista == NULL) {
        printf("NENHUM Roteador \n");
    } else {
        CelulaRoteador* p = lista -> prim;
        while (p != NULL) {
            printf("Roteador: %s \n", p->roteador-> nome);
            printf("Operadora: %s \n", p->roteador-> operadora);
            printf("\n\n");
            p = p -> prox;
        }
    }
}

// jogar para lista de listaEnlaces

// Roteador anterior pode ser NULL, ajeitar sapoha
void conectaRoteadores(Roteador* roteador1, Roteador* roteador2, ListaRoteadores* lista) {
    insereEnlace(buscaRoteadorAnterior(roteador2 -> nome, lista) -> prox, roteador1 -> listaEnlaces);
    insereEnlace(buscaRoteadorAnterior(roteador1 -> nome, lista) -> prox, roteador2 -> listaEnlaces);
}

void desconectaRoteadores(Roteador* roteador1, Roteador* roteador2) {
    if (roteador1 != NULL && roteador2 != NULL) {
        retiraEnlace(roteador1 -> listaEnlaces, roteador2 -> nome);
        retiraEnlace(roteador2 -> listaEnlaces, roteador1 -> nome);
    }
}