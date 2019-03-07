#include<stdio.h>
#define N 10

int ricerca(const int a[], int n, int key);

int main() {
	int a[N] = {0, 11, 45, 96, 69, 23, 85, 65, 159, 1}, val;
	
	printf("Inserire un valore intero da ricercare.\n");
	scanf("%d", &val);
	
	printf(ricerca(a, N, val)? "Valore trovato.\n" : "Valore non trovato.\n");
	
	return 0;

}


int ricerca(const int array[], int arrayDim, int key) {
	const int *p, *dimention  = array + arrayDim;
	p = array;
	
	while(p < dimention && *p != key) {
		p++;	
	}
	
	return *p == key;
}
