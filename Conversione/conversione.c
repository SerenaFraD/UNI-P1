/*Programming project 4.4*/

/*Farsi dare il numero e procedere per divisioni continue per 8*/

#include<stdio.h>
 
int main() {
	
	int num, r1, r2, r3, r4, r5;
	
	printf("Inserire un numero tra 0 e 32767");
	scanf("%d", &num);
	
	r5 = num % 8;
	num /= 8;
	r4 = num % 8;
	num /= 8;
	r3 = num % 8;
	num /= 8;
	r2 = num % 8;
	num /= 8;
	r1 = num % 8;
	num /= 8;
	
	printf("%d%d%d%d%d", r1, r2, r3, r4, r5);
	
	return 0;
}	


