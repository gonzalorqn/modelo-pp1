
typedef struct
{
    int idProducto;
    char nombre[50];
    float precio;
    int cantidadVendida;
    int stock;
    int estado;
}eProductos;

int eProd_init(eProductos productos[], int limite);
void eProd_hardCode(eProductos productos[]);
void mostrarListaSeries(eProductos[], int);
int buscarLibreProductos(eProductos[], int);
int cargarSerie(eProductos[], int);
int buscarIntSeries(eProductos[], int, int);
int bajaSerie(eProductos[], int);
