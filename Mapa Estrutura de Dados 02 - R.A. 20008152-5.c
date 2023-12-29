#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void intercala (int *x, int inicio, int fim, int meio){
	int pl, inicio_v1, inicio_v2,i;
	int aux[fim];
	inicio_v1 = inicio;
	inicio_v2 = meio+1;
	pl = inicio;
	while (inicio_v1 <= meio && inicio_v2<=fim){
		if(x[inicio_v1]<=x[inicio_v2]){
			aux[pl] = x[inicio_v1];
			inicio_v1+=1;
		}else{
			aux[pl] = x[inicio_v2];
			inicio_v2+=1;	
		}
		pl++;
	}
	for (i = inicio_v2; i<=fim; i++){
		aux[pl] = x[i];
		pl++;
	}
	for (i = inicio_v1; i<=meio; i++){
		aux[pl] = x[i];
		pl++;
	}
	for (i = inicio; i<=fim; i++){
		x[i] = aux[i];
	}
}

void merge (int *x, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		merge (x, inicio, meio);
		merge (x, meio+1, fim);
		intercala (x, inicio, fim, meio);
	}
}

void mostrar_vendas (int *x, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("\n%d", x[i]);
	}
	printf("\n");
}

int main (void){
	setlocale(LC_ALL, "Portuguese");
	int arquivo[] = {2,0,0,0,8,1,5,2};
	int tam = sizeof(arquivo)/sizeof(int);
	printf("Olá! Segue abaixo as vendas do dia de cada um dos seus Pontos de Vendas:\n");
	mostrar_vendas (arquivo, tam);
	merge(arquivo, 0, tam-1);
	printf("\nSegue abaixo as vendas de forma ordenada, da menor para a maior:\n");
	mostrar_vendas (arquivo, tam);
}


