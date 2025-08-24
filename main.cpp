#include <iostream>

#include "Cafe.h"
#include <string>
#include <iomanip>  // Formateo de punto flotante
#include <iostream>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;


void mostrarMenuPrincipal()
{
    cout << "===== TecnoCafe - Menu Principal =====\n";
    cout << "1. Registrar producto al pedido\n";
    cout << "2. Eliminar un producto del pedido\n"; // Nueva opcion
    cout << "3. Ver resumen del pedido\n"; // Se movio la opcion
    cout << "4. Finalizar y pagar\n"; // Se movio la opcion
    cout << "5. Prediligenciar productos de demostracion\n"; // Se movio la opcion
    cout << "6. Mostrar el producto mas caro del pedido\n"; // Nueva opcion
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu()
{
    int opcion;
    cin >> opcion;
    // Validacion ajustada para las nuevas opciones
    while (opcion < 1 || opcion > 7)
    {
        cout << "Opcion invalida. Intente de nuevo (1-7): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}



int main()
{

    // Estos son arreglos estáticos en C++ de tamaño fijo, una característica heredada de C.
    // A diferencia de las listas en Python, los arreglos estáticos tienen un tamaño predefinido (MAX_ITEMS en este caso)
    // que no puede cambiarse durante la ejecución del programa.
    // Los elementos se acceden mediante índices, comenzando desde 0.
    // Es importante asegurarse de no acceder a índices fuera del rango permitido, ya que esto puede causar errores graves (comportamiento indefinido).
    int codigos[MAX_ITEMS] = {0};
    int cantidades[MAX_ITEMS] = {0};

    int cantidadItemsRegistrados = 0;



    int opcion = 0;
    do
    {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion)
        {
        case 1:
            {
                registrarProducto(codigos, cantidades, cantidadItemsRegistrados);
                break;
            }
        case 2:
            {
                eliminarProducto(codigos, cantidades, cantidadItemsRegistrados);
                break;
            }
        case 3:
            {
                double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
                cout << fixed << setprecision(2);
                cout << "\nSubtotal actual: $" << subtotal << "\n\n";
                break;
            }
        case 4:
            {
                if (cantidadItemsRegistrados == 0)
                {
                    cout << "\nNo hay productos en el pedido.\n\n";
                    break;
                }
                double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
                int tipoUsuario = leerTipoUsuario();
                double porcentajeDescuento = obtenerPorcentajeDescuento(tipoUsuario);
                mostrarResumenPedido(codigos, cantidades, cantidadItemsRegistrados, porcentajeDescuento);
                double total = calcularTotal(subtotal, porcentajeDescuento);
                //En C++, fixed es un manipulador de flujo que se utiliza con objetos de salida como std::cout para configurar el formato de los números de punto flotante. Cuando se usa fixed, los números de punto flotante se muestran en notación decimal fija en lugar de notación científica (la predeterminada para números muy grandes o pequeños).
                cout << fixed << setprecision(2);
                cout << "Total a pagar: $" << total << "\n\n";
                break;
            }
        case 5:
            {
                prediligenciarProductosDemo(codigos, cantidades, cantidadItemsRegistrados);
                break;
            }
        case 6:
            {
                mostrarProductoMasCaro(codigos, cantidades, cantidadItemsRegistrados);
                break;
            }
        case 7:
            {
                cout << "\nSaliendo del sistema. ¡Hasta pronto!\n";
                break;
            }
        }
    }
    while (opcion != 7);

    return 0;
}