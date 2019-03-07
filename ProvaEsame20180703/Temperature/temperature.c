#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

#define FILES "temperature.txt"
#define NCHAR 100

void meteo(char *lista[], int nArgo);


int main(int argc, char *argv[]) {

	if(argc == 1) {
		printf("Usage: ./temperatura <nomecitta'>\n");
		printf("Usage: ./temperatura <temp1> <tmp2> <min/max>\n");
		printf("Usage: ./temperatura <massima/minima>\n");
		fprintf(stderr, "Input errato.\n");
		exit(EXIT_FAILURE);
	} else {
		meteo(argv, argc);
	}
 	
	return 0;
}

void meteo(char *argv[], int nArgo) {
	FILE *fp = fopen(FILES, "r");
	char line[NCHAR], citta[20], pioggia[4], cittaAbs[15];
	int min, max, minAbs = 100, maxAbs = -100;
	
	if(fp == NULL) {
		fprintf(stderr, "Problema con il file.\n");
		exit(EXIT_FAILURE);
	}
	
	while(fgets(line, sizeof(line), fp)) {
		sscanf(line, "%[^0123456789] %d/%d %[^\n]", citta, &min, &max, pioggia);
		
		
		if(nArgo == 2 && strncmp(argv[1], citta, strlen(argv[1])) == 0) {
			printf("%s minima: %d, massima: %d, piggia: %ld%%.\n", citta, min, max, strlen(pioggia) * 25);
		} else if(nArgo == 4) {
			if(strncmp("min", argv[3], 3) == 0) {
				if(min > atoi(argv[1]) && min < atoi(argv[2])){
					printf("%s\n", citta);
				}
			} else if(strncmp("max", argv[3], 3) == 0){
				if(max > atoi(argv[1]) && max < atoi(argv[2])){
					printf("%s\n", citta);
				}
			}
		} else  if(nArgo == 2){
			if(strncmp("minimo", argv[1], 6) == 0) {
				if(min < minAbs) {
					minAbs = min;
					strncpy(cittaAbs, citta, strlen(citta));
				}
			} else if(strncmp("massimo", argv[1], 7) == 0) {
				if(maxAbs < max) {
					maxAbs = max;
					strncpy(cittaAbs, citta, strlen(citta));
					printf("%s\n", cittaAbs);	
				}
			}
		}
	}
	if(nArgo == 2) {
			printf("Ultimo: %d  %d\n", max, maxAbs);
			printf("%s\n", cittaAbs);				
	}
	
	return;
}











