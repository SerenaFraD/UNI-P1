#include<stdio.h>
#define SIZE 20

int main() {
	char s[SIZE], tmp;
	int i = 0, j;
	
	printf("Inserisci un numero da controllare.\n");
	
	while((tmp = getchar()) != '\n' && i < SIZE) {
		if(tmp != ' ') {
			s[i] = tmp;
			i++;		
		}
	}
	
	i = 0;
	j = i + 1;
	while(i < SIZE) {
		while(j < SIZE) {
			if(s[i] == s[j]) {
				break;
			}
			j++;
		}
		i++;
	}
	
	if(s[i] == s[j]) {
		printf("Ci sono cifre che si ripetono.\n");
	} else {
		printf("Non ci sono cifre che si ripetono.\n");
	}
	
	
}
