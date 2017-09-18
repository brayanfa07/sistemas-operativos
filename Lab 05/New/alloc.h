#define ALLOCSIZE 10000 // tamaño del espacio disponible

static char allocbuf[ALLOCSIZE]; // almacenamiento para alloc
static char *allocp = allocbuf; // siguiente posición libre

char *alloc(int n, int i) { // regresa un puntero a n caracteres
	if (i == 1){
		if (allocbuf + ALLOCSIZE - allocp >= n) {
			allocp += n;
			return allocp -n;
		} else
			return 0;
		}
	}
	else
		if(i == 2){
			return 0;
		}
	
void afree(char *p) { // libera la memoria apunta por p
	if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
	allocp = p;
}
