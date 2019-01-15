#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define NEL 100
#define NCHAR 20
#define NOME_FILE "montagne.txt"

void montagne(int nPar, char *parametri[]);

int main(int argc, char *argv[]) {
	
	if(argc < 2 || argc > 3) {
		fprintf(stderr, "Passaggio errato dei parametri.\n");
		printf("Uso: ./mont <'Nome nazione'>\n");
		printf("Uso: ./mont <'Nome montagna'>\n");
		printf("Uso: ./mon <prima altezza> <seconda altezza>\n");
		exit(EXIT_FAILURE);
	}
	
	montagne(argc, argv);
	
	return 0;
}

void montagne(int nPar, char *parametri[]) {
	char riga[NEL], montagna[NCHAR], altezza[NCHAR], nazione[NCHAR], naz1[NCHAR], naz2[NCHAR];
	int isHeight = 0, isMont = 0, tmp, alt1, alt2;
	FILE *fp;
	
	if((fp = fopen(NOME_FILE, "r")) == NULL) {
		fprintf(stderr, "Errore nell'apertura del file.\n");
		exit(EXIT_FAILURE);
	}
	
	if(isdigit(parametri[1][0])) {
		isHeight = 1;
		
		alt1 = atoi(parametri[1]);
		alt2 = atoi(parametri[2]);
		
		if(alt1 > alt2) {
			tmp = alt1;
			alt1 = alt2;
			alt2 = tmp;
		}
	}
	
	while(fgets(riga, sizeof(riga), fp)) {
		sscanf(riga, "%*d %[^:] : %[^m] m %[^\n]", montagna, altezza, nazione);
		sscanf(nazione, "%[^,], %[^\n]", naz1, naz2);
		
		if(strncmp(montagna, parametri[1], strlen(parametri[1])) == 0){
			isMont = 1;
			break;
		} else if(isHeight) {
			if(alt1 <= atoi(altezza) && alt2 >= atoi(altezza)) {
				printf("%s\n", montagna);
			}
		} else if((strncmp(naz1, parametri[1], strlen(parametri[1])) == 0) || (strncmp(naz2, parametri[1], strlen(parametri[1])) == 0)) {
			printf("%s\n", montagna);
		}
		*naz2 = '\0';
	}
	
	if(isMont) {
		printf("%s m\n", altezza);
	}
}
