
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "ArrayEmployees.h"
#include "funciones.h"


#define ACTIVO 1

#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);


	int opcion;

	eEmployee listaEmpleados[TAM];
	eEmployee empleado;
	int id = 999;
	int idBaja;
	int idModificacion;

	float salarioPromedio;
	int cantidadEmpleadosSuperanPromedio;

	salarioPromedio = 0;

	initEmployees(listaEmpleados, TAM);




	do
	{

		opcion = menu(listaEmpleados, TAM);

		switch(opcion)
		{

		case 1:
			empleado = AskEmployee(&id);
			addEmployee(listaEmpleados, TAM, empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
			break;

		case 2:
			printEmployees(listaEmpleados, TAM);
			idModificacion = GetInt("\nID a modificar: ");
			if(ModificarEmployee(listaEmpleados, TAM, idModificacion) == 0)
			{
				printf("\nID inexistente");
			}

			break;

		case 3:
			sortEmployees(listaEmpleados, TAM, DESCENDENTE);
			printEmployees(listaEmpleados, TAM);
			idBaja = GetInt("\nID a bajar: ");
			if(removeEmployee(listaEmpleados, TAM, idBaja) == 0)
			{
				printf("\nID inexistente");
			}
			else
			{
				printf("\nBaja exitosa!");
			}
			break;


		case 4:
			sortEmployees(listaEmpleados, TAM, DESCENDENTE);
			printEmployees(listaEmpleados, TAM);

			CalcularPromedio(listaEmpleados, TAM, &salarioPromedio);
			CantidadSuperanPromedio(listaEmpleados, TAM, salarioPromedio, &cantidadEmpleadosSuperanPromedio);
			printf("\nSalario promedio: %.2f\nEmpleados que superan el promedio: %d\n", salarioPromedio, cantidadEmpleadosSuperanPromedio);

			break;

		}


	}while(opcion != 5);






	return EXIT_SUCCESS;
}
