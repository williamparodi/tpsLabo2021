
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>

/** \brief Despliega un menu de opciones.
 *
 * \param numero1 int El valor del primer numero ingresado.
 * \param numero2 int EL valor del segundo numero ingresado.
 * \return int Retorna un numero entero con la opcion elegida.
 *
 */
int elegirOpcion(int numero1,int numero2);

/** \brief Suma dos numeros enteros
 *
 * \param numero1 int El valor del primer numero ingresado.
 * \param numero2 int El valor del segundo numero ingresado.
 * \return int Retorna el resultado de la suma.
 *
 */
int sumarEnteros(int numero1,int numero2);

/** \brief Resta dos numeros enteros
 *
 * \param numero1 int El valor del primer numero ingresado.
 * \param numero2 int El valor del segundo numero ingresado.
 * \return int Retorna el resultado de la resta.
 *
 */
int restarEnteros(int numero1,int numero2);

/** \brief Muestra un mensaje y el numero ingresado.
 *
 * \return int Retorna el numero ingresado.
 *
 */
int mostrarEntero();

/** \brief Muestra mensajes con las diferentes operaciones a realizar
 *
 * \param numero1 int El valor del primer numero ingresado
 * \param numero2 int El valor del segundo numero ingresado
 * \return void
 *
 */
void mostrarCalculos(int numero1,int numero2);

/** \brief Multiplica dos numeros enteros
 *
 * \param numero1 int El valor del primer numero ingresado.
 * \param numero2 int El valor del segundo numero ingresado
 * \return int Retrona el resultado de la multiplicacion.
 *
 */
int multiplica(int numero1,int numero2);


/** \brief Divide dos numeros enteros y verifica que el segundo numero no sea 0
 *
 * \param numero1 int El valor del primer numero ingresado.
 * \param numero2 int El valor del segundo numero ingresado
 * \param pResultado float* Puntero con la direccion de memoria del  resultado de la division.
 * \return int Devuelve un numero entero con el estado de la funcion, 0 [si no es exitoso] o 1 [si es exitoso]
 *
 */
int dividirEnteros(int numero1,int numero2,float *pResultado);

/** \brief Calcula el factorial de un numero y verifica q el numero sea positivo y no mayor a 12.
 *
 * \param numero int EL valor del numero ingresado.
 * \param int* puntero con la direccion de memoria para volcar el valor del factorial.
 * \return int Devuelve un numero entero con el estado de la funcion, 0 [si no es exitoso] o 1 [si es exitoso]
 *
 */
 int factorial(int numero,int* pFactorial);



 /** \brief Muestra un mensaje valido con el resultado de la division o invalido en caso de error.
  *
  * \param numero1 int El valor del primer numero ingresado.
  * \param numero2 int  El valor del segundo numero ingresado.
  * \param funcionDivisionOk int El valor con el exito o no de la funcion Division.
  * \param resultadoDivision float EL valor de del resultado de la division.
  * \return void
  *
  */
 void mostrarResultadoDivision(int numero1,int numero2,int funcionDivisionOk,float resultadoDivision);

 void mostrarFactorial(int numero,int factorial,int funcionFactorialOk);




#endif /* BIBLIOTECA_H_ */
