
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

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);
void mostrarUsuarioConSuSerie(eUsuario[], int, eProductos[], int);
void mostrarSerieConSusUsuarios(eProductos[], int, eUsuario[], int);
int buscarLibreUsuario(eUsuario[], int);
int cargarUsuario(eUsuario[], int);
int buscarIntUsuarios(eUsuario[], int, int);
int bajaUsuario(eUsuario[], int);
