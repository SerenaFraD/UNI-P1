#include<stdio.h>

int main() {
	char car, cf; //carattre da controllare, carattere della frase;
	int occ = 0; //occorrenza
	
	printf("Inserire un carattere da controllare. ");
	scanf("%c", &car);
	getchar();
	printf("Inserire una stringa ");
	cf = getchar();
	while(cf != '\n') {
		if(cf == car) {
			occ++;
		}
		cf = getchar();
	}
	
	printf("\nIl carattere %c e' presente n° %d volte\n", car, occ);
	return 0;
}
