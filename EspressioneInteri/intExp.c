/******************************************************************/
/*Calcolatrice semplificata con associatività da sinistra a destra*/
/*con input da linea di comando di una stringa di caratteri interi*/
/******************************************************************/

#include<stdio.h>

int calcola(char *s);
int converti(char *s);

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Errato numero di elementi passati.\n");
		printf("Uso: ./intexp <epresessione di interi>\n");
		return 0;
	}
	
	printf("%d\n", calcola(argv[1]));
	
	return 0;
}

/**********************************************************/
/*Nome: converti																					*/
/*Parametri: *s --> puntatore alla stringa passata dal 		*/
/*main;																										*/
/*Uso: Usata per convertire un numero intero dal segno 		*/
/*fino al successivo;																			*/
/*Return: Restituisce il numero intero converito da		 		*/
/*stringa;																								*/
/**********************************************************/

int converti(char *s) {
	char *p = s;
	int n = 0, neg = 0;

	if(*p == '*' || *p == '/') {
			p++;
	}
	if(*p == '-') {
		p++;	
		neg = 1;
	} else if(*p == '+') {
		p++;
	}
	
	while((*p != '-' && *p != '+' && *p != '*' && *p != '/') && *p != '\0') {
		n = (*p - 48) + n * 10;
		p++;	
	}
	
	return (neg) ? -n : n;
}

/**********************************************************/
/*Nome: calcola																						*/
/*Parametri: *s --> puntatore alla stringa passata da 		*/
/*converti;																								*/
/*Uso: Usata scandire la chiamata di converti ogni volta 	*/
/*che trova un segno;																			*/
/*Return: Restituisce il risultato dell'espressione;			*/
/**********************************************************/

int calcola(char *s) {
	char *p = s;
	int somma = 0, n;
	
	while(*p != '\0') {
		if(*p == '+' || *p == '-') {
			somma += converti(p);
		} else if(*p == '*') {
			somma *= converti(p);
			p++;
		} else if(*p == '/') {
			somma /= converti(p);
			p++;
		}
		p++;
	}

	return somma;
}
