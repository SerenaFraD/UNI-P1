#include<stdio.h>

int main() {
	
	int voti = 0, i = 0, voto = 0;
	
	while(i < 10) {
		printf("Inserire il voto n %d ", i + 1);
		scanf("%d", &voto);
		if(voto >= 0 && voto <= 100) {
			voti += voto;
			i++;
		} else {
			printf("\nVoto non valido.\n");
		}
	}
	
	float media = voti/10.0f;
	printf((media > 60)? "Classe valida" : "Classe non valida");
	printf("  %.2f\n", media);
	
	return 0;
	
}
	
