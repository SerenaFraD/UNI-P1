#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NCHAR 100
#define FILES "albo_piloti.txt"

void alboPiloti(int, char *[]);

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Errore nel passagio dei parametri.\n");
		exit(EXIT_FAILURE);
	}

	alboPiloti(argc, argv);
}

void alboPiloti(int argc, char *argv[]) {
	char riga[NCHAR], scuderia[4], nome[20], vincite[50];
	FILE *fp;
	int somCamp = 0, vinti = 0, arg1 = 0;
	
	if((fp = fopen(FILES, "r")) == NULL) {
		fprintf(stderr, "Errore nell'apertura del file.\n");
		exit(EXIT_FAILURE);	
	}
	
	while(fgets(riga, sizeof(riga), fp)) {
		sscanf(riga, "%3s %[^0123456789] %[^\n]", scuderia, nome, vincite);
		
		if(strncmp(scuderia, argv[1], 3) == 0) {
			arg1 = 1;
			vinti = (strlen(vincite) - (strlen(vincite) % 4)) / 4;
			somCamp = somCamp + vinti;
			printf("%s %d\n", nome, vinti);
			
		}
	}
	
	if(arg1) {
		printf("%d\n", somCamp);
	}
	

}






















