/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leitorArquivo.c
 * Author: joaogcalen
 *
 * Created on 20 de Setembro de 2018, 23:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "Roteador.h"
#include "Enlace.h"
#include "Terminal.h"
//#include "fila.h"

ListaEnlaces* listaEnlaces;
ListaRoteadores* listaRoteadores;
ListaTerminais* listaTerminais;

void leitor(char* nomeArquivo) {
    listaEnlaces = inicializaListaEnlaces();
    listaRoteadores = inicializaListaRoteadores();
    listaTerminais = inicializaListaTerminais();

    FILE *entrada;
    entrada = fopen(nomeArquivo, "r");

    if (entrada == NULL) {
        FILE *log;
        log = fopen("log.txt", "a");
        fprintf(log, "ERRO: ARQUIVO NÃO ENCONTRADO");
        fclose(entrada);
        exit(0);
    }


    char c, *str = NULL;
    int i = 0, j = 1, tam;

    str = (char *) malloc(10 * sizeof (char) + 1);

    while ((c = fgetc(entrada)) != EOF) {
        if (j == 10) {
            tam = strlen(str);
            str = (char*) realloc(str, tam + 11 * sizeof (char));
            j = 1;
        }
        *(str + i * sizeof (char)) = c;
        i++;
        j++;
    }
    tam = strlen(str);
    str = (char*) realloc(str, tam + 1 * sizeof (char));

    *(str + i * sizeof (char)) = '\0';

    separaStrings(str);

    free(str);

    fclose(entrada);
}

void separaStrings(char* string) {
    int i = 0;
    int j = 0;
    int tam = strlen(string);
    //printf("%d", tam);
    while (i < tam) {
        while (string[i] != '\n' && i != tam) {
            i++;
        }
        contaEspacos(substring(string, j, i));
        i++;
        j = i;
        //printf("%d", i);
    }
    // printf("%d", i);
}

char* substring(char str[], int inicio, int fim) {
    int i, j;
    char *sub;
    int tam = strlen(str);
    if (inicio >= fim || fim > tam) {
        return NULL;
    }
    sub = (char *) malloc((fim - inicio + 1) * sizeof (char));
    for (i = inicio, j = 0; i < fim; i++, j++) {
        sub[j] = str[i];
    }
    return sub;
}

void contaEspacos(char* linha) {
    int i = 0;
    int n = 0;
    int tam = strlen(linha);
    while (i < tam) {
        if (linha[i] == ' ') {
            n++;
        }
        i++;
    }
    realizaAcoes(linha, n);
}

void realizaAcoes(char* linha, int n) {
    int i = 0;
    int j = 0;
    char* operacao = NULL;
    char* termo1 = NULL;
    char* termo2 = NULL;
    int tam = strlen(linha);
    switch (n) {
        case 0:
            decideOperacao(linha);
            break;
        case 1:
            i = retornaPosicaoEspaco(linha);
            operacao = substring(linha, 0, i);
            termo1 = substring(linha, i + 1, tam);
            decideOperacao1Termo(operacao, termo1);
            break;
        case 2:
            while (linha[i] != ' ') {
                i++;
            }
            operacao = substring(linha, 0, i);
            i++;
            j = i;
            while (linha[i] != ' ') {
                i++;
            }
            termo1 = substring(linha, j, i);
            termo2 = substring(linha, i + 1, tam);
            decideOperacao2Termos(operacao, termo1, termo2);
            break;
        default:

            break;
    }
    if (linha != NULL) {
        free(linha);
    }

}

int retornaPosicaoEspaco(char* string) {
    int i = 0;
    while (string[i] != ' ') {
        i++;
    }
    return i;
}

void decideOperacao(char* operacao) {
    printf("\n%s\n", operacao);

    if (!strcmp(operacao, "IMPRIMENETMAP")) {
        imprimeNetMap();
    } else if ((!strcmp(operacao, "FIM"))) {
        fechaArquivos();
    } else {
        editaLog(operacao);
    }
}

