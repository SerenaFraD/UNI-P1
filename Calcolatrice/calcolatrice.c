/*INPUT: num1, num2, scelta;
*OUTPUT: stampa delle operazioni tra i due numeri;
*/

#include<stdio.h>

int main() {

	int num1, num2, scelta;
	
	printf("Inserire due numeri ");
	scanf("%d %d", &num1, &num2);
	
	printf("\nInserire la propria scelta.\n");
	printf("1: Somma;\n");
	printf("2: Differenza;\n");
	printf("3: Prodotto;\n");
	printf("4: Modulo;\n");
	printf("5: Quoziente;\n");
	
	scanf("%d", &scelta);
	
	if((scelta < 1) || (scelta > 5)) {
		printf("Scelta non contemplata. Errore, bye!\n");
		return 0;
	} else {
		if(scelta == 1) 
			printf("Somma = %d\n", num1 + num2);
		else if(scelta == 2) 
			printf("Differenza = %d\n", num1 - num2);
		else if(scelta == 3) 
			printf("Prodotto = %d\n", num1 * num2);
		else if(scelta == 4) 
			printf("Modulo = %d\n", num1 % num2);
		else if(scelta == 5) 
			printf("Quoziente = %d\n", num1 / num2);		
	}
	
	return 0;
}	

	
	
