#include<stdio.h>
#include<ctype.h>

int main() {
	char lettera, con = '\n'; //dichiarazione lettera della parola inserita;
	short int pnt = 0; //dichiarazione punteggio
	
	while(con = '\n') {
		printf("Inserire una parola. "); 
		while((lettera = getchar()) != '\n') {
			if((lettera < 'a' && lettera > 'z') && (lettera >= 'A' && lettera <= 'Z')) {
				 	break;
			}
			switch(toupper(lettera)) {
				case 'A': case 'E': case 'I': case 'L': case 'N': case 'R': case 'S': case 'T': case 'U':
					pnt += 1;
					break;	 		
		 		case 'D': case 'G':
		 			pnt += 2;
		 			break;
		 		case 'B': case 'C': case 'M': case 'P':
		 			pnt += 3;
		 			break;
		 		case 'F': case 'H': case 'V': case 'W': case 'Y':
		 			pnt += 4;
		 			break;
		 		case 'K':
		 			pnt += 5;
		 			break;
		 		case 'J': case 'X':
		 			pnt += 8;
		 			break;
		 		case 'Q': case 'Z':
		 			pnt += 10;
		 			break;
			}
		}
		 
		printf("\nIl punteggio e' %d\n", pnt);
		printf("Controllare un'altra parola? Premere Invio per continuare.");
		con = getchar();
		if(con != '\n') {
			printf("Esecuzione terminata.\n");
			break;
		}
	}
	return 0;

}
