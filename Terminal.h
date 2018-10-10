/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terminal.h
 * Author: joaogcalen
 *
 * Created on 4 de Outubro de 2018, 21:42
 */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "Roteador.h"


#ifdef __cplusplus
extern "C" {
#endif

    /*Celula de Terminal 
     * Campos:
     * - terminal (Ponteiro para estrutura Terminal)    
     * - prox (Ponteiro para a próxima célula da lista)    
     * - roteador (Ponteiro para o roteador na qual está conectado)    
     */
    typedef struct celulaTerminal CelulaTerminal;


    /*Lista de Terminais 
     * Campos:
     * - prim (Celula de Terminal)    
     */
    typedef struct listaTerminais ListaTerminais;

    /*Terminal 
     *Tipo estruturado Terminal. Campos:
     *- nome (string)    
     *- localizacao (string)
     */
    typedef struct terminal Terminal;

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


    /*Retira um terminal da lista de terminais
     * inputs: a lista e o nome do terminal a ser retirado da lista
     * output: o terminal(do tipo Terminal) retirado da lista ou NULL, se o terminal não se encontrar na lista
     * pre-condicao: lista não nula
     * pos-condicao: lista não contém o terminal com o nome (nome)
     */
    Terminal* retiraTerminal(ListaTerminais* lista, char* nome);

    /*Libera toda a memória alocada para a lista e seus respectivos elementos
     * inputs: a lista encadeada de terminais
     * output: Lista vazia (NULL)
     * pre-condicao: lista não nula
     * pos-condicao: memória alocada e liberada
     */
    ListaTerminais* liberaTerminais(ListaTerminais* lista);

    /*Imprime os nomes e suas respectivas conexões de todos os terminais da lista no arquivo "saida.dot"
     * inputs: a lista de terminais
     * output: nenhum
     * pre-condicao: lista não nula
     * pos-condicao: nome e conexão de cada terminal impressos no arquivo "saida.dot"
     */
    void imprimeTerminais(ListaTerminais* lista);

    /*Insere um terminal na primeira posição da lista de terminais
     * inputs: terminal a ser inserido na lista (do tipo Terminal) e a lista
     * output: nenhum
     * pre-condicao: terminal e lista não são nulos
     * pos-condicao: lista contém o terminal inserido na primeira posição
     */
    void insereTerminal(Terminal* item, ListaTerminais* lista);

    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e o campo prim aponta para NULL
     */
    ListaTerminais* inicializaListaTerminais();


    /*Realiza uma busca na lista de Terminais e retorna o terminal anterior.
     * inputs: nome do terminal e a lista de terminais
     * output: Celula referente ao terminal anterior;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaTerminal* buscaTerminalAnterior(char* nome, ListaTerminais* lista);

    /*Realiza uma busca na lista de Terminais e retorna o terminal cujo nome é (nome).
     * inputs: nome do terminal e a lista de terminais
     * output: Celula referente ao terminal;
     * pre-condicao: lista não nula
     * pos-condicao: nenhuma
     */
    CelulaTerminal* buscaTerminal(char* nome, ListaTerminais* lista);

    /* Conecta o terminal no roteador em questão.
     * inputs: Terminal, Roteador, lista de terminais e lista de roteadores
     * output: nenhum
     * pre-condicao: Terminal, Roteador, lista de terminais e lista de roteadores não nulos
     * pos-condicao: Terminal conectado ao respectivo roteador
     */
    void conectaTerm(Terminal* terminal, Roteador* roteador, ListaTerminais* listaTerminais, ListaRoteadores* listaRoteadores);



    /*Inicializa um Terminal 
     * inputs: o nome e a localização do terminal
     * output: um ponteiro para o tipo Terminal criado
     * pre-condicao: nome e localizaçao validos
     * pos-condicao: terminal criado, com os campos nome e localizaçao copiados
     */
    Terminal* inicializaTerminal(char* nome, char* localizacao);

    /* Libera espaço na memória referente ao terminal em questão
     * inputs: terminal
     * output: nenhum
     * pre-condicao: terminal não nulo
     * pos-condicao: memória liberada
     */
    void destroiTerminal(Terminal* terminal);

    /* Calcula a frequência da localização. Ou seja, quantos terminais possuem a mesma localização
     * inputs: localizacao (string) e lista de terminais
     * output: inteiro referente à frequência
     * pre-condicao: lista não nula e localização válida
     * pos-condicao: nenhuma
     */
    int frequenciaTerm(char* localizacao, ListaTerminais* lista);

    /* Desconecta todos os terminais de seus roteadores
     * inputs: lista de terminais
     * output: nenhum
     * pre-condicao: lista nao nula
     * pos-condicao: todos os terminais com o campo roteador apontando para NULL
     */
    void desconectaTerminalRoteador(ListaTerminais* listaTerminais);

    /* Desconecta o terminal do roteador em questão.
     * inputs: Terminal e lista de terminais
     * output: nenhum
     * pre-condicao: parâmetros não nulos
     * pos-condicao: Terminal desconectado do seu respectivo roteador
     */
    void desconectaTerm(Terminal* terminal, ListaTerminais* listaTerminais);

    /* Verifica se dois terminais podem se comunicar
     * inputs: Dois terminais, lista de terminais e lista de roteadores
     * output: indicador (0: nao, 1: sim)
     * pre-condicao: parâmetros não nulos
     * pos-condicao: nenhuma
     */
    int enviarPacotes(Terminal* terminal1, Terminal* terminal2, ListaTerminais* lista, ListaRoteadores* listaRoteadores);

#ifdef __cplusplus
}
#endif

#endif /* TERMINAL_H */

