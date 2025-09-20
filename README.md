

# 🍔 Aplicación de Pedidos - Snackly

Este proyecto es una **aplicación en C** que simula un sistema básico de pedidos para un negocio de comidas rápidas llamado **Snackly**.  
Permite a los usuarios visualizar el menú, agregar productos a un carrito, calcular totales con impuestos y costos de domicilio, y finalmente confirmar el pedido.

---

## 📌 Funcionalidades principales

1. **Mostrar menú de productos**  
   - Se presenta un catálogo de hasta 6 productos predefinidos (ejemplo: pizza, hamburguesa, sushi, etc.) con sus respectivos precios.

2. **Agregar productos al carrito**  
   - El usuario puede seleccionar un producto por su **ID** e indicar la cantidad deseada.  
   - Si el producto ya estaba en el carrito, se suman las cantidades.  
   - El carrito puede almacenar hasta **20 ítems**.

3. **Ver carrito y calcular total**  
   - Se muestran los productos seleccionados, sus cantidades, subtotales y el costo final.  
   - Se incluye:  
     - **Subtotal** de los productos.  
     - **Costo de domicilio**:  
       - Gratis para compras ≥ 30,000  
       - $5000 para compras menores a 30,000  
     - **IVA (19%)** aplicado al subtotal + domicilio.  
     - **Total final** a pagar.

4. **Confirmar pedido**  
   - El usuario puede confirmar el pedido (S/N).  
   - Si confirma, se muestra un mensaje de éxito.

5. **Salir del sistema**  
   - Finaliza la aplicación.

---

## 🛠️ Tecnologías utilizadas
- Lenguaje: **C**
- Librerías estándar: `stdio.h`
- Conceptos aplicados:
  - **Estructuras (`struct`)** para manejar productos y carrito.  
  - **Arreglos** para almacenar catálogo y carrito.  
  - **Funciones** para modularizar el código.  
  - **Control de flujo** con `switch` y `do-while`.

---

## ▶️ Ejecución del programa

1. Compilar el código:  
   ```bash
   gcc snackly.c -o snackly

2. Ejecutar el programa:

./snackly


3. Navegar por el menú interactivo y simular un pedido.




---

📖 Ejemplo de uso

--- Menú de opciones ---
1. Ver menú de productos
2. Agregar producto al carrito
3. Ver carrito y total
4. Confirmar pedido
5. Salir
Seleccione una opción (1-5): 1

Catálogo de productos:
ID: 1, Producto: Pizza familiar, Precio: 40000.00
ID: 2, Producto: Hamburguesa, Precio: 15000.00
ID: 3, Producto: sushi, Precio: 80000.00
ID: 4, Producto: salchipapa, Precio: 18000.00
ID: 5, Producto: perro caliente, Precio: 14000.00
ID: 6, Producto: cocacola, Precio: 4000.00


---

🎯 Objetivo del proyecto

Este programa fue creado con fines didácticos, para practicar:

El manejo de estructuras y arreglos en C.

La creación de menús interactivos en consola.

La implementación de un sistema simple de carrito de compras.



---


