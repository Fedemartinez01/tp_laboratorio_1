/*
 * tp1biblioteca.h
 *
 *  Created on: 2 sept 2021
 *      Author: FLIA TOPOS
 */

#ifndef TP1BIBLIOTECA_H_
#define TP1BIBLIOTECA_H_

///Muestra el menú correspondiente segun los numeros ingresados y pide al usuario una opcion
/// @param num1
/// @param num2
/// @param ingreso1
/// @param ingreso2
/// @return retorna la opcion ingresada por el usuario
int Menu(float num1, float num2, int ingreso1, int ingreso2);

/// Pide un numero flotante y lo retorna
/// @param mensaje
/// @return retorna el numero flotante ingresado
float PedirNumero(char mensaje[]);

//VALIDACIONES
/// Valida si el numero ingresado es un entero
/// @param num
/// @return si devuelve 1 el numero es entero, si devuelve 0 es decimal
int ValidarEntero(float num);

///Valida si el numero es positivo
/// @param num
/// @return si devuelve 1, el numero ingresado es positivo, si devuelve 0 es negativo
int ValidarPositivo(float num);


//OPERACIONES
/// Hace la suma de los numeros ingresados
/// @param num1
/// @param num2
/// @return retorna el resultado
float Sumar(float num1, float num2);


/// Hace la resta de los numeros ingresados
/// @param num1
/// @param num2
/// @return retorna el resultado
float Restar(float num1, float num2);


/// Hace la multiplicacion de los numeros ingresados
/// @param num1
/// @param num2
/// @return retorna el resultado
float Multiplicar(float num1, float num2);



/// Hace la division de los numeros ingresados,
/// siempre y cuando no se divida por cero
/// @param num1
/// @param num2
/// @return retorna el resultado
float Dividir(float num1, float num2);

/// Calcula el factorial de los numeros ingresados,
/// verificando que los numeros a calcular no sean negativos,
/// decimales, ni mayores a 13
/// @param num1
/// @param num2
/// @return retorna el resultado
int Factorial(float num);


//MOSTRAR

///Muestra la suma y el resultado
/// @param num1
/// @param num2
/// @param resultado
void MostrarSuma(float num1, float num2, float resultado);

///Muestra la resta y el resultado
/// @param num1
/// @param num2
/// @param resultado
void MostrarResta(float num1, float num2, float resultado);

///Muestra la multiplicacion y el resultado
/// @param num1
/// @param num2
/// @param resultado
void MostrarMultiplicacion(float num1, float num2, float resultado);

///Muestra la division y el resultado, si se trata de dividir por cero muestra un error
/// @param num1
/// @param num2
/// @param resultado
void MostrarDivision(float num1, float num2, float resultado);

///Muestra el factorial, si se trata de hacer el factorial de un numero negativo decimal, o mayor a 13 muestra un error
/// @param num
/// @param resultado
void MostrarFactorial(float num, float resultado);



#endif /* TP1BIBLIOTECA_H_ */


