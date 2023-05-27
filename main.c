#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process(long long *);

int main(void){
  //VARIAVEIS:
  clock_t start; //para pegar o tempo antes de rodar o processo
  clock_t end; //para pegar o tempo depois de rodar o processo
  int n; //para pegar a quantidade de vezes que o usuário quer que o processo rode
  FILE * fp; //para guardar os valores previstos e calculados
  double cpu_time_used = 0; //como não temos um tempo anterior, o primeiro tempo usado do CPU será 0
  double previst; //para guardar o valor previsto pela forma Tn+1 = α × Tn + (1 - α) × Tn
  float alpha; //para guardar o valor de alpha (dado pelo usuário)
  long long sum; //variável será usada no proceso
  fp = fopen("sjf.txt", "w");
  printf("Este programa usa o cálculo de previsão dos picos de CPU do SJF para prever a duração do próximo processo. Também calcula automaticamente o tempo de execução e gera um gráfico com ambas as análises, comparando-as.\n\nDigite, respectivamente, quantas vezes você quer rodar o laço, o pico de CPU inicial e o valor de alpha para o cálculo de previsão: ");
  scanf("%d %lf %f",&n, &cpu_time_used, &alpha);

  while (!(0 <= alpha && alpha <= 1)){
    //fator α deve atender o requisito: 0 ≤ α ≤ 1
    printf("O valor de alpha deve ser entre 0 e 1 (geralmente, o mais usado é 0.5)\n");
    scanf("%f", &alpha);
  }

  for(int i = 0; i < n; i++){
    //processo rodará n vezes (dado pelo usuário)
    

    start = clock(); //pega o tempo inicial, antes do processo
    process(&sum); //processo que terá seu tempo calculado
    end = clock(); //pega o tempo final, após o processo
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //calcula o tempo do proceso em si

    fprintf(fp, "%d %f %f\n", i+1, previst, cpu_time_used); //grava no arquivo o tempo previsto

    /*
        NO ARQUIVO, OS DADOS SERÃO GUARDADOS ASSIM:

        vez da execução | pico de cpu previsto | pico de cpu real calculado
    */
  }
  
  fclose(fp); //fecha o arquivo
  system("gnuplot"); //chama o gnuplot

  
}

void process(long long * sum){
  sum = 0;                                              //PROCESSO
  for (long long i = 1; i <= 1000000; i++) {            //PROCESSO 
    sum += i;                                           //PROCESSO 
  }                                                     //PROCESSO 
}

/*A PARTE BÁSICA DESSE CÓDIGO (O PROCESSO QUE SOMA 1.000.000, E SEU CÁLCULO DE TEMPO) FOI FEITO PELO CHATGPT*/
