#ifndef BUSCAS_H
#define BUSCAS_H

#include <vector>
using namespace std;

// Realiza busca sequencial em um vetor.
// Retorna a posição da chave, se encontrada.
// Retorna -1 caso a chave não exista no vetor.
int buscaSequencial(vector<int>& v, int chave);

// Realiza busca binária em um vetor ordenado.
// Retorna a posição da chave, se encontrada.
// Retorna -1 caso a chave não exista no vetor.
int buscaBinaria(vector<int>& v, int chave);

#endif
