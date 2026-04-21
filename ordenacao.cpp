#include "ordenacao.h"

// O Insertion Sort insere cada elemento na posição correta
// dentro da parte já ordenada do vetor.
void insertionSort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

// Função auxiliar do Merge Sort.
// Junta duas metades já ordenadas em uma única parte ordenada.
void merge(vector<int>& v, int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    vector<int> esquerda(tamanhoEsquerda);
    vector<int> direita(tamanhoDireita);

    for (int i = 0; i < tamanhoEsquerda; i++) {
        esquerda[i] = v[inicio + i];
    }

    for (int j = 0; j < tamanhoDireita; j++) {
        direita[j] = v[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            i++;
        } else {
            v[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        v[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        v[k] = direita[j];
        j++;
        k++;
    }
}

// O Merge Sort divide o vetor em partes menores,
// ordena cada parte recursivamente e depois combina os resultados.
void mergeSort(vector<int>& v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}
