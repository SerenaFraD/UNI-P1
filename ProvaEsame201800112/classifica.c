#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define CHARIGA 256
#define CHAREL	20
#define NFILE "classifica.txt"

void piloti(int npar, char *par[]);

int main(int argc, char *argv[]) {
	
	if(argc == 1) {
		printf("Passaggio argomenti scorretto;\n");
		printf("Uso: ./<nomefile> <nome> <cognome>.\n");
		printf("Uso: ./<nomefile> <cognome>.\n");
		printf("Uso: ./<nomefile> <cognome> <posizione altro pilota>.\n");
		printf("Uso: ./<nomefile> <scuderia>.\n");
		exit(EXIT_FAILURE);											
	} else {
		piloti(argc, argv);
	}
	
	return 0;
}

void piloti(int npar, char *par[]) {
	FILE *fp;						//Puntatore allo stream aperto su NFILE
	char riga[CHARIGA];	//Riga presa dal file
	char nome[CHAREL], cognome[CHAREL], scuderia[CHAREL];			//Elementi della riga*/
	int vinto, pPunti, posPunti;															//El della riga, mem. dei punti del pilota */
	int flag2 = 0, flag3 = 0, nriga = 1, somScud = 0;					//Punto 2, Punto 3, n riga;
	char pnome[CHAREL], pcognome[CHAREL];
	sscanf(par[1], "%s %s", pnome, pcognome);								//Suddivisione del nome completo in due parti
	printf("%s ", pnome);
	printf("%s\n", pcognome);
	
	
	int uno, due;
	
	if((fp = fopen(NFILE, "r")) == NULL) {										//Test sull'apertura del file che ritorna null
		fprintf(stderr, "Problemi con l'apertura del file");		//Se positivo, stampa a video del messaggio di errore
		exit(EXIT_FAILURE);																			//Uscita forzata dal programma, con specifico error code
	}
	
	
	while(fgets(riga, sizeof(riga), fp)) {										//Ciclo di lettura del file
		sscanf(riga, "%s %s %*3s %[^0123456789] %d", nome, cognome, scuderia, &vinto);	//Suddivisione della riga in sottostringhe
		
		/*uno = strncmp(pnome, nome, strlen(pnome));
		printf("Uno %d\n", uno);
		}*/
		if((strncmp(cognome, pnome, strlen(pnome)) == 0) || (strncmp(nome, pnome, strlen(pnome)) == 0)) {
		
			if(par[2] == NULL){
				printf("%d ", nriga);				
				printf("%d \n", vinto);
				break;
			} else if(isdigit(par[2][0])) {
				flag2 = 1; 
				pPunti = vinto;
			} 
		}
		if(par[2] != NULL && atoi(par[2]) == nriga) {
			posPunti = vinto;
		}
		if(strncmp(par[1], scuderia, strlen(par[1])) == 0) {
			flag3 = 1;
			somScud +=	vinto;
		}
		
		nriga++;
	}

	if(flag3) {
		printf("%d\n", somScud);
	} else if(flag2) {
		printf("%d\n", posPunti - pPunti);
	}
	
	return;
}
