/*
 * ArrayEmployee.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Willy
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

int addEmployees(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list,int id,int len);


int removeEmployee(Employee* list,int id,int len);

int findEmpty(Employee* list,int len);


void printEmployee(Employee x);

int printListEmployee(Employee* list,int len);


int changeDataEmployee(Employee* list,int id,int len);

int chargeDataEmployees(int *pId, char name[],char lastName[],float *salary,int *sector);

int sortEmployees(Employee* list,int len,int order);

int sortEmployeesByLastname(Employee* list,int len,int order);

int sortEmployeesBySector(Employee* list,int len,int order);

int accumulateSalary(Employee list[],int len,float* pAccumulator);

int countEmployee(Employee list[],int len,int* pCount);

float calculateAverageSalary(float accumulator,int count,float *pAverage);

float calculateAboveAverageSalary(Employee list[],int len,float average,int* pCountAboveSalary);

int order(int up,int down);

void printSalaryAverageTotal(float totalSalary, float averageSalary, int countAboveAverage);

#endif /* ARRAYEMPLOYEES_H_ */
