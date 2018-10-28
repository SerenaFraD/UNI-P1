#include<stdio.h>
#include<ctype.h>

int main() {
	char c, con = '\n'; //Carattere del numero di telefono, carattere di controllo per la continuazione;
	int i = 0; //Indice del numero di telefono controlla il numero di cifre;
	
	while(con = '\n') {
		printf("Inserire i caratteri del numero: ");
		while((c = getchar()) != '\n' && i < 5) {
			switch(toupper(c)) {
				case 'A': case 'B': case 'C':
					printf("2");
					i++;
					break;
				case 'D': case 'E': case 'F':
					printf("3");
					i++;
					break;
				case 'G': case 'H': case 'I':
					printf("4");
					i++;
					break; 
				case 'J': case 'K': case 'L':
					printf("5");
					i++;
					break;
				case 'M': case 'N': case 'O':
					printf("6");
					i++;
					break;
				case 'P': case 'Q': case 'R': case 'S':
					printf("7");
					i++;
					break;
				case 'T': case 'U': case 'V':
					printf("8");
					i++;
					break;
				case 'W': case 'X': case 'Y': case 'Z':
					printf("9");
					i++;
					break;
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
					printf("%c", c);
					i++;
					break;
				default:
					printf("\nInput errato\n");
					break;
			}
		}
		printf("\nTradurre un altro numero? Premere invio per continuare.");
		con = getchar();	
		if(con != '\n') {
			printf("Esecuzione terminata.\n");
			return 0;
		} else {
			i = 0;
		}		
	}
	return 0;
}
 	

