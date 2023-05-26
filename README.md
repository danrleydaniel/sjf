# SJF
Em escalonamento de processos, existe um cálculo que serve para prever a duração do próximo pico de CPU com base nas durações anteriores. Essa previsão é útil no algoritmo de escalonamento Shortest Job First (SJF). Este programa faz uma previsão do próximo pico de CPU de um determinado processo e calcula o tempo real que de fato o processo leva, gerando um arquivo .txt que pode ser plotado e ter os seus dados comparados.

##T<sub>n+1</sub> = $\alpha$ × (1 - $\alpha$) × T<sub>n</sub>
