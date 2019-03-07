#include<stdio.h>
#define SIZE 20																													//definizione macro con lunghezza dell'array;
#define	LENGHT ((int) sizeof(s) / sizeof(s[0]))													//defiinizione macro con lunghezza reale dell'array;

int main() {
	unsigned char s[SIZE], tmp, rip[SIZE];																//s -> array contenente il digit, tmp var di controllo char, array 																																						appoggio char che si ripetono
	short int i = 0, j, r = -1, x = 0;																		//indice di s, indice di s, indice lunghezza di rip, indice di 																																						scorrimento di rip	
	
	printf("Inserisci un numero da controllare.\n");
	
	while((tmp = getchar()) != '\n' && i < SIZE) {												//lettura carattere con controllo degli spazi
		if(tmp != ' ') {
			s[i] = tmp;
			i++;																														  //incremento solo se non è spazio
		}
	}
	s[i] = '\n';																													//Aggiunta del carattere di fine stringa
	
	for(i = 0; s[i] != '\n'; i++) {																				//ciclo per identificare il primo elemento da confrontare
		for(j = i + 1; s[j] != '\n'; j++) {																	//ciclo per identificare il secondo elemento da confrontare
			if(s[i] == s[j]) {																								
				x = 0;
				while(x <= r && rip[x] != s[i]) {																//controllo se il carattere non sia già presente nell'array rip
					x++;
				}
				if(x > r) {																											//se l'indice x è maggiore della dimensione r, numero non trovato 																																					aggiunta
					r++;
					rip[r] = s[i];
				}
			}
		}
	}
	
	rip[r + 1] = '\n';																										//Aggiunta del carattere di fine stringa
	
	if(r == -1) {																													//Controllo sull'output: in r c'è qualche elemento?
		printf("Non ci sono cifre che si ripetono.\n");
	} else {
		for(x = 0; rip[x] != '\n'; printf("%c", rip[x]), x++);
		printf("\n");
	}
	
	return 0;
}
