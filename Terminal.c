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
#include "Terminal.h"
#include "Roteador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

void conectaTerminal(Terminal* terminal, CelulaRoteador* roteador, ListaTerminais* lista);

struct celulaTerminal {
    Terminal* terminal;
    CelulaTerminal* prox;
    CelulaRoteador* roteador;
};

ListaTerminais* inicializaListaTerminais() {
    ListaTerminais* lista;
    lista = (ListaTerminais*) malloc(sizeof (ListaTerminais));
    lista -> prim = NULL;
    return lista;
}

void insereTerminal(Terminal* terminal, ListaTerminais* lista) {
    CelulaTerminal* celulaTerminal = (CelulaTerminal*) malloc(sizeof (CelulaTerminal));
    celulaTerminal -> terminal = terminal;
    celulaTerminal -> prox = lista -> prim;
    lista -> prim = celulaTerminal;
}

// retira o terminal da lista, mas não o destroi.

Terminal* retiraTerminal(ListaTerminais* lista, char* nome) {
    CelulaTerminal* aux;
    CelulaTerminal* ant;

    ant = buscaTerminalAnterior(nome, lista);
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
    Terminal* terminal = aux -> terminal;

    free(aux);
    return terminal;
}

CelulaTerminal* buscaTerminalAnterior(char* nome, ListaTerminais* lista) {
    CelulaTerminal* aux;
    CelulaTerminal* ant = NULL;
    aux = lista -> prim;
    while ((aux -> terminal -> nome != nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    return ant;
}


// retira o terminal da lista, mas não o destroi.

ListaTerminais* liberaTerminais(ListaTerminais* lista) {
    CelulaTerminal* p = lista -> prim;
    CelulaTerminal* aux;
    while (p != NULL) {
        aux = p->prox;
        destroiTerminal(p->terminal);
        free(p);
        p = aux;
    }
    free(lista);
    return NULL;
}

Terminal* inicializaTerminal(char* nome, char* localizacao) {
    Terminal* terminal = (Terminal*) malloc(sizeof (Terminal));
    terminal -> nome = (char*) malloc((strlen(nome) + 1) * sizeof (char));
    strcpy(terminal->nome, nome);
    terminal -> localizacao = (char*) malloc((strlen(localizacao) + 1) * sizeof (char));
    strcpy(terminal -> localizacao, localizacao);
    return terminal;
}

// Para desconectar, basta passar o parâmetro roteador como NULL;

void conectaTerminal(Terminal* terminal, CelulaRoteador* roteador, ListaTerminais* lista) {
    (buscaTerminalAnterior(terminal -> nome, lista) -> prox) -> roteador = roteador;
}

void destroiTerminal(Terminal* terminal) {
    free(terminal -> localizacao);
    free(terminal -> nome);
    free(terminal);
}

void imprimeTerminais(ListaTerminais* lista) {
    
    if (lista == NULL) {
        printf("NENHUM TERMINAL");
    } else {
        CelulaTerminal* p = lista -> prim;
        while (p != NULL) {
            printf("Terminal: %s \n", p->terminal-> nome);
            printf("Endereco: %s \n", p->terminal->localizacao);
            printf("\n\n");
            p = p -> prox;
        }
    }

}


