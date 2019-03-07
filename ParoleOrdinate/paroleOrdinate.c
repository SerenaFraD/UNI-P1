#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define NPUNTATORI 5
#define NCHAR 10

void getParole(char *stringa[], int nChar) {
	char **p = stringa;
	int i = 0, dim;
	
	printf("%c", *(*p + 1));
	
}

int main() {
	char *parole[4] = {"casa", "mare", "giochi"};

	getParole(parole, NCHAR);
	

}


