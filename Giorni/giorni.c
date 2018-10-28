/*Scrivere un programma che inserendo in input un data dd/mm e restituisca i giorni che sono trascorsi dall'inizio dell'anno*/

#include<stdio.h>

int main() {
	
	int d, m, y i = 1, day = 0;
	
	printf("Inserire una data in formato dd/mm/yyyy ");
	scanf("%2d/%2d", &d, &m);
	
	if((d > 0) && (d < 31)) && ((m > 0) && (m < 12)) {
		while(i <= m-1) {
			switch(i) {
			case 1: case 3: case 5: case 7: case 8: 
			case 10: day += 31;
							break;
			case 2: if(y % 4 == 0) || (y % 100 == 0){
								day += 29;
							} else {
								day += 28;
							}
							break;
			case 4: case 6: case 9:
			case 11: day += 30;
							break;	
			}
			i++;
		}
	
		day += d;
	
		printf("I giorni che sono passati sono %d\n", day);
	} else {
		printf("Data errata. Formato non esistente!");
	}						
	return 0;
}
	

