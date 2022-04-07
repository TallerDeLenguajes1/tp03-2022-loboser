#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char * TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char * TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char * NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto * Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
};

int costoTotalDeUnProducto(struct Producto producto);

int main(){
    srand(time(NULL));

    int cantidadDeClientes;
    struct Cliente * ptrCliente;
    struct Cliente aux;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantidadDeClientes);

    ptrCliente = (struct Cliente *) malloc(cantidadDeClientes*sizeof(struct Cliente));

    int ProductoIdAux = 1;

    for (int i = 0; i < cantidadDeClientes; i++)
    {
        aux.ClienteID = i+1;
        printf("Ingrese el nombre del cliente: ");
        gets(aux.NombreCliente);
        aux.CantidadProductosAPedir = 1 + rand() % 6;
        aux.Productos[aux.CantidadProductosAPedir];

        for (int c = 0; c < aux.CantidadProductosAPedir; c++)
        {
            aux.Productos[c].ProductoID = ProductoIdAux;
            aux.Productos[c].Cantidad = 1 + rand() % 10;
            aux.Productos[c].TipoProducto = TiposProductos[rand() % 6];
            aux.Productos[c].PrecioUnitario = 11 + rand() % 100;
            ProductoIdAux++;
        }

        ptrCliente[i] = aux;
    }
    
    for (int i = 0; i < cantidadDeClientes; i++)
    {
        int totalFinal = 0;
        printf("ID del Cliente: %d\n", ptrCliente[i].ClienteID);
        printf("Nombre: %s\n", ptrCliente[i].NombreCliente);
        printf("Cantidad de Productos a pedir: %d\n", ptrCliente[i].CantidadProductosAPedir);
        printf("Productos que pidio: \n\n");

        for (int c = 0; c < ptrCliente[i].CantidadProductosAPedir; i++)
        {
            int total = costoTotalDeUnProducto(ptrCliente[i].Productos[c]);
            printf("ID: %d\n", ptrCliente[i].Productos[c].ProductoID);
            printf("Tipo: %s\n", ptrCliente[i].Productos[c].TipoProducto);
            printf("Cantidad: %d\n", ptrCliente[i].Productos[c].Cantidad);
            printf("Precio Unitario: %d\n", ptrCliente[i].Productos[c].PrecioUnitario);
            printf("Precio Final: %d\n\n", total);
            totalFinal += total;
        }
            printf("Precio Total Final: %d\n\n", totalFinal);
    }

    system("pause");
    return 0;
}

int costoTotalDeUnProducto(struct Producto producto){
    return producto.Cantidad*producto.PrecioUnitario;
}