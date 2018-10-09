///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   main.c
// * Author: joaogcalen
// *
// * Created on 6 de Outubro de 2018, 15:02
// */
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Roteador.h"
#include "Terminal.h"
#include "Enlace.h"
#include "leitorArquivo.h"
//#include "pilha.h"
//#include "leitorArquivo.h"
//#include "fila.h"
//
///*
// * 
// */
char* rtrim(char* string, char junk);
int main(int argc, char *argv[]) {
    //    printf("TESTE 1 \n\n");
    //
    //    printf("INSERINDO Terminais: \n\n");
    //
    //    Terminal* terminal1 = inicializaTerminal("Terminal 1", "Iconha");
    //    Terminal* terminal2 = inicializaTerminal("Terminal 2", "Guarapari");
    //    Terminal* terminal3 = inicializaTerminal("Terminal 3", "Iconha");
    //    Terminal* terminal4 = inicializaTerminal("Terminal 4", "Piúma");
    //    Terminal* terminal5 = inicializaTerminal("Terminal 5", "Vitória");
    //
    //    ListaTerminais* listaTerminais = inicializaListaTerminais();
    //
    //    insereTerminal(terminal1, listaTerminais);
    //    insereTerminal(terminal2, listaTerminais);
    //    insereTerminal(terminal3, listaTerminais);
    //    insereTerminal(terminal4, listaTerminais);
    //    insereTerminal(terminal5, listaTerminais);
    //
    //
    //
    //    ListaRoteadores* listaRoteadores = inicializaListaRoteadores();
    //
    //    Roteador* roteador1 = inicializaRoteador("Roteador 1", "GVT");
    //    Roteador* roteador2 = inicializaRoteador("Roteador 2", "NET");
    //    Roteador* roteador3 = inicializaRoteador("Roteador 3", "Vivo");
    //    Roteador* roteador4 = inicializaRoteador("Roteador 4", "GVT");
    //    Roteador* roteador5 = inicializaRoteador("Roteador 5", "NET");
    //
    //    printf("\nATÉ AQUI EU CHEGO SEU FILHO DA PUTA \n");
    //
    //    insereRoteador(roteador1, listaRoteadores);
    //    insereRoteador(roteador2, listaRoteadores);
    //    insereRoteador(roteador3, listaRoteadores);
    //    insereRoteador(roteador4, listaRoteadores);
    //    insereRoteador(roteador5, listaRoteadores);
    //
    //    imprimeRoteadores(listaRoteadores);
    //
    //    printf("\nTAMO AQUI NA ATIVIDADE SEU INUTIL\n");
    //
    //    conectaRoteadores(roteador1, roteador5, listaRoteadores);
    //    conectaRoteadores(roteador1, roteador3, listaRoteadores);
    //    conectaRoteadores(roteador2, roteador4, listaRoteadores);
    //    conectaRoteadores(roteador2, roteador3, listaRoteadores);
    //    conectaRoteadores(roteador4, roteador5, listaRoteadores);
    //
    //    conectaTerminal(terminal3, roteador4, listaTerminais, listaRoteadores);
    //    conectaTerminal(terminal2, roteador2, listaTerminais, listaRoteadores);
    //
    //    imprimeTerminais(listaTerminais);
    //
    //
    //    imprimeEnlaces(roteador2 ->listaEnlaces);
    //    imprimeEnlaces(roteador1 ->listaEnlaces);
    //
    //    printf("\nFrequencia NET: %i\n", frequenciaRoteador("NET", listaRoteadores));
    //    printf("\nFrequencia Iconha: %i\n", frequenciaTerminal("Iconha", listaTerminais));
    //
    //    //printf("\nDados: %i\n", enviarPacotesDados(terminal3, terminal2, listaTerminais, listaRoteadores));
    //
    //
    //    Roteador* roteadorLiberado = retiraRoteador(listaRoteadores, roteador4 -> nome);
    //    printf("%s retirado\n", roteadorLiberado -> nome);
    //
    //    desconectaTerminalRoteador(roteadorLiberado, listaTerminais);
    //
    //
    //    imprimeEnlaces(roteador2 ->listaEnlaces);
    //    imprimeEnlaces(roteador4 ->listaEnlaces);
    //
    //    Terminal* terminalLiberado = retiraTerminal(listaTerminais, terminal5 -> nome);
    //
    //    destroiTerminal(terminalLiberado);
    //
    //    imprimeTerminais(listaTerminais);
    //    listaTerminais = liberaTerminais(listaTerminais);
    //
    //
    //    printf("LIBERANDO Roteadores:\n");
    //    destroiRoteador(roteadorLiberado);
    //    listaRoteadores = liberaRoteadores(listaRoteadores);
    //
    //
    //
    //
    //
    //    imprimeRoteadores(listaRoteadores);
    //
    //    //liberaRoteadores(listaRoteadores);
    //    //liberaTerminais(listaTerminais);
    //
    //
    //

    //printf("%s",argv[argc-1]);
    
    
    //printf(rtrim("    asfqepfjqpiej    ",' '));

    leitor(argv[argc - 1]);


    return (EXIT_SUCCESS);
}