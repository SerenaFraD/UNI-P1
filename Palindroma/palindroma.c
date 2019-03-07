#include<stdio.h>
#include<ctype.h>
#define N 50
//Fare palindromo bidimensionale*/

int palindroma(const char array[], int n);
void creaFrase(char array[], int n);



int main() {
	 char f[N];
	 
	 printf("Inserire una frase.\n");
	 creaFrase(f, N);
	 printf(palindroma(f, N)? "E' palindroma.\n" : "Non è palindroma.\n");
	 
	 return 0;
}

void creaFrase(char array[], int dimArray) {
	char ch = getchar();
	char* p = array;
	
	while(ch != '\n' && p < array + dimArray - 1) {
		if(isalpha(ch)) {
			*p = ch;
		}
		p++;
	}
	
	p = array + dimArray;
	*p = '\n';
}


int palindroma(const char array[], int dimArray) {
	const char* inizio = array, *fine = array + dimArray;
	
	while(inizio != fine && *inizio == *fine) {
		inizio++;
		fine--;
	}
	
	return (inizio == fine);
}











