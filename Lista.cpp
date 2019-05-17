/**
 *
 * Implementação dos métodos da classe Lista.
 *
 */

//Inclui o cabeçalho da classe Lista
#include "Lista.h"

/**
 * Construtor sem parâmetro da lista.
 */
Lista::Lista() {
    //Inicializa a lista com o 0 nós
    this->n = 0;
}

/**
 * Recuperador de N.
 *
 * @return Um inteiro com a quantidade de nós da lista.
 */
int Lista::getN() {
    return n;
}

/**
 * Modificador de N.
 *
 * @param n Um valor inteiro a ser atribuído para a N.
 */
void Lista::setN(int n) {
    this->n = n;
}

/**
 * Insere um nó no início da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool Lista::inserirInicio(int valor) {
    if (n < TAMANHO_LISTA) {
        //Desloca os nós do fim até a posição 0
        for (int i = n - 1; i >= 0; i--) {
            lista[i + 1] = lista[i];
        }
        //Instancia o novo nó
        No* novo = new No;
        novo->setDado(valor);
        //Insere o novo valor na posição 0.            
        lista[0] = novo;
        //Incrementa a quantidade de nós.
        setN(getN() + 1);
        return true;
    } else {
        cout << "A lista está cheia!\n";
        return false;
    }
}

/**
 * Insere um nó em uma posição especifica da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param k Posição a ser inserida o valor.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool Lista::inserirPosicao(int valor, int k) {
    if (n < TAMANHO_LISTA) {
        //Verifica se a posição está no intervalo de valores da lista.
        if ((k >= 0) && (k <= getN())) {
            //Desloca os nós do fim até a posição k
            for (int i = n - 1; i >= k; i--) {
                lista[i + 1] = lista[i];
            }
            //Instancia o novo nó
            No* novo = new No;
            novo->setDado(valor);
            //Insere o novo valor na posição k.
            lista[k] = novo;
            //Incrementa a quantidade de nós.
            setN(getN() + 1);
            return true;
        } else {
            cout << "Posição inválida!\n";
            return false;
        }
    } else {
        cout << "A lista está cheia!\n";
        return false;
    }
}

/**
 * Insere um nó no final da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool Lista::inserirFim(int valor) {
    if (n < TAMANHO_LISTA) {
        //Desloca os nós do fim até a posição n
        for (int i = n - 1; i >= getN(); i--) {
            lista[i + 1] = lista[i];
        }
        //Instancia o novo nó
        No* novo = new No;
        novo->setDado(valor);
        //Insere o novo valor na posição n.
        lista[getN()] = novo;
        //Incrementa a quantidade de nós.
        setN(getN() + 1);
        return true;
    } else {
        cout << "A lista está cheia!\n";
        return false;
    }
}

/**
 * Inclui de forma ordenado um nó na lista levando em consideração o seu
 * valor.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool Lista::inserirOrdenado(int valor) {
    if (n < TAMANHO_LISTA) {
        int j = 0;
        while ((j < getN()) && (valor > lista[j]->getDado())) {
            j = j + 1;
        }
        if (j <= n) {
            //Desloca os nós do fim até a posição j
            for (int i = n - 1; i >= j; i--) {
                lista[i + 1] = lista[i];
            }
            //Instancia o novo nó
            No* novo = new No;
            novo->setDado(valor);
            //Insere o novo valor na posição j.
            lista[j] = novo;
            //Incrementa a quantidade de nós.
            setN(getN() + 1);
        } else {
            cout << "Posição Inválida!\n";
            return false;
        }
    } else {
        cout << "A lista está cheia!\n";
        return false;
    }
    return false;
}

/**
 * Excluir um nó do início da lista.
 *
 * @return Verdadeiro ou falso se excluiu o valor do início.
 */
bool Lista::excluirInicio() {
    return excluirPosicao(0);
}

/**
 * Excluir um Nó da lista pela posição.
 *
 * @param k Posição do nó a ser excluído da lista.
 * @return Verdadeiro ou falso se excluiu o valor da posição.
 */
