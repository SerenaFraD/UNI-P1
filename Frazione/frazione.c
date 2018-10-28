#include<stdio.h>

int main() {

	int num, den, r, n, m;
	
	printf("Inserire la frazione ");
	scanf("%d/%d", &num, &den);
	
	if(num > den) {
		n = den;
		m = num;
	} else {
		n = num;
		m = den;
	}	
	
	while(n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	
	printf("La frazie e' %d / %d\n", num/m, den/m);
	
	return 0;
}
	
	
