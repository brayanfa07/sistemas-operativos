#include "alloc.h"
#include "stdio.h"

int main() {
	int* arreglo;
	arreglo = (int*)alloc(sizeof(int)*10, 2); //Ingresa 1 o 2 dependiendo de donde se quiere guardar
	for (int i=0; i<10; i++)
		arreglo[i]=10*i;

		for (int i=0; i<10; i++)
			printf("%i\n",arreglo[i]);
			afree((char*)arreglo);
			arreglo = (int*)alloc(sizeof(int)*10, 2);

		for (int i=0; i<10; i++)
			arreglo[i]=20*i;
		
		for (int i=0; i<10; i++)
			printf("%i\n",arreglo[i]);
}