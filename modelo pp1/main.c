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
            if(index == 0)
            {
                printf("Usuario ingresado\n\n");
            }
            else
            {
                printf("No hay lugar\n\n");
            }
            break;

        case 2:
            index = eUsu_modificacion(listaDeUsuarios, TAMUSUARIOS);
            if(index == 0)
            {
                printf("Usuario modificado\n\n");
            }
            else
            {
                printf("ID incorrecto\n\n");
            }
            break;

        case 3:
            index = eUsu_baja(listaDeUsuarios, listaDeProductos, TAMUSUARIOS, TAMPRODUCTOS);
            if(index == 0)
            {
                printf("Usuario dado de baja\n\n");
            }
            else
            {
                printf("ID incorrecto\n\n");
            }
            break;

        case 4:
            index = eProd_alta(listaDeProductos, listaDeUsuarios, TAMPRODUCTOS, TAMUSUARIOS);
            if(index == 0)
            {
                printf("Producto ingresado\n\n");
            }
            else if(index == -3)
            {
                printf("ID incorrecto\n\n");
            }
            else
            {
                printf("No hay lugar\n\n");
            }
            break;

        case 5:
            index = eProd_modificacion(listaDeProductos,listaDeUsuarios,TAMPRODUCTOS,TAMUSUARIOS);
            if(index == 0)
            {
                printf("Producto modificado\n\n");
            }
            else if(index == -3)
            {
                printf("ID de producto incorrecto\n\n");
            }
            else
            {
                printf("ID de usuario incorrecto\n\n");
            }
            break;

        case 6:

        case 7: //pedir calif
                //prom = ((prom * cont) + calif) / (cont + 1)
                //cont++
            break;
        }

    }
    while(opcion!=11);

    return 0;
}
