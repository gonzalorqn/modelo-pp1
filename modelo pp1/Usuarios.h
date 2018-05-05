
#include "Productos.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    char password[50];
    int contCalificaciones;
    float promCalificaciones;
    int estado;
}eUsuario;

int eUsu_init(eUsuario usuarios[], int limite);
void eUsu_hardCode(eUsuario usuarios[]);
int eUsu_buscarLugarLibre(eUsuario usuarios[],int limite);
int eUsu_siguienteId(eUsuario usuarios[],int limite);
int eUsu_alta(eUsuario usuarios[],int limite);
int eUsu_buscarPorId(eUsuario usuarios[] ,int limite, int id);
int eUsu_modificacion(eUsuario usuarios[],int limite);
int eUsu_baja(eUsuario usuarios[],eProductos productos[],int limiteUsu,int limiteProd);
void eUsu_mostrarUno(eUsuario usuarios);
void eUsu_mostrar(eUsuario usuarios[], int cant);
int eProd_alta(eProductos productos[], eUsuario usuarios[],int limiteProd, int limiteUsu);
int eProd_modificacion(eProductos productos[],eUsuario usuarios[],int limiteProd,int limiteUsu);
void eUsu_mostrarUsuarioConSusProductos(eProductos productos[], int limiteProd, eUsuario usuarios[], int limiteUsu,int idUsu);

void mostrarUsuarioConSuSerie(eUsuario[], int, eProductos[], int);
void mostrarSerieConSusUsuarios(eProductos[], int, eUsuario[], int);
