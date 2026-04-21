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
