#include<stdio.h>

void invertiCifre(char* s);

int main(int argc, char* argv[]) {
	 
	invertiCifre(argv[1]);
	printf("%s\n", argv[1]);	

	return 0;
}

void invertiCifre(char* s) {
	char *p, *inizio = NULL, *fine = NULL, tmp;
	
	for (p = s; 1; p++) {
		if (*p >= '0' && *p <= '9') {
			if (inizio == NULL) {
				inizio = p;
			}
		} else if(inizio != NULL) {
			fine = p - 1;
			while(inizio < fine) {
				tmp = *inizio;	
				*inizio = *fine;
				*fine = tmp;
				inizio++;
				fine--;
			}
			inizio = fine = NULL;
		}
		if (*p == '\0') {
			break;
		}
	}
}
