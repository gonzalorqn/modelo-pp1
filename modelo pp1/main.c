#include <stdio.h>
#include <stdlib.h>
#include "Usuarios.h"
#define TAMUSUARIOS 100
#define TAMPRODUCTOS 1000

int main()
{
    eProductos listaDeProductos[TAMPRODUCTOS];
    eUsuario listaDeUsuarios[TAMUSUARIOS];

    eProd_init(listaDeProductos, TAMPRODUCTOS);
    eProd_hardCode(listaDeProductos);

    eUsu_init(listaDeUsuarios,TAMUSUARIOS);
    eUsu_hardCode(listaDeUsuarios);

    int opcion;
    int index;
    do
    {
        printf("1. ALTAS DE USUARIO\n2. MODIFICAR DATOS DEL USUARIO\n3. BAJA DEL USUARIO\n4. PUBLICAR PRODUCTO\n5. MODIFICAR PUBLICACION\n6. CANCELAR PUBLICACION\n7. COMPRAR PRODUCTO\n8. LISTAR PUBLICACIONES DE USUARIO\n9. LISTAR PUBLICACIONES\n10. LISTAR USUARIOS\n11. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            index = eUsu_alta(listaDeUsuarios, TAMUSUARIOS);
            if(index == -2)
            {
                printf("No hay lugar\n");
            }
            else
            {
                printf("Usuario ingresado\n");
            }

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:
            break;
        }

    }
    while(opcion!=11);

    return 0;
}
