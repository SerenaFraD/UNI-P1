#include<stdio.h>
#define SIZE 5

int main() {
	int num[SIZE], i;
	
	printf("Inserire 5 numeri interi\n");
	
	for(i = 0; i < SIZE; i++) {
		scanf("%d", &num[i]);
	}
	
	printf("Il reverse della sequenza e' \n");
	
	for(i = SIZE - 1; i >= 0; i--) {
		printf("%d", num[i]);
	}
	
	printf("\n");
	
	return 0;
}
