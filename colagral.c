#include<stdio.h>
#include<stdlib.h>


struct nodo {
    int info;
    struct nodo *sig;
};

//variables globales que apuntan al primer nodo de la cola, y al último
struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

void insertar(int x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    nuevo->sig=NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

void imprimir()
{
    struct nodo *reco = raiz;
   	if(raiz==NULL)
   		printf("La cola está vacía.\n");
	else
	{
	    printf("Listado de todos los elementos de la cola.\n");
	    while (reco != NULL)
	    {
	        printf("%i - ", reco->info);
	        reco = reco->sig;
	    }
	    printf("\n");
	}
}

int extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else
        {
            raiz = raiz->sig;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
	raiz=NULL;
	fondo=NULL;
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

int main()
{
	int opc,val;
	do{
	printf("\n============================================\n");
	printf("1. Entra nodo a la cola...\n");
	printf("2. Sale nodo de la cola...\n");
	printf("3. Mostrar Cola...\n");
	printf("4. Vaciar Cola...\n");
	printf("5. Ver si Cola esta vacia...\n");
	printf("6. Terminar \n");
	printf("\nEscoja opción...\n");
	scanf("%d", &opc);
	switch(opc){
		case 1: 
			printf("Indique valor...\n");
			scanf("%d", &val);
			insertar(val);
    		break;
    	case 2:
    		printf("Eliminamos nodo de la Cola (siempre el primero): %i\n",extraer());
    		break;	
		case 3:
			imprimir();
			break;
		case 4:
			liberar(); 
			break;
		case 5:
			if(vacia()==0)
				printf("La Cola tiene informacion...\n");
			else
				printf("La Cola esta vacia...\n");
			break;
		case 6:
			printf("Chao...\n");
			break;
		default:
			printf("Error de opción...\n");
			break;
		}
	}while(opc!=6);
    getch();
    return 0;
}
