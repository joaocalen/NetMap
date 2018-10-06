/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enlace.h
 * Author: joaogcalen
 *
 * Created on 4 de Outubro de 2018, 21:42
 */

#ifndef ENLACE_H
#define ENLACE_H

#include "Roteador.h"


#ifdef __cplusplus
extern "C" {
#endif
    typedef struct celulaEnlace CelulaEnlace;

    typedef struct listaEnlaces ListaEnlaces;

    struct celulaEnlace {
        CelulaEnlace* prox;
        CelulaRoteador* roteador;
    };

    struct listaEnlaces {
        CelulaEnlace* prim;
        CelulaEnlace* atual;
    };

    /*Tipo que define a lista (tipo opaco)
      Estrutura interna do tipo deve ser definida na implementa��o do TAD.
      Usar lista COM Sentinela
     */

    /*Inicializa um Terminal aluno
     * inputs: o nome, a matricula e o endereco do aluno
     * output: um ponteiro para o tipo item criado
     * pre-condicao: nome, matricula e endereco validos
     * pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
     */
    CelulaEnlace* inicializaEnlace(CelulaRoteador* roteador);



    /*Retira um aluno de matr�cula mat da lista de alunos
     * inputs: a lista e a matr�cula do aluno a ser retirado da lista
     * output: o aluno (do tipo Terminal) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
     * pre-condicao: lista n�o � nula
     * pos-condicao: lista n�o cont�m o aluno de matr�cula mat
     */
    CelulaEnlace* retiraEnlace(ListaEnlaces* lista, char* nome);

    /*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
     * inputs: a lista encadeada de alunos
     * output: Lista vazia (NULL)
     * pre-condicao: lista n�o � nula
     * pos-condicao: mem�ria alocada � liberada
     */
    ListaEnlaces* liberaEnlace(ListaEnlaces* lista);

    /*Imprime os dados de todos os alunos da lista
     * inputs: a lista de alunos
     * output: nenhum
     * pre-condicao: lista n�o � nula
     * pos-condicao: dados dos alunos impressos na saida padrao
     */
    void imprimeEnlaces(ListaEnlaces* lista);

    /*Insere um aluno na primeira posi��o da lista de alunos
     * inputs: aluno a ser inserido na lista (do tipo Terminal) e a lista
     * output: nenhum
     * pre-condicao: aluno e lista n�o s�o nulos
     * pos-condicao: lista cont�m o aluno inserido na primeira posi��o
     */
    void insereEnlace(CelulaEnlace* item, void* lista);

    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
     */
    ListaEnlaces* inicializaListaEnlaces();

    CelulaEnlace* buscaEnlace(Roteador* enlace, ListaEnlaces* lista);


#ifdef __cplusplus
}
#endif

#endif /* ENLACE_H */

