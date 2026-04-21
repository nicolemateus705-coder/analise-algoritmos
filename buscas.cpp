#include "buscas.h"

// A busca sequencial percorre o vetor do início ao fim
// até encontrar o valor procurado.
int buscaSequencial(vector<int>& v, int chave) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == chave) {
            return i;
        }
    }
    return -1;
}

// A busca binária divide o vetor ordenado ao meio a cada etapa,
// reduzindo rapidamente o espaço de busca.
int buscaBinaria(vector<int>& v, int chave) {
    int inicio = 0;
    int fim = v.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == chave) {
            return meio;
        }

        if (v[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}
