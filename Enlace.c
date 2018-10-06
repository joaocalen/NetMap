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

struct listaEnlaces {
    CelulaEnlace* prim;
    CelulaEnlace* atual;
};

//ListaEnlaces* inicializaLista() {
//    ListaEnlaces* lista;
//    lista = (ListaEnlaces*) malloc(sizeof (ListaEnlaces));
//    lista -> prim = NULL;
//    return lista;
//}
//
//void insereEnlace(Enlace* enlace, ListaEnlaces* lista) {
//    CelulaEnlace* celulaEnlace = (CelulaEnlace*) malloc(sizeof (CelulaEnlace));
//    celulaEnlace -> enlace == enlace;
//    celulaEnlace -> prox = lista -> prim;
//    lista -> prim = celulaEnlace;
//}
//
//// retira o enlace da lista, mas não o destroi.
//
//Enlace* retira(ListaEnlaces* lista, Enlace* remEnlace) {
//    //CelulaEnlace* enlaceCel = (CelulaEnlace*) malloc(sizeof (CelulaEnlace));
//    //enlaceCel -> enlace -> mat = mat;
//    if (lista -> prim == NULL) {
//        return NULL;
//    }
//    CelulaEnlace* aux;
//    CelulaEnlace* ant;
//
//    if (lista -> prim -> prox == NULL) {
//        ant = NULL;
//        aux = lista -> prim;
//    } else {
//        ant = buscaEnlace(lista, remEnlace);
//    }
//    if (aux == NULL) {
//        printf("Elemento não encontrado");
//        return NULL;
//    } else if (aux == lista -> prim) {
//        lista -> prim == NULL;
//        return aux;
//    }
//    ant -> prox = aux -> prox;
//    return aux -> enlace;
//}
//
//CelulaEnlace* buscaEnlace(Enlace* enlace, ListaEnlaces* lista) {
//    CelulaEnlace* aux;
//    CelulaEnlace* ant;
//    aux = lista -> prim;
//    while ((aux -> enlace -> nome != enlace ->nome) && (aux != NULL)) {
//        ant = aux;
//        aux = aux -> prox;
//    }
//    if (aux == NULL) {
//        return NULL;
//    }
//    return ant;
//}

//ListaEnlaces* libera(ListaEnlaces* lista) {
//    CelulaEnlace* p = lista -> prim;
//    CelulaEnlace* aux;
//    while (p != NULL) {
//        aux = p->prox;
//        free(p->enlace->nome);
//        free(p->enlace->localizacao);
//        free(p->enlace);
//        free(p);
//        p = aux;
//    }
//    free(lista);
//    return NULL;
//}



//void imprime(ListaEnlaces* lista) {
//    CelulaEnlace* p = lista -> prim;
//    while (p != NULL) {
//        printf("Enlace de matrícula %d \n", p->enlace->mat);
//        printf("Nome: %s \n", p->enlace->nome);
//        printf("Endereco: %s \n", p->enlace->localizacao);
//        printf("\n\n");
//    }
//}

// criar outro arquivo para essas funções