bool Lista::excluirPosicao(int k) {
    if (getN() != 0) {
        //Verifica se a posição está no intervalo de nós da lista.
        if ((k >= 0) && (k < getN())) {
            //Desaloca o elemento da posição k
            delete lista[k];
            //Desloca os nós do fim até a posição k da lista.
            for (int i = k; i < getN(); i++) {
                lista[i] = lista[i + 1];
            }
            //Decrementa a quantidade de nós da lista.
            setN(getN() - 1);
            return true;
        } else {
            cout << "Posição inválida!\n";
            return false;
        }
    } else {
        cout << "Excluir posição - Lista vazia.\n";
        return false;
    }
}

/**
 * Excluir um nó do final da lista.
 *
 * @return Verdadeiro ou falso se excluiu o valor do final.
 */
bool Lista::excluirFim() {
    if (getN() != 0) {
        //desaloca o último elemento
        delete lista[getN() - 1];
        //Decrementa a quantidade de nós da lista.
        setN(getN() - 1);
        return true;
    } else {
        cout << "Excluir fim - Lista vazia.\n";
        return false;
    }
}

/**
 * Excluir um nó da lista pelo valor.
 *
 * @param valor Um valor de um nó a ser excluído da lista.
 * @return Verdadeiro ou falso se excluiu o valor.
 */
bool Lista::excluirValor(int valor) {
    if (getN() != 0) {
        int j = 0;
        //Procura a posição do nó na lista.
        //Compara o valor na lista ou até chegar no final da lista.
        while ((j < getN()) && (valor != lista[j]->getDado())) {
            j = j + 1;
        }
        //Verifica se a posição esta dentro do intervalo da lista
        if (j < n) {
            //Desaloca o elemento da posição k
            delete lista[j];
            //Desloca os nós do fim até a posição j da lista.
            for (int i = j; i < getN(); i++) {
                lista[i] = lista[i + 1];
            }
            //Decrementa a quantidade de nós da lista.
            setN(getN() - 1);
            return true;
        } else {
            cout << "Excluir valor - Valor não existe na lista.\n";
            return false;
        }
    } else {
        cout << "Excluir valor - Lista vazia.\n";
        return false;
    }
}

/**
 * Retorna o dado de uma posição na lista.
 *
 * @param k Posição do nó a ser consultado na lista.
 * @return A posição de valor na lsita.
 */
int Lista::procurarPosicao(int k) {
    if (getN() != 0) {
        //Verifica se a posição esta dentro do intervalo da lista
        if ((k >= 0) && (k < getN())) {
            return lista[k]->getDado();
        } else {
            cout << "Procurar posição - Posição inválida.\n";
            return -1;
        }
    } else {
        cout << "Procurar posição - Lista vazia.\n";
        return -1;
    }
}

/**
 * Retorna a posição de um nó na lista.
 *
 * @param valor O valor de um nó a ser procurado na lista.
 * @return A posição de valor na lsita.
 */
int Lista::procurarValor(int valor) {
    if (getN() != 0) {
        int i = 0;
        //Procura a posição do nó na lista.
        //Compara o valor na lista ou até chegar no final da lista.
        while ((i < getN()) && (valor != lista[i]->getDado())) {
            i = i + 1;
        }
        //Verifica se a posição esta dentro do intervalo da lista
        if (i < getN()) {
            return i;
        } else {
            return -1;
        }
    } else {
        cout << "Posição Valor - Lista Vazia.\n";
        return -1;
    }
}

/**
 * Lista os dados da lista.
 *
 * @return Uma String com os dados da lista.
 */
string Lista::listar() {
    //String de retorno
    string temp = "";
    for (int i = 0; i < getN(); i++) {
        temp = temp + to_string(i) + "-" + lista[i]->paraString() + "\n";
    }
    return temp;
}

/**
 * Retorna se a lista está cheia.
 *
 * @return Verdadeiro ou falso se a lista está cheia.
 */
bool Lista::estaCheia() {
    return getN() == TAMANHO_LISTA;
}

/**
 * Retorna se a lista esta vazia.
 *
 * @return Verdadeiro ou falso se a lista está vazia.
 */
bool Lista::estaVazia() {
    return getN() == 0;
}

/**
 * Retorna a quantidade de Nós da lista.
 *
 * @return A quantidade de Nós da lista.
 */
int Lista::getQuantidade() {
    return getN();
}