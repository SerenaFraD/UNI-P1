/*Scrivere un programma he chiede in input due interi e restituisce il massimo tra i due*/

/*Richiedo in input i due numeri num1 e num2;
*confronto se num1 è maggiore di num2 e lo stampo;
*confronto se i due numeri sono uguali e stampo;
*altrimenti stampo che num2 e maggiore di num1;
*/

/*INPUT: num1, num2;
*OUTPUT: max(num1, num2) or equal(num1, num2);
*/


#include<stdio.h>

int main() {

	int num1, num2;
	
	printf("Inserire i due numeri ");
	scanf("%d%d", &num1, &num2);
	
	if(num1 > num2) {
		//MAX: num1;
		printf("Il numero %d è il maggiore.\n", num1);
	} else {
		if(num1 == num2) {
			printf("I due numeri sono uguali.\n");
		} else {
			//MAX: num2;
			printf("Il numero %d è il maggiore.\n", num2);
		}
	}
			
	return 0;
}
