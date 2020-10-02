
#include "ArrayEmployee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define LONG_NOMBRE 51
#define CANTIDAD_EMPLOYEE 1000
#define SALARY_MIN 1
#define SALARY_MAX 100000

static int generarIdNuevo(void);


/**
 * \brief Realiza el alta de un employee solo si el indice corresponde a un Empty
 * \param Employee arrayEmployees[], Es el puntero al array de employees
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el employee
 * \return (-1) Error / (0) Ok
 *
 */


int init_Employees(Employee* pArray, int limite)
{
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int employee_alta(Employee arrayEmployee[],int limite,int indice)
{
	int retorno = -1;
	Employee bufferEmployee;

	if(	arrayEmployee != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayEmployee[indice].isEmpty == TRUE)
	{
		if(utn_getNombre("\nIngrese un Nombre: \n ","\nIngrese un nombre valido: \n",bufferEmployee.name,2,LONG_NOMBRE)==0 &&
		   utn_getNombre("\nIngrese un Apellido: \n ","\nIngrese un Apellido valido: \n",bufferEmployee.lastName,2,LONG_NOMBRE)==0 &&
		   utn_getFloat("\nIngrese un salario: \n","\nIngrese un salario valido",&bufferEmployee.salary,2,SALARY_MAX,1)==0 &&
		   utn_getInt("\nIngrese un sector(Numero entero)","Ingrese un sector valido",&bufferEmployee.sector,2,500,SALARY_MIN)==0
		)
		{
			//bufferEmployee.isEmpty = FALSE;
			bufferEmployee.id= generarIdNuevo();
			arrayEmployee[indice] = bufferEmployee;
			arrayEmployee[indice].isEmpty = FALSE;

			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Modifica los datos de un employee solo si el indice corresponde a un NO Empty
 * \param Employee arrayEmployees[], Es el puntero al array de employees
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el employee
 * \return (-1) Error / (0) Ok
 *
 */
int employee_modificar(Employee arrayEmployee[],int limite,int indice)
{
	int retorno = -1;

	Employee bufferEmployee;

	if(	utn_getNombre("\nIngrese un Nombre: \n ","\nIngrese un nombre valido: \n",bufferEmployee.name,2,LONG_NOMBRE)==0 &&
		utn_getNombre("\nIngrese un Apellido: \n ","\nIngrese un Apellido valido: \n",bufferEmployee.lastName,2,LONG_NOMBRE)==0 &&
		utn_getFloat("\nIngrese un salario: \n","\nIngrese un salario valido",&bufferEmployee.salary,2,100000,1)==0 &&
		utn_getInt("\nIngrese un sector(Numero entero)","Ingrese un sector valido",&bufferEmployee.sector,2,500,1)==0)
	{
		//bufferEmployee.isEmpty = FALSE;
		bufferEmployee.id= arrayEmployee[indice].id; //generarIdNuevo(); // NOOOOOOOOO

		arrayEmployee[indice] = bufferEmployee;
		arrayEmployee[indice].isEmpty = FALSE;

		retorno = 0;
	}



	return retorno;
}

/**
 * \brief Da de baja a un empleado
 * \param Employee arrayEmployees[], Es el puntero al array de employees
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el employee
 * \return (-1) Error / (0) Ok
 *
 */

int employee_baja(Employee arrayEmployee[],int limite,int indice)
{
	int retorno = -1;

	if(	arrayEmployee != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayEmployee[indice].isEmpty == FALSE)
	{
			arrayEmployee[indice].isEmpty = TRUE;
			retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime los employees cargados
 * \param Employee arrayEmployees[], Es el puntero al array de employees
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int employee_imprimir(Employee* pArrayEmployee, int limite)
{
	int retorno = -1;
	if(pArrayEmployee != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArrayEmployee[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Apellido: %s - Salary:%.2f - Sector:%d - ID:%d",
						pArrayEmployee[i].name,
						pArrayEmployee[i].lastName,
						pArrayEmployee[i].salary,
						pArrayEmployee[i].sector,
						pArrayEmployee[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Inicializa el array de employees
 * \param Employee arrayEmployees[], Es el puntero al array de employees
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int employee_initArray(Employee* pArrayEmployee, int limite)
{
	int retorno = -1;
	if(pArrayEmployee != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArrayEmployee[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}



int employee_printById(Employee* pArray, int limit, int index)
{
		int retorno = -1;

		if(pArray != NULL && limit > 0 && index < limit)
		{
			if(pArray[index].isEmpty == FALSE)
			{
				printf("Nombre: %s - Legajo: %d\n",pArray[index].name, pArray[index].sector);
				retorno = 0;
			}
		}
		return retorno;
}



int employee_buscarLibreRef(Employee pArrayEmployee[], int limit, int *pIndex)
{
	int retornar = -1;
	if(pArrayEmployee != NULL && pIndex != NULL && limit>0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArrayEmployee[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}

int employee_buscarLibreValor(Employee pArrayEmployee[], int limit)
{
	int retornar = -1;
	if(pArrayEmployee != NULL && limit>0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArrayEmployee[i].isEmpty == TRUE)
			{
				retornar = i;
				break;
			}
		}
	}

	return retornar;
}


/* Cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 */


static int generarIdNuevo(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}


int employee_buscarId(Employee* pArrayEmployee, int limite, int* pIndex, int id)
{
    int retorno = -1;
    //*pIndex = -1;
    if (pArrayEmployee != NULL && limite > 0)
    {
        for (int i = 0; i < limite; i++)
        {
            if(pArrayEmployee[i].isEmpty == FALSE )
            {
                if(pArrayEmployee[i].id == id)
                {
                   *pIndex = i;
                   retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int employee_ordenarApellido(Employee* pArray, int limite)
{
	int retorno = -1;
	int FlagSwap;

	Employee bufferEmployee;

	if (pArray != NULL && limite >0)
	{
		do
		{
			FlagSwap = 0;
			for (int i = 0; i<limite; i++ )
				{
					if(strncmp(pArray[i].lastName,pArray[i+1].lastName,LONG_NOMBRE) > 0)
						{
							FlagSwap = 1;
							bufferEmployee = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = bufferEmployee;
						}

				}
				limite--;
		}while(FlagSwap);
		retorno = 0;
	}

	return retorno;
}

int employee_ordenarApellidoSector(Employee* pArray, int limite)
{
	int retorno = -1;
	int FlagSwap;

	Employee bufferEmployee;

	if (pArray != NULL && limite > 0)
	{
		do
		{
			FlagSwap = 0;
			for (int i=0; i<limite-1; i++ )
				{
					if(strncmp(pArray[i].lastName,pArray[i+1].lastName,LONG_NOMBRE) > 0 ||
					   (strncmp(pArray[i].lastName,pArray[i+1].lastName,LONG_NOMBRE) == 0 && pArray[i].sector < pArray[i+1].sector))
						{
							FlagSwap = 1;
							bufferEmployee = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = bufferEmployee;
						}
				}
				limite--;
		}while(FlagSwap);
		retorno = 0;
	}

	return retorno;
}


