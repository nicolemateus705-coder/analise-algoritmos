# Análise Empírica de Complexidade de Algoritmos

Projeto desenvolvido para a disciplina de Estruturas de Dados Básicos I.

## Objetivo
Analisar empiricamente o tempo de execução de algoritmos clássicos e comparar os resultados obtidos com funções assintóticas teóricas.

## Algoritmos analisados
- Busca Sequencial
- Busca Binária
- Insertion Sort

## Metodologia
Foram realizados testes com diferentes tamanhos de entrada, calculando o tempo médio de execução de cada algoritmo após múltiplas repetições.

## Resultados esperados
- Busca Sequencial → O(n)
- Busca Binária → O(log n)
- Insertion Sort → O(n²)

## Estrutura do projeto
- `main.cpp`: execução dos testes e medição dos tempos
- `buscas.h / buscas.cpp`: implementação dos algoritmos de busca
- `ordenacao.h / ordenacao.cpp`: implementação do algoritmo de ordenação
