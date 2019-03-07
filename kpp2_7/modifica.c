/*Scrivere un programma che chiede all'utentedi inserire un ammontare intero in euro e mostra, secondo lo schema seguente, come pagare usando il minor numero di carte da 1, 5, 10, 20 euro.*/

/*Richiedere in input la cifra;
*dichiarare variabili euro, num (per il numero delle carte/monete), resto (per la *quantità di soldi rimasti);
*Dividere per la quantità di carte da 20 e mostrare il risultato, colcolare il *resto con operazione di modulo e continuare l'esecuzione;
*/

#include<stdio.h>

int main() {

	int euro, num, resto = 0;

	printf("Inserire la cifra in euro. ");
	scanf("%d", &euro);

	printf("\n\n");

	printf("Numero di carte da 520 euro:%2d", euro / 20);
	euro = euro % 20;

	printf("\nNumero di carte da 10 euro:%2d", euro / 10);
	euro = euro % 10;

	printf("\nNumero di carte da 5 euro:%3d", euro / 5);
	euro = euro % 5;
	
	printf("\nNumero di carte da 1 euro:%3d", euro);
	
	printf("\n\n");
	
	return 0;
}
	






