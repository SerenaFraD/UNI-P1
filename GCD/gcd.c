#include<stdio.h>

int main() {

	int n, m, r;
	
	printf("Inserire due numeri ");
	scanf("%d %d", &n, &m);
	
	while(n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	
	printf("%d e' il massimo comun divisore", m);

	
	return 0;
}
		
	
