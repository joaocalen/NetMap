/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitorArquivo.h"
#include "Roteador.h"
#include "Enlace.h"
#include "Terminal.h"
//#include "fila.h"

ListaRoteadores* listaRoteadores;
ListaTerminais* listaTerminais;
int intermediario;

void leitor(char* nomeArquivo) {
    intermediario = 0;
    listaRoteadores = inicializaListaRoteadores();
    listaTerminais = inicializaListaTerminais();

    FILE *entrada;
    entrada = fopen(nomeArquivo, "r");

    if (entrada == NULL) {
        FILE *log;
        log = fopen("log.txt", "a");
        fprintf(log, "Erro: I/O, nao foi possivel abrir o arquivo %s", nomeArquivo);
        fclose(log);
        liberaListas();
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
    while (i < tam) {
        while (string[i] != '\n' && i != tam) {
            i++;
        }
        contaEspacos(substring(string, j, i));
        i++;
        j = i;
    }
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
        liberaListas();
    } else {
        FILE *log;
        log = fopen("log.txt", "a");
        fprintf(log, "Erro: Operação %s inexistente no NetMap", operacao);
        fclose(log);
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

void liberaListas() {
    liberaRoteadores(listaRoteadores);
    liberaTerminais(listaTerminais);
}

void cadastraRoteador(char* nome, char* operadora) {
    insereRoteador(inicializaRoteador(nome, operadora), listaRoteadores);
}

void cadastraTerminal(char* nome, char* localizacao) {
    insereTerminal(inicializaTerminal(nome, localizacao), listaTerminais);
}

void removeRoteador(char* nome) {
    Roteador* roteador = retiraRoteador(listaRoteadores, nome);
    if (roteador != NULL) {
        if (listaTerminais != NULL) {
            CelulaTerminal* aux = listaTerminais -> prim;
            while (aux != NULL) {
                if (!strcmp(aux -> roteador -> roteador ->nome, nome)) {
                    desconectaTerminal(aux -> terminal ->nome);
                }
                aux = aux -> prox;
            }
        }
        destroiRoteador(roteador);
    } else {
        FILE *log;
        log = fopen("log.txt", "a");
        fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", nome);
        fclose(log);
    }
}

void conectaTerminal(char* terminal, char* roteador) {
    CelulaTerminal* terminal1 = (buscaTerminal(terminal, listaTerminais));
    CelulaRoteador* roteador1 = (buscaRoteador(roteador, listaRoteadores));
    if (terminal1 != NULL && roteador1 != NULL) {
        conectaTerm(terminal1->terminal, roteador1->roteador, listaTerminais, listaRoteadores);
    } else {
        if (roteador1 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", roteador);
            fclose(log);
        }
        if (terminal1 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Terminal %s inexistente no NetMap\n\n", terminal);
            fclose(log);
        }
    }
}

void desconectaTerminal(char* terminal) {
    CelulaTerminal* terminal1 = buscaTerminal(terminal, listaTerminais);
    if (terminal1 != NULL) {
        desconectaTerm(terminal1->terminal, listaTerminais);
    } else {
        FILE *log;
        log = fopen("log.txt", "a");
        fprintf(log, "Erro: Terminal %s inexistente no NetMap\n\n", terminal);
        fclose(log);
    }
}

void removeTerminal(char* nome) {
    Terminal* terminal = retiraTerminal(listaTerminais, nome);
    destroiTerminal(terminal);
}

void conectaRoteadores(char* roteador10, char* roteador20) {
    CelulaRoteador* roteador1 = (buscaRoteador(roteador10, listaRoteadores));
    CelulaRoteador* roteador2 = (buscaRoteador(roteador20, listaRoteadores));
    if (roteador1 != NULL && roteador2 != NULL) {
        conectaRot(roteador1 -> roteador, roteador2 ->roteador, listaRoteadores);
    } else {
        if (roteador1 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", roteador10);
            fclose(log);
        }
        if (roteador2 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", roteador20);
            fclose(log);
        }
    }
}

void desconectaRoteadores(char* roteador10, char* roteador20) {
    CelulaRoteador* roteador1 = (buscaRoteador(roteador10, listaRoteadores));
    CelulaRoteador* roteador2 = (buscaRoteador(roteador20, listaRoteadores));
    if (roteador1 != NULL && roteador2 != NULL) {
        desconectaRot(roteador1 -> roteador, roteador2 ->roteador);
    } else {
        if (roteador1 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", roteador10);
            fclose(log);
        }
        if (roteador2 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Roteador %s inexistente no NetMap\n\n", roteador20);
            fclose(log);
        }
    }
}

void frequenciaTerminal(char* localizacao) {
    FILE *saida;
    saida = fopen("saida.txt", "a");
    fprintf(saida, "FREQUENCIATERMINAL %s: %d\n\n", localizacao, frequenciaTerm(localizacao, listaTerminais));
    fclose(saida);
}

void frequenciaOperadora(char* operadora) {
    FILE *saida;
    saida = fopen("saida.txt", "a");
    fprintf(saida, "FREQUENCIAOPERADORA %s: %d\n\n", operadora, frequenciaRoteador(operadora, listaRoteadores));
    fclose(saida);
}

void enviarPacotesDados(char* terminal10, char* terminal20) {
    CelulaTerminal* terminal1 = buscaTerminal(terminal10, listaTerminais);
    CelulaTerminal* terminal2 = buscaTerminal(terminal20, listaTerminais);
    if (terminal1 != NULL && terminal2 != NULL) {
        FILE *saida;
        saida = fopen("saida.txt", "a");
        fprintf(saida, "ENVIAPACOTEDADOS %s %s: ", terminal1->terminal->nome, terminal2->terminal->nome);
        if (terminal1 -> roteador == NULL || terminal2 -> roteador == NULL) {
            fprintf(saida, "NAO\n\n");
            fclose(saida);
        } else {
            fclose(saida);
            enviarPacotes(terminal1->terminal, terminal2->terminal, listaTerminais, listaRoteadores);
            resetarDados();
        }
    } else {
        if (terminal1 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Terminal %s inexistente no NetMap\n\n", terminal10);
            fclose(log);
        }
        if (terminal2 == NULL) {
            FILE *log;
            log = fopen("log.txt", "a");
            fprintf(log, "Erro: Terminal %s inexistente no NetMap\n\n", terminal20);
            fclose(log);
        }
    }
}

void imprimeNetMap() {
    FILE *netMap;
    netMap = fopen("saida.dot", "a");
    if (intermediario == 1) {
        fprintf(netMap, "//intermediario\n\n");
    }
    fprintf(netMap, "strict graph {\n");
    fclose(netMap);
    imprimeTerminais(listaTerminais);
    imprimeRoteadores(listaRoteadores);
    netMap = fopen("saida.dot", "a");
    fprintf(netMap, "}\n");
    fclose(netMap);
    intermediario = 1;
}

void resetarDados() {
    CelulaRoteador* aux = listaRoteadores -> prim;
    while (aux != NULL) {
        aux -> roteador -> listaEnlaces -> atual = aux -> roteador -> listaEnlaces -> prim;
        aux -> roteador -> visto = naoVerificado;
        aux = aux -> prox;
    }
}