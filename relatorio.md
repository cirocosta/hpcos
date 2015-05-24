% Relatório EP2 MAC0438
% Ciro S. Costa, 8071488
% May, 25, 2015

# Sobre

Um pouco sobre o processo e o que achei do experimento.

## Configuração das máquinas de teste

Feature     Máquina1          Máquina 2
-------     --------          ---------
CPU         i5-460M           i5-4210U
Cores       2                 2
Threads     4                 4
Cache       3M                3M
Geração     1st               4th
Freq        2.53GHz           1.7GHz
RAM         3072 MB           8192 MB
Storage     HDD               SSD


## Benchmark

- Como o tempo foi medido

- Comparação do desempenho em termos de tempo de execução do programa
  - paralelo
  - para cada tipo de entrada, quantas repetições foram realizadas?
     - variando o número de threads, como foi o resultado?
     - definir hipóteses a serem testadas
  - sequencial

- Conclusões do benchmark: foi o esperado? não foi? etc...

```cpp
glm::mat4 matrix(1.0f);
```

## Sobre a biblioteca de multipla precisão

- Como funciona?
- Qual precisão?
- Quais tipos simples são utilizados internamente?

