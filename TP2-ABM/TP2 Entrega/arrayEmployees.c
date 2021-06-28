#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"


// Menu del ABM
int menuAbm()
{
    int option;
    system("cls");
    printf("\t -----*** ABM EMPLEADOS ***-----\n\n\t 1 - DAR ALTA A EMPLEADO\n\t 2 - MODIFICAR EMPLEADO\n\t 3 - DAR BAJA A EMPLEADO\n\t 4 - INFORMAR\n\t 5 - SALIR\n");
    getInt(&option,"\n\tINGRESE UNA OPCION: ","ERROR. LA OPCION NO ES VALIDA",1,5,2);
    return option;
}


int initEmployees(sEmployee listEmployee[],int tam)
{
    int estaOk = -1;

    for(int i = 0; i<tam; i++)
    {
        listEmployee[i].isEmpty = 1;
        estaOk = 0;
    }

    return estaOk;
}

// Funcion para buscar posicion libre
int searchFree(sEmployee listEmployee[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(listEmployee[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

// Funcion para mostrar un Empleado
void showOneEmployee(sEmployee listEmployee)
{
    printf("\n%2d %11s %11s %15.2f %8d\n",
           listEmployee.id,
           listEmployee.name,
           listEmployee.lastName,
           listEmployee.salary,
           listEmployee.sector
           );
}

// Muestra todos los empleados
int printEmployees(sEmployee listEmployee[],int tam)
{
    int estaOk = -1;
    printf("     LISTADO DE EMPLEADOS \n");
    printf("\n  ID     NOMBRE      APELLIDO      SALARIO    SECTOR\n\n");

    if(listEmployee != NULL && tam >=0 )
    {
        for(int i=0; i<tam ; i++)
        {
            if(listEmployee[i].isEmpty==0)
            {
                // funcion mostrar un EMpleado
                showOneEmployee(listEmployee[i]);
                estaOk = 0;
            }
        }
        if(estaOk == -1)
        {
            printf("\n\t NO HAY EMPLEADOS PARA MOSTRAR.\n\n");
        }

    }
    return estaOk;
}


int addEmployee(sEmployee listEmployee[],int tam, int id,char name[],char lastName[],float salary, int sector)
{
    int index;
    int estaOk = -1;
    index = searchFree(listEmployee,tam);

    if(index == -1)
    {
        printf("\n El SISTEMA ESTA COMPLETO\n\n");
    }
    else
    {
        listEmployee[index] = newEmp(id,name,lastName,salary,sector);
        printf("\n --- ALTA EXITOSA ---\n\n");
        estaOk = 0;
    }

    return estaOk;
}

// Funcion para crear un nuevo empleado
sEmployee newEmp(int id, char name[],char lastName[],float salary,int sector)
{
    sEmployee newEmplo;

    newEmplo.id = id;
    strcpy(newEmplo.name, name);
    strcpy(newEmplo.lastName, lastName);
    newEmplo.salary = salary;
    newEmplo.sector = sector;
    newEmplo.isEmpty = 0;

    return newEmplo;
}


int loadEmployee(sEmployee listEmployee[],int len,int lastId)
{
    int todoOK;
    char name[CARACTERES];
    char lastName[CARACTERES];
    float salary;
    int sector;

    system("cls");
    printf("\n\t---ALTA EMPLEADO---\n\n");

    getString(name,"\n\tINGRESE NOMBRE: ","\n\tERROR, el nombre debe contener entre 2 y 30 caracteres",2,30,2);
    getString(lastName,"\n\tINGRESE APELLIDO: ","\n\tERROR,el apellido debe contener entre 2 y 30 caracteres",2,30,2);
    getFloat(&salary,"\n\tINGRESE SALARIO: ","\n\tERROR, debe ingresar un numero",1.0,10000000.0,2);
    getInt(&sector,"\n\tINGRESE SECTOR (1- 10): ","\n\tERROR, debe ingresar un numero",1,10,2);

    todoOK = addEmployee(listEmployee,len,lastId,name,lastName,salary,sector);

    return todoOK;
}

// Busco a empleado por ID
int findEmployeeById(sEmployee listEmployee[],int tam,int id)
{
    int estaOk = -1;
    if(listEmployee != NULL && tam >= 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listEmployee[i].id == id && listEmployee[i].isEmpty == LIBRE)
            {
                estaOk = i;
                break;
            }
        }
        if ( estaOk == -1)
        {
            printf("\t NO EXISTE UN EMPLEADO CON ESTE ID");
        }

    }
    return estaOk;
}

// Modificar Empleados
int modifyEmployee(sEmployee listEmployee[],int tam)
{
    int estaOk = -1;
    int index;
    int id;

    system("cls");
    printf("\n\t--- MODIFICAR EMPLEADO ---\n\n");

    if(listEmployee != NULL && tam >= 0)
    {
        if(printEmployees(listEmployee,tam) == 0)
        {

            getInt(&id,"\n INGRESE ID DE EMPLEADO A MODIFICAR: ","ERROR, INGRESE ID VALIDO.\n",1,10000,2);

            index = findEmployeeById(listEmployee,tam,id);

            if(index == -1)
            {
                printf("\n\tNO EXISTE NINGUN EMPLEADO CON ESE ID\n\n");
            }
            else
            {
                estaOk =0;
                printf("\n    ID          NOMBRE        APELLIDO       SALARIO      SECTOR\n\n");
                showOneEmployee(listEmployee[index]);


                switch(menuModif())
                {
                case 1:
                    getString(listEmployee[index].name,"\tINGRESE SU NUEVO NOMBRE: ","\nERROR, EL NOMBRE NO ES VALIDO",2,30,2);
                    break;
                case 2:
                    getString(listEmployee[index].lastName,"\tINGRESE SU NUEVO APELLIDO: ","\nERROR, APELLIDO NO VALIDO",2,30,2);
                    break;
                case 3:
                    getFloat(&listEmployee[index].salary,"\tINGRESE SU NUEVO SALARIO: ","\nERROR, DEBE INGRESAR UN NUMERO",1.0,10000000.0,2);
                    break;
                case 4:
                    getInt(&listEmployee[index].sector,"\tINGRESE SU NUEVO SECTOR (1 - 10): ","\nERROR, DEBE INGRESAR UN NUMERO",1,10,2);
                    break;
                case 5:
                    printf("\n\t SE CANCELO LA MODIFICACION.\n\n");
                    break;
                default:
                    printf("\n\tOPCION INVALIDA!\n\n");
                }

            }
        }
    }
    return estaOk;
}


int menuModif()
{
    int option;
    printf("\n\t*QUE DESEAS MODIFICAR*\n");
    printf("1 - MODIFICAR NOMBRE\n2 - MODIFICAR AOELLIDO\n3 - MODIFICAR SALARIO\n4 - MODIFCAR SECTOR\n5 - SALIR\n");
    getInt(&option,"\nINGRESE OPCION: ","Error. LA OPCION NO ES VALIDA.",1,5,2);
    return option;
}

// Elimino empleados
int removeEmployee(sEmployee listEmployee[],int tam)
{
    int estaOk;
    int index;
    int id;
    char confirma;

    system("cls");
    printf("\n\t---BAJA EMPLEADO---\n\n");

    printEmployees(listEmployee,tam);

    getInt(&id,"\n INGRESE ID:","ERROR, INGRESE UN ID VALIDO.\n",0,10000,2);

    index = findEmployeeById(listEmployee,tam,id);

    if(index == -1)
    {
        printf("\n\t NO EXISTE UN EMPLEADO CON ESE ID.\n\n");
    }
    else
    {
        //MUESTRO EL EMPLEADO A DAR DE BAJA!
        showOneEmployee(listEmployee[index]);
        printf("\n  ID      NOMBRE    APELLIDO      SALARIO   SECTOR\n\n");

        //getChar(&confirma,"\nConfirma baja? <s/n>: ","Error. ingrese <s/n> :",0,125,2);
        printf("\n COFIRMA LA BAJA?: ");
        fflush(stdin);
        confirma = getch();

        if(confirma == 's')
        {
            listEmployee[index].isEmpty = OCUPADO;
            estaOk = 0;
            printf("\n\n --- BAJA EXITOSA ---\n\n");
        }
        else if(confirma == 'n')
        {
            printf("\n SE CANCELO LA OPERACION.\n\n");
        }
        else
        {
            printf("\nINGRESE UNA OPCION VALIDA .\n\n");
        }
    }
    return estaOk;
}
// Menu de Informes
int menuReports()
{
    int option;

    system("cls");
    printf("\n---INFORMES---\n\n");
    printf("1 - EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR \n");
    printf("2 - TOTAL Y PROMEDIO DE SALARIOS,Y CANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO\n");
    printf("3 - MOSTRAR LISTA DE EMPLEADOS\n");
    printf("4 - SALIR\n");
    getInt(&option,"\nINGRESE OPCION: ","\nERROR,LA OPCION NO ES VALIDA\n\n",1,4,2);

    return option;
}

// Ordenar empleados

int sortEmployees(sEmployee listEmployee[],int tam, int order)
{
    int estaOk = -1;

    sEmployee employeeAux;

    switch(order)
    {
        case 1:
            for(int i=0;i<tam;i++)
            {
                for(int j=i+1;j<tam;j++)
                {
                    if(listEmployee[i].sector > listEmployee[j].sector ||
                       listEmployee[i].sector == listEmployee[j].sector ||
                        listEmployee[i].lastName > listEmployee[j].lastName)
                    {
                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;
                        estaOk = 0;
                    }
                }
            }
            break;

        case 2:
            for(int i = 0; i<tam; i++)
            {
                for(int j = i+1; j<tam; j++)
                {
                    if(listEmployee[i].sector < listEmployee[j].sector)
                    {
                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;
                        estaOk = 0;
                    }
                    else if(listEmployee[i].sector == listEmployee[j].sector)
                    {
                        if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName))
                        {
                            employeeAux = listEmployee[i];
                            listEmployee[i] = listEmployee[j];
                            listEmployee[j] = employeeAux;
                            estaOk = 0;
                        }
                    }
                }
            }
            break;
    }
    return estaOk;
}
/*
int sortEmployees(sEmployee listEmployee[],int len, int order)
{
    int retorno = -1;

    sEmployee employeeAux;

    //ORDENARLO ALFABETICAMENTE POR APELLIDO Y SECTOR

    switch(order)
    {
        case 1:
            for(int i=0;i<len -1;i++)
            {
                for(int j=i+1;j<len;j++)
                {
                    if(order == 1 && (listEmployee[i].sector > listEmployee[j].sector ||
                        listEmployee[i].sector == listEmployee[j].sector &&
                         stricmp( listEmployee[i].lastName,listEmployee[j].lastName)
                        > 0))
                    {

                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;
                    }
                    else if(order == 1 && (listEmployee[i].sector > listEmployee[j].sector ||
                        listEmployee[i].sector == listEmployee[j].sector &&
                         stricmp( listEmployee[i].lastName,listEmployee[j].lastName)
                        < 0)){

                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;

                    }
            }
            retorno = 0;
    }
    return retorno;
 }
}
*/
// Salarios
void printSalaryInformation(sEmployee listEmployee[],int tam)
{
    int cont = 0;
    float acum = 0;
    float prom = 0;
    int i;
    int promMay = 0;

    for(i=0;i<tam;i++)
    {
        if(listEmployee[i].isEmpty==LIBRE)
        {
            cont++;
            acum = acum + listEmployee[i].salary;
        }
    }

     prom = (float) acum/cont;

    for(i = 0; i<tam; i++)
    {
        if(listEmployee[i].isEmpty == LIBRE && listEmployee[i].salary >  prom)
        {
            promMay++;
        }
    }

    printf("\nTOTAL DE EMPLEADOS: %d\n\nSALARIO TOTAL DE EMPLEADOS: $%.2f\n\nPROMEDIO DE SALARIOS: $%.2f\n\nEMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d\n\n",
           cont,
           acum,
           prom,
           promMay);
}
