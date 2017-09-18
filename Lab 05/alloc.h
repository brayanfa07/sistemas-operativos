#include "stdio.h"

#define ALLOCSIZE 10000 // tamaño del espacio disponible

static char allocbuf[ALLOCSIZE]; // almacenamiento para alloc
static char *allocp = allocbuf; // siguiente posición libre


char *alloc(int n) { // regresa un puntero a n caracteres
	for (int i=0; i<1000; i++)
		printf("%i\n",allocbuf[i]);
	printf("Numero allocsize %d\n", ALLOCSIZE);
	printf("Numero allocp %d\n", *allocp);
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp -n;
	} else
		return 0;
	}
	
void afree(char *p) { // libera la memoria apunta por p
	if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
	allocp = p;
}
