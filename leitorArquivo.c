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
#include "fila.h"

/*
 * Usar fila de operações a serem feitas
 */


Fila* separaStrings(char* linha) {
    const char separador[2] = " ";
    char* token = strtok(linha, separador);
    
    while (token != NULL){
        
    }
}