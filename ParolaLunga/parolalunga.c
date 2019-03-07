#include<stdio.h>
#define N (int) 100

void initArray(char array[], int dimArray);
int checkParola(char array[]);
void printParola(char array[], int index);

int main() {
	char frase[N];
	printf("Inserire una frase da controllare.\n");
	initArray(frase, N);
	printf("initArray: V Fatto!\n");
	
	printf("La parola inizia dall'indice %d\n", checkParola(frase));
	return 0;
}



void initArray(char array[], int dimArray) {
	int i = 0;
	char ch;

	while((ch = getchar()) != '\n') {
	  if(ch != ' ') {
	    array[i] = ch;
		}
		i++;
	}
	array[i + 1] = ' ';
	array[i + 2] = '\n';
	return;
}

int checkParola(char array[]) {
	int i = 0, index = 0, tmpm = 0, tmpi = 0, max = 0;
	
	while(array[i] != '\n') {
		while(array[i] != ' ') {
			i++;
		}
		tmpm = i - tmpi;
		if(tmpm > max) {
			max = tmpm;
			index = tmpi;
		} 
		tmpi = i + 1;
		tmpm = 0;
		i++;
	}		
	return index;
}

//void printParola(char array[], int index) {


//}















