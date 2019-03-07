#include<stdio.h>
#define SIZE ((int) sizeof(f) / sizeof(f[0])) //Definizione della macro Size

int main() {
	long int f[40] = {0, 1};	//Dichiarazione dell'array con inizializzazione 
	
	printf("%ld\n%ld\n", f[0], f[1]); //Stampa dei primi due elementi della successione
	
	for(int i = 2; i < SIZE; i++) {	//Ciclo di riempimento della sequenza
		f[i] = f[i - 1] + f[i - 2];	//Somma dell'ultimo elemento e del penultimo 
		printf("%ld\n", f[i]); //Stampa dell'elemento appena creato
	}
	
	return 0;
}
