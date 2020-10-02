

#ifndef UTN_H_
#define UTN_H_

#define LIMITE_BUFFER_STRING 4096
#define CANTIDAD_EMPLEADOS 1000
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo);


#endif /* UTN_H_ */
