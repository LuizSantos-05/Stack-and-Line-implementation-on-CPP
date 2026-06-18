#pragma once
#include <iostream>

using namespace std;

const int MAXPILHA = 100;
template <typename T>
class Pilha
{
private:
    T* Dados;
    int Topo;
    int Tam = MAXPILHA;
public:
    Pilha();
    Pilha(int tam);
    ~Pilha();
    void limparPilha();
    bool pilhaCheia();
    bool pilhaVazia();
    void inserirPilha(T dado);
    T removerPilha();
    T topoPilha();
    void imprimirPilha();
};

#include "Pilha.cpp"