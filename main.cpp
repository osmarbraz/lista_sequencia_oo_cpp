/**
 * Implementação de Lista Sequencial de forma orientada a objeto.
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

/**
 * Realiza a leitura dos dados dos nós.
 *
 * @return O valor lido.
 */
int leitura() {
    cout << "\nDigite um valor: ";
    int valor = 0;
    cin >> valor;
    return valor;
}

int main(int argc, char** argv) {
    /**
     * Declara e instancia a lista.
     */
    Lista lista;

    // Controla o menu da lista
    int opcao = -1;

    //Laço do menu de opções
    while (opcao != 99) {
        //Monta o menu de opções        
        cout << "\n\t### Lista Sequencial ###\n"
                << "Selecione a opção desejada:\n"
                << " 1- Listar Nós\n"
                << " 2- Inserir Nó no início\n"
                << " 3- Inserir Nó no fim\n"
                << " 4- Inserir Nó em uma posição especifica\n"
                << " 5- Inserir Nó ordenado\n"
                << " 6- Remover Nó do início\n"
                << " 7- Remover Nó do fim\n"
                << " 8- Remover Nó de uma posição específica\n"
                << " 9- Remover Nó pelo valor\n"
                << "10- Procurar o dado de uma posição específica\n"
                << "11- Procurar a posição de um dado\n"
                << "12- Mostrar a quantidade de Nós\n"
                << "13- Está cheia?\n"
                << "14- Está vazia?\n"
                << "99- Sair\n"
                << " Opcao:";
        cin >> opcao;
        switch (opcao) {
            case 1:
            {
                if (lista.estaVazia()) {
                    cout << "\nLista vazia!" << endl;
                } else {
                    cout << "\nListagem \n" << lista.listar() << endl;
                }
                break;
            }
            case 2:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirInicio(dado) == true) {
                    cout << "\nNó inserido no início com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no início!" << endl;
                }
                break;
            }
            case 3:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirFim(dado) == true) {
                    cout << "\nNó inserido no fim com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no fim!" << endl;
                }
                break;
            }
            case 4:
            {
                int k;
                cout << "\nDigite a posição a ser inserido:";
                cin >> k;
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirPosicao(dado, k) == true) {
                    cout << "\nNó inserido na posição " << k << " com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido na posição " << k << "!" << endl;
                }
                break;
            }
            case 5:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirOrdenado(dado) == true) {
                    cout << "\nNó inserido ordenado com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido ordenado!" << endl;
                }
                break;
            }
            case 6:
            {
                if (lista.excluirInicio()) {
                    cout << "\nO Nó do início foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do início não foi excluído!" << endl;
                }
                break;
            }
            case 7:
            {
                if (lista.excluirFim()) {
                    cout << "\nO Nó da fim foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do fim não foi excluído!" << endl;
                }
                break;
            }
            case 8:
            {
                int k;
                cout << "\nDigite a posição a ser excluída:";
                cin >> k;
                if (lista.excluirPosicao(k)) {
                    cout << "\nO valor da posição " << k << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi excluído!" << endl;
                }
                break;
            }
            case 9:
            {
                //Preenche o valor do dado                 
                int dado;
                cout << "\nDigite o valor do dado a ser excluído:";
                cin >> dado;
                if (lista.excluirValor(dado)) {
                    cout << "\nO valor " << dado << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi excluído!" << endl;
                }
                break;
            }
            case 10:
            {
                int k;
                cout << "\nDigite a posição do dado a ser procurada:";
                cin >> k;
                int dado = lista.procurarPosicao(k);
                if (dado != -1) {
                    cout << "\nO valor da posição " << k << "  possui o dado = " << dado << endl;
                } else {
                    cout << "\nA posição " << k << " não está preenchida" << endl;
                }
                break;
            }
            case 11:
            {
                int chave;
                cout << "\nDigite o valor do dado a ser procurado:";
                cin >> chave;
                int posicao = lista.procuraValor(chave);
                cout << "\nO valor " << chave << " esta na posição " << posicao << endl;
                break;
            }
            case 12:
            {
                cout << "\nQuantidade de Nós na lista : " << lista.getQuantidade() << endl;
                break;
            }
            case 13:
            {
                cout << "\nLista está cheia : " << lista.estaCheia() << endl;
                break;
            }
            case 14:
            {
                cout << "\nLista está vazia : " << lista.estaVazia() << endl;
                break;
            }
        }//Fim Switch
    }//Fim While

    return 0;
}

