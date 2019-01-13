/****************************************************/
/*Prende in input da linea di comando due stringhe,	*/
/*controlla che che le due strignhe siano uguali	*/
/*per una sottostringa e fa il reverse della		*/
/*sottostringa della prima stringa inserita			*/
/****************************************************/
#include<stdio.h>

void subreverse (char *stringa1, char *stringa2);

int main(int argc, char *argv[]) {

	if(argc != 3) {
		fprintf(stderr, "Inserimento sbagliato di parametri.\n");
		printf("Uso: ./subrev <str 1> <str2>\n");
		return 1;	
	}
	
	subreverse(argv[1], argv[2]);
	printf("%s\n", argv[1]);
	
	return 0;
}

void subreverse (char *stringa1, char *stringa2) {
	char *s1 = stringa1, *s2 = stringa2, *fine, tmp;
	int i = 0;
	
	while(*s1 == *s2 && (*s1 != '\0' && *s2 != '\0')){
		printf("%c %c\n", *s1, *s2);
		s1++;
		s2++;
	}
	
	if(*s1 != *s2 || (*s1 == '\0' && *s2 == '\0')){
		fine = --s1;
		s1 = stringa1;
		while(s1 < fine) {
			tmp = *s1;
			*s1 = *fine;
			*fine = tmp;	
			s1++;
			fine--;
		}
	}	
}