#pragma once
using namespace std;

const int MAXFILA = 100;

template <typename T>
class Fila
{
private:
    T *Dados;
    int Fim;
    int Tam = MAXFILA;
public:
    Fila();
    Fila(int tam);
    ~Fila();
    void limparFila();
    bool filaCheia();
    bool filaVazia();
    void inserirFila(T dado);
    T removerFila();
    T ultimo();
    void imprimirFila();
};

#include "Fila.cpp"