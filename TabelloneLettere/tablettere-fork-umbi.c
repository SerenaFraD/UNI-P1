#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
#define M 4
#define NLETTERE 26

void createTabellone(char tabella[][M], int row, int colum);
void occorrenzeLett(char tabella[][M], int row, int colum, int occorrenze[], int numeroLettere);
void stampa(char tabella[][M], int row, int colum);
int randomLettere();
int ricercaLettera(char tabella[][M], int row, int colum, int lettera, int ox, int oy);
void azzeraArray(int occorrenze[], int numeroLettere);
void stampaOccorrenze(int occorrenze[], int numeroLettere);

int main() {
	char tab[N][M];
	int occ[NLETTERE];
	
	srand(time(0));
	
	createTabellone(tab, N, M);
	stampa(tab, N, M);
	azzeraArray(occ, NLETTERE);
	occorrenzeLett(tab, N, M, occ, NLETTERE);
	stampaOccorrenze(occ, NLETTERE);
	
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
	
	int x, y;
	char lettera;
	for(y = 0; y < row; y++) {
		for(x = 0; x < colum; x++) {
			lettera = tabella[y][x];
			if (occorrenze[lettera-'a'] == 0) {
				occorrenze[lettera-'a'] = 1 + ricercaLettera(tabella, row, colum, lettera, x, y);
			}
		}
	}
	
	return;
}
	
void stampaOccorrenze(int occorrenze[], int numeroLettere) {
	int i;
	
	for(i = 0; i < numeroLettere; i++) {
		printf("| %c %d ", i + 'a', occorrenze[i]);
		if (i % 13 == 12) {
			printf("|\n");
		}
	}
	
	return;
}

int ricercaLettera(char tabella[][M], int row, int colum, int lettera, int ox, int oy) {
	int y, x = ox + 1;
	int count = 0;
	
	for(y = oy; y < row; y++) {
		for(; x < colum; x++) {
			if (tabella[y][x] == lettera) {
				count++;
			}
		}
		x = 0;
	}
	
	return count;
}

