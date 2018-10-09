//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "pilha.h"
//#include "Roteador.h"
//#define MaxTam 10
//
//struct pilha {
//    Roteador* roteadors[MaxTam];
//    int topo;
//};
//
//struct celulaPilha {
//    Roteador* roteador;
//    CelulaPilha* prox;
//};
//
//Pilha* cria_pilha() {
//    Pilha* pilhaAlunos = (Pilha*) malloc(sizeof (Pilha));
//    pilhaAlunos -> topo = 0;
//    return pilhaAlunos;
//}
//
//void push(Roteador* roteador, Pilha* pilha) {
//    if (pilha -> topo < MaxTam) {
//        pilha -> roteadors[pilha -> topo] = roteador;
//        pilha -> topo++;
//    }
//}
//
//Roteador* pop(Pilha* pilha) {
//    if (pilha -> topo != 0) {
//        pilha -> topo--;
//        return (pilha -> roteadors[pilha-> topo]);
//    }
//
//}
//
//Pilha* destroi_pilha(Pilha* pilha) {
//    int i;
//    for (i = 0; i < pilha->topo; i++) {
//        pop(pilha);
//    }
//    free(pilha);
//}
//
//void imprime_pilha(Pilha* pilha) {
//    int i;
//    for (i = 0; i < pilha->topo; i++) {
//        printf("%s\n", pilha->roteadors[i]->endereco);
//        printf("%s\n", pilha->roteadors[i]->nome);
//        printf("%d\n\n\n", pilha->roteadors[i]->idade);
//    }
//}