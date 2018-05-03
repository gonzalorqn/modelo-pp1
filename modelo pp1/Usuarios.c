#include <stdio.h>
#include <string.h>
#include "Usuarios.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};

    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }

}

void mostrarListaUsuarios(eUsuario usuarios[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(usuarios[i].estado == 1)
        {
            printf("%d %s %d\n",usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].idSerie);
        }
    }
}

void mostrarUsuarioConSuSerie(eUsuario usuarios[], int cantUsuarios, eSerie series[], int cantSeries)
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
                if(series[j].idSerie == usuarios[i].idSerie && series[j].estado == 1)
                {
                    printf("%s", series[j].nombre);
                    break;
                }
            }
            printf("\n");

        }
    }
}

void mostrarSerieConSusUsuarios(eSerie series[], int cantSeries, eUsuario usuarios[], int cantUsuarios)
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
                if(series[i].idSerie == usuarios[j].idSerie && usuarios[j].estado == 1)
                {
                    printf("%s ",usuarios[j].nombre);
                }
            }
            printf("\n");

        }
    }
}

int buscarLibreUsuario(eUsuario usuarios[], int tam)
{
    int index=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(usuarios[i].estado == 0)
        {
            index=i;
            break;
        }
    }

    return index;
}

int cargarUsuario(eUsuario usuarios[], int tam)
{
    int index;
    index = buscarLibreUsuario(usuarios, tam);

    if(index!=-1)
    {
        printf("Ingrese ID usuario: ");
        scanf("%d", &usuarios[index].idUsuario);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(usuarios[index].nombre);
        printf("Ingrese ID serie que ve: ");
        scanf("%d", &usuarios[index].idSerie);
        usuarios[index].estado=1;
    }

    return index;
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
