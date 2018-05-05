#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

int eUsu_init(eUsuario usuarios[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            usuarios[i].estado = 0;
            usuarios[i].idUsuario = 0;
        }
    }
    return retorno;
}

void eUsu_hardCode(eUsuario usuarios[])
{
    int id[5] = {1,2,3,4,5};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose"};
    char password[][50]= {"asd123","maria123","pedro","vanesa98","jose10"};
    int contCalif[5] = {5,2,13,20,0};
    float promCalif[5] = {10,8,7.5,9.3,0};

    int i;

    for(i=0; i<5; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].estado = 1;
        usuarios[i].contCalificaciones = contCalif[i];
        usuarios[i].promCalificaciones = promCalif[i];
        strcpy(usuarios[i].nombre, nombre[i]);
        strcpy(usuarios[i].password, password[i]);

    }

}

int eUsu_buscarLugarLibre(eUsuario usuarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuarios[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsu_siguienteId(eUsuario usuarios[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(usuarios[i].estado == 1)
            {
                    if(usuarios[i].idUsuario>retorno)
                    {
                         retorno=usuarios[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}

int eUsu_alta(eUsuario usuarios[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        indice = eUsu_buscarLugarLibre(usuarios,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsu_siguienteId(usuarios,limite);

            retorno = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(usuarios[indice].nombre);
            printf("Ingrese password: ");
            fflush(stdin);
            gets(usuarios[indice].password);
            usuarios[indice].idUsuario = id;
            usuarios[indice].estado = 1;
        }
    }
    return retorno;
}

int eUsu_buscarPorId(eUsuario usuarios[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(usuarios[i].estado == 1 && usuarios[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsu_modificacion(eUsuario usuarios[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        eUsu_mostrar(usuarios,limite);
        printf("Ingrese ID a modificar: ");
        scanf("%d", &id);

        indice = eUsu_buscarPorId(usuarios,limite,id);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(usuarios[indice].nombre);
            printf("Ingrese password: ");
            fflush(stdin);
            gets(usuarios[indice].password);
            usuarios[indice].idUsuario = id;
            usuarios[indice].estado = 1;
        }
    }
    return retorno;
}

int eUsu_baja(eUsuario usuarios[],eProductos productos[],int limiteUsu,int limiteProd)
{
    int retorno = -1;
    int id;
    int indice;
    int i;

    if(limiteUsu > 0 && usuarios != NULL && limiteProd > 0 && productos != NULL)
    {
        retorno = -2;
        eUsu_mostrar(usuarios,limiteUsu);
        printf("Ingrese ID a dar de baja: ");
        scanf("%d", &id);

        indice = eUsu_buscarPorId(usuarios,limiteUsu,id);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = 0;
            usuarios[indice].estado = 0;

            for(i=0;i<limiteProd;i++)
            {
                if(productos[i].idUsuario == usuarios[indice].idUsuario)
                {
                    productos[i].estado = 0;
                }
            }

        }
    }
    return retorno;
}

void eUsu_mostrarUno(eUsuario usuarios)
{
    printf("%d %s\n",usuarios.idUsuario, usuarios.nombre);
}

void eUsu_mostrar(eUsuario usuarios[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(usuarios[i].estado == 1)
        {
            eUsu_mostrarUno(usuarios[i]);
        }
    }
}


int eProd_alta(eProductos productos[], eUsuario usuarios[],int limiteProd, int limiteUsu)
{
    int retorno = -1;
    int id;
    int idUsu;
    int indice;
    int i;

    if(limiteProd > 0 && productos != NULL && limiteUsu > 0 && usuarios != NULL)
    {
        retorno = -2;
        indice = eProd_buscarLugarLibre(productos,limiteProd);
        if(indice >= 0)
        {
            retorno = -3;
            id = eProd_siguienteId(productos,limiteProd);

            eUsu_mostrar(usuarios,limiteUsu);
            printf("Ingrese ID usuario: ");
            scanf("%d", &idUsu);
            for(i=0;i<limiteUsu;i++)
            {
                if(idUsu == usuarios[i].idUsuario && usuarios[i].estado == 1)
                {
                    retorno = 0;
                    printf("Ingrese nombre de producto: ");
                    fflush(stdin);
                    gets(productos[indice].nombre);
                    printf("Ingrese precio: ");
                    scanf("%f", &productos[indice].precio);
                    printf("Ingrese stock: ");
                    scanf("%d", &productos[indice].stock);
                    productos[indice].idProducto = id;
                    productos[indice].estado = 1;
                    productos[indice].idUsuario = idUsu;
                }
            }
        }
    }
    return retorno;
}

int eProd_modificacion(eProductos productos[],eUsuario usuarios[],int limiteProd,int limiteUsu)
{
    int retorno = -1;
    int id;
    int idProd;
    int indice;

    if(limiteUsu > 0 && usuarios != NULL && limiteProd > 0 && productos != NULL)
    {
        retorno = -2;
        eUsu_mostrar(usuarios,limiteUsu);
        printf("Ingrese ID de usuario: ");
        scanf("%d", &id);

        indice = eUsu_buscarPorId(usuarios,limiteUsu,id);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = -3;
            eUsu_mostrarUsuarioConSusProductos(productos,limiteProd,usuarios,limiteUsu,id);
            printf("Ingrese ID de producto: ");
            scanf("%d", &idProd);

            indice = eProd_buscarPorId(productos,limiteProd,idProd);

            if(indice == -2 || indice == -1 || productos[indice].idUsuario != id)
            {

            }

            else
            {
                retorno = 0;
                printf("Ingrese nuevo precio: ");
                scanf("%f", &productos[indice].precio);
                printf("Ingrese stock: ");
                scanf("%d", &productos[indice].stock);
                productos[indice].estado = 1;
            }

        }
    }
    return retorno;
}

void eUsu_mostrarUsuarioConSusProductos(eProductos productos[], int limiteProd, eUsuario usuarios[], int limiteUsu,int idUsu)
{
    int i;
    int j;
    for(i=0;i<limiteUsu;i++)
    {
        if(usuarios[i].estado == 1 && usuarios[i].idUsuario == idUsu)
        {
            printf("%s:\n",usuarios[i].nombre);
            for(j=0;j<limiteProd;j++)
            {
                if(usuarios[i].idUsuario == productos[j].idUsuario && productos[j].estado == 1)
                {
                    printf("%d - %s - %.2f - %d - %d\n",productos[j].idProducto,productos[j].nombre,productos[j].precio,productos[j].cantidadVendida,productos[j].stock);
                }
            }
            printf("\n");

        }
    }
}

void mostrarUsuarioConSuSerie(eUsuario usuarios[], int cantUsuarios, eProductos productos[], int cantSeries)
{
    int i;
    int j;
    for(i=0;i<cantUsuarios;i++)
    {
        if(usuarios[i].estado == 1)
        {
            printf("%s ", usuarios[i].nombre);
            for(j=0;j<cantSeries;j++)
            {
//                if(series[j].idSerie == usuarios[i].idSerie && series[j].estado == 1)
                {
//                    printf("%s", series[j].nombre);
                    break;
                }
            }
            printf("\n");

        }
    }
}

void mostrarSerieConSusUsuarios(eProductos series[], int cantSeries, eUsuario usuarios[], int cantUsuarios)
{
    int i;
    int j;
    for(i=0;i<cantSeries;i++)
    {
        if(series[i].estado == 1)
        {
            printf("%s ",series[i].nombre);
            for(j=0;j<cantUsuarios;j++)
            {
//                if(series[i].idSerie == usuarios[j].idSerie && usuarios[j].estado == 1)
                {
                    printf("%s ",usuarios[j].nombre);
                }
            }
            printf("\n");

        }
    }
}

