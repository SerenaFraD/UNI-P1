#include<stdio.h>
#define N 10

int main() {
	int occ[N] = {0}, n[N] = {0}, i = 0, r = 0;	//Array delle occorrenze, numero dato in input, indice dell'array, resto del numero;
	long int num;
	
	printf("Inserire un numero.\n");
	scanf("%ld", &num);
	
	occ[0] = (num % N);
	n[0]++;
	num /= 10;
	r++;
	
	while(num > 0) {
		i = 0;
		
		while(i <= r && occ[i] != (num % N)) {
			i++;
		}
		
		if(i > r) {
			r++;
			occ[r] = num % N;
			n[r]++;
		} else if(occ[i] == (num % N)) {
			n[i]++;
		} 
		
		num /= 10;
	}
	
	
	if(r == 0) {
			printf("\nLe cifre non vengono ripetute.\n");
	} else {
		for(i = 0; i < r; i++, printf("%d  %d\n", occ[i], n[i]));
	} 
	
	return 0;
}
