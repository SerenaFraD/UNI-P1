/*Esercizio 6.5*/

//123456   654321

#include<stdio.h>

int main() {
	int num, res, i = 10;
	
	printf("Inserire un numero intero positivo ");
	scanf("%d", &num);
	
	do {
		res = num % i;
		printf("%d", res);
		num /= i;	
	} while(num > 0);
	
	printf("\n");
	
	return 0;
	
}
