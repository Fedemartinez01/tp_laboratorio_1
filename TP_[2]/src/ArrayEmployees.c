/*
 * ArrayEmployees.c
 *
 *  Created on: 4 oct 2021
 *      Author: FLIA TOPOS
 */

#include "ArrayEmployees.h"


int menu(eEmployee listaEmpleados[], int tam)
{
	int opcion;

	if(listaEmpleados != NULL && tam > 0)
	{
		if(SearchPlace(listaEmpleados, tam) == -1)
		{
			opcion = GetIntRangos("\n1. Alta (no disponible)\n2. Modificar\n3. Baja\n4. Informar\n5. Salir\nIngresar opcion: ", 2, 5);
		}
		else
		{
			if(SearchActive(listaEmpleados, tam) == 0)
			{
				do
				{
					opcion = GetIntRangos("\n1. Alta\n2. Modificar (no disponible)\n3. Baja (no disponible)\n4. Informar (no disponible)\n5. Salir\nIngresar opcion: ", 1, 5);
				}while(opcion > 1 && opcion < 5);
			}
			else
			{
				opcion = GetIntRangos("\n1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5. Salir\nIngresar opcion: ", 1, 5);
			}
		}
	}





	return opcion;
}

int initEmployees(eEmployee listaEmpleados[], int tam)
{
	int retorno;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			listaEmpleados[i].isEmpty = VACIO;
			retorno = 1;
		}
	}

	return retorno;
}

eEmployee AskEmployee(int *pId)
{
	eEmployee empleado;
	*pId += 1;
	empleado.id = *pId;
	GetString("\nNombre: ", empleado.name);
	GetString("Apellido: ", empleado.lastName);
	empleado.salary = GetFloat("Salario: $");
	empleado.sector = GetIntRangos("Sector (1 - 2 - 3 - 4 - 5): ", 1, 5);

	return empleado;
}

int addEmployee(eEmployee listaEmpleados[], int tam, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	int indiceEmpty;
	retorno = 0;


	if(listaEmpleados != NULL && tam > 0 && name != NULL && lastName != NULL)
	{
		indiceEmpty = SearchPlace(listaEmpleados, tam);

		if(indiceEmpty != -1)
		{
			listaEmpleados[indiceEmpty].id = id;
			strcpy(listaEmpleados[indiceEmpty].name, name);
			strcpy(listaEmpleados[indiceEmpty].lastName, lastName);
			listaEmpleados[indiceEmpty].salary = salary;
			listaEmpleados[indiceEmpty].sector = sector;
			listaEmpleados[indiceEmpty].isEmpty = ACTIVO;
			retorno = 1;
		}
	}



	return retorno;
}



int printOneEmployee(eEmployee empleado)
{
	int imprimio;
	imprimio = 1;
	printf("| %4d | %21s | %21s | %9.2f | %6d |\n", empleado.id, empleado.name,
												empleado.lastName, empleado.salary,
												empleado.sector);
	printf("|------|-----------------------|-----------------------|-----------|--------|\n");

	return imprimio;
}


int printEmployees(eEmployee listaEmpleados[], int tam)
{
	int retorno;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		printf(" ___________________________________________________________________________\n");
		printf("|      |                       |                       |           |        |\n");
		printf("|  ID  |         NOMBRE        |        APELLIDO       |  SALARIO  | SECTOR |\n");
		printf("|      |                       |                       |           |        |\n");
		printf("|______|_______________________|_______________________|___________|________|\n");
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == ACTIVO)
			{
				retorno = 1;
				printOneEmployee(listaEmpleados[i]);
			}
		}
	}





	return retorno;
}

int removeEmployee(eEmployee listaEmpleados[], int tam, int id)
{
	int retorno;
	retorno = 0;
	int indiceRemove;

	if(listaEmpleados != NULL && tam > 0)
	{
		indiceRemove = findEmployeeById(listaEmpleados, tam, id);

		if(indiceRemove != -1)
		{
			listaEmpleados[indiceRemove].isEmpty = VACIO;
			retorno = 1;
		}
	}




	return retorno;
}

