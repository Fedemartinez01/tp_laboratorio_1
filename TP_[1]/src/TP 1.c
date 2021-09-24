/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "tp1biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	float num1;
	float num2;

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorial1;
	float resultadoFactorial2;

	int ingreso1ero = 0;
	int ingreso2do = 0;
	int operacionesCalculadas = 0;

	printf("\n\t\t-----------------TRABAJO PRACTICO Nº 1-----------------");


	do
	{
		opcion = Menu(num1, num2, ingreso1ero, ingreso2do);


		switch(opcion)
		{

			case 1:
				num1 = PedirNumero("Ingresar 1er operando: ");
				ingreso1ero = 1;
			break;

			case 2:
				num2 = PedirNumero("Ingresar 2do operando: ");
				ingreso2do = 1;
			break;

			case 3:
				if(ingreso1ero != 1|| ingreso2do != 1)
				{
					printf("\nIngresar operandos antes de calcular\n");
				}
				else
				{
					resultadoSuma = Sumar(num1, num2);
					resultadoResta = Restar(num1, num2);
					resultadoMultiplicacion = Multiplicar(num1, num2);
					resultadoDivision = Dividir(num1, num2);
					resultadoFactorial1 = Factorial(num1);
					resultadoFactorial2 = Factorial(num2);
					operacionesCalculadas = 1;
					printf("\n--------------OPERACIONES CALCULADAS--------------\n");
				}

			break;

			case 4:
				if(ingreso1ero != 1 || ingreso2do != 1)
				{
					printf("\nIngresar opreandos antes de mostrar resultados\n");
				}
				else
				{
					if(operacionesCalculadas == 0)
					{
						printf("\nPrimero se debe calcular las operaciones (opcion 3).\n");
					}
					else
					{
						printf("\n--------------------RESULTADOS--------------------");
						MostrarSuma(num1, num2, resultadoSuma);
						MostrarResta(num1, num2, resultadoResta);
						MostrarMultiplicacion(num1, num2, resultadoMultiplicacion);
						MostrarDivision(num1, num2, resultadoDivision);
						MostrarFactorial(num1, resultadoFactorial1);
						MostrarFactorial(num2, resultadoFactorial2);
						printf("\n--------------------------------------------------");
					}

				}

			break;
		}
	}while(opcion != 5);


	return EXIT_SUCCESS;
}
