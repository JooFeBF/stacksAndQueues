#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};

void liberar(struct nodo **raiz, struct nodo **fondo)
{
    struct nodo *reco = *raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
	*raiz=NULL;
	*fondo=NULL;
}

int vacia(struct nodo **raiz)
{
    if (*raiz == NULL)
        return 1;
    else
        return 0;
}
void insertar(int x, struct nodo **raiz, struct nodo **fondo)
{
	struct nodo *nuevo;
	nuevo=malloc(sizeof(struct nodo));
	nuevo->info=x;
	nuevo->sig=NULL;
	if (vacia(raiz))
	{
		*raiz = nuevo;
		*fondo = nuevo;
	}
	else
	{
		(*fondo)->sig = nuevo;
		*fondo = nuevo;
	}
}

int extraer(struct nodo **raiz, struct nodo **fondo)
{
    if (!vacia(raiz))
    {
        int informacion = (*raiz)->info;
        struct nodo *bor = *raiz;
        if (*raiz == *fondo)
        {
            *raiz = NULL;
            *fondo = NULL;
        }
        else
        {
            *raiz = (*raiz)->sig;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void imprimir(struct nodo **raiz, struct nodo **fondo)
{
	struct nodo *raizA = *raiz;
	struct nodo **temp = raiz;
	while (temp != NULL) {
		int info = extraer(raiz, fondo);
		printf("%d\n", info);
		insertar(info, raiz, fondo);
		if ( *temp == raizA ) break;
	}
}

void insertarN(int x, struct nodo **raiz, struct nodo **fondo, int n) {
	struct nodo *tempRaiz = NULL;
	struct nodo *tempFondo = NULL;
	int i = 0;

	// Remove elements until reaching position n
	while (!vacia(raiz) && i < n) {
		int info = extraer(raiz, fondo);
		insertar(info, &tempRaiz, &tempFondo);
		printf("%d\n", i);
		i++;
	}

	// Insert the new element at position n
	insertar(x, raiz, fondo);

	// Reinsert the removed elements back into the queue
	while (!vacia(&tempRaiz)) {
		printf("aaaaaa");
		int info = extraer(&tempRaiz, &tempFondo);
		insertar(info, raiz, fondo);
	}
}

void extraerN(struct nodo **raiz, struct nodo **fondo, int n) {
    struct nodo *tempRaiz = NULL;
    struct nodo *tempFondo = NULL;
    int i = 0;

    // Remove elements until reaching position n
    while (!vacia(raiz) && i < n - 1) {
        int info = extraer(raiz, fondo);
        insertar(info, &tempRaiz, &tempFondo);
        i++;
    }

    // Remove the element at position n
    if (!vacia(raiz)) {
        extraer(raiz, fondo);
    }

    // Reinsert the removed elements back into the queue
    while (!vacia(&tempRaiz)) {
        int info = extraer(&tempRaiz, &tempFondo);
        insertar(info, raiz, fondo);
    }
}

int contar (struct nodo **raiz, struct nodo **fondo) {
	struct nodo *raizA = *raiz;
	struct nodo **temp = raiz;
	int count = 0;
	while (temp != NULL) {
		count++;
		int info = extraer(raiz, fondo);
		insertar(info, raiz, fondo);
		if ( *temp == raizA ) break;
	}
	return count;
}



int main()
{
	struct nodo *raiz=NULL;
	struct nodo *fondo=NULL;
	 int opc,val;
	do{
	printf("\n============================================\n");
	printf("1. Entra nodo a la cola...\n");
	printf("2. Sale nodo de la cola...\n");
	printf("3. Mostrar Cola...\n");
	printf("4. Vaciar Cola...\n");
	printf("5. Ver si Cola esta vacia...\n");
	printf("6. Contar nodos en la Cola...\n");
	printf("7. Insertar en posición\n");
	printf("8. Extraer en posición\n");
    printf("9. Salir...\n");
	printf("\nEscoja opcion...\n");
	scanf("%d", &opc);
	switch(opc){
		case 1:
			printf("Indique valor...\n");
			scanf("%d", &val);
			insertar(val, &raiz, &fondo);
    		break;
    	case 2:
    		printf("Eliminamos nodo de la Cola (siempre el primero): %i\n",extraer(&raiz, &fondo));
    		break;
		case 3:
			imprimir(&raiz, &fondo);
			break;
		case 4:
			liberar(&raiz, &fondo);
			break;
		case 5:
			if(vacia(&raiz)==0)
				printf("La Cola tiene informacion...\n");
			else
				printf("La Cola esta vacia...\n");
			break;
		case 6:
			printf("La Cola tiene %i nodos...\n",contar(&raiz, &fondo));
			break;
		case 7:
            printf("Indique valor a insertar...\n");
            scanf("%d", &val);
            printf("Indique posición a insertar...\n");
            int pos;
            scanf("%d", &pos);
            insertarN(val, &raiz, &fondo, pos);
            break;
		case 8:
            printf("Indique posición a extraer...\n");
            int pos2;
            scanf("%d", &pos2);
            extraerN(&raiz, &fondo, pos2);
            break;
		case 9:
			printf("Chao...\n");
		default:
			printf("Error de opcion...\n");
			break;
		}
	}while(opc!=9);
    return 0;
}
