#include <stdio.h>
#include <stdlib.h>

int filtro(){
	int tamFil = 2;  
	int tam = 4;
	int tamSai = (tam - tamFil+1);
	int vSai[tamSai];
	int vEntr[tam], vFil[tamFil];

	
	//int n = 0;
	int i, j;
	// j = ecx
	// i = edx
	for (i = 0; i < tamSai; i++) {
		for ( j = 0; j < tamFil; j++) {
			vSai[i] += (vFil[j]*vEntr[i+j]);
		}
		//n++;
	}
}

int main(){
	filtro();
}