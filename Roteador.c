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

struct roteador {
    char* nome;
    char* operadora;
};

struct celulaRoteador {
    Roteador* roteador;
    CelulaRoteador* prox;
    CelulaEnlace* enlace;
};

struct listaRoteadores {
    CelulaRoteador* prim;
    int tam; // tam max para caminho em pilha
};

ListaRoteadores* inicializaListaRoteadores() {
    ListaRoteadores* lista;
    lista = (ListaRoteadores*) malloc(sizeof (ListaRoteadores));
    lista -> prim = NULL;
    lista -> tam = 0;
    return lista;
}

void insereRoteador(Roteador* roteador, ListaRoteadores* lista) {
    CelulaRoteador* celulaRoteador = (CelulaRoteador*) malloc(sizeof (CelulaRoteador));
    celulaRoteador -> roteador == roteador;
    celulaRoteador -> prox = lista -> prim;
    lista -> prim = celulaRoteador;
    lista -> tam++;    
}

// retira o roteador da lista, mas não o destroi.

Roteador* retiraRoteador(ListaRoteadores* lista, char* nome) {
    if (lista -> prim == NULL) {
        return NULL;
    }
    CelulaRoteador* aux = NULL;
    CelulaRoteador* ant = NULL;

    if (lista -> prim -> prox == NULL) {
        ant = NULL;
        if (lista -> prim -> roteador -> nome == nome) {
            aux = lista -> prim;
            lista -> prim = NULL;
        }
    } else {
        ant = buscaRoteador(nome, lista, aux);
    }
    if (aux == NULL) {
        printf("Elemento não encontrado");

    } else {
        ant -> prox = aux -> prox;
    }
    return aux -> roteador;
}

CelulaRoteador* buscaRoteador(char* nome, ListaRoteadores* lista, CelulaRoteador* aux) {
    CelulaRoteador* ant;
    aux = lista -> prim;
    while ((aux -> roteador -> nome != nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux == NULL) {
        return NULL;
    }
    return ant;
}

ListaRoteadores* liberaRoteadores(ListaRoteadores* lista) {
    CelulaRoteador* p = lista -> prim;
    CelulaRoteador* aux;
    while (p != NULL) {
        aux = p->prox;
        free(p->roteador->nome);
        free(p->roteador->operadora);
        free(p->roteador);
        free(p);
        p = aux;
    }
    free(lista);
    return NULL;
}

Roteador* inicializaRoteador(char* nome, char* operadora) {
    Roteador* roteador = (Roteador*) malloc(sizeof (Roteador));
    roteador -> nome = (char*) malloc((strlen(nome) + 1) * sizeof (char));
    strcpy(roteador->nome, nome);
    roteador -> operadora = (char*) malloc((strlen(operadora) + 1) * sizeof (char));
    strcpy(roteador -> operadora, operadora);
    return roteador;
}

void destroiRoteador(Roteador* roteador) {
    free(roteador -> operadora);
    free(roteador -> nome);
    free(roteador);
}

void imprimeRoteadores(ListaRoteadores* lista) {
    CelulaRoteador* p = lista -> prim;
    while (p != NULL) {
        printf("Roteador:  %s \n", p->roteador-> nome);
        printf("Operadora: %s \n", p->roteador->operadora);
        printf("\n\n");
        p = p-> prox;
    }
}