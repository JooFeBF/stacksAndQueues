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
        insertar(info, raiz);
        return;
    }
    imprimir(raiz);
    printf("%d\n", info);
    insertar(info, raiz);
}

void extraerN(struct nodo **raiz, int n)
{
    int info = extraer(raiz);
    if (*raiz == NULL || n == 1) {
        extraer(raiz);
        insertar(info, raiz);
        return;
    }
    extraerN(raiz, n-1);
    insertar(info, raiz);
}

void insertarN(int x, struct nodo **raiz, int n)
{
    int info = extraer(raiz);
    if (*raiz == NULL || n == 0) {
        insertar(info, raiz);
        insertar(x, raiz);
        return;
    }
    insertarN(x, raiz, n-1);
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

    insertar(1, &raiz);
    insertar(2, &raiz);
    insertar(3, &raiz);
    insertar(5, &raiz);
    insertarN(3, &raiz, 2);
    extraerN(&raiz, 2);
    // imprimir should print 3, 5, 3, 2, 1


    while (opt != 7) {
        printf("1. Insertar\n");
        printf("2. Extraer\n");
        printf("3. Imprimir\n");
        printf("4. Contar\n");
        printf("5. Insertar en posición\n");
        printf("6. Extraer en posición\n");
        printf("7. Salir\n");
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
            printf("Número a insertar: ");
            int num2;
            scanf("%d", &num2);
            printf("Posición: ");
            int pos;
            scanf("%d", &pos);
            insertarN(num2, &raiz, pos);
            break;
        case 6:
            printf("Elemento a extraer: ");
            int pos2;
            scanf("%d", &pos2);
            extraerN(&raiz, pos2);
            break;
        case 7:
            break;
        default:
            printf("Opción inválida\n");
        }
    }

}
