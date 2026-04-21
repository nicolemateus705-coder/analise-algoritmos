# Análise Empírica de Complexidade de Algoritmos

##  Objetivo

Este projeto tem como objetivo analisar empiricamente o tempo de execução de algoritmos clássicos, comparando os resultados obtidos com funções assintóticas teóricas.

##  Algoritmos analisados

###  Busca

* Busca Sequencial → O(n)
* Busca Binária → O(log n)

###  Ordenação

* Insertion Sort → O(n²)
* Merge Sort → O(n log n)

##  Metodologia

* Execução com diferentes tamanhos de entrada
* Cálculo do tempo médio com múltiplas repetições
* Uso da biblioteca `<chrono>` para medição
* Normalização dos dados para comparação
* Geração de gráficos com funções teóricas

##  Resultados esperados

Os resultados experimentais confirmam:

* Busca Sequencial → crescimento linear
* Busca Binária → crescimento logarítmico
* Insertion Sort → crescimento quadrático
* Merge Sort → crescimento O(n log n)

##  Estrutura do projeto

* `main.cpp` → execução dos testes
* `buscas.h / buscas.cpp` → algoritmos de busca
* `ordenacao.h / ordenacao.cpp` → algoritmos de ordenação

##  Observação

Este projeto foi desenvolvido como parte da disciplina de Estruturas de Dados, com foco na análise empírica de algoritmos.

##  Relatório

O relatório completo acompanha a entrega do trabalho.
