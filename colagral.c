#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// las funciones para imprimir (el contenido de la estructura) y contar (la cantidad de nodos en la estructura) sean programadas con la lógica de pilas y colas mencionada en clase, es decir, partiendo del principio que solo se agrega nodo y/o se elimina nodo, y que toda acción adicional depende de esas dos acciones

struct nodo {
    int info;
    struct nodo *sig;
};

//variables globales que apuntan al primer nodo de la cola, y al �ltimo
struct nodo *raiz=NULL;
struct nodo *fondo=NULL;

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

void imprimir()
{
	struct node *raizA = raiz;
	struct node **temp = &raiz;
	while (temp != NULL) {
		int info = extraer();
		printf("%d\n", info);
		insertar(info);
		if ( *temp == raizA ) break;
	}
}


int contar () {
	struct node *raizA = raiz;
	struct node **temp = &raiz;
	int count = 0;
	while (temp != NULL) {
		count++;
		int info = extraer();
		insertar(info);
		if ( *temp == raizA ) break;
	}
	return count;
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
	printf("6. Contar nodos en la Cola...\n");
	printf("7. Terminar \n");
	printf("\nEscoja opci�n...\n");
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
			printf("La Cola tiene %i nodos...\n",contar());
			break;
		case 7:
			printf("Chao...\n");
			break;
		default:
			printf("Error de opci�n...\n");
			break;
		}
	}while(opc!=7);
    getch();
    return 0;
}
