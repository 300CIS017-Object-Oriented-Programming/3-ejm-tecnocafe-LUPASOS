//
// Created by Me on 20/08/2025.
//
#include "Cafe.h"


void mostrarCartaProductos()
{
    cout << "\n--- Carta de productos ---\n";
    cout << "1. Tinto       $" << PRECIO_TINTO << "\n";
    cout << "2. Cappuccino  $" << PRECIO_CAPPUCCINO << "\n";
    cout << "3. Pandebono   $" << PRECIO_PANDEBONO << "\n";
    cout << "4. Sandwich    $" << PRECIO_SANDWICH << "\n";
    // Agregar un nuevo producto a la carta
    cout << "5. Pastel      $" << PRECIO_PASTEL << "\n";
}

int leerCodigoProducto()
{
    cout << "Ingrese el codigo del producto (1-5): ";
    int codigo;
    cin >> codigo;
    while (codigo < 1 || codigo > 5)
    {
        cout << "Codigo inválido. Intente de nuevo (1-5): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadProducto()
{
    cout << "Ingrese la cantidad (1-20): ";
    int cantidad;
    cin >> cantidad;
    while (cantidad < 1 || cantidad > 20)
    {
        cout << "Cantidad invalida. Intente de nuevo (1-20): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

int obtenerPrecioPorCodigo(int codigoProducto)
{
    int precio;
    switch (codigoProducto)
    {
    case 1:
        {
            precio = PRECIO_TINTO;
            break;
        }
    case 2:
        {
            precio = PRECIO_CAPPUCCINO;
            break;
        }
    case 3:
        {
            precio = PRECIO_PANDEBONO;
            break;
        }
    case 4:
        {
            precio = PRECIO_SANDWICH;
            break;
        }
    case 5:
        {
            precio = PRECIO_PASTEL;
            break;
        }
    default:
        {
            precio = 0;
            break;
        }
    }
    // Asegurar que el precio sea positivo como buena práctica
    return (precio > 0) ? precio : 0;
}

string obtenerNombreProducto(int codigoProducto)
{
    switch (codigoProducto)
    {
    case 1:
        {
            return "Tinto";
        }
    case 2:
        {
            return "Cappuccino";
        }
    case 3:
        {
            return "Pandebono";
        }
    case 4:
        {
            return "Sándwich";
        }
    case 5:
        {
            return "Pastel";
        }
    default:
        {
            return "Desconocido";
        }
    }
}

void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados >= MAX_ITEMS)
    {
        cout << "No es posible registrar más ítems en el pedido.\n";
        return;
    }
    mostrarCartaProductos();
    int codigo = leerCodigoProducto();
    int cantidad = leerCantidadProducto();

    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            cantidades[i] += cantidad;
            cout << "Producto actualizado: " << obtenerNombreProducto(codigo)
                << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }

    codigos[cantidadItemsRegistrados] = codigo;
    cantidades[cantidadItemsRegistrados] = cantidad;
    cantidadItemsRegistrados++;

    cout << "Producto agregado: " << obtenerNombreProducto(codigo)
        << " x" << cantidad << "\n\n";
}

void eliminarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados == 0)
    {
        cout << "\nEl pedido esta vacio, no hay productos para eliminar.\n\n";
        return;
    }

    mostrarResumenPedido(codigos, cantidades, cantidadItemsRegistrados, 0.0);
    cout << "Ingrese el codigo del producto a eliminar: ";
    int codigoEliminar;
    cin >> codigoEliminar;

    int indiceEliminar = -1;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigoEliminar)
        {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1)
    {
        cout << "\nEl producto con el codigo " << codigoEliminar << " no se encuentra en el pedido.\n\n";
        return;
    }

    // Desplazar los elementos para llenar el espacio vacío
    for (int i = indiceEliminar; i < cantidadItemsRegistrados - 1; i++)
    {
        codigos[i] = codigos[i + 1];
        cantidades[i] = cantidades[i + 1];
    }

    cantidadItemsRegistrados--;
    cout << "\nProducto eliminado del pedido.\n\n";
}

double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        int precioUnitario = obtenerPrecioPorCodigo(codigos[i]);
        subtotal += precioUnitario * cantidades[i];
    }
    return subtotal;
}

int leerTipoUsuario()
{
    cout << "Tipo de usuario (1=Estudiante, 2=Profesor, 3=Visitante, 4=Senior): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 4)
    {
        cout << "Opción inválida. Intente de nuevo (1-4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoUsuario)
{
    if (tipoUsuario == 1)
    {
        return DESCUENTO_ESTUDIANTE;
    }
    if (tipoUsuario == 2)
    {
        return DESCUENTO_PROFESOR;
    }
    if (tipoUsuario == 3)
    {
        return DESCUENTO_VISITANTE;
    }
    if (tipoUsuario == 4)
    {
        return DESCUENTO_SENIOR;
    }
    return 0.0; // Caso por defecto
}

double calcularTotal(double subtotal, double porcentajeDescuento)
{
    return subtotal * (1.0 - porcentajeDescuento);
}

void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento)
{
    cout << "\n===== Resumen del Pedido =====\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        string nombre = obtenerNombreProducto(codigos[i]);
        int precio = obtenerPrecioPorCodigo(codigos[i]);
        double parcial = precio * cantidades[i];
        subtotal += parcial;
        cout << "- " << nombre << " x" << cantidades[i] << " = $" << parcial << "\n";
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << (porcentajeDescuento * 100) << "%\n";
}

void prediligenciarProductosDemo(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    // Limpiar pedido actual si existe
    cantidadItemsRegistrados = 0;

    // Añadir productos de ejemplo
    codigos[0] = 1;  // Tinto
    cantidades[0] = 2;

    codigos[1] = 3;  // Pandebono
    cantidades[1] = 3;

    codigos[2] = 4;  // Sandwich
    cantidades[2] = 1;

    // Agregar un nuevo producto a la demostración
    codigos[3] = 5; // Pastel
    cantidades[3] = 4;


    cantidadItemsRegistrados = 4;

    cout << "\nSe han cargado productos de ejemplo en el pedido:\n";
    cout << "- 2 Tintos\n";
    cout << "- 3 Pandebonos\n";
    cout << "- 1 Sándwich\n";
    // Agregamos el mensaje del nuevo producto
    cout << "- 4 Pasteles\n\n";
}

void mostrarProductoMasCaro(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    // Comprobar si hay productos en el pedido.
    if (cantidadItemsRegistrados == 0)
    {
        cout << "\nEl pedido esta vacio, no hay productos para comparar.\n\n";
        return;
    }

    // Inicializar el producto mas caro con el primer item del pedido.
    int codigoMasCaro = codigos[0];
    int precioMasCaro = obtenerPrecioPorCodigo(codigos[0]);

    // Recorrer el resto del pedido para encontrar el producto con el precio unitario mas alto.
    for (int i = 1; i < cantidadItemsRegistrados; i++)
    {
        int precioActual = obtenerPrecioPorCodigo(codigos[i]);
        if (precioActual > precioMasCaro)
        {
            precioMasCaro = precioActual;
            codigoMasCaro = codigos[i];
        }
    }

    // Mostrar el resultado.
    cout << "\n===== Producto Mas Caro =====\n";
    cout << "El producto mas caro en el pedido es: " << obtenerNombreProducto(codigoMasCaro)
        << " con un precio de $" << precioMasCaro << " por unidad.\n\n";
}
