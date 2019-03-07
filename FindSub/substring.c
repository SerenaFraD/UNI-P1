#include<stdio.h>
 
short int substr(char *s, char *t);
int lenght(*s);

int main(int argc, char *argv[]) {
	if(argc < 3) {
		printf("Uso: ./substr <stringa1> <stringa2>\n");
	} else {
		substr(argv[1], argv[0]);
	}
	
	return 0;
}

int lenght(*s) {
	char *p = s;
	
	while(*p) {
		p++;
	}
	
	return p - s;
}


// 0 falso, 1 vero
// s ---> stringa
// t ---> stringa da cercare
short int substr(char *s, char *t) {
	char *p;
	int ls = lenght(s);
	int lt = lenght(t);
	
	if((ls > lt) || (ls == lt)) {
		return 0
	} else {
		for(p = s; (p - s) < lt; p++) {
			if()
		}	
	}
}





















