#include<stdio.h>

int main() {
	int i = 1;
	char c;
	
	printf("Inserisci una parola ");
	c = getchar();
	while(c != '\n' && c != 32) {
		if(i % 2 == 0) {
			printf("%c", c);
		}
		i++;
		c = getchar();
	}
	
	printf("\n");
	return 0;
}
	
	
	
	

