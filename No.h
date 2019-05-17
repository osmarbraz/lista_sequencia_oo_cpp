//Evita a referência circular
#ifndef NO_H
#define NO_H

//Declaração de bibliotecas
#include <iostream>
#include <string>
#include <sstream>   

using namespace std;

/**
 *
 * Nó a ser armazenado na lista.
 *
 */
class No {
private:
    int dado;
public:
    /**
     * Construtor sem parâmetros.
     */
    No();
    
    /**
     * Construtor com parâmetros.
     *
     * @param dado um valor do tipo inteiro.
     */    
    No(int dado);

    /**
     * Recuperador de dado.
     *
     * @return Um inteiro com o dado do nó.
     */    
    int getDado();
   
     /**
     * Modificador de dado.
     *
     * @param dado Um valor inteiro a ser atribuído para o dado.
     */
    void setDado(int dado);

      /**
     * Retorna o valor em String do dado.
     *
     * @return Uma string com o valor do dado do nó.
     */    
    string paraString();
};

#endif /* NO_H */

