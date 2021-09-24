/*
 * tp1biblioteca.c
 *
 *  Created on: 2 sept 2021
 *      Author: FLIA TOPOS
 */


#include <stdio.h>
#include <stdlib.h>

#include "tp1biblioteca.h"


int Menu(float num1, float num2, int ingreso1, int ingreso2)
{
	int opcionIngresada;

	if(ingreso1 == 0 && ingreso2 == 0)
	{
		printf("\n\n1. Ingresar primer operando: A");
		printf("\n2. Ingresar segundo operando: B");
		printf("\n3. Calcular operaciones");
		printf("\n\ta)Sumar A + B");
		printf("\n\tb)Restar A - B");
		printf("\n\tc)Multiplicar A * B");
		printf("\n\td)Dividir A / B");
		printf("\n\te)Factorial de A");
		printf("\n\tf)Factorial de B");
	}
	else
	{
		if(ingreso1 == 1 && ingreso2 == 0)
		{
			printf("\n\n1. Ingresar primer operando: %.2f", num1);
			printf("\n2. Ingresar segundo operando: B ");
			printf("\n3. Calcular operaciones");
			printf("\n\ta)Sumar %.2f + B", num1);
			printf("\n\tb)Restar %.2f - B", num1);
			printf("\n\tc)Multiplicar %.2f * B", num1);
			printf("\n\td)Dividir %.2f / B", num1);
			printf("\n\te)Factorial de %.2f", num1);
			printf("\n\tf)Factorial de B");
		}
		else
		{
			if(ingreso1 == 0 && ingreso2 == 1)
			{
				printf("\n\n1. Ingresar primer operando: A ");
				printf("\n2. Ingresar segundo operando: %.2f ", num2);
				printf("\n\ta)Sumar A + %.2f ", num2);
				printf("\n\tb)Restar A - %.2f", num2);
				printf("\n\tc)Multiplicar A * %.2f", num2);
				printf("\n\td)Dividir A / %.2f", num2);
				printf("\n\te)Factorial de A");
				printf("\n\tf)Factorial de %.2f", num2);
			}
			else
			{
				printf("\n\n1. Ingresar primer operando: %.2f ", num1);
				printf("\n2. Ingresar segundo operando: %.2f ", num2);
				printf("\n3. Calcular operaciones");
				printf("\n\ta)Sumar %.2f + %.2f", num1, num2);
				printf("\n\tb)Restar %.2f - %.2f", num1, num2);
				printf("\n\tc)Multiplicar %.2f * %.2f", num1, num2);
				printf("\n\td)Dividir %.2f / %.2f", num1, num2);
				printf("\n\te)Factorial de %.2f", num1);
				printf("\n\tf)Factorial de %.2f", num2);
			}
		}
	}
	printf("\n4. Mostrar resultados");
	printf("\n5. Salir\n");
	printf("\nIngresar opcion: ");
	scanf("%d", &opcionIngresada);
	return opcionIngresada;
}


float PedirNumero(char mensaje[])
{
	float numero;
	printf(mensaje);
	scanf("%f", &numero);
	return numero;
}

//OPERACIONES
float Sumar(float num1, float num2)
{
	float resultadoSuma;
	resultadoSuma = num1 + num2;
	return resultadoSuma;
}

float Restar(float num1, float num2)
{
	float resultadoResta;
	resultadoResta = num1 - num2;
	return resultadoResta;
}

float Multiplicar(float num1, float num2)
{
	float resultadoMultiplicacion;
	resultadoMultiplicacion = num1 * num2;
	return resultadoMultiplicacion;
}

float Dividir(float num1, float num2)
{
	float resultadoDividision;
	if(num2 == 0 || num2==0)
	{
		resultadoDividision = 0;
	}
	else
	{
		resultadoDividision = num1 / num2;
	}
	return resultadoDividision;
}

int Factorial(float num)
{
	int b, factorial = 1;

	if(ValidarEntero(num) && ValidarPositivo(num) && num < 13)
	{
		for (b = num; b > 1; b--)
		{
			factorial = factorial * b;
		}
	}
	return factorial;
}


//MOSTRAR
void MostrarSuma(float num1, float num2, float resultado)
{
	printf("\n\tEl resultado de %.2f + %.2f = %.2f", num1, num2, resultado);
}

void MostrarResta(float num1, float num2, float resultado)
{
	printf("\n\tEl resultado de %.2f - %.2f = %.2f", num1, num2, resultado);
}

void MostrarMultiplicacion(float num1, float num2, float resultado)
{
	printf("\n\tEl resultado de %.2f * %.2f = %.2f", num1, num2, resultado);
}

void MostrarDivision(float num1, float num2, float resultado)
{
	if(num2 != 0 && num1 != 0)
	{
		printf("\n\tEl resultado de %.2f / %.2f = %.2f", num1, num2, resultado);
	}
	else
	{
		printf("\nNo se puede dividir por '0'");
	}
}

void MostrarFactorial(float num, float resultado)
{
	if(ValidarEntero(num) && ValidarPositivo(num) && num < 13)
	{
		printf("\n\tEl factorial de %.2f es: %.2f", num, resultado);
	}
	else
	{
		printf("\nNo se puede calcular el factorial de un numero decimal, negativo ni mayor a 13");
	}
}


//VALIDACIONES
int ValidarEntero(float num)
{
	int entero = 0;

	if(num - (int)num == 0)
	{
		entero = 1;
	}
	return entero;
}

int ValidarPositivo(float num)
{
	int positivo = 0;
	if(num > 0)
	{
		positivo = 1;
	}
	return positivo;
}


