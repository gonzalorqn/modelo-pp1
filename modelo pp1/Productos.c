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
    int idUsu[5]= {4,2,5,1,3};
    float precio[5]={1000,450,250,300,5000};
    int cantidadVendida[5] = {5,2,13,20,0};
    int stock[5] = {5,7,20,4,2};

    int i;

    for(i=0; i<5; i++)
    {
        productos[i].idProducto=id[i];
        productos[i].idUsuario=idUsu[i];
        productos[i].precio=precio[i];
        productos[i].cantidadVendida=cantidadVendida[i];
        productos[i].stock=stock[i];
        productos[i].estado = 1;
        strcpy(productos[i].nombre, nombre[i]);
    }
}

int eProd_buscarLugarLibre(eProductos productos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(productos[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProd_siguienteId(eProductos productos[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && productos != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(productos[i].estado == 1)
            {
                    if(productos[i].idProducto>retorno)
                    {
                         retorno=productos[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}

int eProd_buscarPorId(eProductos productos[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(productos[i].estado == 1 && productos[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
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


int bajaProducto(eProductos productos[], int tam)
{
    int numeroProducto;
    int index = -1;

    printf("Ingrese producto a dar de baja: ");
    scanf("%d", &numeroProducto);

//    index = buscarIntProductos(productos,tam,numeroProducto);

    if(index!=-1)
    {
        productos[index].estado = 0;
    }
    return index;
}
