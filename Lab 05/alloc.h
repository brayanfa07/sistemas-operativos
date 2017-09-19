#include "stdio.h"

#define ALLOCSIZE 10000 // tamaño del espacio disponible

static char allocbuf[ALLOCSIZE]; // almacenamiento para alloc
static char *allocp = allocbuf; // siguiente posición libre


char *alloc(int n, int i) { // regresa un puntero a n caracteres
	int memorySector = i;
	if (memorySector == 1){
		for (int i=0; i<1000; i++){
			//printf("Printing allocbuf %i\n",allocbuf[i]);
		}
		printf("Numero allocsize %d\n", ALLOCSIZE);
		printf("Numero allocp %d\n", *allocp);
		if (allocbuf + ALLOCSIZE - allocp >= n) {
			allocp += n;
			printf("Print de N %d\n", n);
			printf("Print de allocp 1 %d\n", *allocp);
			printf("Print de allocp 2 (allocp - n) %d\n", *allocp -n);
			return allocp -n;
		} 
		else{
			return 0;
		}
		
	}else{
		if (memorySector == 2){
			for (int i=0; i<1000; i++){
			//printf("Printing allocbuf %i\n",allocbuf[i]);
			}
			printf("Numero allocsize %d\n", ALLOCSIZE);
			printf("Numero allocp %d\n", *allocp);
			if (allocbuf + ALLOCSIZE - allocp >= n) {
				*allocp = n;
				printf("Print de N %d\n", n);
				printf("Print de allocp 1 %d\n", *allocp);
				printf("Print de allocp 2 (allocp - n) %d\n", *allocp -n);
				return allocp -n;
			} else
				return 0;
		}
	}
}

	
void afree(char *p) { // libera la memoria apunta por p
	if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
	allocp = p;
}
