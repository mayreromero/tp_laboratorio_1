/*
 * romero.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Mayre
 */

#ifndef ROMERO_H_
#define ROMERO_H_


/** \brief Pide al usuario un numero.
 *
 * \param mensaje char* aqui se guarda la direccion de memoria de donde se llame.
 * \return int retorna el numero ingresado por el usuario
 *
 */
int pedirNumero(char *mensaje);


/** \brief Realiza la suma de dos numeros ingresados
 *
 * \param nro_1 int 1er operando
 * \param nro_2 int 2do operando
 * \return int   me retorna el resultado de la suma.
 *
 */
int calcularSuma(int nro_1, int nro_2);

/** \brief Realiza la resta de dos numeros ingresados
 *
 * \param nro_1 int 1er operando
 * \param nro_2 int 2do operando
 * \return int   me retorna el resultado de la resta.
 *
 */
int calcularResta(int nro_1, int nro_2);

/** \brief Realiza la division de dos numeros ingresados
 *
 * \param nro_1 int 1er operando
 * \param nro_2 int 2do operando validado para que no sea 0
 * \return int   me retorna el resultado de la division.
 *
 */
float calcularDivision(int nro_1, int nro_2);

/** \brief Realiza la multiplicacion de dos numeros ingresados
 *
 * \param nro_1 int 1er operando
 * \param nro_2 int 2do operando
 * \return int   me retorna el resultado de la multiplicacion.
 *
 */
int calcularMultiplicacion(int nro_1, int nro_2);

/** \brief Realiza el factorial de dos numeros ingresados
 *
 * \param nro_1 int 1er operando
 * \param nro_2 int 2do operando
 * \return int   me retorna el resultado del calculo del factorial si el numero es menor que 16 .
 *
 */
long int calcularFactorial(int numero);

/** \brief muestra el menu con las diferentes opciones de calculos a realizar.
 *
 * \return void
 *
 */
void menuCalculadora();


#endif /* ROMERO_H_ */
