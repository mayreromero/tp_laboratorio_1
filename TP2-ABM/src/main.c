#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "arrayEmployees.h"

#define ELEMENTS 1000


int main()
{
	setbuf(stdout, NULL);

    sEmployee arrayEmployee[ELEMENTS];

    int lastId = 1;
    char exit = 'n';
    char exitSort = 'n';
    int ordenar;
    int flag = 0;

    initEmployees(arrayEmployee,ELEMENTS);

    do
    {
        switch(menuAbm())
        {
            case 1:
                if(loadEmployee(arrayEmployee,ELEMENTS,lastId) == LIBRE)
                {
                    lastId++;
                    flag = 1;
                }
                break;

            case 2:
                if(flag == 1)
                {
                    modifyEmployee(arrayEmployee,ELEMENTS);
                }
                else
                {
                    printf("\n\t PRIMERO DEBES CARGAR EMPLEADOS.\n\n");
                }
                break;

            case 3:
                if(flag == 1)
                {
                    removeEmployee(arrayEmployee,ELEMENTS);
                }
                else
                {
                    printf("\n\t PRIMERO DEBES CARGAR EMPLEADOS.\n\n");
                }
                break;

            case 4:
                if(flag == 1)
                {
                    do
                    {
                        switch(menuReports())
                        {
                        case 1:
                            getInt(&ordenar,"\n--ORDENAR LISTADO--\n\n 1- FORMA ASCENDENTE\n\n INGRESE OPCION: ", "ERROR, INGRESE UNA OPCION CORRECTA\n",1,2,3);
                            sortEmployees(arrayEmployee,ELEMENTS,ordenar);
                            break;
                        case 2:
                            printSalaryInformation(arrayEmployee,ELEMENTS);
                            break;
                        case 3:
                            printEmployees(arrayEmployee,ELEMENTS);
                            break;
                        case 4:
                            printf("CONFIRMAS SALIDA s/n ?: ");
                            fflush(stdin);
                            exitSort = getchar();
                            break;

                        default:
                            printf("...VOLVEMOS AL MENU...\n\n");
                        }
                       // system("pause");
                    }while(exitSort == 'n');
                }
                else
                {
                    printf("\n\t PRIMERO DEBES CARGAR EMPLEADOS\n\n");
                }
                break;

            case 5:
                printf("\t CONFIRMAS SALIDA s/n ?:");
                fflush(stdin);
                exit = getchar();
                break;

            default:
                printf("\n\n... VOLVEMOS AL MENU...\n\n");
        }
        //system("pause");
    }while(exit=='n');

    return 0;
}
