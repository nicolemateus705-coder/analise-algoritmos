#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "buscas.h"
#include "ordenacao.h"

using namespace std;
using namespace chrono;

// Variável global usada para evitar que o compilador elimine
// chamadas de busca durante otimizações.
volatile int resultadoBusca = 0;

// Função para medir o tempo médio da busca sequencial.
// O pior caso é usado procurando o último elemento do vetor.
void testarBuscaSequencial(const vector<int>& tamanhos) {
    cout << "BUSCA SEQUENCIAL" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            // Preenche o vetor com valores crescentes.
            for (int j = 0; j < n; j++) {
                v[j] = j;
            }

            int chave = n - 1;

            auto inicio = high_resolution_clock::now();

            // A repetição interna evita tempos iguais a zero.
            for (int k = 0; k < 1000; k++) {
                resultadoBusca = buscaSequencial(v, chave);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        long long media = soma / 30;
        cout << "n = " << n << " | tempo medio = " << media << " ns" << endl;
    }

    cout << endl;
}

// Função para medir o tempo médio da busca binária.
// O vetor já está ordenado, como o algoritmo exige.
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

            // A busca binária é muito rápida, então usa mais repetições.
            for (int k = 0; k < 100000; k++) {
                resultadoBusca = buscaBinaria(v, chave);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        long long media = soma / 30;
        cout << "n = " << n << " | tempo medio = " << media << " ns" << endl;
    }

    cout << endl;
}

// Função para medir o tempo médio do Insertion Sort.
void testarInsertionSort(const vector<int>& tamanhos) {
    cout << "INSERTION SORT" << endl;

    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            // Gera valores aleatórios para o vetor.
            for (int j = 0; j < n; j++) {
                v[j] = rand();
            }

            vector<int> copia = v;

            auto inicio = high_resolution_clock::now();

            // Repete várias vezes e usa cópia para evitar medir
            // o algoritmo em vetor já ordenado.
            for (int k = 0; k < 10; k++) {
                vector<int> temp = copia;
                insertionSort(temp);
            }

            auto fim = high_resolution_clock::now();

            soma += duration_cast<nanoseconds>(fim - inicio).count();
        }

        long long media = soma / 30;
        cout << "n = " << n << " | tempo medio = " << media << " ns" << endl;
    }

    cout << endl;
}

int main() {
    vector<int> tamanhosBusca = {1000, 5000, 10000, 20000, 50000, 100000};
    vector<int> tamanhosOrdenacao = {100, 500, 1000, 2000, 5000, 10000};

    testarBuscaSequencial(tamanhosBusca);
    testarBuscaBinaria(tamanhosBusca);
    testarInsertionSort(tamanhosOrdenacao);

    return 0;
}
