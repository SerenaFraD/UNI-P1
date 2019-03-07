#include<stdio.h>

void reverseArgv(int argc, char* argv[]);


int main(int argc, char* argv[]) {
	
	if(argc != 1) {
		reverseArgv(argc, argv);
	}
	
	return 0;
}

void reverseArgv(int argc, char* argv[]) {
	
	for(int i = argc - 1; i > 0; i--) {
		printf("%s\n", argv[i]);	
	}

	return;
}
