#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NCHAR 100
#define NNAME	30
#define FILE_NAME "albo.txt"
#define DIM 5

void mondiali(char *parametri[], int nPar);

int main(int argc, char *argv[]) {

	if(argc < 2 || argc > 3) {
		fprintf(stderr, "Passaggio errato dei parametri.\n");
		printf("Uso: ./mon <'Nome nazione'>\n");
		printf("Uso: ./mon <max> {<oro>, <argento>, <bronzo>, <totale>}\n");
		exit(EXIT_FAILURE);
	}
	
	mondiali(argv, argc);
	
	return 0;
}

void mondiali(char *parametri[], int nPar) {
	char riga[NCHAR], nation[NNAME], maxNat[NNAME], oro[DIM], argento[DIM], bronzo[DIM], totale[DIM];
	FILE *fp;
	int somma = 0, tmp, max = -1000, pos = 0;
	short int isMax = 0, isNation = 0, isGold = 0, isSilver = 0, isBronze = 0, isTotal = 0;

	if((fp = fopen(FILE_NAME, "r")) == NULL) {
		fprintf(stderr, "Errore nell'apertura del file.\n");
		exit(EXIT_FAILURE);
	}
	
	if(strncmp(parametri[1], "max", 3) == 0) {
		isMax = 1;
		
		if(strcmp(parametri[2], "oro") == 0) {
			isGold = 1;
		} else if(strcmp(parametri[2], "argento") == 0) {
			isSilver = 1;
		} else if(strcmp(parametri[2], "bronzo") == 0) {
			isBronze = 1;
		} else if(strcmp(parametri[2], "totale") == 0) {
			isTotal = 1;
		}
	}
	
	while(fgets(riga, sizeof(riga), fp)) {
		sscanf(riga, "%[^0123456789-] %s %s %s %s", nation, oro, argento, bronzo, totale);
		
		if(isMax) {
			if(isGold){
				tmp = atoi(oro);
			} else if(isSilver) {
				tmp = atoi(argento);
			} else if(isBronze) {
				tmp = atoi(bronzo);
			} else if(isTotal) {
				tmp = atoi(oro) + atoi(argento) + atoi(bronzo) ;
			}
			if(max < tmp) {
				max = tmp;
				strcpy(maxNat, nation);
			}
		} else {
			if(strncmp(parametri[1], nation, strlen(parametri[1])) == 0) {
				isNation = 1;
				break;
			}		
		}
	}
	
	if(isMax) {
		printf("%s %d\n", maxNat, max);
	} else if(isNation) {
		printf("%s %s %s %s %s %d\n", nation, ((strncmp(oro, "-", 2) == 0)? "0" : oro), argento, bronzo, totale, (atoi(oro) + atoi(argento) + atoi(bronzo)));
	} else {
		printf("Errore nell'immissione dei dati.\n");
	}
}
