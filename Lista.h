/**
 * Implementação de Lista Sequencial de forma orientada a objetos.
 *
 */

//Evita a referência circular
#ifndef LISTA_H
#define LISTA_H

//Declaração de bibliotecas
#include <iostream>
#include <string>

//Inclui o cabeçalho da classe No
#include "No.h"

using namespace std;

/**
 * Tamanho máximo da lista.
 */
const int TAMANHO_LISTA = 100;

class Lista {
private:
    /**
     * Tamanho atual da lista.
     */
    int n;

    /**
     * Vetor que armazena os nós.
     */
    No* lista[TAMANHO_LISTA];

public:
    /**
     * Construtor sem parâmetro da lista.
     */
    Lista();

    /**
     * Recuperador de N.
     *
     * @return Um inteiro com a quantidade de nós da lista.
     */
    int getN();

    /**
     * Modificador de N.
     *
     * @param n Um valor inteiro a ser atribuído para a N.
     */
    void setN(int n);

    /**
     * Insere um nó no início da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
     */
    bool inserirInicio(int valor);

    /**
     * Insere um nó em uma posição especifica da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @param k Posição a ser inserida o valor.
     * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
     */
    bool inserirPosicao(int valor, int k);

    /**
     * Insere um nó no final da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
     */
    bool inserirFim(int valor);

    /**
     * Inclui de forma ordenado um nó na lista levando em consideração o seu
     * valor.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
     */
    bool inserirOrdenado(int valor);

    /**
     * Excluir um nó do início da lista.
     *
     * @return Verdadeiro ou falso se excluiu o valor do início.
     */
    bool excluirInicio();

    /**
     * Excluir um Nó da lista pela posição.
     *
     * @param k Posição do nó a ser excluído da lista.
     * @return Verdadeiro ou falso se excluiu o valor da posição.
     */
    bool excluirPosicao(int k);

    /**
     * Excluir um nó do final da lista.
     *
     * @return Verdadeiro ou falso se excluiu o valor do final.
     */
    bool excluirFim();

    /**
     * Excluir um nó da lista pelo valor.
     *
     * @param valor Um valor de um nó a ser excluído da lista.
     * @return Verdadeiro ou falso se excluiu o valor.
     */
    bool excluirValor(int valor);

    /**
     * Retorna o dado de uma posição na lista.
     *
     * @param k Posição do nó a ser consultado na lista.
     * @return A posição de valor na lsita.
     */
    int procurarPosicao(int k);

    /**
     * Retorna a posição de um nó na lista.
     *
     * @param valor O valor de um nó a ser procurado na lista.
     * @return A posição de valor na lsita.
     */
    int procuraValor(int valor);

    /**
     * Lista os dados da lista.
     *
     * @return Uma String com os dados da lista.
     */
    string listar();

    /**
     * Retorna se a lista está cheia.
     *
     * @return Verdadeiro ou falso se a lista está cheia.
     */
    bool estaCheia();

    /**
     * Retorna se a lista esta vazia.
     *
     * @return Verdadeiro ou falso se a lista está vazia.
     */
    bool estaVazia();

    /**
     * Retorna a quantidade de Nós da lista.
     *
     * @return A quantidade de Nós da lista.
     */
    int getQuantidade();

};

#endif /* LISTA_H */

