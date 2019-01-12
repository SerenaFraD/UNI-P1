#include<stdio.h>

void inverti_cifre(char* frase);

int main(int argc, char* argv[]) {

	if (argc != 2){
		fprintf(stderr, "Uso: %s <stringa>\n", argv[0]);
		return 1;
	}
	
	inverti_cifre(argv[1]);
	printf("%s\n", argv[1]);
	
	return 0;
}

void inverti_cifre(char* frase) {
	int first = 0;	//se asserito indica che è stato trovata la prima cifra
	char *p = frase, *pl = NULL, *ul = NULL, tmp; //puntatore, punt a prima lettera, punt. aultima lettera, variabile di appoggio

	while(*p != '\0') {										//Scorro l'intera stringa
		if(*p >= '0' && *p <= '9') {					//ciclo per identificare se abbiamo una cifra									
			if(!first) {												//controllo che quella sia una cifra
				first = 1;												//indico che è stata trovata la cifra e assegnazione a pl
				pl = p; 
			}
			while(*p != '\0' && (*p >= '0' && *p <= '9')){		//ciclo per assegnazione dell'ultima cifra
				ul = p;
				p++;
			}
			while(pl < ul) {											//ciclo per lo scambio delle cifre
				tmp = *pl;
				*pl = *ul;
				*ul = tmp;
				pl++;
				ul--;
			}
			first = 0;														//azzeramento del flag trovato per la prossima seq di cifre
			pl = ul = NULL;												//annullamento dei punt alle cifre
		}	
		p++;																	//puntamento al prossimo carattere
	}
}

















