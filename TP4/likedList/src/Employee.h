
#ifndef SRC_EMPLOYEE_H_
#define SRC_EMPLOYEE_H_

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByWorksHours(void* empleadoA, void* empleadoB);
int employeeSortBySalary(void* empleadoA, void* empleadoB);

void printEmployee2(Employee* empleado);
int employeeLastId(LinkedList* pArrayListEmployee);
int findEmployeeById(LinkedList* pArrayListEmployee,int id);

int filtrarHoras(void* empleado);



#endif /* SRC_EMPLOYEE_H_ */
