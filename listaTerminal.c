/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaTerminal.c
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
 */

//#include <cstdlib>
#include "simplesComSentinela.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

struct item {
    char* nome;
    char* localizacao;
};

typedef struct cel Celula;

struct cel {
    Terminal* terminal;
    Celula* prox;
    Celula* roteador;
};

struct tipoLista {
    Celula* prim;
};

TipoLista* inicializaLista() {
    TipoLista* lista;
    lista = (TipoLista*) malloc(sizeof (TipoLista));
    lista -> prim = NULL;
    return lista;
}

void insere(Terminal* terminal, TipoLista* lista) {
    Celula* celulaTerminal = (Celula*) malloc(sizeof (Celula));
    celulaTerminal -> terminal == terminal;
    celulaTerminal -> prox = lista -> prim;
    lista -> prim = celulaTerminal;
}

// retira o terminal da lista, mas não o destroi.

Terminal* retira(TipoLista* lista, Terminal* remTerminal) {
    //Celula* terminalCel = (Celula*) malloc(sizeof (Celula));
    //terminalCel -> terminal -> mat = mat;
    if (lista -> prim == NULL) {
        return NULL;
    }
    Celula* aux;
    Celula* ant;

    if (lista -> prim -> prox == NULL) {
        ant = NULL;
        aux = lista -> prim;
    } else {
        ant = buscaTerminal(lista, remTerminal);
    }
    if (aux == NULL) {
        printf("Elemento não encontrado");
        return NULL;
    } else if (aux == lista -> prim) {
        lista -> prim == NULL;
        return aux;
    }
    ant -> prox = aux -> prox;
    return aux -> terminal;
}

Celula* buscaTerminal(Terminal* terminal, TipoLista* lista) {
    Celula* aux;
    Celula* ant;
    aux = lista -> prim;
    while ((aux -> terminal -> nome != terminal ->nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux == NULL) {
        return NULL;
    }
    return ant;
}

//TipoLista* libera(TipoLista* lista) {
//    Celula* p = lista -> prim;
//    Celula* aux;
//    while (p != NULL) {
//        aux = p->prox;
//        free(p->terminal->nome);
//        free(p->terminal->localizacao);
//        free(p->terminal);
//        free(p);
//        p = aux;
//    }
//    free(lista);
//    return NULL;
//}

Terminal* inicializaTerminal(char* nome, char* localizacao) {
    Terminal* terminal = (Terminal*) malloc(sizeof (Terminal));
    terminal -> nome = (char*) malloc((strlen(nome) + 1) * sizeof (char));
    strcpy(terminal->nome, nome);
    terminal -> localizacao = (char*) malloc((strlen(localizacao) + 1) * sizeof (char));
    strcpy(terminal -> localizacao, localizacao);
    return terminal;
}

Terminal* desconectaTerminal(Terminal* terminal) {
    buscaTerminal(terminal) -> roteador = NULL;
}

void destroiTerminal(Terminal* terminal) {
    free(terminal -> localizacao);
    free(terminal -> nome);
    free(terminal);
}

//void imprime(TipoLista* lista) {
//    Celula* p = lista -> prim;
//    while (p != NULL) {
//        printf("Terminal de matrícula %d \n", p->terminal->mat);
//        printf("Nome: %s \n", p->terminal->nome);
//        printf("Endereco: %s \n", p->terminal->localizacao);
//        printf("\n\n");
//    }
//}

// criar outro arquivo para essas funções

