#include<stdio.h>
#define LENGHT ((int) sizeof(stringa) / sizeof(stringa[0]))
#define N 20

int main() {
	unsigned char stringa[N], tmp[N][2], ch;
	int i = 0, r = -1, x = 0;
	
	printf("Inserire una stringa.\n");
	while((ch = getchar()) != '\n' && i < N) {
		if(ch != ' ') {
			stringa[i] = ch;
			i++;
			while(x <= r && tmp[x][0] != stringa[i]) {													//controllo se il carattere non sia già presente nell'array rip
				x++;
			}
			if(x > r) {																						//se l'indice x è maggiore della dimensione r, numero non trovato aggiunta
				r++;
				tmp[r][1]++;
			}
		}
	}
	
	printf("Inserire la stringa da controllare.\n");
	while((ch = getchar()) != '\n') {
		while(x <= r && tmp[x][1] != stringa[i]) {										//controllo se il carattere sia già presente nell'array tmp
				x++;
		}
		if(x > r) {																						//se l'indice x è maggiore della dimensione r, numero non trovato aggiunta
			r++;
			tmp[r][1] = stringa[i];
		}
		
	}



	return 0;
}
