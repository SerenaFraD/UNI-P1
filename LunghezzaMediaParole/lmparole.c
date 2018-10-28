#include<stdio.h>
#include<ctype.h>

int main() {
	int nw = 0, nl = 0;//Numero parole, numero lettere;
	float media = 0; 
	char c, con = '\n'; //Carattere inserito, carattere di controllo di continuazione di esecuzione;
	
	while(con == '\n') {
		printf("Inserire una frase da controllare. ");
		while((c = toupper(getchar())) != '\n') {
			if(c >= 'A' && c <= 'Z') {
				nl++;
			} else if(c == ' ')  {
				nw++;
			}	
		}
		
		media = (float) nl / (nw + 1);
		printf("Il numero di lettere medio è %.1f.\n", media);
		
		printf("Continuare l'esecuzione. Premere Invio per continuare.");
		con = getchar();
		if(con != '\n') {
			printf("\n Esecuzione terninata.\n");		
		}
	}
}	
	
