#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "buscas.h"
#include "ordenacao.h"

using namespace std;
using namespace chrono;

// Variável global para evitar otimização do compilador
volatile int resultadoBusca = 0;

// ================= BUSCAS =================

// Teste da busca sequencial (O(n))
void testarBuscaSequencial(const vector<int>& tamanhos) {
    cout << "BUSCA SEQUENCIAL" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            for (int j = 0; j < n; j++) {
                v[j] = j;
            }

            int chave = n - 1;

            auto inicio = high_resolution_clock::now();

            for (int k = 0; k < 1000; k++) {
                resultadoBusca = buscaSequencial(v, chave);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        cout << "n = " << n << " | tempo medio = " << soma / 30 << " ns" << endl;
    }

    cout << endl;
}

// Teste da busca binária (O(log n))
void testarBuscaBinaria(const vector<int>& tamanhos) {
    cout << "BUSCA BINARIA" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            for (int j = 0; j < n; j++) {
                v[j] = j;
            }

            int chave = n - 1;

            auto inicio = high_resolution_clock::now();

            for (int k = 0; k < 100000; k++) {
                resultadoBusca = buscaBinaria(v, chave);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        cout << "n = " << n << " | tempo medio = " << soma / 30 << " ns" << endl;
    }

    cout << endl;
}

// ================= ORDENAÇÃO =================

// Teste do Insertion Sort (O(n²))
void testarInsertionSort(const vector<int>& tamanhos) {
    cout << "INSERTION SORT" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            for (int j = 0; j < n; j++) {
                v[j] = rand();
            }

            vector<int> copia = v;

            auto inicio = high_resolution_clock::now();

            for (int k = 0; k < 10; k++) {
                vector<int> temp = copia;
                insertionSort(temp);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        cout << "n = " << n << " | tempo medio = " << soma / 30 << " ns" << endl;
    }

    cout << endl;
}

// Teste do Merge Sort (O(n log n))
void testarMergeSort(const vector<int>& tamanhos) {
    cout << "MERGE SORT" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            for (int j = 0; j < n; j++) {
                v[j] = rand();
            }

            auto inicio = high_resolution_clock::now();

            for (int k = 0; k < 10; k++) {
                vector<int> temp = v;
                mergeSort(temp, 0, temp.size() - 1);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        cout << "n = " << n << " | tempo medio = " << soma / 30 << " ns" << endl;
    }

    cout << endl;
}

// ================= MAIN =================

int main() {
    vector<int> tamanhosBusca = {1000, 5000, 10000, 20000, 50000, 100000};
    vector<int> tamanhosOrdenacao = {100, 500, 1000, 2000, 5000, 10000};

    testarBuscaSequencial(tamanhosBusca);
    testarBuscaBinaria(tamanhosBusca);
    testarInsertionSort(tamanhosOrdenacao);
    testarMergeSort(tamanhosOrdenacao);

    return 0;
}
