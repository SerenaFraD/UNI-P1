#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NEL 100 //Numero caratteri della riga
#define NCHAR 20 //	Numero di caratteri delle singole parti
#define NAME_FILE	"brani.txt" //Nome file

void album(char *parametri[]);

int main(int argc, char *argv[]) {
	
	if(argc != 2) {
		fprintf(stderr, "Errore nel passaggio dei parametri.\n");
		printf("Uso: ./htd <'titolo'>\n");
		printf("Uso: ./htd <'m:s'>\n");
		exit(EXIT_FAILURE);
	}
	
	album(argv);

	return 0;
}

void album(char *parametri[]) {
	FILE *fp;
	char riga[NEL], titolo[NCHAR];
	int min, sec, totmin = 0, totsec = 0, isTime = 0, parMin, parSec, inizio;

	if((fp = fopen(NAME_FILE, "r")) == NULL) {
		fprintf(stderr, "Errore nell'apertura del file.\n");
		exit(EXIT_FAILURE);
	}
	
	if(isdigit(parametri[1][0])) {
		isTime = 1;
		sscanf(parametri[1], "%d:%d", &parMin, &parSec);
	}
	
	while(fgets(riga, sizeof(riga), fp)) {
		sscanf(riga, "%*[^[] [%[^]]] %*[^0123456789]%d:%d", titolo, &min, &sec);
		
		if(strncmp(titolo, parametri[1], strlen(parametri[1])) == 0) {
			printf("%s %d:%d\n", titolo, totmin, totsec);
		}
		
		if(isTime) {
			if((totmin <= parMin) && (parMin < (totmin + min))) {
								
				printf("%s ", titolo);
				
				inizio = ((totmin * 60) + totsec) - ((parMin * 60) + parSec);	//Errore
				printf("%d:%d\n", inizio / 60, inizio % 60);					//Continuazione errore
				
			}
			break;
		}

		totsec += sec;
		totmin += min;

		if(totsec > 59) {
			totsec = totsec - 60;
			totmin++;
		}

		min = sec = 0;
	}
}
