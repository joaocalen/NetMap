/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#ifdef __cplusplus
extern "C" {
#endif

    /*Faz a leitura do arquivo de entrada, guarda todo o conteúdo do arquivo em uma string, para depois dividíla em linhas em outra função*/
    void leitor(char* arquivo);

    /* Recebe como parâmetros uma linha do arquivo texto, e quantos espaços existem nessa linha. Sendo assim, divide a linha em Strings menores que são separadas por um espaço.
     * Após isso, faz a chamada da função correspondente ao número de Termos referentes à operação. A operação pode ter de 0 a 2 termos, que são os parâmetros para determinadas funções.
     */
    void realizaAcoes(char* linha, int i);

    /*Retorna um pedaço de uma String. O primeiro caractere da string será o caractere de índice equivalente ao parâmetro inicio, e o último será será o caractere de índice equivalente ao parâmetro fim*/
    char* substring(char string[], int inicio, int fim);

    /*Retorna o número de espaços da String e chama a função realizaAcoes*/
    void contaEspacos(char* linha);

     /*Função que divide a string completa referente ao arquivo em string menores referentes as linhas desse. A cada divisão de uma linha, chama a função que conta espaço*/
    void separaStrings(char* string);

    /*Decide qual operação deverá ser feita. Como não possui termos, ou a operação será "IMPRIMENETMAP" ou "FIM"
     * inputs: nome da operação (string)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: chamada da função referente à operação.
     */
    void decideOperacao(char* operacao);
    
    /* Decide qual operação deverá ser feita. O leque de operações que podem ser escolhidas são apenas as funções que admitem um termo.
     * inputs: nome da operação, termo1 (strings)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: chamada da função referente à operação.
     */
    void decideOperacao1Termo(char* operacao, char* termo);
    
    /* Decide qual operação deverá ser feita. O leque de operações que podem ser escolhidas são apenas as funções que admitem dois termos.
     * inputs: nome da operação, termo1 e termo2 (strings)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: chamada da função referente à operação.
     */
    void decideOperacao2Termos(char* operacao, char* termo1, char* termo2);
    
    /* Função auxiliar para retornar o índice do espaço na String.
     * inputs: string (string)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: número de espaços presentes na String
     */
    int retornaPosicaoEspaco(char* string);
    
    /* Verifica se é possível enviar Dados de um terminal para o outro. Escreve no arquivo saida.txt se é possível haver a comunicação entre os dois terminais em questão
     * inputs: nome de dois terminais
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: escrito no arquivo saida.txt se é possível enviar dados de um terminal para o outro
     */
    void enviarPacotesDados(char* terminal1, char* terminal2);

    /* Retorna o número de Roteadores da determinada operadora, e escreve no arquivo saida.txt essa frequência
     * inputs: operadora (string)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: frequência escrita no arquivo saida.txt.
     */
    void frequenciaOperadora(char* operadora);

    /* Retorna o número de Terminais em uma determinada localização, e escreve no arquivo saida.txt essa frequência
     * inputs: localizacao (string)
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: frequência escrita no arquivo saida.txt
     */
    void frequenciaTerminal(char* localizacao);

    /* Desconecta os roteadores, removendo um da lista de enlaces do outro
     * inputs: nome de dois roteadores
     * output: nenhum
     * pre-condicao: nome e operadora válidos
     * pos-condicao: roteador1 removido na lista de enlace do roteador2, e vice-versa.
     */
    void desconectaRoteadores(char* roteador1, char* roteador2);

    /* Conecta os roteadores, adicionando um na lista de enlaces do outro
     * inputs: nome de dois roteadores
     * output: nenhum
     * pre-condicao: nome e operadora válidos
     * pos-condicao: roteador1 adicionado na lista de enlace do roteador2, e vice-versa.
     */
    void conectaRoteadores(char* roteador1, char* roteador2);

    /* Remove o terminal da lista de terminais
     * inputs: nome do terminal a ser removido
     * output: nenhum
     * pre-condicao: nome válido
     * pos-condicao: roteador removido da lista, e espaço de memória liberado.
     */
    void removeTerminal(char* nome);

    /* Desconecta o terminal do roteador na qual estava conectado previamente
     * inputs: nome do terminal
     * output: nenhum
     * pre-condicao: nome válido
     * pos-condicao: ponteiro de roteador do terminal apontando para NULL
     */
    void desconectaTerminal(char* terminal);

    /* Conecta o terminal em um roteador
     * inputs: nome do roteador e nome do terminal a serem conectados
     * output: nenhum
     * pre-condicao: nomes válidos
     * pos-condicao: terminal apontando para o roteador
     */
    void conectaTerminal(char* terminal, char* roteador);

    /*Remove o roteador da lista de roteadores
     * inputs: nome do terminal a ser removido
     * output: nenhum
     * pre-condicao: nome válido
     * pos-condicao: roteador removido da lista de roteadores
     */
    void removeRoteador(char* nome);

    /* Adiciona um terminal na lista de terminais
     * inputs: nome e localização do terminal a ser cadastrado
     * output: nenhum
     * pre-condicao: nome e localização válidos
     * pos-condicao: terminal inicializado e inserido na lista de terminais
     */
    void cadastraTerminal(char* nome, char* localizacao);

    /*Adiciona um roteador na lista de roteadores
     * inputs: nome e operadora do roteador a ser cadastrado
     * output: nenhum
     * pre-condicao: nome e operadora válidos
     * pos-condicao: roteador inicializado e inserido na lista de roteadores
     */
    void cadastraRoteador(char* nome, char* operadora);

    /*Ao final do programa, dá free em todas as listas e seus respectivos elementos.
     * inputs: nenhum
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: todas as listas utilizadas liberadas.
     */
    void liberaListas();

    /* Imprime os terminais e roteadores em forma de grafo no arquivo "saida.dot" para uso posterior na ferramente graphviz. Os terminais e roteadores são oriundos das listas globais.
     * inputs: nenhum
     * output: nenhum
     * pre-condicao: nenhuma
     * pos-condicao: terminais e roteadores impressos em forma de grafo no arquivo "saida.dot".
     */
    void imprimeNetMap();

    /*Após a função enviaPacotesDados(), reseta valores dos roteadores. Ou seja, todos os roteadores voltam a ter a variável
     * visto com o valor padrão de naoVerificado, e o ponteiro "atual" de suas listas de enlaces apontam para o início.
     */
    void resetarDados();

#ifdef __cplusplus
}
#endif

#endif /* LEITORARQUIVO_H */

