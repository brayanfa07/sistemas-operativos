//malloc.h

typedef long Align; //alineamiento al limite superior
union header {	//Encabezado de bloque

	struct {
		union header *ptr; //siguiente bloque
		unsigned size; 	//tamano del bloque
	}s;
	Align x;			//Alineamiento de bloque
};

typedef union header Header;
static Header base;		//lista vacia al inicio
static Header *freep = NULL; //lista libre


//free: coloca el bloque ap en la lista vacia
void free(void *ap){
	Header *bp, *p;

	bp = (Header*) ap-1;
	for (p = freep; !(bp>p && bp > p->s.ptr); p=p->s.ptr)

		if (p >= p->s.ptr && (bp>p || bp < p->s.ptr))
			break; //libera bloque al inicio o al final

	if (bp + bp->s.size == p->s.ptr){ //fusiona al nbr superior
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr;
	}else
		bp->s.ptr = p->s.ptr; //fusiona al bnr inferior
	if(p + p->s.size == bp){
		p->s.size += bp->s.size;
		p->s.ptr = bp-s.ptr;
	}else
		p->s.ptr = bp;
	freep = p;
}

#define NALLOC 1024 //minimo de unidades por requerir

//morecore: solicita mas memoria del sistema

static Header *morecore (unsigned nu){
	char *cp, *sbrk(int);
	Header *up;
	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp = (char*)-1) // no hay nada de espacio
		return NULL;
	up->s.size = nu;

	free((void*) (up+1));
	return freep;
}

//malloc:Asignador de memoria

void* malloc(unsigned long nbytes){
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes+sizeof(Header)-1) / sizeof(Header)+1;

	if ((prevp = freep) == NULL){ //no hay lista libre
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp -> s.ptr;;prevp = p, p = p->s.ptr){
		if (p-> s.size >= nunits){ //suficiente grande
			if (p-> s.size == nunits) //exacto
				prevp->s.ptr = p->s.ptr;
		else{
			p->s.size -= nunits;
			p += p->s.size;
			p->s.size = nunits;
		}
		freep = prevp;
		return (void *)(p+1);
	}
	if (p == freep) //dio la vuelta a la lista libre
		if ((p=morecore(nunits)) == NULL)
			return NULL;
	}
}


