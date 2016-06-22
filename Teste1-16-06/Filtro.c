#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>

struct  pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

int tempoEs(int *valor);


/////////////////////////////////Ler Arquivo/////////////////////////////////////////

void valor_Arq(int valor[]){

}
///////////////////////////Fim Ler arquivo/////////////////////////////////////////



int filtro(int vEntr[], int vFil[], int vSai[], int tamSai, int tamFil){
  printf("Chegou na função FILTRO!!(DEBUG)");
  int n = 0;
  int i, j;
  for (i = 0; i < tamSai; i++) {
    for ( j = 0; j < tamFil; j++) {
      vSai[n] += (vFil[j]*vEntr[i+j]);
    }
    n++;
  }
}

int main () {
  int tam = 0, tamFil = 0;
  long int inicio, fim;

///////////Tamanho do Sinal////////////
//  printf("Digite o tamanho do Sinal: \n");
//  tempoEs(&tam);
///////////Tamanho do Filtro////////////
  printf("Digite o tamanho do Filtro: \n");
  tempoEs(&tamFil);
///////////Variáveis////////////
  int tamSai = (tam - tamFil+1);
  int vEntr[6], vFil[tamFil], vSai[tamSai];
  int i, j, soma = 0, aux;
///////////Zerar Vetores////////////
  for (i = 0; i < tamSai; i++) {
    vSai[i] = 0;
  }



/*//////////Valores do Sinal////////////
  printf("Digite os valores do Sinal: \n");
    for (i = 0; i < tam; i++) {
      tempoEs(&vEntr[i]);
    }
*/

// Aqui node ele pega os valores do arquivo!!! Um pequeno problema em executar a função filtro dpois que pega os valores!!!
//---------------------------------------------------------------
int x = 0;
  int ch;
  FILE *arq;
  arq = fopen("teste.txt", "r");
  printf("Abriu o arquivo\n");
  if(arq == NULL){
      printf("Erro, nao foi possivel abrir o arquivo\n");
  }
  else {
    printf("Pegando valores(DEBUG)\n");
      while(fscanf(arq, "%d,", &vEntr[x++]) != EOF);
      fclose(arq);
  }

  printf("\n\nVetor de Entrada(DEBUG)!!\n");
  for (i = 0; i < 6; i++) {
    printf("%d\n", vEntr[i]);
  }
  printf("\n\n");
  //-------------------------------------------------

///////////Valores do Filtro////////////
  printf("Digite os valores do Filtro: \n");
    for (i = 0; i < tamFil; i++) {
      tempoEs(&vFil[i]);
    }


inicio = clock();
///////////Filtro////////////
filtro(vEntr, vFil, vSai, tamSai, tamFil);
fim = clock();
///////////Imprimir Saída////////////
    printf("\n\n");
    printf("Chegou em imprimir VETOR FINAL (DEBUG)!!!\n");
    for (i = 0; i < tamSai; i++) {
      printf("%d\n", vSai[i]);
    }


    printf("Tempo de execução do filtro: %.10lf segundos\n",(double)(fim-inicio)/CLOCKS_PER_SEC);

}

int tempoEs(int *valor){
  if( poll(&mypoll, 1, 2000)) {
      scanf("%d", valor);
  }else{
    printf("Digite algo!!!\n");
    tempoEs(valor);
  }
}
