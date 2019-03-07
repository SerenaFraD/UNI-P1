//Parola più lunga presente in una stringa
#include<stdio.h>
#define NCHAR 50 //NUMERO CARATTERI

int creazioneFrase(char* stringa, int dimStringa);
int parolaLunga(char* stringa[], int dimFrase);

int main(void) {
	char frase[NCHAR + 1];
	int dimReale;
	
	printf("%d\n", dimReale = creazioneFrase(frase, NCHAR + 1));
	
	return 0;
}

int parolaLunga(char* stringa[], int dimFrase) {
	int max = 0;
	char *p, *inizio = stringa, *fine;
	
	for(p = stringa; p <= stringa + dimFrase; p++) {
		if(*p == ' ') {
			fine = p;
		}
		tmp = fine - inizio;
		if(max < tmp) {
			max = tmp;
		}
		inizio = p + 1;
		fine = p + 1;
	}
	
	return max;
}



int creazioneFrase(char* stringa, int dimStringa) {
	char* p;
	
	for(p = stringa; (p < stringa + dimStringa - 1) && ((*p = getchar()) != '\n'); p++);
	*(p + dimStringa) = '\0';
	
	return p - stringa;
}


