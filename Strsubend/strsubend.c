/****************************************************/
/*Prende in input tre stringhe, s, t e r, e 	    */
/*si comporta come segue:			    */
/*•(a) se la stringa t corrisponde alla parte finale*/
/* di s (come ad esempio giorno in buongiorno) 	    */
/*						    */														*/
/*•(b) le stringhe t e r hanno la stessa lunghezza, */
/*allora la funzione restituisce 1 e sostituisce la */
/*parte finale di s (che corrisponde a t) con la    */
/*stringa r;					    */
/*						    */
/*• se una delle due condizioni (a) o (b) non è     */
/*verificata, la funzione lascia inalterata la 	    */
/*stringa s e restituisce 0.    	            */
/****************************************************/

#include<stdio.h>
#define NEL 15	//Numero caratteri delle stringhe

int strsubend (char *s, char *t, char *r);
int sameLenght(int len1, int len2);
int lenght(char *stringa);
int stringCompare(char *str1, char *str2, int nlett);

int main(void) {
	char str1[NEL], str2[NEL], str3[NEL];
	
	printf("Inserisci la prima stringa --->  ");
	scanf("%NELs", str1);
	
	printf("Inserisci la seconda stringa --->  ");
	scanf("%NELs", str2);
	
	printf("Inserisci la terza stringa --->  ");
	scanf("%NELs", str3);

	if(strsubend(str1, str2, str3)) {
		printf("%s\n", str1);
	} else {
		printf("Modifica non effettuata.\n");
	}
	
	return 0;
}

int lenght(char *stringa) {
	char *str1 = stringa;
	int nlet = 0;
	
	while(*str1 != '\0') {
		nlet++;
		str1++;
	}
	
	return nlet;
}

int sameLenght(int len1, int len2) {
	return (len1 == len2)? 1 : 0;
}

int stringCompare(char *s, char *t, int nlett) {
	char *str1 = s, *str2 = t;
	
	str1 = str1 + (lenght(str1) - lenght(str2)) + 1;  
	
	while(*str1 != '\0' && *str2 != '\0') {
		if(*str1 != *str2) {
			break;
		}
		str1++;
		str2++;
	}
	
	return (*str1 == '\0' && *str2 == '\0')? 1 : 0;
}

int strsubend (char *s, char *t, char *r) {
	char *str1 = s, *str2 = t, *str3 = r;
	
	if(sameLenght(lenght(str2), lenght(str3)) && stringCompare) {
		str1 = str1 + (lenght(str1) - lenght(str2));
		while(*str3 != '\0') {
			*str1 = *str3;
			str1++;
			str3++;
		}
		return 1;
	}
	
	return 0;
}
