#ifndef PILHA_H_
#define PILHA_H_

/* Define a estrutura Roteador. Contem campos:
  - nome (string)
  - operadora (string)
  - prox (ponteiro)
  - rot (ponteiro que aponta para o roteador caso esse esteja na lista de enlace).
  - verificado (boolean) - Indica se o nó já foi verificado na função de enviarPacotesDados
 */
typedef struct Roteador roteador;


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Roteadors
*/
typedef struct pilha Pilha;


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
Pilha* cria_pilha();

/*Insere uma roteador no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma roteador)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(Roteador* roteador, Pilha* pilha);


/*Retira uma Roteador do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a roteador retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Roteador* pop(Pilha* pilha);


/*Imprime as roteadors da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* pilha);


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha);


/*Inicializa um TipoItem Roteador
* inputs: o nome, a idade e o endereco da roteador
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Roteador* inicializaRoteador(char* nome, int idade, char* endereco);


#endif /* PILHA_H_ */
