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
    printf("\nENTREI NA FUNÇÃO SEU LAZARENTO\n");
    CelulaEnlace* celulaEnlace = (CelulaEnlace*) malloc(sizeof (CelulaEnlace));
    celulaEnlace -> roteador = (CelulaRoteador*) roteador;
    celulaEnlace -> prox = lista -> prim;
    lista -> prim = celulaEnlace;
    lista -> atual = lista -> prim;
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

CelulaEnlace* buscaEnlaceAnterior(char* nome, ListaEnlaces* lista) {
    CelulaEnlace* aux;
    CelulaEnlace* ant;
    aux = lista -> prim;
    while ((aux -> roteador -> roteador -> nome != nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux == NULL) {
        return NULL;
    }
    return ant;
}

ListaEnlaces* liberaEnlaces(ListaEnlaces* lista, void* rot) {
    CelulaEnlace* p = lista -> prim;
    CelulaEnlace* aux;
    Roteador* roteador = (Roteador*) rot;
    while (p != NULL) {
        aux = p->prox;
        desconectaRoteadores(roteador,p->roteador -> roteador);
        free(p);
        p = aux;
    }
    free(lista);
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
//criar outro arquivo para essas funções

