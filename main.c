///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Roteador.h"
#include "Terminal.h"
#include "Enlace.h"
#include "leitorArquivo.h"
//
///*
// * 
// */

int main(int argc, char *argv[]) {   
    leitor(argv[argc - 1]);
    return (EXIT_SUCCESS);
}