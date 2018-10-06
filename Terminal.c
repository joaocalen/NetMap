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

struct terminal {
    char* nome;
    char* localizacao;
};

struct listaTerminais {
    CelulaTerminal* prim;
};

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
    if (lista -> prim == NULL) {
        return NULL;
    }
    CelulaTerminal* aux = NULL;
    CelulaTerminal* ant = NULL;

    if (lista -> prim -> prox == NULL) {
        ant = NULL;
        if (lista -> prim -> terminal -> nome == nome) {
            aux = lista -> prim;
            lista -> prim = NULL;
        }
    } else {
        ant = buscaTerminalAnterior(nome, lista);
    }
    if (aux == NULL) {
        printf("Elemento não encontrado");

    } else {
        ant -> prox = aux -> prox;
    }
    return aux -> terminal;
}

CelulaTerminal* buscaTerminalAnterior(char* nome, ListaTerminais* lista) {
    CelulaTerminal* aux;
    CelulaTerminal* ant;
    aux = lista -> prim;
    while ((aux -> terminal -> nome != nome) && (aux != NULL)) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux == NULL) {
        return NULL;
    }
    return ant;
}


// retira o terminal da lista, mas não o destroi.

ListaTerminais* liberaTerminais(ListaTerminais* lista) {
    CelulaTerminal* p = lista -> prim;
    CelulaTerminal* aux;
    while (p != NULL) {
        aux = p->prox;
        free(p-> terminal -> nome);
        free(p->terminal->localizacao);
        free(p->terminal);
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
    CelulaTerminal* p = lista -> prim;
    if (p == NULL) {
        printf("NENHUM TERMINAL");
    } else {
        while (p != NULL) {
            printf("Terminal: %s \n", p->terminal-> nome);
            printf("Endereco: %s \n", p->terminal->localizacao);
            printf("\n\n");
            p = p -> prox;
        }
    }

}


