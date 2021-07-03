#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "ctype.h"
#include "menu.h"



int main(void)
{
	setbuf(stdout, NULL);

    /*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort*/

    int rpta;
    char seguir = 's';
    char confirmacion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaClonadaHoras = NULL;

    do{
        switch(menu())
        {
            case 1:
                if(!controller_loadFromText("data.cvs",listaEmpleados)){
                    printf("DATOS CARGADOS CON EXITO.\n");
                }else{
                    printf("ERROR AL CARGAR LOS DATOS.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados)){
                    printf("DATOS CARGADOS CON EXITO.\n");
                }else{
                    printf("ERROR AL CARGAR LOS DATOS.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados)){
                }else{
                    printf("ERROR PARA DAR EL ALTA.\n");
                }
                break;
            case 4:
                if(ll_isEmpty(listaEmpleados) == 0){
                	rpta = controller_editEmployee(listaEmpleados);
                    if(!rpta){
                        printf("CAMBIOS EXITOSOS.\n");
                    }else if(rpta == 2){
                        printf("OPERACION CANCELADA POR EL USUARIO.\n");
                    }else{
                        printf("ERROR PARA MODIFICAR.\n");
                    }
                }else{
                    printf("LA LISTA ESTA VACIA.\n");
                }
                break;
            case 5:
                if(ll_isEmpty(listaEmpleados) == 0){
                	rpta = controller_removeEmployee(listaEmpleados);
                    if(!rpta){
                        printf("BAJA REALIZADA CON EXITO.\n");
                    }else if(rpta == 2){
                        printf("BAJA CANCELADA POR EL USUARIO.\n");
                    }else{
                        printf("ERROR EN LA BAJA.\n");
                    }
                }else{
                    printf("LA LISTA ESTA VACIA.\n");
                }
                break;
            case 6:
                if(controller_ListEmployee(listaEmpleados)){
                    printf("ERROR AL MOSTRAR LA LISTA");
                }
                break;
            case 7:
                if(ll_isEmpty(listaEmpleados) == 0){
                	rpta = controller_sortEmployee(listaEmpleados);
                    if(!rpta){
                        printf("LISTA OREDNADA CON EXITO.\n");
                    }else if(rpta == 2){
                        printf("OPERACION CANCELADA POR EL USUARIO.\n");
                    }else{
                        printf("ERROR PARA ORDENAR LA LISTA.\n");
                    }
                }else{
                    printf("LA LISTA ESTA VACIA.\n");
                }
                break;
            case 8:
                if(!controller_revisarHoras(listaEmpleados)){
                    printf("HAY EMPLEADOS QUE TRABAJAN MAS HORAS .\n");
                }else{
                    printf("HORAS CORRECTAS.\n");
                }
                listaClonadaHoras = ll_clone(ll_filter(listaEmpleados,filtrarHoras));
                break;
            case 9:
                if(controller_ListEmployee(listaClonadaHoras)){
                    printf("ERROR PARA MOSTRAR LA LISTA");
                }
                break;
            case 10:
                if(!controller_saveAsText("data.cvs",listaEmpleados)){
                    printf("DATOS GUARDADOS CON EXITO.\n");
                }else{
                    printf("ERROR AL GUARDAR LOS DATOAS.\n");
                }
                break;
            case 11:
                if(!controller_saveAsBinary("data.bin",listaEmpleados)){
                    printf("DATOS GUARDADOS CON EXITO.\n");
                }else{
                    printf("ERROR AL GUARDAR LOS DATOS.\n");
                }
                break;
            case 12:
                printf("CONFIRMAS LA SALIDA?(s/n)");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if(confirmacion == 's'){
                seguir = 'n';
                ll_deleteLinkedList(listaEmpleados);
                }
                break;
            default:
                printf("LA OPCION NO ES VALIDA.\n");

        }
    system("pause");
    }while(seguir == 's');

    return 0;
}































