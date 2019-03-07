#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	int x1, x2, x3, x4, x5;
	char line[256];
	FILE *fp;
	
	if(argc != 2) {
			exit(EXIT_FAILURE);	
	}
	
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("Errore: file inesistente.\n");
		exit(EXIT_FAILURE);
	}
	
	while(fgets(line, sizeof(line), fp)){
		sscanf(line, "%d", &x1);
		printf("%d\n", x1);
	}
	
}


