#include<stdio.h>

int main() {
	int i;
	char command;
	
	printf("Inserire un intero ");
	scanf("%d", &i);
	getchar();
	printf("Inseire un comando ");
	command = getchar();
	
	return 0;
}
