/**
 *
 * Implementação dos métodos da classe Nó.
 *
 */

//Inclui o cabeçalho da classe No
#include "No.h"

/**
 * Construtor sem parâmetros.
 */
No::No() {
    this->dado = 0;
}

/**
 * Construtor com parâmetros.
 *
 * @param dado um valor do tipo inteiro.
 */
No::No(int dado) {
    this->dado = dado;
}

/**
 * Recuperador de dado.
 *
 * @return Um inteiro com o dado do nó.
 */
int No::getDado() {
    return this->dado;
}

/**
 * Modificador de dado.
 *
 * @param dado Um valor inteiro a ser atribuído para o dado.
 */
void No::setDado(int dado) {
    this->dado = dado;
}

/**
 * Retorna o valor em String do dado.
 *
 * @return Uma string com o valor do dado do nó.
 */
string No::paraString() {
    stringstream endereco;
    endereco << this;
    return "OID: " + endereco.str() + " / dado: " + to_string(getDado());
}

