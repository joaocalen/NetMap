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
    
    Terminal* terminal1 = inicializaTerminal("Terminal 1","Iconha");
    Terminal* terminal2 = inicializaTerminal("Terminal 2","Guarapari");
    Terminal* terminal3 = inicializaTerminal("Terminal 3","Iconha");
    Terminal* terminal4 = inicializaTerminal("Terminal 4","Piúma");
    Terminal* terminal5 = inicializaTerminal("Terminal 5","Vitória");
    
    ListaTerminais* listaTerminais = inicializaListaTerminais();
    
    insereTerminal(terminal1,listaTerminais);
    insereTerminal(terminal2,listaTerminais);
    insereTerminal(terminal3,listaTerminais);
    insereTerminal(terminal4,listaTerminais);
    insereTerminal(terminal5,listaTerminais);
    
    printf("IMPRIMINDO TERMINAIS: \n\n");
    
    imprimeTerminais(listaTerminais);
    
    terminal3 = retiraTerminal(listaTerminais, terminal3 -> nome);
    
    imprimeTerminais(listaTerminais);
    
    printf("IMPRIMINDO TERMINAIS (sem o terceiro) :");
    
    
    printf("LIBERANDO TERMINAIS:");
    liberaTerminais(listaTerminais);
    
    printf("TENTANDO IMPRIMIR TERMINAIS (nenhum):");
    
    return (EXIT_SUCCESS);
}

