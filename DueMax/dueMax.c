#include<stdio.h>
#define  N (int) 7

void trovaDueMax(const int a[], int arrayDim, int* max1, int* max2);

int main() {
	int a[N] = {0, 1, 2, 50, 3, 30, 5}, max1, max2;
	trovaDueMax(a, N, &max1, &max2);
}

void trovaDueMax(const int array[], int arrayDim, int* max1, int* max2) {
	const int* p = array;
	if(*array > *(array + 1)) {
		*max1 = *array;
		*max2 = *(array + 1);
	} else {
		*max2 = *array;
		*max1 = *(array + 1);
	}
	
	for(p = array + 2; p < array + arrayDim; p++) {
		if(*p > *max1) {
			*max2 = *max1;
			*max1 = *p;
		}else if(*p > *max2) {
			*max2 = *p;
		}
	}
	
	printf("%d %d\n", *max1, *max2);
}
