#include<stdio.h>
#define SIZE 20

int main() {
	char cognome[SIZE], n, tmp; 																	//Cognome, carattere nome;
	int i = 1; 																										//Flag per controllo del primo carattere
	
	printf("Inseire nome e cognome:\n");
	n = getchar();																								//Lettura iniaziale nome
	while(getchar() != ' ');																			//Lettura restanti caratteri fino allo spazio
	while((tmp = getchar()) == ' ');															//Lettura caratteri uguali a spazio fino a carattere diverso
	cognome[0] = tmp;																							//Copia del carattere diverso da spazio in cognome
	while((cognome[i] = getchar()) != '\n') {											//Lettura del cognome
		i++;
	}
	
	i = 0;																												//POsizionamento all'inizio del cognome
	while(cognome[i] != '\n') {																		//Stampa cognome
		printf("%c", cognome[i]);
		i++;
	}
	
	printf(", %c.\n", n);																					//Stampa virgola, iniziale e punto
	
	
	return 0;
}
