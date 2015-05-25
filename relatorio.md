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

Para conseguir analisar os resultados obtidos com a implementação utilizou-se de benchmarking através de repetida execução de testes automatizados.

Mediu-se o tempo através da biblioteca padrão (C++11) com a implementação de um pequeno conjunto de macros utilizadas para capturar os resultados obtidos das repetidas execuções.

Com os dados coletados, buscou-se então validar as seguintes hipóteses:

1.  Utilizando o modo 'f' teremos menos eficiência do que com o método 'm' dado que o segundo, apesar de precisar parar na barreira tanto quanto o primeiro, precisa realizar menos etapas de redução.
2.  Maior eficiência para número de threads utilizadas igual ao número suportado pela máquina (especificando 0 no parâmetro de entrada, por tanto).


- Comparação do desempenho em termos de tempo de execução do programa
  - paralelo
  - para cada tipo de entrada, quantas repetições foram realizadas?
     - variando o número de threads, como foi o resultado?
     - definir hipóteses a serem testadas
  - sequencial

- Conclusões do benchmark: foi o esperado? não foi? etc...


## Barreiras e Biblioteca de Múltipla Precisão

A sincronização do cálculo das threads (etapas de redução e verificação) contou com a implementação de uma barreira de duas fases e semáforos com a possibilidade de 'pre-carregar' o semáforo com mais de um sinal. Isto permitiu uma representação simples do conceito.

Para que fosse possível efetuar cálculos com tamanha precisão foi utilizada a biblioteca GMP (Gnu Multiple Precision Arithmetic Library) que nos permite utilizar de precisão artitrária (limitada à memória disponível). A ideia básica é tratar grandes números como uma composição de pequenas partes e aplicar regras básicas de aritimética parte a parte.

Para cada tipo que a biblioteca define (inteiros, floats e racionais), uma representação interna diferente é utilizada. No caso do Mpf (multiple precision float) - o mais utilizado na implementação - a estrutura é dada por duas partes: o conjunto reference ao expoente que trata de determinar o ponto de raíz


- Como funciona?
- Quais tipos simples são utilizados internamente?

