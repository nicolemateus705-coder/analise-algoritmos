#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

// ================= BUSCAS =================

// Busca Sequencial
int buscaSequencial(vector<int>& v, int chave) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == chave) return i;
    }
    return -1;
}

// Busca Binária
int buscaBinaria(vector<int>& v, int chave) {
    int inicio = 0, fim = v.size() - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == chave) return meio;
        if (v[meio] < chave) inicio = meio + 1;
        else fim = meio - 1;
    }

    return -1;
}

// ================= ORDENAÇÃO =================

// Insertion Sort
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

// variável global para evitar otimização excessiva
volatile int resultadoBusca = 0;

// ================= MAIN =================

int main() {
    vector<int> tamanhos = {1000, 5000, 10000, 20000, 50000, 100000};

    cout << "BUSCA SEQUENCIAL" << endl;
    for (int n : tamanhos) {
        long long soma = 0;

        for (int i = 0; i < 30; i++) {
            vector<int> v(n);

            for (int j = 0; j < n; j++) {
                v[j] = j;
            }

            int chave = n - 1; // pior caso: último elemento

            auto inicio = high_resolution_clock::now();

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

        long long media = soma / 30;
        cout << "n = " << n << " | tempo medio = " << media << " ns" << endl;
    }

    return 0;
}