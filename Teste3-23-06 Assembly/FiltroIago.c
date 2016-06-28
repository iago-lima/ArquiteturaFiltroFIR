#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>

struct  pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

int tempoEs(int *valor){
	if( poll(&mypoll, 1, 2000)) {
		scanf("%d", valor);
	}else{
		printf("Digite algo!!!\n");
		tempoEs(valor);
	}
}

int CMAIN(int *vEntrada, int *vFiltro, int tamFiltro);
/*
int filtro(int vEntrada[], int vFiltro[], int vSaida[], int tamSaida, int tamFiltro){
	printf("Chegou na função FILTRO!!(DEBUG)");
	//int n = 0;
	int i, j;
	// j = ecx
	// i = edx
	for (i = 0; i < tamSaida; i++) {
		for ( j = 0; j < tamFiltro; j++) {
			vSaida[i] += (vFiltro[j]*vEntrada[i+j]);
		}
		//n++;
	}
}
*/
int main () {
	int tamEntrada = 0, tamFiltro = 0;
	
	int i, j, soma = 0, aux;
	int cont = 0;
	long int inicio, fim;

	printf("Digite o tamanho da Entrada: \n");
	tempoEs(&tamEntrada);

	printf("Digite o tamanho do Filtro: \n");
	tempoEs(&tamFiltro);

	int tamSaida = (tamEntrada - tamFiltro+1);
	int vSaida[tamSaida];
	int vEntrada[tamEntrada], vFiltro[tamFiltro];

	for (i = 0; i < tamSaida; i++) {
    	vSaida[i] = 0;
	}


	
	FILE *entrada;
	FILE *saida;

	entrada = fopen("entrada.txt", "r");

	if(entrada == NULL){
    	printf("Erro ao abrir o arquivo!!!");
    	return;
	}else {
		while(fscanf(entrada, "%d,", &vEntrada[cont++]) != EOF);
		      fclose(entrada);
	}

	printf("\n\nVetor de Entrada!!\n");
	
	for (i = 0; i < tamEntrada; i++) {
		printf("%d\n", vEntrada[i]);
	}
	
	printf("\n\n");
	printf("Digite os valores do Filtro: \n");
	
	for (i = 0; i < tamFiltro; i++) {
		tempoEs(&vFiltro[i]);
    }

	inicio = clock();
	for(j = 0; j < (tamEntrada-tamFiltro+1); j++){
      vSaida[j] = CMAIN(vEntrada+j, vFiltro, tamFiltro);

  }
	//filtro(vEntrada, vFiltro, vSaida, tamSaida, tamFiltro);
	fim = clock();

	saida = fopen("saida.txt", "w");

	for (i = 0; i < tamSaida; i++){
		fprintf(saida, "%d\n", vSaida[i]);
	}
	
	fclose(saida);

    printf("\n\n");
    printf("Chegou em imprimir VETOR FINAL (DEBUG)!!!\n");
    for (i = 0; i < tamSaida; i++) {
		printf("%d\n", vSaida[i]);
    }

	printf("Tempo de execução do filtro: %.10lf segundos\n",
		  (double)(fim-inicio)/CLOCKS_PER_SEC);

}