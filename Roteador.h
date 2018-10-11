/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef ROTEADOR_H
#define ROTEADOR_H

#define verificado 1
#define naoVerificado 0


#include "Enlace.h"


#ifdef __cplusplus
extern "C" {
#endif

    /*Roteador 
     *   estrutura. Campos:
     * - nome (string)
     * - operadora (string)
     * - visto (int)
     * - lista de enlaces
     */
    typedef struct roteador Roteador;

    /* Celula de Roteador
     * Campos:
     * - roteador (Ponteiro para estrutura Roteador)    
     * - prox (Ponteiro para a próxima célula da lista)    
     */
    typedef struct celulaRoteador CelulaRoteador;

    /* Lista de Roteadores
     * Campos:
     * - prim (Celula de Roteador)
     * - int tam
     */
    typedef struct listaRoteadores ListaRoteadores;

    struct roteador {
        char* nome;
        char* operadora;
        int visto;
        ListaEnlaces* listaEnlaces;
    };

    struct listaRoteadores {
        CelulaRoteador* prim;
        int tam; // tam max para caminho em pilha
    };

    struct celulaRoteador {
        Roteador* roteador;
        CelulaRoteador* prox;
    };

    /*Inicializa um Roteador
     * inputs: o nome e a operadora do roteador
     * output: um ponteiro para o tipo Roteador criado
     * pre-condicao: nome e operadora validos
     * pos-condicao: roteador criado, com os campos nome e operadora copiados
     */
    Roteador* inicializaRoteador(char* nome, char* operadora);

    /*Retira um roteador de nome (nome) da lista de roteadores
     * inputs: a lista e o nome do roteador a ser retirado da lista
     * output: o roteador(do tipo Roteador) retirado da lista ou NULL, se o roteador não se encontrar na lista
     * pre-condicao: lista não nula
     * pos-condicao: lista não contém o roteador de nome (nome)
     */
    Roteador* retiraRoteador(ListaRoteadores* lista, char* nome);

    /*Libera toda a memória alocada para a lista
     * inputs: a lista encadeada de roteadores
     * output: Lista vazia (NULL)
     * pre-condicao: lista não nula
     * pos-condicao: memória alocada é liberada
     */
    ListaRoteadores* liberaRoteadores(ListaRoteadores* lista);

    /*Imprime os dados de todos os roteadores da lista no arquivo "saida.dot"
     * inputs: a lista de roteadores
     * output: nenhum
     * pre-condicao: lista não é nula
     * pos-condicao: dados dos roteadores impressos na saida "saida.dot"
     */
    void imprimeRoteadores(ListaRoteadores* lista);

    /*Insere um roteador na primeira posição da lista de roteadores
     * inputs: roteador a ser inserido na lista (do tipo Roteador) e a lista
     * output: nenhum
     * pre-condicao: roteador e lista não são nulos
     * pos-condicao: lista contém o roteador inserido na primeira posição
     */
    void insereRoteador(Roteador* item, ListaRoteadores* lista);

    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e o campos prim aponta para NULL
     */
    ListaRoteadores* inicializaListaRoteadores();

    /*Realiza uma busca na lista de Roteadores e retorna o roteador anterior.
     * inputs: nome do roteador e a lista de roteadores
     * output: Celula referente ao roteador anterior;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaRoteador* buscaRoteadorAnterior(char* nome, ListaRoteadores* lista);

    /* Libera espaço na memória referente ao roteador em questão
     * inputs: roteador
     * output: nenhum
     * pre-condicao: roteador não nulo
     * pos-condicao: memória liberada
     */
    void destroiRoteador(Roteador* roteador);

    /* Conecta o roteador no roteador em questão.
     * inputs: Dois roteadores, lista de roteadores e lista de roteadores
     * output: nenhum
     * pre-condicao: parâmetros não nulos
     * pos-condicao: roteador1 na lista de enlaces do roteador 2 e roteador 2 na lista de enlaces do roteador 1.
     */
    void conectaRot(Roteador* roteador1, Roteador* roteador2, ListaRoteadores* lista);

    /* Desconecta o roteador do roteador em questão.
     * inputs: Roteador e lista de roteadores
     * output: nenhum
     * pre-condicao: parâmetros não nulos
     * pos-condicao: roteador1 fora da lista de enlaces do roteador 2 e roteador 2 fora da lista de enlaces do roteador 1.
     */
    void desconectaRot(Roteador* roteador1, Roteador* roteador2);

    /*Realiza uma busca na lista de Roteadores e retorna o roteador cujo nome é (nome).
     * inputs: nome do roteador e a lista de roteadores
     * output: Celula referente ao roteador;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaRoteador* buscaRoteador(char* nome, ListaRoteadores* lista);

    /* Calcula a frequência da operadora. Ou seja, quantos roteadores possuem a mesma operadora
     * inputs: operadora (string) e lista de roteadores
     * output: inteiro referente à frequência
     * pre-condicao: lista não nula e operadora válida
     * pos-condicao: nenhuma
     */
    int frequenciaRoteador(char* operadora, ListaRoteadores* lista);

    /* função auxiliar da função enviaPacoteDados. Apenas faz a chamada de uma nova função em "Enlace.c" para dar seguimento à função
     */
    int procuraCaminho(Roteador* roteador1, Roteador* roteador2, ListaRoteadores* lista);

#ifdef __cplusplus
}
#endif

#endif /* ROTEADOR_H */

