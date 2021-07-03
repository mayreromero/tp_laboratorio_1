
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(){
    int opcion;

    printf("*** CONTROL DE EMPLEADOS  (TP4 en TP3 )***\n\n");
    printf("1) CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.csv (modo texto).\n");
    printf("2) CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.bin (modo binario).\n");
    printf("3) ALTA DE EMPLEADO.\n");
    printf("4) MODIFICAR DATOS DE EMPLEADO.\n");
    printf("5) BAJA DE EMPLEADO.\n");
    printf("6) LISTAR EMPLEADOS.\n");
    printf("7) ORDENAR EMPLEADOS.\n");
    printf("8) REVISAR HORAS.\n");
    printf("9) LISTAR EMPLEADOS QUE TRABAJAN MENOS DE 48HS.\n");
    printf("10) GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.csv (modo texto).\n");
    printf("11) GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.bin (modo binario).\n");
    printf("12) SALIR.\n");
    printf("INGRESE UNA OPCION: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
