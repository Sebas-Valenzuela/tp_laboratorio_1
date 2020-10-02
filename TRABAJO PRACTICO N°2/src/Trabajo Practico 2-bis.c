

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployee.h"
#include "utn.h"

#define LONG_NOMBRE 51
#define CANTIDAD_EMPLOYEE 1000

int main(void) {
	setbuf(stdout,NULL);
	int indiceVacio;
	int idModificar;
	int indice;
	int opcion;
	int respuesta;

	Employee arrayEmployee[CANTIDAD_EMPLOYEE];

	employee_initArray(arrayEmployee,CANTIDAD_EMPLOYEE);

	do
		{
			respuesta = utn_getInt( "\n1-ALTAS"
					    			"\n2-MODIFICAR (por ID)"
									"\n3-BAJA"
									"\nINFORMAR: "
									"\n4-Listado empleados(ordenado alfabeticamente y por sector)"
									"\n5-Total Promedio salario. Cuantos superan salario promedio"
									"\n6-SALIR\n",
									"\nIngrese una Opcion Valida\n",
									&opcion,2,6,1);
			if(respuesta == 0)
			{switch(opcion)
			{
				case 1:
					//ALTA
					if(employee_buscarLibreRef(arrayEmployee, CANTIDAD_EMPLOYEE, &indiceVacio)==0)
					{
						employee_alta(arrayEmployee, CANTIDAD_EMPLOYEE, indiceVacio);

					}
					break;
				case 2:
					// MODIFICAR POR ID
					if(utn_getInt("Ingrese el ID a modificar:","Error ingrese un ID valido",&idModificar,2,CANTIDAD_EMPLOYEE,1)==0)
					{
						if(employee_buscarId(arrayEmployee, CANTIDAD_EMPLOYEE, &indice, idModificar)==0)
						{
							employee_modificar(arrayEmployee,CANTIDAD_EMPLOYEE,indice);
						}
					}
					break;
				case 3:
					//BAJA
					if(utn_getInt("Ingrese el ID a dar de baja:","Error ingrese un ID valido",&idModificar,2,CANTIDAD_EMPLOYEE,1)==0)
						{
							if(employee_buscarId(arrayEmployee, CANTIDAD_EMPLOYEE, &indice, idModificar)==0)
							{
								employee_baja(arrayEmployee,CANTIDAD_EMPLOYEE,indice);
							}
						}
					break;
				case 4:
					//ORDENAR IMPRIMIR
					if((employee_ordenarApellidoSector(arrayEmployee,CANTIDAD_EMPLOYEE))==0)
					{
						employee_imprimir(arrayEmployee,CANTIDAD_EMPLOYEE);
					}
					break;
				case 5:

					break;

			}
			}
		}while(opcion != 6);

		return EXIT_SUCCESS;
}