int ModificarEmployee(eEmployee listaEmpleados[], int tam, int id)
{
	int retorno;
	retorno = 0;
	int opcionModificacion;
	char modificacionString[51];
	int indiceEmpleadoModificar;

	if(listaEmpleados != NULL && tam > 0)
	{
		indiceEmpleadoModificar = findEmployeeById(listaEmpleados, tam, id);

		if(indiceEmpleadoModificar != -1)
		{
			opcionModificacion = GetIntRangos("\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n¿Que desea modificar?: ", 0, 4);

			switch(opcionModificacion)
			{
			case 1:
				GetString("\nNuevo nombre: ", modificacionString);
				strcpy(listaEmpleados[indiceEmpleadoModificar].name, modificacionString);
				break;

			case 2:
				GetString("\nNuevo apellido: ", listaEmpleados[indiceEmpleadoModificar].lastName);
				break;

			case 3:
				listaEmpleados[indiceEmpleadoModificar].salary = GetFloat("\nNuevo salario: $");
				break;

			case 4:
				listaEmpleados[indiceEmpleadoModificar].sector = GetIntRangos("\nNuevo sector (1 - 2 - 3 - 4 - 5): ", 1, 5);
				break;
			}
			retorno = 1;
		}
	}


	return retorno;
}

int SearchPlace(eEmployee listaEmpleados[], int tam)//DEVUELVE -1 SI ESTÁ LLENO. SINO DEVUELVE EL INDICE VACIO
{
	int indiceEmpty;
	indiceEmpty = -1;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == VACIO)
			{
				indiceEmpty = i;
				break;
			}
		}
	}



	return indiceEmpty;
}



int SearchActive(eEmployee listaEmpleados[], int tam)//DEVUEVE 0 SI ESTÁ VACIO, 1 SI POR LO MENOS HAY 1
{
	int retorno;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == ACTIVO)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int sortEmployees(eEmployee listaEmpleados[], int tam, int order)
{
	int retorno;
	retorno = 0;

	if(listaEmpleados != NULL)
	{
		retorno = 1;
		if(order == DESCENDENTE)
		{
			sortEmployeeDown(listaEmpleados, tam);
		}
		else
		{
			sortEmployeeUp(listaEmpleados, tam);
		}
	}

	sortEmployeeSector(listaEmpleados, tam);
	return retorno;
}

int sortEmployeeDown(eEmployee listaEmpleados[], int tam)
{
	int retorno;
	eEmployee aux;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam-1; i++)
		{
			for(int j = i+1; j < tam; j++)
			{
				if(listaEmpleados[i].isEmpty == ACTIVO && listaEmpleados[j].isEmpty == ACTIVO)
				{
					if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName) > 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
		}
	}
	return retorno;
}

int sortEmployeeUp(eEmployee listaEmpleados[], int tam)
{
	int retorno;
	eEmployee aux;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		retorno = 1;
		for(int i = 0; i < tam-1; i++)
		{
			for(int j = i+1; j < tam; j++)
			{
				if(listaEmpleados[i].isEmpty == ACTIVO && listaEmpleados[j].isEmpty == ACTIVO)
				{
					if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName) < 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
		}
	}
	return retorno;
}


int sortEmployeeSector(eEmployee listaEmpleados[], int tam)
{
	int retorno;
	eEmployee aux;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if(listaEmpleados[i].isEmpty == ACTIVO && listaEmpleados[j].isEmpty == ACTIVO)
				{
					if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName) == 0)
					{
						if(listaEmpleados[i].sector > listaEmpleados[j].sector)
						{
							aux = listaEmpleados[i];
							listaEmpleados[i] = listaEmpleados[j];
							listaEmpleados[j] = aux;
						}
					}
				}
			}
		}
	}



	return retorno;
}

int findEmployeeById(eEmployee listaEmpleados[], int tam, int id)
{
	int indice;
	indice = -1;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == ACTIVO && listaEmpleados[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}


	return indice;
}



void CalcularPromedio(eEmployee listaEmpleados[], int tam, float *pSalarioPromedio)
{
	int cantidadPromedio;
	float acumuladorPromedio;

	cantidadPromedio = 0;
	acumuladorPromedio = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == ACTIVO)
			{
				cantidadPromedio++;
				acumuladorPromedio += listaEmpleados[i].salary;
			}
		}

		*pSalarioPromedio = acumuladorPromedio / cantidadPromedio;
	}





}


void CantidadSuperanPromedio(eEmployee listaEmpleados[], int tam, float promedioTotal, int *pEmpleadosSuperanSalario)
{
	int contadorEmpleadosSuperanPromedio;
	contadorEmpleadosSuperanPromedio = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == ACTIVO && listaEmpleados[i].salary > promedioTotal)
			{
				contadorEmpleadosSuperanPromedio ++;
			}
		}
		*pEmpleadosSuperanSalario = contadorEmpleadosSuperanPromedio;
	}


}




