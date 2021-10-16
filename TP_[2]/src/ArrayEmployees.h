/*
 * ArrayEmployees.h
 *
 *  Created on: 4 oct 2021
 *      Author: FLIA TOPOS
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#endif /* ARRAYEMPLOYEES_H_ */

#include "funciones.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define ACTIVO 1
#define VACIO 0

#define ASCENDENTE 0
#define DESCENDENTE 1



typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

/// Muestra el menú
/// @param listaEmpleados
/// @param tam
/// @return retorna la opcion ingresada
int menu(eEmployee listaEmpleados[], int tam);

/// Inicializa la lista en VACIO
/// @param listaEmpleados
/// @param tam
/// @return 1
int initEmployees(eEmployee listaEmpleados[], int tam);

/// Pide un empleado
/// @param pId
/// @return un empleado
eEmployee AskEmployee(int *pId);

/// Agrega un empleado en la lista
/// @param listaEmpleados
/// @param tam
/// @param id
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return 1 si pudo agregar un empleado
int addEmployee(eEmployee listaEmpleados[], int tam, int id, char name[],char lastName[],float salary,int sector);

/// Busca un empleado por id
/// @param listaEmpleados
/// @param tam
/// @param id
/// @return el indice del empleado buscado, -1 si no lo encontró
int findEmployeeById(eEmployee listaEmpleados[], int tam, int id);

/// Elimina un empleado (cambia el estado a VACIO)
/// @param listaEmpleados
/// @param tam
/// @param id
/// @return 1 si pudo, 0 sino
int removeEmployee(eEmployee listaEmpleados[], int tam, int id);

/// Ordena los empleados alfabeticamente por apellido y por sector
/// @param listaEmpleados
/// @param tam
/// @param order
/// @return 1 si pudo, 0 sino
int sortEmployees(eEmployee listaEmpleados[], int tam, int order);

/// Muestra la lista de empleados
/// @param listaEmpleados
/// @param tam
/// @return 1 si pudo, 0 sino
int printEmployees(eEmployee listaEmpleados[], int tam);

/// Muestra un empleado
/// @param unEmpleado
/// @return 1 si pudo, 0 sino
int printOneEmployee(eEmployee unEmpleado);

/// Modifica un campo del empleado
/// @param listaEmpleados
/// @param tam
/// @param id
/// @return 1 si pudo, 0 sino
int ModificarEmployee(eEmployee listaEmpleados[], int tam, int id);

/// Busca "VACIO"
/// @param listaEmpleados
/// @param tam
/// @return el indice del primer lugar vacio o -1 si la lista está llena
int SearchPlace(eEmployee listaEmpleados[], int tam);

/// Busca un "CARGADO"
/// @param listaEmpleados
/// @param tam
/// @return 1 si por lo menos hay un cargado, 0 si está vacio
int SearchActive(eEmployee listaEmpleados[], int tam);

/// Calcula el salario promedio
/// @param listaEmpleados
/// @param tam
/// @param pSalarioPromedio
void CalcularPromedio(eEmployee listaEmpleados[], int tam, float *pSalarioPromedio);

/// Calcula la cantidad de empleados que superan el salario promedio
/// @param listaEmpleados
/// @param tam
/// @param promedioTotal
/// @param pEmpleadosSuperanSalario
void CantidadSuperanPromedio(eEmployee listaEmpleados[], int tam, float promedioTotal, int *pEmpleadosSuperanSalario);

/// Ordena empleados por sector
/// @param listaEmpleados
/// @param tam
/// @return 1 si pudo, 0 sino
int sortEmployeeSector(eEmployee listaEmpleados[], int tam);

/// Ordena los empleados alfabeticamente ascendentemente
/// @param listaEmpleados
/// @param tam
/// @return 1 si pudo, 0 sino
int sortEmployeeUp(eEmployee listaEmpleados[], int tam);

/// Ordena los empleados alfabeticamente descendendentemente
/// @param listaEmpleados
/// @param tam
/// @return 1 si pudo, 0 sino
int sortEmployeeDown(eEmployee listaEmpleados[], int tam);


