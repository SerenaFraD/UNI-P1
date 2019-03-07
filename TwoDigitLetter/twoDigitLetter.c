#include<stdio.h>

int inputNumero(void);
void cifreLettere(int);

char *decine[] = {"Venti", "Trenta", "Quaranta", "Cinquanta", "Sessanta", "Settanta", "Ottanta", "Novanta"};
char *special[] = {"", "Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Undici", "Dodici", "Tredici", "Quattordici", "Quindici", "Sedici", "Diciasette", "Diciotto", "Diciannove"};

int main() {

	cifreLettere(inputNumero());
	
	return 0;
}





int inputNumero(void) {
	int n;
	
		printf("Inserisci un numero di due cifre.\n");
		scanf("%2d", &n);
	
	return n;
}


void cifreLettere(int numero) {

	if(numero > 19 && numero < 100) {
		printf("%s ", decine[(numero / 10) - 2]);
		numero = numero % 10;
	}
	printf("%s", special[numero]);

	printf("\n");
	return;
}
