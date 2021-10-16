/*
 * ArrayEmployee.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Willy
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "ArrayEmployees.h"



int initEmployees(Employee* list, int len)
{
    int itsOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            list[i].isEmpty = 1;
        }

        itsOk = 0;
    }

    return itsOk;
}

int addEmployees(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int itsOk = -1;
    int index;
    Employee auxEmployee;

    if(list != NULL && name != NULL && lastName != NULL && len > 0)
    {
        index = findEmpty(list,len);

        if(index == -1)
        {
            printf("Error, no se pudo cargar empleado\n");
        }
        else
        {
            auxEmployee.id = id;

            strncpy(auxEmployee.name,name,sizeof(auxEmployee.name));
            pasarMayusculaPrimerCaracter(auxEmployee.name);

            strncpy(auxEmployee.lastName,lastName,sizeof(auxEmployee.lastName));
            pasarMayusculaPrimerCaracter(auxEmployee.lastName);

            auxEmployee.salary = salary;
            auxEmployee.sector = sector;
            auxEmployee.isEmpty = 0;

            list[index] = auxEmployee;
        }

        itsOk = 0;
    }

    return itsOk;
}

int findEmployeeById(Employee* list,int id,int len)
{
    int index = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int removeEmployee(Employee* list,int id,int len)
{
    int itsOk = 0;
    int index;
    int option;

    if(list != NULL && len >0)
    {
        id = ingresarInt("Ingrese el id del empleado que desea borrar: ");

        index = findEmployeeById(list,id,len);

        if(index == -1)
        {
            printf("El id del empleado no existe\n");
        }
        else
        {
            //system("cls");
            printf("-------------------------------\n");
            printf("    ***Borrar empleado***      \n");
            printf("-------------------------------\n");
            printEmployee(list[index]);
            option = ingresarInt("Desea borrar este id: 1- Aceptar 2-Cancelar ");

            while(!validarMinMax(option,1,2))
            {
            	option = ingresarInt("Error, Desea borrar este id: 1- Aceptar 2-Cancelar ");
            }

            switch(option)
            {
                case 1:
                    list[index].isEmpty = 1;
                    break;
                case 2:
                    printf("Baja cancelada\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }


        }

        itsOk = 1;
    }

    return itsOk;
}

int findEmpty(Employee* list,int len)
{
    int index = -1;

    if(list != NULL && len >0)
    {
        for(int i = 0;i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }

    }

    return index;
}

void printEmployee(Employee x)
{

    printf("%d  %8s    %10s    %13.2f    %10d   \n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

int printListEmployee(Employee* list,int len)
{
    int itsOk = 0;

    if(list != NULL && len > 0)
    {
        printf("----------------------------------------------------------\n");
        printf("           ***Lista de Empleados***         \n");
        printf("----------------------------------------------------------\n");
        printf("Id     Nombre       Apellido        Salario         Sector\n");

        for(int i = 0;i < len;i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
            }

        }


        itsOk = 1;
    }

    return itsOk;

}

int changeDataEmployee(Employee* list,int id,int len)
{
    int itsOk = 0;
    int index;
    char choice = 's';
    int option;
    char auxName[25];
    char auxLastName[25];
    float auxSalary;
    int auxSector;

    if(list != NULL && len >0)
    {


        id = ingresarInt("Ingrese el id del empleado a modificar : ");

        index = findEmployeeById(list,id,len);

        if(index == -1)
        {
            printf("No se encontro ese Id\n");
        }
        else
        {
            printf("Id Empleado a modificar: %d \n",id);


            do
            {
            	 option = ingresarInt("Elija el campo a modificar: 1-Nombre 2-Apellido 3-Salario 4-Sector 5-Cancelar ");

            	 while(!validarMinMax(option,1,5))
                 {
            	     option = ingresarInt("Error, Elija el campo a modificar: 1-Nombre 2-Apellido 3-Salario 4-Sector 5-Cancelar ");
                 }

				 switch(option)
				 {

					case 1:
						ingresarString("Modifique el nombre : ", auxName);
						pasarMayusculaPrimerCaracter(auxName);
						while(strlen(auxName) > 20)
						{
							ingresarString("Error, Ingresar nombre : ", auxName);
						}
						strcpy(list[index].name,auxName);
						break;
					case 2:
						ingresarString("Modifique el apellido : ", auxLastName);
						pasarMayusculaPrimerCaracter(auxLastName);
						while(strlen(auxLastName) > 20)
						{
							ingresarString("Error, Ingresar nombre : ", auxLastName);
						}
						strcpy(list[index].lastName,auxLastName);
						break;
					case 3:
						auxSalary = ingresarFloat("Modifique el salario : ");
						list[index].salary = auxSalary;
						break;
					case 4:
					   auxSector = ingresarInt("Modifique el sector : 1-Administracion 2-Contabilidad 3-Produccion 4-Publicidad 5-Venta ");
					   while(!validarMinMax(auxSector,1,5))
					   {
						   auxSector = ingresarInt("Error,Modifique el sector : 1-Administracion 2-Contabilidad 3-Produccion 4-Publicidad 5-Venta ");
					   }
					   list[index].sector = auxSector;
					   break;
					case 5:
						printf("Modificacion cancelada\n");
						choice = 'n';
						break;
					default:
						printf("Opcion invalida\n");
						break;

				}

            }while(choice == 's');


        }

        itsOk = 1;
    }



    return itsOk;
}

int sortEmployees(Employee* list,int len,int order)
{
    int itsOk = -1;
    int option;

    if(list != NULL && len >0)
    {
    	option = ingresarInt("Desea ordenar por Apellido o por Sector?: 1- Apellido o 2-Sector ");

    	while(!validarMinMax(option,1,2))
    	{
    	    option = ingresarInt("Error, 1- Ascendente o 2 Descendente\n");
    	}

    	switch(option)
    	{
    	  case 1:
     		  sortEmployeesByLastname(list,len,order);
     		  break;
    	  case 2:
    		  sortEmployeesBySector(list,len,order);
    		  break;
    	}

    	itsOk = 0;

    }

   return itsOk;

}

int chargeDataEmployees(int *pId, char name[],char lastName[],float *salary,int *sector)
{
	int itsOk = 0;
	char auxName[20];
	char auxLastName[20];

	if(name != NULL && lastName != NULL && pId != NULL && salary != NULL && sector != NULL)
	{
		(*pId)++;

		ingresarString("Ingresar nombre : ", auxName);
		pasarMayusculaPrimerCaracter(auxName);

		while(strlen(auxName) > 15)
		{
			ingresarString("Error, Ingresar nombre : ", auxName);
		}

		ingresarString("Ingresar Apellido : ", auxLastName);
		pasarMayusculaPrimerCaracter(auxLastName);

		while(strlen(auxLastName) > 15)
		{
			ingresarString("Error, Ingresar apellido: ", auxLastName);
		}

		*salary = ingresarFloat("Ingresar salario : ");
		*sector = ingresarInt("Ingresar el sector : 1-Administracion 2-Contabilidad 3-Venta 4-Publicidad 5-Produccion ");

		strcpy(name,auxName);
		strcpy(lastName,auxLastName);

		itsOk = 1;

	}

	return itsOk;


}


int accumulateSalary(Employee list[],int len,float* pAccumulator)
{
    int itsOk = 0;

    float accumulator = 0;

    if(list != NULL && pAccumulator != NULL && len >0)
    {
        for(int i = 0;i < len;i++)
        {
            if(list[i].isEmpty == 0)
            {
                accumulator+=list[i].salary;
            }

        }

        *pAccumulator = accumulator;

        itsOk = 1;
    }

    return itsOk;
}

int countEmployee(Employee list[],int len,int* pCount)
{
    int itsOk = 0;

    int count = 0;

    if(list != NULL && pCount != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                count++;
            }

        }

        *pCount = count;

        itsOk = 1;
    }

    return itsOk;
}

float calculateAverageSalary(float accumulator,int count,float *pAverage)
{
    int itsOk = 0;

    if(pAverage != NULL && count != 0)
    {
        *pAverage = accumulator / (float) count;

        itsOk = 1;
    }

    return itsOk;

}

float calculateAboveAverageSalary(Employee list[],int len,float average,int* pCountAboveSalary)
{
    int itsOk = 0;

    int count = 0;

    if(list != NULL && len >0)
    {
        for(int i = 0;i < len;i++)
        {
            if(list[i].isEmpty == 0)
            {
               if(list[i].salary > average)
                {
                    count++;
                }
            }

        }

        *pCountAboveSalary = count;
        itsOk = 1;
    }

    return itsOk;

}

int order(int up,int down)
{
    int choose;

    choose = ingresarInt("Ingrese un orden: 1- Para mostrar en orden ascendente o 2- Para descendente: ");

    return choose;
}

int sortEmployeesByLastname(Employee* list,int len,int order)
{
	int itsOk = 0;
	int auxLastName;
	Employee auxEmployee;

	if(list != NULL && len > 0)
	{

		for(int i = 0;i< len - 1;i++)
		{
			for(int j = i+1;j < len;j++)
			{
				auxLastName = strcmp(list[i].lastName,list[j].lastName);

				if((auxLastName == 1 && order) || (auxLastName == -1 && !order)
						|| (auxLastName == 0 && list[i].sector > list[j].sector && order)
						|| (auxLastName == 0 && list[i].sector < list[j].sector && !order))
				{
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
				}

			}
		}


		itsOk = 1;
	}

	return itsOk;


}

int sortEmployeesBySector(Employee* list,int len,int order)
{

	int itsOk = 0;
	int auxLastName;
	Employee auxEmployee;

		if(list != NULL && len > 0)
		{

			for(int i = 0;i< len - 1;i++)
			{
				for(int j = i+1;j < len;j++)
				{
					auxLastName = strcmp(list[i].lastName,list[j].lastName);

					if((list[i].sector > list[j].sector && order)|| (list[i].sector < list[j].sector && !order)
						||(auxLastName == 1 && order) || (auxLastName == -1 && !order))
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;

					}

				}
			}


			itsOk = 1;
		}

		return itsOk;

}

void printSalaryAverageTotal(float totalSalary, float averageSalary, int countAboveAverage)
{
	printf("\nSalario Total : %.2f\n",totalSalary);
	printf("Salario promedio : %.2f\n",averageSalary);
	printf("Cantidad de empleados por arriba del salario promedio : %d\n",countAboveAverage);
}
