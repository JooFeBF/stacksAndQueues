#include<stdio.h>
#include<stdlib.h>


struct nodo {
    int info;
    struct nodo *sig;
};

//variable global que apunta al primer nodo de la lista

void insertar(int x, struct nodo **raiz)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = x;
    if (*raiz == NULL)
    {
        *raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = *raiz;
        *raiz = nuevo;
    }
}

void imprimir(struct nodo *raiz)
{
    struct nodo *reco=raiz;
   	if(raiz==NULL)
   		printf("La pila está vacía.\n");
	else
	{
	    printf("Impresion de Lista tipo pila...\n");
	    while (reco!=NULL)
	    {
	        printf("%i ",reco->info);
	        printf("\n");
	        reco=reco->sig;
	    }
	}
	printf("\n");
}

//int extraer()
//{
//   	if(raiz==NULL)
//   	{
//   		printf("La pila está vacía.\n");
//   		return -1;
//   }
//	else
//	{
//        int informacion = raiz->info;
//        struct nodo *bor = raiz;
//        raiz = raiz->sig;
//        free(bor);
//        return informacion;
//    }
//}
//
//void liberar()
//{
//    struct nodo *reco = raiz;
//    struct nodo *bor;
//   	if(raiz==NULL)
//   		printf("La pila está vacía.\n");
//	else
//	{
//	    while (reco != NULL)
//	    {
//	        bor = reco;
//	        reco = reco->sig;
//	        free(bor);
//	    }
//		raiz=NULL;
//	}
//}
//
//
//int cantidad()
//{
//    struct nodo *reco = raiz;
//    int cant = 0;
//    while (reco != NULL)
//    {
//        cant++;
//        reco = reco->sig;
//    }
//    return cant;
//}
//
//int vacia()
//{
//    if (raiz == NULL)
//        return 1;
//    else
//        return 0;
//}
//
//

int main()
{
	struct nodo *raiz = NULL;
    insertar(10, &raiz);
    insertar(40, &raiz);
    //insertar(3);
    //insertar(20);
    //insertar(50);

    imprimir(raiz);
//    printf("Extraemos un nodo de la pila: %i\n",extraer());
//    imprimir();
//    printf("La cantidad de nodos de la pila es: %i\n",cantidad());
//    while (vacia() == 0)
//	{
//     printf("Extraemos un nodo de la pila: %i\n",extraer());
//    }
////		extraer(); 
////   	liberar();
//	getch();
////	printf("%d",cantidad());
//	imprimir();   
//    getch();
    return 0;
}
