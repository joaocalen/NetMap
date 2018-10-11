/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



//#include <cstdlib>
#include "Terminal.h"
#include "Roteador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

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
    celulaTerminal -> roteador = NULL;
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
    while ((aux != NULL) && (strcmp(aux -> terminal -> nome, nome))) {
        ant = aux;
        aux = aux -> prox;
    }
    return ant;
}

CelulaTerminal* buscaTerminal(char* nome, ListaTerminais* lista) {
    CelulaTerminal* aux;
    CelulaTerminal* ant = NULL;
    aux = lista -> prim;
    while ((aux != NULL) && (strcmp(aux -> terminal -> nome, nome))) {
        ant = aux;
        aux = aux -> prox;
    }
    return aux;
}

// retira o terminal da lista, mas não o destroi.

ListaTerminais* liberaTerminais(ListaTerminais* lista) {
    if (lista != NULL) {
        CelulaTerminal* p = lista -> prim;
        CelulaTerminal* aux;
        while (p != NULL) {
            aux = p->prox;
            destroiTerminal(p->terminal);
            free(p);
            p = aux;
        }
        free(lista);
    }
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

void conectaTerm(Terminal* terminal, Roteador* roteador, ListaTerminais* listaTerminais, ListaRoteadores* listaRoteadores) {
    buscaTerminal(terminal -> nome, listaTerminais) -> roteador = buscaRoteador(roteador-> nome, listaRoteadores);
}

void desconectaTerminalRoteador(ListaTerminais* listaTerminais) {
    if (listaTerminais != NULL) {
        CelulaTerminal* aux;
        aux = listaTerminais -> prim;
        while (aux != NULL) {
            if (aux -> roteador != NULL) {
                desconectaTerm(aux -> terminal, listaTerminais);
            }
            aux = aux -> prox;
        }
    }
}

void desconectaTerm(Terminal* terminal, ListaTerminais* listaTerminais) {
    buscaTerminal(terminal -> nome, listaTerminais) -> roteador = NULL;
}

void destroiTerminal(Terminal* terminal) {
    if (terminal != NULL) {
        free(terminal -> localizacao);
        free(terminal -> nome);
        free(terminal);
    }
}

void imprimeTerminais(ListaTerminais* lista) {
    if (lista != NULL) {
        FILE *netMap;
        netMap = fopen("saida.dot", "a");
        CelulaTerminal* p = lista -> prim;
        while (p != NULL) {
            fprintf(netMap, "    %s", p->terminal-> nome);
            if (p-> roteador != NULL) {
                fprintf(netMap, " -- %s", p-> roteador -> roteador -> nome);
            }
            fprintf(netMap, ";\n");
            p = p -> prox;
        }
        fclose(netMap);
    }
}

int frequenciaTerm(char* localizacao, ListaTerminais* lista) {
    int i = 0;
    if (lista == NULL) {        
    } else {
        CelulaTerminal* p = lista -> prim;
        while (p != NULL) {
            if (!strcmp(p->terminal->localizacao, localizacao)) {
                i++;
            }
            p = p -> prox;
        }
    }
    return i;
}

int enviarPacotes(Terminal* terminal1, Terminal* terminal2, ListaTerminais* lista, ListaRoteadores* listaRoteadores) {
    if (lista != NULL && terminal1 != NULL && terminal2 != NULL) {
        if (buscaTerminal(terminal1->nome, lista) ->roteador != NULL && buscaTerminal(terminal2 -> nome, lista) ->roteador != NULL) {
            return procuraCaminho(buscaTerminal(terminal1 -> nome, lista) -> roteador -> roteador, buscaTerminal(terminal2-> nome, lista) -> roteador ->roteador, listaRoteadores);
        }
    }    
    return 0;
}



