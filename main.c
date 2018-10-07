/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joaogcalen
 *
 * Created on 6 de Outubro de 2018, 15:02
 */

#include <stdio.h>
#include <stdlib.h>
#include "Roteador.h"
#include "Terminal.h"
#include "Enlace.h"
//#include "pilha.h"
//#include "leitorArquivo.h"
//#include "fila.h"

/*
 * 
 */
int main(int argc, char** argv) {
    printf("TESTE 1 \n\n");

    printf("INSERINDO Terminais: \n\n");

    Terminal* terminal1 = inicializaTerminal("Terminal 1", "Iconha");
    Terminal* terminal2 = inicializaTerminal("Terminal 2", "Guarapari");
    Terminal* terminal3 = inicializaTerminal("Terminal 3", "Iconha");
    Terminal* terminal4 = inicializaTerminal("Terminal 4", "Piúma");
    Terminal* terminal5 = inicializaTerminal("Terminal 5", "Vitória");

    ListaTerminais* listaTerminais = inicializaListaTerminais();

    insereTerminal(terminal1, listaTerminais);
    insereTerminal(terminal2, listaTerminais);
    insereTerminal(terminal3, listaTerminais);
    insereTerminal(terminal4, listaTerminais);
    insereTerminal(terminal5, listaTerminais);

    imprimeTerminais(listaTerminais);

    Terminal* terminalLiberado = retiraTerminal(listaTerminais, terminal5 -> nome);

    printf("%s retirado\n", terminalLiberado -> nome);

    printf("IMPRIMINDO TERMINAIS (sem o terceiro) :\n ");

    imprimeTerminais(listaTerminais);




    printf("LIBERANDO TERMINAIS\n:");
    destroiTerminal(terminalLiberado);
    listaTerminais = liberaTerminais(listaTerminais);

    printf("TENTANDO IMPRIMIR TERMINAIS (nenhum):\n");
    
    imprimeTerminais(listaTerminais);
    

    ListaRoteadores* listaRoteadores = inicializaListaRoteadores();

    Roteador* roteador1 = inicializaRoteador("Roteador 1", "GVT");
    Roteador* roteador2 = inicializaRoteador("Roteador 2", "NET");
    Roteador* roteador3 = inicializaRoteador("Roteador 3", "Vivo");
    Roteador* roteador4 = inicializaRoteador("Roteador 4", "GVT");
    Roteador* roteador5 = inicializaRoteador("Roteador 5", "NET");

    printf("ATÉ AQUI EU CHEGO SEU FILHO DA PUTA \n");

    insereRoteador(roteador1, listaRoteadores);
    insereRoteador(roteador2, listaRoteadores);
    insereRoteador(roteador3, listaRoteadores);
    insereRoteador(roteador4, listaRoteadores);
    insereRoteador(roteador5, listaRoteadores);

    imprimeRoteadores(listaRoteadores);
    
    printf("TAMO AQUI NA ATIVIDADE SEU INUTIL");
    
    //conectaRoteadores(roteador1,roteador5,listaRoteadores);
    //conectaRoteadores(roteador1,roteador3,listaRoteadores);
    conectaRoteadores(roteador2,roteador4,listaRoteadores);

    Roteador* roteadorLiberado = retiraRoteador(listaRoteadores, roteador2 -> nome);
    printf("%s retirado\n", roteador1 -> nome);


    imprimeEnlaces(roteador1 ->listaEnlaces);

    printf("LIBERANDO Roteadores:\n");
    destroiRoteador(roteadorLiberado);
    //listaRoteadores = liberaRoteadores(listaRoteadores);
    
    
    
    imprimeRoteadores(listaRoteadores);  

    //liberaRoteadores(listaRoteadores);
    //liberaTerminais(listaTerminais);
    
    

    return (EXIT_SUCCESS);
}

