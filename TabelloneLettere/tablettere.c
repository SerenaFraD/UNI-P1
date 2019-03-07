#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 4
#define NLETTERE 26


void createTabellone(char tabella[][M], int row, int colum);
void occorrenzeLett(char tabella[][M], int row, int colum, int occorrenze[], int numeroLettere);
void stampa(char tabella[][M], int row, int colum);
int randomLettere();
int ricercaLettera(char tabella[][M], int row, int colum, int lettera, int letterai, int letteraj);
void azzeraArray(int occorrenze[], int numeroLettere);
void stampaOccorrenze(int occorrenze[], int numeroLettere);

int main() {
	char tab[N][M];
	int occ[NLETTERE];
	
	createTabellone(tab, N, M);
	stampa(tab, N, M);
	azzeraArray(occ, NLETTERE);
	occorrenzeLett(tab, N, M, occ, NLETTERE);

	return 0;
}

/************************************************************
* Inseririsce nella matrice row x colum le lettere generate	*
* casualmente.																							*
* tabella[][] --> matrice da passare;												*
* row  --> numero righe;																		*
* colum  --> numero colonne;																*
************************************************************/
void createTabellone(char tabella[][M], int row, int colum) {
	int i, j;
	
	for(i = 0; i < row; i++) {
		for(j = 0; j < colum; j++) {
			tabella[i][j] = randomLettere();
		}
	}
	
	return;
}

int randomLettere() {
	return (rand() % NLETTERE) + 'a';
}

void stampa(char tabella[][M], int row, int colum) {
	int i, j;
	
	printf("\n");
	
	for(i = 0; i < row; i++) {
		for(j = 0; j < colum; j++) {
			printf("%c", tabella[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	return;
}

void azzeraArray(int occorrenze[], int numeroLettere) {
	
	int i;
	
	for(i = 0; i < numeroLettere; i++) {
		occorrenze[i] = 0; 
	}
	
	return;
}

void occorrenzeLett(char tabella[][M], int row, int colum, int occorrenze[], int numeroLettere) {
	
	int i, j, li, lj;
	char lettera;
	
	for(li = 0; li < row; li++) {
		for(lj = 0; lj < colum; lj++) {
			lettera = tabella[li][lj];
			if(ricercaLettera(tabella, row, colum, lettera, li, lj)) {
				occorrenze[lettera - 'a']++;
			}			 
			
		}
	}
	
	
	stampaOccorrenze(occorrenze, numeroLettere);
	return;
}
	
void stampaOccorrenze(int occorrenze[], int numeroLettere) {
	int i;
	
	for(i = 0; i < numeroLettere; i++) {
		printf("%c  =  %d\n", i + 'a', occorrenze[i]);
	}
	
	return;
}

int ricercaLettera(char tabella[][M], int row, int colum, int lettera, int letterai, int letteraj) {
	int i, j;
	for(i = letterai; i < row; i++) {
		for(j = letteraj + 1; lettera != tabella[i][j] && j < colum; j++);
	}
	
	return lettera != tabella[i][j];
}	
	
	










