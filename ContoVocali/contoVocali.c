#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define NCHAR 40

int numberVowel(char *);
void inputStringa(int nChar, char stringa[]);

int main() {
	char s[NCHAR];
	
	inputStringa(NCHAR, s);
	printf("Il numero di vocali e': %d.\n", numberVowel(s));

	return 0;
}


void inputStringa(int nChar, char stringa[]) {
	char *p;
	
	printf("Inserire una stringa da controllare.\n");
	for(p = stringa; (p - stringa) < (nChar - 1) && (*p = getchar()) != '\n'; p++);
	
	*(p++) = '\n';

	return;
}

int numberVowel(char *stringa) {
	char *p = stringa;
	int i = 0;
	
	while(*p != '\n') {
		if((tolower(*p) == 'a') || (tolower(*p) == 'e') || (tolower(*p) == 'i') || (tolower(*p) == 'o') || (tolower(*p) == 'u')) {
			i++;
		}
		p++;
	}
	
	return i;
}
