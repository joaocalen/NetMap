/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leitorArquivo.h
 * Author: joaogcalen
 *
 * Created on 21 de Setembro de 2018, 00:01
 */

#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#ifdef __cplusplus
extern "C" {
#endif

    /*Faz a leitura do arquivo de entrada, guarda todo o conteúdo do arquivo em uma string, para depois dividíla em linhas em outra função*/
    void leitor(char* arquivo);

    /* Recebe como parâmetros uma linha do arquivo texto, e quantos espaços existem nessa linha. Sendo assim, divide a linha em Strings menores que são separadas por um espaço.
     * Após isso, faz a chamada da função correspondente ao número de Termos referentes à operação. A operação pode ter de 0 a 2 termos, que são os parâmetros para determinadas funções.
     */
    void realizaAcoes(char* linha, int i);

    /*Retorna um pedaço de uma String. O primeiro caractere da string será o caractere de índice equivalente ao parâmetro inicio, e o último será será o caractere de índice equivalente ao parâmetro fim*/
    char* substring(char string[], int inicio, int fim);

    /*Retorna o número de espaços da String e chama a função realizaAcoes*/
    void contaEspacos(char* linha);

    /*Função que divide a string completa referente ao arquivo em string menores referentes as linhas desse. A cada divisão de uma linha, chama a função que conta espaço*/
    void separaStrings(char* string);

    /*Decide qual operação deverá ser feita. Como não possui termos, ou a operação será "IMPRIMENETMAP" ou "FIM".*/
    void decideOperacao(char* operacao);
    /*Decide qual operação deverá ser feita. O leque de operações que podem ser escolhidas são apenas as funções que admitem um termo.*/
    void decideOperacao1Termo(char* operacao, char* termo);
    /*Decide qual operação deverá ser feita. O leque de operações que podem ser escolhidas são apenas as funções que admitem dois termos.*/
    void decideOperacao2Termos(char* operacao, char* termo1, char* termo2);
    /*Função auxiliar para retornar o índice do espaço na String.*/
    int retornaPosicaoEspaco(char* string);
    /*Verifica se é possível enviar Dados de um terminal para o outro. Escreve no arquivo saida.txt se é possível haver a comunicação entre os dois terminais em questão*/
    void enviarPacotesDados(char* terminal1, char* terminal2);
    /*Retorna o número de Roteadores da determinada operadora, e escreve no arquivo saida.txt essa frequência*/
    void frequenciaOperadora(char* operadora);
    /*Retorna o número de Terminais em uma determinada localização, e escreve no arquivo saida.txt essa frequência*/
    void frequenciaTerminal(char* localizacao);
    /*Desconecta os roteadores, removendo um da lista de enlaces do outro*/
    void desconectaRoteadores(char* roteador1, char* roteador2);
    /*Conecta os roteadores, adicionando um na lista de enlaces do outro*/
    void conectaRoteadores(char* roteador1, char* roteador2);
    /*Remove o terminal da lista de terminais*/
    void removeTerminal(char* nome);
    /*Desconecta o terminal do roteador na qual estava conectada previamente*/
    void desconectaTerminal(char* terminal);
    /*Conecta o terminal em um roteador*/
    void conectaTerminal(char* terminal, char* roteador);
    /*Remove o roteador da lista de roteadores*/
    void removeRoteador(char* nome);
    /*Adiciona um terminal na lista de terminais*/
    void cadastraTerminal(char* nome, char* localizacao);
    /*Adiciona um roteador na lista de roteadores*/
    void cadastraRoteador(char* nome, char* operadora);
    /*Ao final do programa, dá free em todas as listas e seus respectivos elementos.*/
    void liberaListas();
    /* Imprime os terminais e roteadores em forma de grafo no arquivo "saida.dot" para uso posterior na ferramente graphviz
     */
    void imprimeNetMap();
    /*Após a função enviaPacotesDados(), reseta valores dos roteadores. Ou seja, todos os roteadores voltam a ter a variável
     * visto com o valor padrão de naoVerificado, e o ponteiro "atual" de suas listas de enlaces apontam para o início.
     */
    void resetarDados();

#ifdef __cplusplus
}
#endif

#endif /* LEITORARQUIVO_H */

