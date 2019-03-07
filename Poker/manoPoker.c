#include<stdio.h>
#include<stdlib.h>
#define SEMI 4			//Numero tipi di carte;
#define CAR 12 			//Numero di carte usate;
#define TCAR 48			//Totale numero di carte;
#define CARM 5			//Totale carte per mano;
#define STOP (int) 48 % 5

int main() {
	const char carte[12] = {'a', '2', '3', '4', '5', '6', '7', '8', '9', 'j','k', 'q'}; //Asso, ..., 10, 11, 12;
	const char semi[4] = {'h', 's', 'd', 'c'}; 								//Cuori, spade, quadri, picche;
	
	short int usate [CAR][SEMI] = {0};
	int i, s, c, ncarte = TCAR;
	char con = '\n';
	
	while(con == '\n' && ncarte > STOP) {
		i = 0;
		while(i < CARM) {
			s =  rand() % SEMI;
			c =  rand() % CAR;
			
			if(!usate[c][s]) {
				usate[c][s] = 1;
				printf("%c %c\t", carte[c], semi[s]);
				ncarte--;
				i++;
			}
		}
		
		if(ncarte <= STOP) {
			printf("\nCarte terminate.\n");
			break;
		} else {
			printf("\nEstrarre altre 5 carte? Premere Invio per continuare.");
			if((con = getchar()) != '\n') {
				printf("\nEsecuzione terniminata.\n");
			}
		}
	}




	return 0;
}

