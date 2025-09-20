/*APLICACION DE PEDIDOS Snackly
*/
#include <stdio.h>

#define MAX_PRODUCTOS 6  // Definimos el número máximo de productos en el catálogo

// Estructura para representar un producto del catálogo
typedef struct {
    int id;             // Identificador único del producto
    char nombre[50];    // Nombre del producto
    float precio;       // Precio del producto
} Producto;

// Estructura para representar un ítem en el carrito (producto + cantidad)
typedef struct {
    Producto producto;  // El producto agregado al carrito
    int cantidad;       // Cantidad del producto en el carrito
} ItemCarrito;

// Declaración del catálogo de productos con 6 productos predefinidos
Producto catalogo[MAX_PRODUCTOS] = {
    {1, "Pizza familiar", 40000.0},       // Producto 1: Pizza, precio 200.0
    {2, "Hamburguesa", 15000.0}, // Producto 2: Hamburguesa, precio 150.0
    {3, "sushi", 80000.0},        // Producto 3: Tacos, precio 80.0
    {4, "salchipapa", 18000.0},       // Producto 4: Pasta, precio 120.0
    {5, "perro caliente", 14000.0},     // Producto 5: Ensalada, precio 70.0
    {6, "cocacola", 4000.0}          // Producto 6: Soda, precio 30.0
};

// Función para mostrar el catálogo de productos
void verMenuProductos() {
    printf("\nCatálogo de productos:\n");
    // Recorrer el catálogo e imprimir los productos disponibles
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("ID: %d, Producto: %s, Precio: %.2f\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
    }
}

// Función para agregar un producto al carrito
#define MAX_CARRITO 20  // Capacidad máxima del carrito, más grande que MAX_PRODUCTOS

// Cambiar la declaración del carrito en main a:
// ItemCarrito carrito[MAX_CARRITO];

void agregarAlCarrito(ItemCarrito carrito[], int *cantidadCarrito) {
    int idProducto, cantidad;

    if (*cantidadCarrito >= MAX_CARRITO) {
        printf("El carrito está lleno. No puede agregar más productos.\n");
        return;
    }

    printf("\nIngrese el ID del producto que desea agregar: ");
    scanf("%d", &idProducto);

    // Buscar el producto en el catálogo
    int encontradoProducto = 0;
    Producto prodSeleccionado;

    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (catalogo[i].id == idProducto) {
            prodSeleccionado = catalogo[i];
            encontradoProducto = 1;
            break;
        }
    }

    if (!encontradoProducto) {
        printf("ID de producto no válido.\n");
        return;
    }

    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("La cantidad debe ser mayor a 0.\n");
        return;
    }

    // Verificar si el producto ya está en el carrito para sumar la cantidad
    for (int i = 0; i < *cantidadCarrito; i++) {
        if (carrito[i].producto.id == idProducto) {
            carrito[i].cantidad += cantidad;
            printf("Se sumaron %d unidades al producto %s en el carrito.\n", cantidad, carrito[i].producto.nombre);
            return;  // Terminar la función porque ya sumamos la cantidad
        }
    }

    // Si el producto no estaba en el carrito, agregarlo como nuevo ítem
    if (*cantidadCarrito < MAX_CARRITO) {
        carrito[*cantidadCarrito].producto = prodSeleccionado;
        carrito[*cantidadCarrito].cantidad = cantidad;
        (*cantidadCarrito)++;
        printf("Producto agregado al carrito.\n");
    } else {
        printf("No se puede agregar más productos, carrito lleno.\n");
    }
}
//funcion para ver el carrito
void verCarrito(ItemCarrito carrito[], int cantidadCarrito) {
    if (cantidadCarrito == 0) {
        printf("\nEl carrito está vacío.\n");
        return;
    }

    float subtotal = 0.0;  // Suma de todos los productos antes de domicilio e impuestos
    float domicilio = 0.0;
    float iva = 0.0;
    float total = 0.0;

    printf("\nCarrito de compras:\n");

    // Mostrar productos en el carrito y calcular subtotal
    for (int i = 0; i < cantidadCarrito; i++) {
        float itemSubtotal = carrito[i].producto.precio * carrito[i].cantidad;
        printf("Producto: %s, Cantidad: %d, Precio unitario: %.2f, Subtotal: %.2f\n",
               carrito[i].producto.nombre,
               carrito[i].cantidad,
               carrito[i].producto.precio,
               itemSubtotal);
        subtotal += itemSubtotal;
    }

    printf("\nSubtotal: %.2f\n", subtotal);

    // Evaluar si se aplica el costo de domicilio (automático)
    if (subtotal >= 30000.0) {
        printf("Domicilio: GRATIS (por compras mayores o iguales a 30000.00)\n");
        domicilio = 0.0;
    } else {
        domicilio = 5000.0;
        printf("Domicilio: %.2f (por compras menores a 30000.00)\n", domicilio);
    }

    // Calcular IVA obligatorio (19%)
    iva = (subtotal + domicilio) * 0.19;
    printf("IVA (19%%): %.2f\n", iva);

    // Calcular el total final
    total = subtotal + domicilio + iva;

    // Mostrar el total con todo incluido
    printf("\nTOTAL FINAL A PAGAR: %.2f\n", total);
}


// Función para confirmar el pedido
void confirmarPedido(ItemCarrito carrito[], int cantidadCarrito) {
    if (cantidadCarrito == 0) {
        printf("\nEl carrito está vacío. No se puede confirmar el pedido.\n");  // No se puede confirmar si el carrito está vacío
        return;
    }

    char opcion;
    printf("\n¿Está seguro que desea confirmar el pedido (S/N)? ");
    scanf(" %c", &opcion);  // Leer la respuesta del usuario

    // Si el usuario confirma, mostrar un mensaje de éxito
    if (opcion == 'S' || opcion == 's') {
        printf("\n¡Pedido confirmado con éxito! ¡Gracias por su compra!\n");
    } else {
        printf("\nPedido no confirmado.\n");
    }
}

// Función principal con el menú interactivo
int main() {
    ItemCarrito carrito[MAX_PRODUCTOS];  // Arreglo para almacenar los productos del carrito
    int cantidadCarrito = 0;  // Contador de productos en el carrito
    int opcion;

    // Ciclo principal que se repite hasta que el usuario elija salir
    do {
        // Mostrar el menú de opciones al usuario
        printf("\n--- Menú de opciones ---\n");
        printf("1. Ver menú de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito y total\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Seleccione una opción (1-5): ");
        scanf("%d", &opcion);  // Leer la opción seleccionada por el usuario

        // Usar un switch para manejar las diferentes opciones del menú
        switch (opcion) {
            case 1:
                verMenuProductos();  // Mostrar el catálogo de productos
                break;
            case 2:
                agregarAlCarrito(carrito, &cantidadCarrito);  // Agregar un producto al carrito
                break;
            case 3:
                verCarrito(carrito, cantidadCarrito);  // Mostrar el carrito y el total
                break;
            case 4:
                confirmarPedido(carrito, cantidadCarrito);  // Confirmar el pedido
                break;
            case 5:
                printf("\n¡Hasta pronto!\n");  // Salir del programa
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");  // Manejo de opciones inválidas
                break;
        }
    } while (opcion != 5);  // El ciclo continuará hasta que el usuario elija salir

    return 0;  // Fin del programa
}
