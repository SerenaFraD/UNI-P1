/*Programming progect 4.1*/

/*Richiedere l'inserimento del numero;
*in prontf calcolre decina con mod 10;
*in printf calcolare unità con diviso 10;
*/

#include<stdio.h>

int main() {
	
	int num;
	
	printf("Inserire numero. ");
	scanf("%d", &num);
	printf("Il reverse e' %d%d", num % 1o, num / 10);
	
	return 0;
}
