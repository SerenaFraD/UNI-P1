#include<stdio.h>
#define N (int) 12

void splitDate(int giornoAnno, int dayOfMonth[], int dimArray, int* day, int* month, int* year);

int main() {
	int day[N] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int nGiorno, giorno, mese, anno;
	
	do {
		printf("Inserire un numero tra 1 e 365.  --->   ");
		scanf("%d", &nGiorno);
	} while(nGiorno < 0 && nGiorno > 366);
	
	printf("Inserire anno. --->  ");
	scanf("%d", &anno);
	
	splitDate(nGiorno, day, N, &giorno, &mese, &anno);
	printf("E' il %d/%d/%d\n", giorno, mese, anno);
	
	return 0;
}

void splitDate(int giornoAnno, int dayOfMonth[], int dimArray, int* day, int* month, int* year) {
	int i, bis = 0;
	
	for(i = 0; i < dimArray; i++) {
		if((i == 0) && ((*year % 4 == 0) || (*year % 400 == 0))) {
			giornoAnno = giornoAnno - dayOfMonth[i] - 1;
			bis = 1;
			printf("Sono bisestile\n");
		}
		giornoAnno -= dayOfMonth[i];
		if(giornoAnno <= 0) {
			*day = giornoAnno + dayOfMonth[i];
			if(bis == 1) {
				*day += 1;
			}
			*month = i + 1;
			break;
		}
	}

	return;
}
