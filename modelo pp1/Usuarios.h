
#include "Productos.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    char password[50];
    int idProducto;
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

void mostrarListaUsuarios(eUsuario[], int);
void mostrarUsuarioConSuSerie(eUsuario[], int, eProductos[], int);
void mostrarSerieConSusUsuarios(eProductos[], int, eUsuario[], int);
int buscarIntUsuarios(eUsuario[], int, int);
int bajaUsuario(eUsuario[], int);
