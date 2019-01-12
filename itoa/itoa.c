#include<stdio.h>
#define NEL 10

void itoa(int n, char *s);

int main(void) {
	int n;
	char stringa[NEL];
	
	printf("Inserire un numero.\n");
	scanf("%d", &n);
	
	itoa(n, stringa);

	printf("%s\n", stringa);

	return 0;
}

void itoa(int n, char *s) {
	char *p = s, *ul, tmp;
	
	if(n < 0) {
		n = -n;
		*p = '-';
		p++;
	} else {
		*p = '+';
		p++;
	}
	
	while(n != 0) {
		*p = n % 10 + 48;
		p++;
		n = n / 10;
	}
	
	*p = '\0';
	ul = --p;
	p = s + 1;
	
	while(p < ul) {
		tmp = *p;
		*p++ = *ul;
		*ul-- = tmp;
	}
}
