#include <stdio.h>
#include "Productos.h"
#include <string.h>

/*
    int idProducto;
    char nombre[50];
    int precio;
    int cantidadVendida;
    int stock;
    int estado;

*/

int eProd_init(eProductos productos[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && productos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            productos[i].estado = 0;
            productos[i].idProducto = 0;
        }
    }
    return retorno;
}


void eProd_hardCode(eProductos productos[])
{
    int id[5] = {1,2,3,4,5};
    char nombre[][50]={"Silla de madera","Pizarron","Mochila","Teclado","Sillon"};
    float precio[5]={1000,450,250,300,5000};
    int cantidadVendida[5] = {5,2,13,20,0};
    int stock[5] = {5,7,20,4,2};

    int i;

    for(i=0; i<5; i++)
    {
        productos[i].idProducto=id[i];
        productos[i].precio=precio[i];
        productos[i].cantidadVendida=cantidadVendida[i];
        productos[i].stock=stock[i];
        productos[i].estado = 1;
        strcpy(productos[i].nombre, nombre[i]);
    }
}

void mostrarListaProductos(eProductos productos[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(productos[i].estado == 1)
        {
//            printf("%d %s %s %d\n",productos[i].idProducto, productos[i].nombre, productos[i].genero, productos[i].cantidadTemporadas);
        }
    }
}

int buscarLibreProducto(eProductos productos[], int tam)
{
    int index=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(productos[i].estado == 0)
        {
            index=i;
            break;
        }
    }

    return index;
}

int cargarProducto(eProductos productos[], int tam)
{
    int index;
    index = buscarLibreProducto(productos, tam);

    if(index!=-1)
    {
        printf("Ingrese ID: ");
        scanf("%d", &productos[index].idProducto);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(productos[index].nombre);
        printf("Ingrese genero: ");
        fflush(stdin);
//        gets(productos[index].genero);
        printf("Ingrese temporadas: ");
//        scanf("%d", &productos[index].cantidadTemporadas);
        productos[index].estado=1;
    }

    return index;
}


int buscarIntProductos(eProductos productos[], int tam, int cual)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(productos[i].idProducto==cual)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaProducto(eProductos productos[], int tam)
{
    int numeroProducto;
    int index = -1;

    printf("Ingrese producto a dar de baja: ");
    scanf("%d", &numeroProducto);

    index = buscarIntProductos(productos,tam,numeroProducto);

    if(index!=-1)
    {
        productos[index].estado = 0;
    }
    return index;
}
