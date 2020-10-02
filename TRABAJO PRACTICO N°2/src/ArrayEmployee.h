
#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

#define CANTIDAD_EMPLOYEE 1000
#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 51
#define SALARY_MIN 1
#define SALARY_MAX 100000

typedef struct
{
int id;
char name[LONG_NOMBRE];
char lastName[LONG_NOMBRE];
float salary;
int sector;
int isEmpty;
}Employee;

int employee_buscarId(Employee* pArrayEmployee, int limite, int* pIndex, int id);
int employee_alta(Employee arrayEmployee[],int limite,int indice);
int employee_imprimir(Employee* pArrayEmployee, int limite);
int employee_initArray(Employee* pArrayEmployee, int limite);
int employee_modificar(Employee arrayEmployee[],int limite,int indice);
int employee_baja(Employee arrayEmployee[],int limite,int indice);
int employee_ordenarApellido(Employee* pArray, int limite);
int employee_ordenarApellidoSector(Employee* pArray, int limite);
int employee_buscarLibreRef(Employee pArrayEmployee[], int limit, int *pIndex);
int employee_salary(Employee* pArrayEmployee, int limite);
#endif /* ARRAYEMPLOYEE_H_ */



