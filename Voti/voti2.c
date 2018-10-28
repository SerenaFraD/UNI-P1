#include<stdio.h>

int main(void) {
	
	int media = 0, i = 0, voto;
	
	printf("Inserire il primo voto\n(-1 termina l'esecuzione)\n");
	scanf("%d", &voto);
	
	while(voto != -1) {
		if(voto >= 0 && voto <= 100) {
			media += voto;
			i++;
		} else {
			printf("\nVoto non valido.\n");
		}
		printf("Inserire il voto n %d ", i + 1);
		scanf("%d", &voto);
	}
	
	if(i != -1) {
		media /= i;
		printf((media >= 60)? "Classe valida" : "Classe non valida");
		printf("  %d\n", media);
	}
	
	return 0;
	
}
