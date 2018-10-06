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

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct celulaTerminal CelulaTerminal;

    typedef struct listaTerminais ListaTerminais;

    /*Terminal Aluno (tipo opaco)
    Estrutura interna do tipo deve ser definida na implementa��o do TAD. Devem ser definidos campos:
    - nome (string)
    - matricula (int)
    - endereco (string)
     */
    typedef struct terminal Terminal;

    /*Retira um aluno de matr�cula mat da lista de alunos
     * inputs: a lista e a matr�cula do aluno a ser retirado da lista
     * output: o aluno (do tipo Terminal) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
     * pre-condicao: lista n�o � nula
     * pos-condicao: lista n�o cont�m o aluno de matr�cula mat
     */
    Terminal* retiraTerminal(ListaTerminais* lista, char* nome);

    /*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
     * inputs: a lista encadeada de alunos
     * output: Lista vazia (NULL)
     * pre-condicao: lista n�o � nula
     * pos-condicao: mem�ria alocada � liberada
     */
    ListaTerminais* liberaTerminais(ListaTerminais* lista);

    /*Imprime os dados de todos os alunos da lista
     * inputs: a lista de alunos
     * output: nenhum
     * pre-condicao: lista n�o � nula
     * pos-condicao: dados dos alunos impressos na saida padrao
     */
    void imprimeTerminais(ListaTerminais* lista);

    /*Insere um aluno na primeira posi��o da lista de alunos
     * inputs: aluno a ser inserido na lista (do tipo Terminal) e a lista
     * output: nenhum
     * pre-condicao: aluno e lista n�o s�o nulos
     * pos-condicao: lista cont�m o aluno inserido na primeira posi��o
     */
    void insereTerminal(Terminal* item, ListaTerminais* lista);

    /*Inicializa o sentinela de uma lista
     * inputs: nenhum
     * output: Sentinela inicializado
     * pre-condicao: nenhuma
     * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
     */
    ListaTerminais* inicializaListaTerminais();

    CelulaTerminal* buscaTerminalAnterior(char* nome, ListaTerminais* lista);

    

    /*Inicializa um Terminal aluno
     * inputs: o nome, a matricula e o endereco do aluno
     * output: um ponteiro para o tipo item criado
     * pre-condicao: nome, matricula e endereco validos
     * pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
     */
    Terminal * inicializaTerminal(char* nome, char* localizacao);


#ifdef __cplusplus
}
#endif

#endif /* TERMINAL_H */
