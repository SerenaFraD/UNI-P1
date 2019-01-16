#include<stdio.h>
#include<stdlib.h>
#define NCHAR 30
int hextodec(char *s, char *t, int limit);
int itoa(int numero, char *s);

int main(int argc, char *argv[]) {
	char risultato[NCHAR];
	int limite = argv[2][0] - 48;

	if(argc != 3) {
		fprintf(stderr, "Errore nel passaggio dei parametri.\n");
		printf("Uso: ./htd <esadecimale> <limite>\n");
		exit(EXIT_FAILURE);
	}

	
	if(hextodec(argv[1], risultato, limite)) {
		printf("%s\n", risultato);
	} else {
		printf("Numero non rappresentabile in %d cifre.\n", limite);
	}

	return 0;
}

int itoa(int numero, char *t) {
	char *res = t, *fine, tmp;
	int ncifre = 0;

	while(numero > 0) {
		*res = (numero % 10) + 48;
		numero /= 10;
		res++;
	}
	
	ncifre = res - t;

	fine = res - 1;
	res = t;

	while(res < fine) {
		tmp = *res;
		*res++ = *fine;
		*fine-- = tmp;
	}

	return ncifre;
}

int hextodec(char *s, char *t, int limit) {
	char *p = s, *res = t, *fine, tmp;
	int num = 0, pot = 1, esp = 0, ncifre = 0;
	
	while(*p != '\0') {
		pot = pot * 16;
		esp++;
		p++;
	}
	pot /= 16;	
	p = s;

	while(*p != '\0') {
		
		if(*p == 'f') {
			num = num + 15 * pot; 
		} else if(*p == 'e') {
			num = num + 14 * pot; 
		} else if(*p == 'd') {
			num = num + 13 * pot; 
		} else if(*p == 'c') {
			num = num + 12 * pot; 
		} else if(*p == 'b') {
			num = num + 11 * pot; 
		} else if(*p == 'a') {
			num = num + 10 * pot; 
		} else {
			num = num + ((*p - 48) * pot);
		}

		pot = pot / 16;		
		p++;
	}

	return (limit >= itoa(num, t));

}
