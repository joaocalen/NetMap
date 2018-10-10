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

//#include "Roteador.h"


#ifdef __cplusplus
extern "C" {
#endif
    typedef struct celulaEnlace CelulaEnlace;

    /*Tipo que define a lista 
     Lista de Enlaces. Campos
     * - prim (ponteiro de Celula de Enlace)
     * - atual (ponteiro de Celula de Enlace)
     */
    typedef struct listaEnlaces ListaEnlaces;

    struct listaEnlaces {
        CelulaEnlace* prim;
        CelulaEnlace* atual;
    };

    /*Retira um roteador da lista de enlaces
     * inputs: a lista e o nome do roteador a ser retirado da lista
     * output: o roteador (do tipo Roteador) retirado da lista ou NULL, se o roteador não se encontrar na lista
     * pre-condicao: lista não nula
     * pos-condicao: lista não contém o roteador de nome (nome)
     */
    CelulaEnlace* retiraEnlace(ListaEnlaces* lista, char* nome);

    /*Libera toda a memória alocada para a lista
     * inputs: a lista encadeada de enlaces
     * output: Lista vazia (NULL)
     * pre-condicao: lista não nula
     * pos-condicao: memória alocada é liberada
     */
    ListaEnlaces* liberaEnlaces(ListaEnlaces* lista, void* roteador);

    /*Imprime os dados de todos os enlaces da lista no arquivo "saida.dot"
     * inputs: a lista de enlaces
     * output: nenhum
     * pre-condicao: lista não é nula
     * pos-condicao: dados dos enlaces impressos na saida "saida.dot"
     */
    void imprimeEnlaces(ListaEnlaces* lista, void* roteador);

    /*Insere um roteador na primeira posição da lista de enlaces
     * inputs: roteador a ser inserido na lista (do tipo Roteador) e a lista
     * output: nenhum
     * pre-condicao: roteador e lista não são nulos
     * pos-condicao: lista contém o roteador inserido na primeira posição
     */
    void insereEnlace(void* roteador, ListaEnlaces* lista);

    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e o campo prim aponta para NULL
     */
    ListaEnlaces* inicializaListaEnlaces();

    /*Realiza uma busca na lista de enlaces e retorna o enlace anterior.
     * inputs: nome do roteador e a lista de enlaces
     * output: Celula referente ao enlace anterior;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaEnlace* buscaEnlaceAnterior(char* nome, ListaEnlaces* lista);

    /*Realiza uma busca na lista de Roteadores e retorna o enlace cujo nome é (nome).
     * inputs: nome do roteador e a lista de enlaces
     * output: Celula referente ao roteador;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaEnlace* buscaEnlace(char* nome, ListaEnlaces* lista);

    /*Insere um roteador na última posição da lista de enlaces
     * inputs: roteador a ser inserido na lista (do tipo Roteador) e a lista
     * output: nenhum
     * pre-condicao: roteador e lista não são nulos
     * pos-condicao: lista contém o roteador inserido na última posição
     */
    void insereEnlaceFim(void* roteador, ListaEnlaces* lista);

    /*Retira o último roteador da lista de enlaces
     * inputs: a lista e o nome do roteador a ser retirado da lista
     * output: o roteador (do tipo Roteador) retirado da lista ou NULL, se o roteador não se encontrar na lista
     * pre-condicao: lista não nula
     * pos-condicao: lista não contém o último roteador
     */
    CelulaEnlace* retiraUltimoEnlace(ListaEnlaces* lista, char* nome);

    /*Inicia uma pilha (listaEnlaces), insere o roteador de origem na pilha e chama a função procuraEnlace*/
    int procuraEnlace1Nivel(void* roteador1, void* roteador2, void* listaRoteadores);

    /*Função com chamadas recursivas. Verifica o roteador da lista de enlaces do ultimo roteador da pilha, caso ainda não tenha sido verificado, insere na lista. Faz isso até o
     * último elemento da pilha ter todos os roteadores da lista de enlaces veriricados. Caso isso aconteça, volta um caminho e avança um roteador da lista de enlaces do anterior, até
     * o roteador de origem ser econtrado. Caso não seja, escreve no "saida.txt" que não é possível a comunicação entre os dois terminais da função enviaPacotesDados. Caso seja possível,
     * escreve no "saida.txt" que a comunicação entre os terminais é possível. 
     */
    int procuraEnlace(void*roteadorInicio, void* roteadorAtual, void* roteadorFim, ListaEnlaces* caminho);



#ifdef __cplusplus
}
#endif

#endif /* ENLACE_H */

