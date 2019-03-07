#include<stdio.h>
#include<ctype.h>
#define LENGHT 50

int input(char stringa[], int dimStringa);
void subreverse(char* stringa1, int lungh1, char* stringa2, int lungh2);
void stampa(char stringa[], int dimStringa);

int main() {
	char s1[LENGHT], s2[LENGHT];
	int len1, len2;
	
	printf("Inserire la prima stringa.     --->   ");
	len1 = input(s1, LENGHT);
	printf("Inserire la seconda stringa.   --->   ");
	len2 = input(s2, LENGHT);
	subreverse(s1, len1, s2, len2);
	stampa(s1, len1);
	return 0;
}

void subreverse(char* stringa1, int lungh1, char* stringa2, int lungh2) {
	char* p, * s, * rev, * fine;
	
	for(p = stringa1, s = stringa2; (*p = *s) || (((p - stringa1) < lungh1) && ((s - stringa2) < lungh2)); p++, s++);
	
	if(*p == *s) {	
		for(rev = stringa1, fine = p; rev < p; rev++) {
			int dist = fine - rev;
			*(stringa1 + dist) = *(fine--);
		}
	}

}

void stampa(char stringa[], int dimStringa) {
	char* p;
	
	for(p = stringa; p < stringa + dimStringa; p++) {
		putchar(*p);
	}

	return;
}


/******************************************
*Funzione riempitrice delle stringhe date *
*in input.																*
*char stringa[] -> array di caratteri			*
*	vuoto.																	*
*int dimStringa -> dimensione della 			*
*stringa passata tra i parametri, passata *
*per valore.															*
******************************************/
int input(char stringa[], int dimStringa) {
	char* p;
	char ch;
	
	for(p = stringa; (ch = getchar()) != '\n' && p < stringa + dimStringa;) {
		if(isalpha(ch)) {
			*p = ch;
			p++;
		}
	}

	return p - stringa; 
}

