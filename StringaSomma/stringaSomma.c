#include<stdio.h>

int somma(int dimensione, char* stringhe[]); 
int conversione(char* stringhe[], int index);

int main(int argc, char* argv[]) {
	printf("%d\n", somma(argc, argv));
}

int conversione(char* stringhe[], int index) {
	char* p;
	int som = 0, i = 0;
	
	for(p = &stringhe[index][i]; *(p + i); i++) {
		som = 10 * som + *(p + i) - '0';
	}
	
	return som;
}


int somma(int dimensione, char* stringhe[]) {
	int som = 0, i;
		
	for(i = 1; i < dimensione ; i++) {
		som = som + conversione(stringhe, i);
	}

	return som;
}


