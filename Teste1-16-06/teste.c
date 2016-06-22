#include <stdio.h>
//#include <conio.h>


int main () {
  int tam = 0, tamFil = 0;
/*
  if(kbhit()){
    tam = getch();
  }else{
    printf("Digite uma informação!\n");
  }
*/

  printf("Digite o tamanho do Sinal: ");
  scanf("%d", &tam);
  printf("Digite o tamanho do Filtro: ");
  scanf("%d", &tamFil);

  int tamSai = (tam - tamFil+1);
  printf("%d", tamSai);
  int v[tam], f[tamFil], s[tamSai];
  int i, j, soma = 0, aux;
///////////Zerar Vetores////////////
  for (i = 0; i < tam; i++) {
    v[i] = 0;
  }
  for (i = 0; i < tamFil; i++) {
    f[i] = 0;
  }
  for (i = 0; i < tamSai; i++) {
    s[i] = 0;
  }
  /////////////////////////////////

  printf("Digite os valores do Sinal: \n");
    for (i = 0; i < tam; i++) {
      scanf("%d", &v[i]);
    }
  printf("Digite os valores do Filtro: \n");
    for (i = 0; i < tamFil; i++) {
      scanf("%d", &f[i]);
    }

    for (i = 0; i < tamSai; i++) {
      aux = 0;
      for ( j = i; j <= (tamFil+i); j++) {
        soma += v[j]*f[aux];
        aux++;
      }
      s[i] = soma;
      soma = 0;
    }

    printf("\n\n");
    for (i = 0; i < tamSai; i++) {
      printf("%d\n", s[i]);
    }

}
