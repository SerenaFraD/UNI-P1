#include<stdio.h>

int main() {
	int nchar = 0, nspace = 0, nv = 0; //Numero caratteri, numero spazi, numero vocali;
	char c;
	
	printf("Inserire una stringa ");
	c = getchar();
	while(c != '\n') {
		nchar++;
		if((c >= 'A') && (c <= 'Z')) {
			c = c - 'A' + 'a';
		}
		if((c == 97) || (c == 'e')|| (c == 'i')|| (c == 'o')|| (c == 'u')) {
			nv++;
		} else if(c == 32){
			nspace++;
		}
		c = getchar();
	}
	
	printf("Il numero totale dei caratteri e' %d\n", nchar);
	printf("Il numero di caratteri esclusi spazi e' %d\n", nchar - nspace);
	printf("Il numero di vocali e ' %d\n", nv);
	
	return 0;

}
