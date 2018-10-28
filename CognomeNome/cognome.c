#include<stdio.h>


int main(void) {
	char i, n, cognome; //i iniziale, cognome lettere del cognome;
	
	printf("Inserire il nome\n");
	i = getchar();
	while(getchar() != ' ');

	while((cognome = getchar()) != '\n') {
		if(cognome != ' ') {
			putchar(cognome);
		}
	}
	
	printf(", ");
	putchar(i);
	printf(".\n");
	
	return 0;
}
