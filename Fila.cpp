#include <iostream>
#include "Fila.h"

using namespace std;

template <typename T>
Fila<T>::Fila()
{
    Dados = new T[MAXFILA];
    Fim = -1;
}

template <typename T>
Fila<T>::Fila(int tam)
{
    Tam = tam;
    Dados = new T[tam];
    Fim = -1;
}

template <typename T>
Fila<T>::~Fila()
{
    delete[] Dados;
}

template <typename T>
void Fila<T>::limparFila()
{
    for (int i = 0; i <= Fim; i++)
    {
        Dados[i] = 0;
    }
    Fim = -1;
}

template <typename T>
bool Fila<T>::filaCheia()
{
    if (Fim == Tam - 1)
        return true;
    else
        return false;
}

template <typename T>
bool Fila<T>::filaVazia()
{
    if (Fim == -1)
        return true;
    else
        return false;
}

template <typename T>
void Fila<T>::inserirFila(T dado)
{
    try
    {
        if (filaCheia())
        {
            throw runtime_error("\033[31mErro: Fila cheia\033[0m\n");
        }
        Fim++;
        Dados[Fim] = dado;
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
    }
}

template <typename T>
T Fila<T>::removerFila()
{
    try
    {
        if (filaVazia())
        {
            throw runtime_error("\033[31mErro: Fila vazia\033[0m\n");
        }
        T dadoRemovido = Dados[0];
        for (int i = 0; i < Fim; i++)
        {
            Dados[i] = Dados[i + 1];
        }
        Dados[Fim] = 0;
        Fim--;
        return dadoRemovido;
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return Fim;
    }
}

template <typename T>
T Fila<T>::ultimo()
{
    try
    {
        if (filaVazia())
        {
            throw runtime_error("\033[31mErro: Fila vazia\033[0m\n");
        }
        return Dados[Fim];   
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return Fim;
    }
}

template <typename T>
void Fila<T>::imprimirFila()
{
    for (int i = 0; i <= Fim; i++)
    {
        if (i == 0)
        cout << "| " << Dados[i] << " | ";
        else
        cout << Dados[i] << " | ";
    }
    cout << "\n\033[32m| " << Fim << " |\033[0m\n";
}