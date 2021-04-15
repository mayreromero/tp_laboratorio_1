#include <stdio.h>
#include <stdlib.h>

int pedirNumero(char *mensaje)
{

    int numero;
    printf(mensaje);
    scanf("%d", &numero);
    return numero;

}
int calcularSuma(int nro_1, int nro_2)
{
    int resultado;
    resultado = nro_1 + nro_2;
    return resultado;
}
int calcularResta(int nro_1, int nro_2)
{
    int resultado;
    resultado = nro_1 - nro_2;
    return resultado;
}

float calcularDivision(int nro_1, int nro_2)
{
    float resultado;
    resultado = (float) nro_1 / nro_2;
    return resultado;
}

int calcularMultiplicacion(int nro_1, int nro_2)
{
    int resultado;
    resultado = nro_1 * nro_2;
    return resultado;
}


long int calcularFactorial(int numero) {

    if (numero < 0){ // Lo hago para convertir el numero en positivo
        numero = numero * -1;
    }
    if (numero == 0){
        return 1;
    }

    long int factorial = 1;
    while (numero > 1) {
        factorial = factorial * numero;
        numero--;
    }
    return factorial;
}

void menuCalculadora(){

	int Rsuma;
    int Rresta;
    int Rmulti;
    float Rdivi;
    long int Rfacto_A;
	long int Rfacto_B;

    int numero_uno;
    int numero_dos;
	int opcion;
	int flag_nroUno = 0;
	int flag_nroDos = 0;
	int flag_validar = 0;

		    do
		    {
		    	printf("\t-------- ***             *** --------\n");
		        printf("\t-------- *** CALCULADORA *** --------\n");
		        printf("\t-------- ***             *** --------\n");

		        if(flag_nroUno == 1)
		        {
		            printf("\t 1. Ingrese el 1er operando (A = %d):\n", numero_uno);
		        }
		        else
		        {
		            printf("\t1. Ingrese el 1er operando (A = X):\n ");
		        }

		        if(flag_nroDos == 1)
		        {
		            printf("\t2. Ingrese el 2do operando (B = %d):\n", numero_dos);
		        }
		        else
		        {
		            printf("\t2. Ingrese el 2do operando (B = Y):\n ");
		        }

		        printf("\t3. Calcular todas las operaciones:\n");
		        printf("\t a. Calcular la suma (A + B)\n");
		        printf("\t b. Calcular la resta (A - B)\n");
		        printf("\t c. Calcular la division (A / B)\n");
		        printf("\t d. Calcular la multiplicacion (A * B)\n");
		        printf("\t e. Calcular el factorial (A!) y (B!)\n");

		        printf("\t4. Informar resultados:\n");
		        printf("\t5. Salir:\n\n");
		        printf("\t Ingrese una opcion: \n ");
		        scanf("%d",&opcion);

		        switch(opcion)
		        {
		        case 1: // pedir 1er numero;
		            numero_uno = pedirNumero("\tIngrese el 1er operando: \n");
		           // system("cls");
		            flag_nroUno = 1;
		            break;

		        case 2: // pedir segundo numero;
		        	if(flag_nroUno == 1){
		        		numero_dos = pedirNumero("\tIngrese el 2do operando: \n");
		        		flag_nroDos = 1;
		        	}
		        	else{
		        		printf("\tPRIMERO INGRESA EL 1er OPERANDO \n");
		        	}

		            break;

		        case 3: // Calculo las operaciones;

		            if(flag_nroUno == 1 && flag_nroDos == 1)
		            {

		                Rsuma = calcularSuma(numero_uno, numero_dos);
		                Rresta = calcularResta(numero_uno, numero_dos);
		                Rdivi = calcularDivision(numero_uno, numero_dos);
		                Rmulti = calcularMultiplicacion(numero_uno, numero_dos);
		                Rfacto_A = calcularFactorial(numero_uno);
		                Rfacto_B = calcularFactorial(numero_dos);

		                printf("\tCALCULOS FINALIZADOS EXITOSAMENTE... \n");
		                flag_validar = 1;

		            }
		            else
		            {
		                printf("\tIngrese los operando para poder realizar las operaciones \n");
		            }
		            break;


		        case 4://Mostrar resultados;
		            if(flag_validar == 1){


                                if(flag_nroUno == 1 && flag_nroDos == 1 && flag_validar == 1)
                        {
                            printf("\t a) El resultado de la suma de %d + %d es: %d\n", numero_uno, numero_dos, Rsuma);
                            printf("\t b) El resultado de la resta de %d - %d es: %d \n", numero_uno, numero_dos, Rresta);
                        if(numero_dos == 0){
                            printf("\t c) NO SE PUEDE DIVIDIR POR CERO\n");
                        }
                        else{
                            printf("\t c) El resultado de dividir %d / %d es: %.2f \n",numero_uno, numero_dos,Rdivi);
                            }

                            printf("\t d) El resultado de multiplicar %d * %d es: %d\n", numero_uno, numero_dos,Rmulti);

                        if(numero_uno > 16 || numero_dos > 16){
                            printf("\t e) No se puede calcular el factorial, numero muy grande\n");
                            }
                         else{
                            printf("\t e) El factorial de %d es: %ld\n",numero_uno,Rfacto_A);
                            printf("\t e) El factorial de %d es: %ld\n",numero_dos,Rfacto_B);
                            }

                        }

                        flag_nroUno = 0;
                        flag_nroDos = 0;
                        flag_validar = 0;

		            }
		            else{
                        printf("\n PRIMERO HAGAMOS LOS CALCULOS ANTES DE MOSTRARLOS\n");
		            }

		            break;

		        case 5: // Salgo del programa;
		            printf("\t SALIENDO DE LA CALCULADORA \n ");
		            break;

		        default:
		            printf("\t Ingrese una de las opciones corectas \n");
		            system("pause");

		        }
		    }
		    while(opcion != 5);
}
