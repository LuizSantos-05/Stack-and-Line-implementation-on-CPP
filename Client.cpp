#include <iostream>
#include <locale.h>
#include "Fila.h"
#include "Pilha.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR-UTF-8");
    int tamFila, tamPilha;
    cout << "Digite o tamanho da Fila:\n>> ";
    cin >> tamFila;
    cout << "Digite o tamanho da Pilha:\n>> ";
    cin >> tamPilha;

    Fila<int> fila(tamFila);
    Pilha<int> pilha(tamPilha);
    
    while (true)
    {
        int opcao;
        cout << "\n============================\n";
        cout << "Escolha uma operação:\n"
             << "0. Sair\n"
             << "1. Adicionar na fila\n"
             << "2. Remover da fila\n"
             << "3. Limpar fila\n"
             << "4. Imprimir fila\n"
             << "5. Adicionar na pilha\n"
             << "6. Remover da pilha\n"
             << "7. Limpar pilha\n"
             << "8. Imprimir pilha\n"
             << ">> ";
        cin >> opcao;

        if (opcao == 0)
            break;
        
        int dado;
        switch (opcao)
        {
            case 1:
                cout << "Qual valor deseja adicionar?\n>> ";
                cin >> dado;
                fila.inserirFila(dado);
                break;
            case 2:
                cout << "Removendo dado -> " << fila.removerFila() << endl;
                break;
            case 3:
                fila.limparFila();
                break;
            case 4:
                fila.imprimirFila();
                break;
            case 5:
                cout << "Qual valor deseja adicionar?\n>> ";
                cin >> dado;
                pilha.inserirPilha(dado);
                break;
            case 6:
                cout << "Removendo dado -> " << pilha.removerPilha() << endl;
                break;
            case 7:
                pilha.limparPilha();
                break;
            case 8:
                pilha.imprimirPilha();
                break;
        }

    }
    return 0;
}