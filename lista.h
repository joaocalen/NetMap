///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   lista.h
// * Author: joaogcalen
// *
// * Created on 4 de Outubro de 2018, 21:43
// */
//
//// LISTA SIMPLESMENTE ENCADEADA COM SENTINELA, com funções básicas que qualquer lista possui
//
//#ifndef LISTA_H
//#define LISTA_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//    
//    typedef struct celula Celula;
//    
//    typedef struct tipoLista TipoLista;
//
//    /*Retira um aluno de matr�cula mat da lista de alunos
//     * inputs: a lista e a matr�cula do aluno a ser retirado da lista
//     * output: o aluno (do tipo Terminal) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
//     * pre-condicao: lista n�o � nula
//     * pos-condicao: lista n�o cont�m o aluno de matr�cula mat
//     */
//    void* retira(TipoLista* lista, void* item);
//
//    /*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
//     * inputs: a lista encadeada de alunos
//     * output: Lista vazia (NULL)
//     * pre-condicao: lista n�o � nula
//     * pos-condicao: mem�ria alocada � liberada
//     */
//    TipoLista* libera(TipoLista* lista);
//
//    /*Imprime os dados de todos os alunos da lista
//     * inputs: a lista de alunos
//     * output: nenhum
//     * pre-condicao: lista n�o � nula
//     * pos-condicao: dados dos alunos impressos na saida padrao
//     */
//    void imprime(TipoLista* lista);
//
//    /*Insere um aluno na primeira posi��o da lista de alunos
//     * inputs: aluno a ser inserido na lista (do tipo Terminal) e a lista
//     * output: nenhum
//     * pre-condicao: aluno e lista n�o s�o nulos
//     * pos-condicao: lista cont�m o aluno inserido na primeira posi��o
//     */
//    void insere(void* item, void* lista);
//
//    /*Inicializa o sentinela de uma lista
//     * inputs: nenhum
//     * output: Sentinela inicializado
//     * pre-condicao: nenhuma
//     * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
//     */
//    TipoLista* inicializaLista();
//    
//    Celula* buscaItem(void* item, TipoLista* lista);
//
//
//
//
//
//#ifdef __cplusplus
//}
//#endif
//
//#endif /* LISTA_H */
//
