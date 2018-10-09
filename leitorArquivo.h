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

    typedef struct fila Fila;

    struct fila {
    };

    void leitor(char* arquivo);

    void realizaAcoes(char* string, int i);

    char* substring(char str[], int start, int end);
    void contaEspacos(char* linha);
    void separaStrings(char* string);
    void decideOperacao(char* operacao);
    void decideOperacao1Termo(char* operacao, char* termo);
    void decideOperacao2Termos(char* operacao, char* termo1, char* termo2);
    int retornaPosicaoEspaco(char* string);
    void enviarPacotesDados(char* terminal1, char* terminal2);
    void frequenciaOperadora(char* operadora);
    void frequenciaTerminal(char* localizacao);
    void desconectaRoteadores(char* roteador1, char* roteador2);
    void conectaRoteadores(char* roteador1, char* roteador2);
    void removeTerminal(char* nome);
    void desconectaTerminal (char* terminal);
    void conectaTerminal (char* terminal, char* roteador);
    void removeRoteador(char* nome);
    void cadastraTerminal (char* nome, char* localizacao);
    void cadastraRoteador(char* nome, char* operadora);
    void fechaArquivos();
    void editaSaida();
    void editaLog(char* erro);
    void imprimeNetMap();

#ifdef __cplusplus
}
#endif

#endif /* LEITORARQUIVO_H */

