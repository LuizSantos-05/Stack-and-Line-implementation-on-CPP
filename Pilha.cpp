#include <iostream>
#include "Pilha.h"

using namespace std;

template <typename T>
Pilha<T>::Pilha()
{
    Dados = new T[MAXPILHA];
    Topo = -1;
}

template <typename T>
Pilha<T>::Pilha(int tam)
{
    Tam = tam;
    Dados = new T[tam];
    Topo = -1;
}

template <typename T>
Pilha<T>::~Pilha()
{
    delete[] Dados;
}

template <typename T>
void Pilha<T>::limparPilha()
{
    for (int i = Topo; i >= 0; i--)
    {
        Dados[i] = 0;
    }
    Topo = -1;
}

template <typename T>
bool Pilha<T>::pilhaCheia()
{
    if (Topo == Tam - 1)
        return true;
    else
        return false;
}

template <typename T>
bool Pilha<T>::pilhaVazia()
{
    if (Topo == -1)
        return true;
    else
        return false;
}

template <typename T>
void Pilha<T>::inserirPilha(T dado)
{
    try
    {
        if (pilhaCheia())
        {
            throw runtime_error("\033[31mErro: Pilha cheia\033[0m\n");
        }

        Topo++;
        Dados[Topo] = dado;
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
T Pilha<T>::removerPilha()
{
    try
    {
        if (pilhaVazia())
        {
            throw runtime_error("\033[31mErro: Pilha vazia\033[0m\n");
        }

        T temp = Dados[Topo];
        Dados[Topo] = 0;
        Topo--;
        return temp;
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return Topo;
    }
}

template <typename T>
T Pilha<T>::topoPilha()
{
    try
    {
        if (pilhaVazia())
        {
            throw runtime_error("\033[31mErro: Pilha vazia\033[0m\n");
        }

        return Dados[Topo];
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return Topo;
    }
}

template <typename T>
void Pilha<T>::imprimirPilha()
{
    try
    {
        if (pilhaVazia())
        {
            throw runtime_error("\033[31mErro: Pilha vazia\033[0m\n");
        }
        for (int i = Topo; i >= 0;)
        {
            cout << "| " << Dados[i] << " |";
            if (i != 0)
                cout << "\n";
            i--;                // Por algum motivo, este i-- estava decrescendo antes de executar o laço, por isso foi colocado aqui
        }
        cout << " \033[32m| " << Topo << " |\033[0m\n";
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }
}
