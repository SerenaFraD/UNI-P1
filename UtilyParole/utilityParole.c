#include<stdio.h>
#include<ctype.h>
#define N 50

int CreateStringa(char stringa[], int dimStringa); v
void StampaStringa(const char stringa[], int dimStringa); v
int NumeroCaratteri(const char stringa, int dimStringa); ///Già fatta senza volerlo.
int NumeroParole(const char stringa[], int dimStringa); v
void ParolaLunga(const char stringa, int dimStringa, int* inizio);
void ReverseStringa(const char stringa[], int dimStringa); v
void ReverseParole(const char stringa, int dimStringa);
void ToMaiusc(char stringa[], int dimStringa); 

int main() {
	char s[N];
	int dimReale;
	
	printf("Inserisci una frase.\n");
	dimReale = CreateStringa(s, N);
	printf("%d\n", dimReale);		//Numero caratteri
	StampaStringa(s, dimReale);
	printf("%d\n", NumeroParole(s, dimReale));
	ReverseStringa(s, dimReale);
	ToMaiusc(s, dimReale);
	StampaStringa(s, dimReale);
	
	return 0;
}

void ToMaiusc(char stringa[], int dimStringa) {
	char* p;
	
	for(p = stringa; p < stringa + dimStringa; p++, *p = toupper(*p));
	
	return;
}



void ReverseStringa(const char stringa[], int dimStringa) {
	const char* p;
	
	for(p = stringa + dimStringa - 1; stringa < p; p--) {
		printf("%c", *p);
	} 
	
	printf("\n");
	return;
}

int NumeroParole(const char stringa[], int dimStringa) {
	const char* p;
	int nParole = 0;
	
	for(p = stringa; *p != '\n'; p++) {
		if(*p == ' ' || *p == '.' || *p == '!' || *p == '?' || *(p + 1) == '\n') {
			nParole++;
		}
	}
	
	return nParole;
}





void StampaStringa(char const stringa[], int dimStringa) {
	const char* p;
	
	for(p = stringa; p < stringa + dimStringa; p++) {
		printf("%c", *p);
	}
	
	printf("\n");
	return;
}





int CreateStringa(char stringa[], int dimStringa) {
	char ch;
	int i = 0;
	
	while((ch = getchar()) != '\n' && i < dimStringa) {
		*(stringa + i) = ch;
		i++;		
	}
	
	*(stringa + i + 1) = '\n';
	
	return i;

}
