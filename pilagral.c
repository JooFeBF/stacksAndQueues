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

int extraer(struct nodo **raiz)
{
   	if(*raiz==NULL)
   	{
   		printf("La pila está vacía.\n");
   		return -1;
   }
	else
	{
        int informacion = (*raiz)->info;
        struct nodo *bor = *raiz;
        *raiz = (*raiz)->sig;
        free(bor);
        return informacion;
    }
}
void imprimir(struct nodo **raiz)
{
    int info = extraer(raiz);
    if (*raiz == NULL) {
        printf("%d\n", info);
        return;
    }
    imprimir(raiz);
    printf("%d\n", info);
    insertar(info, raiz);
}

int contar (struct nodo **raiz) {
  if (*raiz == NULL) return 0;
    int info = extraer(raiz);
    int count = contar(raiz);
    insertar(info, raiz);
    return count + 1;
}

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
  int opt = 0;
  struct nodo *raiz = NULL;

    while (opt != 5) {
        printf("1. Insertar\n");
        printf("2. Extraer\n");
        printf("3. Imprimir\n");
        printf("4. Contar\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("Número a insertar: ");
            int num;
            scanf("%d", &num);
            insertar(num, &raiz);
            break;
        case 2:
            printf("Número extraído: %d\n", extraer(&raiz));
            break;
        case 3:
            imprimir(&raiz);
            break;
        case 4:
            printf("Cantidad de elementos: %d\n", contar(&raiz));
            break;
        case 5:
            break;
        default:
            printf("Opción inválida\n");
        }
    }

}
