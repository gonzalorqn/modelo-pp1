
typedef struct
{
    int idProducto;
    char nombre[50];
    int idUsuario;
    float precio;
    int cantidadVendida;
    int stock;
    int estado;
}eProductos;

int eProd_init(eProductos productos[], int limite);
void eProd_hardCode(eProductos productos[]);
int eProd_buscarLugarLibre(eProductos productos[],int limite);
int eProd_siguienteId(eProductos productos[],int limite);
int eProd_buscarPorId(eProductos productos[] ,int limite, int id);
