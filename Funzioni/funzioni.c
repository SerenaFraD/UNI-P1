#include<stdio.h>
#include<stdlib.h>
#define N (int) 10

void Input(int array[], int dimArray);
void Stampa(int array[], int dimArray);
int Somma(int array[], int dimArray, int som);

int main(void) {
	int a[N];

	Input(a, N);
	printf("La somma degli elementi e' %d\n", Somma(a, N, 0));
	Stampa(a, N);

	return 0;
}

void Input(int array[], int dimArray) {
	printf("Inserimento elementi nel vettore\n");

	while(dimArray > 0) {
		scanf("%d", &array[dimArray - 1]);
		dimArray--;
	}

	printf("Input completato.\n");
	return;
}

void Stampa(int array[], int dimArray);
	int i = dimArray;

	printf("Stampa elementi del vettore\n");

	while(dimArray > 0) {
		printf("%d   ", dimArray);
		printf("%d\n", array[dimArray - m + 1]);
		m--;
	}

	return;
}

int Somma(int array[], int dimArray, int som) {

	if(dimArray == 0) {
		return som;
	} else {
		som = som + array[dimArray - 1];
		return Somma(array, dimArray - 1, som);
	}
}
