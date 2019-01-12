#include<stdio.h>
#define NEL 10

int converti(char *s);

int main(void) {
	char stringa[NEL];
	
	printf("Inserire la stringa da convertire --->  ");
	scanf("%s", stringa);
	
	printf("%d\n", converti(stringa));

	return 0;
}

int converti(char *s) {
	char *p = s;
	int n = 0;

	if(*p == '-' || *p == '+') {
		p++;
	}
	
	while(*p != '\0') {
		n = (*p - 48) + n * 10;
		p++;	
	}
	
	return (*s == '-') ? -n : n;
}
