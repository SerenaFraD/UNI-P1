#include<stdio.h>

int main() {
	char con = '\n'; //Carattere di controllo per continuare a visualizzare altre 24 quadrati;
	int i = 1, n = 24; //Indice dei quadrati, numero di quarati da visualizzare;
	
	while(con = '\n') {
		 for(; i <= n; i++) {
		 	printf("%d\n", i * i);
		 }	
		printf("Continuare la visulaizzazione? Premere Enter ");
		con = getchar();
		if(con != '\n') {
			printf("Errore fine programma");
			return 0;
		} else {
			i = n + 1;
			n += 24;
		}
	}
	
	return 0;
}
