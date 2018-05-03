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
    int idProducto[5] = {1,2,3,4,5};
    int contCalif[5] = {5,2,13,20,0};
    float promCalif[5] = {10,8,7.5,9.3,0};

    int i;

    for(i=0; i<5; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idProducto=idProducto[i];
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
    char nombre[50];
    char password[50];
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

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(usuarios[indice].nombre);
                printf("Ingrese password: ");
                fflush(stdin);
                gets(usuarios[indice].password);
                usuarios[indice].idUsuario = id;
                usuarios[indice].estado = 1;
            //}
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
    char nombre[50];
    char password[50];
    int id;
    int indice;

    if(limite > 0 && usuarios != NULL)
    {
        retorno = -2;
        printf("Ingrese ID a modificar: ")
        scanf("%d", &id);

        indice = eUsu_buscarPorId(usuarios,limite,id);

        if(indice == -2)
        {
            printf("ID incorrecto");
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

void mostrarListaUsuarios(eUsuario usuarios[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(usuarios[i].estado == 1)
        {
//            printf("%d %s %d\n",usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].idSerie);
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



int buscarIntUsuarios(eUsuario usuarios[], int tam, int cual)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(usuarios[i].idUsuario==cual)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaUsuario(eUsuario usuarios[], int tam)
{
    int numeroUsuario;
    int index = -1;

    printf("Ingrese usuario a dar de baja: ");
    scanf("%d", &numeroUsuario);

    index = buscarIntUsuarios(usuarios,tam,numeroUsuario);

    if(index!=-1)
    {
        usuarios[index].estado = 0;
    }
    return index;
}
