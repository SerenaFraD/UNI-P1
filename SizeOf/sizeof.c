#include<stdio.h>

int main() {
	int i;
	short int si;
	long int li;
	float f;
	double d;
	long double ld;
	
	printf("******** Dimensione ********\n");
	printf("Intero       %lu\n", sizeof(i));
	printf("Short int    %lu\n", sizeof(si));
	printf("Long int     %lu\n", sizeof(li));
	printf("Float        %lu\n", sizeof(f));
	printf("Double       %lu\n", sizeof(d));
	printf("Long double  %lu\n", sizeof(ld));
	
	return 0;
}
	
	


