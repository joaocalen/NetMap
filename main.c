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



    terminal3 = retiraTerminal(listaTerminais, terminal3 -> nome);

    printf("%s retirado\n", terminal3 -> nome);

    printf("IMPRIMINDO TERMINAIS (sem o terceiro) :");

    imprimeTerminais(listaTerminais);




    printf("LIBERANDO TERMINAIS\n:");
    destroiTerminal(terminal3);
    liberaTerminais(listaTerminais);

    printf("TENTANDO IMPRIMIR TERMINAIS (nenhum):\n");

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

    roteador5 = retiraRoteador(listaRoteadores, roteador5 -> nome);
    printf("%s retirado\n", roteador5 -> nome);
    
    
    imprimeRoteadores(listaRoteadores);
    
    printf("LIBERANDO TERMINAIS\n:");
    destroiRoteador(roteador3);
    liberaRoteadores(listaRoteadores);


    return (EXIT_SUCCESS);
}