void decideOperacao1Termo(char* operacao, char* termo) {
    printf("\n%s %s\n", operacao, termo);
    if (!strcmp(operacao, "REMOVEROTEADOR")) {
        removeRoteador(termo);
    } else if ((!strcmp(operacao, "REMOVETERMINAL"))) {
        removeTerminal(termo);
    } else if ((!strcmp(operacao, "DESCONECTATERMINAL"))) {
        desconectaTerminal(termo);
    } else if ((!strcmp(operacao, "FREQUENCIAOPERADORA"))) {
        frequenciaOperadora(termo);
    } else if ((!strcmp(operacao, "FREQUENCIATERMINAL"))) {
        frequenciaTerminal(termo);
    } else {

    }
    free(operacao);
    free(termo);
}

void decideOperacao2Termos(char* operacao, char* termo1, char* termo2) {
    printf("\n%s %s %s\n", operacao, termo1, termo2);

    if (!strcmp(operacao, "CADASTRAROTEADOR")) {
        cadastraRoteador(termo1, termo2);
    } else if (!strcmp(operacao, "CADASTRATERMINAL")) {
        cadastraTerminal(termo1, termo2);
    } else if ((!strcmp(operacao, "CONECTAROTEADORES"))) {
        conectaRoteadores(termo1, termo2);
    } else if ((!strcmp(operacao, "CONECTATERMINAL"))) {
        conectaTerminal(termo1, termo2);
    } else if ((!strcmp(operacao, "DESCONECTAROTEADORES"))) {
        desconectaRoteadores(termo1, termo2);
    } else if ((!strcmp(operacao, "ENVIARPACOTESDADOS"))) {
        enviarPacotesDados(termo1, termo2);
    } else {

    }
    free(operacao);
    free(termo1);
    free(termo2);
}

void editaLog(char* erro) {

}

void editaSaida() {

}

void fechaArquivos() {
    liberaRoteadores(listaRoteadores);
    liberaTerminais(listaTerminais);
}

void cadastraRoteador(char* nome, char* operadora) {
    insereRoteador(inicializaRoteador(nome, operadora), listaRoteadores);
    imprimeRoteadores(listaRoteadores);
}

void cadastraTerminal(char* nome, char* localizacao) {
    insereTerminal(inicializaTerminal(nome, localizacao), listaTerminais);
    imprimeTerminais(listaTerminais);

}

void removeRoteador(char* nome) {
    Roteador* roteador = retiraRoteador(listaRoteadores, nome);
    if (roteador != NULL)
        destroiRoteador(roteador);
}

void conectaTerminal(char* terminal, char* roteador) {
    Terminal* terminal1 = (buscaTerminal(terminal, listaTerminais)) -> terminal;
    Roteador* roteador1 = (buscaRoteador(roteador, listaRoteadores)) -> roteador;
    conectaTerm(terminal1, roteador1, listaTerminais, listaRoteadores);
}

void desconectaTerminal(char* terminal) {
    Terminal* terminal1 = buscaTerminal(terminal, listaTerminais) -> terminal;
    desconectaTerm(terminal1, listaTerminais);
}

void removeTerminal(char* nome) {
    Terminal* terminal = retiraTerminal(listaTerminais, nome);
    destroiTerminal(terminal);

}

void conectaRoteadores(char* roteador1, char* roteador2) {
    conectaRot(buscaRoteador(roteador1, listaRoteadores) -> roteador, buscaRoteador(roteador2, listaRoteadores) -> roteador, listaRoteadores);
}

void desconectaRoteadores(char* roteador1, char* roteador2) {
    desconectaRot(buscaRoteador(roteador1, listaRoteadores) -> roteador, buscaRoteador(roteador2, listaRoteadores) ->roteador);
}

void frequenciaTerminal(char* localizacao) {
    FILE *saida;
    saida = fopen("saida.txt", "a");
    fprintf(saida, "FREQUENCIATERMINAL %s: %d", localizacao, frequenciaTerm(localizacao, listaTerminais));
    fclose(saida);
}

void frequenciaOperadora(char* operadora) {
    FILE *saida;
    saida = fopen("saida.txt", "a");
    fprintf(saida, "FREQUENCIAOPERADORA %s: %d", operadora, frequenciaRoteador(operadora, listaRoteadores));
    fclose(saida);
}

void enviarPacotesDados(char* terminal1, char* terminal2) {
    FILE *saida;
    saida = fopen("saida.txt", "a");
    fprintf(saida, "ENVIARPACOTESDADOS %s %s: SIM", terminal1, terminal2);
    fclose(saida);
}

void imprimeNetMap() {
    imprimeTerminais(listaTerminais);
    imprimeRoteadores(listaRoteadores);
}

