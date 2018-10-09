//#ifndef PILHA_H_
//#define PILHA_H_
//
//
///*Tipo que define a Pilha (tipo opaco)
//  Atencao: Esta pilha pode conter ate 10 Pessoas
//*/
//typedef struct pilha Pilha;
//
// typedef celulaPilha CelulaPilha;
//
///*Inicializa a Pilha
//* inputs: nenhum
//* output: P (a pilha criada)
//* pre-condicao: nenhuma
//* pos-condicao: P est� definida e vazia
//*/
//Pilha* cria_pilha();
//
///*Insere uma pessoa no topo da pilha (se houver espaco)
//* inputs: P (uma pilha) e E (uma pessoa)
//* output: nenhum
//* pre-condicao: P nao vazia e com espaco para o elemento.
//* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
//do topo
//*/
//void push(void* roteador, Pilha* pilha);
//
//
///*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
//* inputs: a Pilha
//* output: a pessoa retirada do topo da pilha
//* pre-condicao: Pilha n�o � nula e n�o � vazia
//* pos-condicao: pilha n�o cont�m o elemento retirado do topo
//*/
//void* pop(Pilha* pilha);
//
//
///*Imprime as pessoas da pilha
// * inputs: a pilha
// * output: nenhum
// * pre-condicao: pilha P n�o vazia
// * pos-condicao: Pilha permanece inalterada
// */
//void imprime_pilha (Pilha* pilha);
//
//
///*Libera a memoria ocupada pela pilha
//* inputs: a Pilha
//* output: NULL
//* pre-condicao: Pilha n�o � nula
//* pos-condicao: Toda memoria eh liberada
//*/
//Pilha* destroi_pilha(Pilha* pilha);
//
//
//
//
//#endif /* PILHA_H_ */
