//
// Created by lupassos yes sirr on 22/08/2025.
//

#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// --- Constantes de precios ---
/**
 * @brief Precio del producto Tinto.
 */
const int PRECIO_TINTO = 1500;

/**
 * @brief Precio del producto Cappuccino.
 */
const int PRECIO_CAPPUCCINO = 4500;

/**
 * @brief Precio del producto Pandebono.
 */
const int PRECIO_PANDEBONO = 3000;

/**
 * @brief Precio del producto Sándwich.
 */
const int PRECIO_SANDWICH = 8500;


//Precio del nuevo producto.
/**
 * @brief Precio del producto Pastel.
 */
const int PRECIO_PASTEL = 6000;


// --- Descuentos (% expresado de 0.0 a 1.0) ---
/**
 * @brief Descuento aplicado a estudiantes (10%).
 */
const double DESCUENTO_ESTUDIANTE = 0.10;

/**
 * @brief Descuento aplicado a profesores (5%).
 */
const double DESCUENTO_PROFESOR = 0.05;

/**
 * @brief Descuento aplicado a visitantes (0%).
 */
const double DESCUENTO_VISITANTE = 0.00;

/**
 * @brief Máximo número de ítems distintos que se pueden registrar en un pedido.
 */
const int MAX_ITEMS = 50;

// --- Declaraciones de funciones ---

/**
 * @brief Muestra la carta de productos disponibles con sus precios.
 */
void mostrarCartaProductos();

/**
 * @brief Lee el código del producto ingresado por el usuario.
 * @return Código del producto seleccionado.
 */
int leerCodigoProducto();

/**
 * @brief Lee la cantidad de un producto ingresada por el usuario.
 * @return Cantidad del producto seleccionada.
 */
int leerCantidadProducto();

/**
 * @brief Obtiene el precio de un producto dado su código.
 * @param codigoProducto Código del producto.
 * @return Precio del producto.
 */
int obtenerPrecioPorCodigo(int codigoProducto);

/**
 * @brief Obtiene el nombre de un producto dado su código.
 * @param codigoProducto Código del producto.
 * @return Nombre del producto.
 */
string obtenerNombreProducto(int codigoProducto);

/**
 * @brief Registra un producto en el pedido.
 * @param codigos Arreglo de códigos de productos en el pedido.
 * @param cantidades Arreglo de cantidades de productos en el pedido.
 * @param cantidadItemsRegistrados Referencia al número de ítems registrados en el pedido.
 */
void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados);

/**
 * @brief Calcula el subtotal del pedido actual.
 * @param codigos Arreglo de códigos de productos en el pedido.
 * @param cantidades Arreglo de cantidades de productos en el pedido.
 * @param cantidadItemsRegistrados Número de ítems registrados en el pedido.
 * @return Subtotal del pedido.
 */
double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);

/**
 * @brief Lee el tipo de usuario (estudiante, profesor, visitante).
 * @return Tipo de usuario seleccionado.
 */
int leerTipoUsuario();

/**
 * @brief Obtiene el porcentaje de descuento según el tipo de usuario.
 * @param tipoUsuario Tipo de usuario (estudiante, profesor, visitante).
 * @return Porcentaje de descuento correspondiente.
 */
double obtenerPorcentajeDescuento(int tipoUsuario);

/**
 * @brief Calcula el total a pagar aplicando el descuento al subtotal.
 * @param subtotal Subtotal del pedido.
 * @param porcentajeDescuento Porcentaje de descuento a aplicar.
 * @return Total a pagar.
 */
double calcularTotal(double subtotal, double porcentajeDescuento);

/**
 * @brief Muestra un resumen del pedido actual.
 * @param codigos Arreglo de códigos de productos en el pedido.
 * @param cantidades Arreglo de cantidades de productos en el pedido.
 * @param cantidadItemsRegistrados Número de ítems registrados en el pedido.
 * @param porcentajeDescuento Porcentaje de descuento aplicado.
 */
void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento);

/**
 * @brief Carga un pedido de demostración con productos predefinidos.
 * @param codigos Arreglo de códigos de productos en el pedido.
 * @param cantidades Arreglo de cantidades de productos en el pedido.
 * @param cantidadItemsRegistrados Referencia al número de ítems registrados en el pedido.
 */
void prediligenciarProductosDemo(int codigos[], int cantidades[], int& cantidadItemsRegistrados);

#endif //CAFE_H