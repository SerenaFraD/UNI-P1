/******************************************************************/
/*Calcolatrice semplificata con associatività da sinistra a destra*/
/*con input da linea di comando di una stringa di decimali				*/
/******************************************************************/

#include<stdio.h>

double calcola(char *s);
double calcola_double (char *s);

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Errato numero di elementi passati.\n");
		printf("Uso: ./intexp <epresessione di interi>\n");
		return 0;
	}
	
	printf("%.2f\n", calcola_double(argv[1]));
	
	return 0;
}

/**********************************************************/
/*Nome: converti																					*/
/*Parametri: *s --> puntatore alla stringa passata dal 		*/
/*main;																										*/
/*Uso: Usata per convertire un numero decimale dal segno	*/
/*fino al successivo;																			*/
/*Return: Restituisce il numero decimale converito da	 		*/
/*stringa;																								*/
/**********************************************************/

double converti(char *s) {
	char *p = s;
	double n = 0, pdec = 0, div = 10.0;
	int neg = 0, dec = 0;

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
		
		if(*p == '.') {
			dec = 1;
			p++;
		}
		
		if(dec) {
			pdec = pdec + ((*p - 48) / div);
			div = div * 10.0;
		} else if(*p != '.') {
			n = (*p - 48) + n * 10.0;
		}
		
		p++;	
	}
		n = n + pdec;
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

double calcola_double (char *s) {
	char *p = s;
	double somma = 0;
	
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
