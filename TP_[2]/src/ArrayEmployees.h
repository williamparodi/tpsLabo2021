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

/**
 * @fn int addEmployees(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return  Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployees(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id en returns the index position in array.
 * @param list
 * @param id
 * @param len
 * @return  Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list,int id,int len);

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove a Employee by Id (put isEmpty Flag in 1)
 * @param list
 * @param id
 * @param len
 * @return  Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list,int id,int len);

/**
 * @fn int findEmpty(Employee*, int)
 * @brief
 * @param list
 * @param len
 * @return
 */
int findEmpty(Employee* list,int len);

/**
 * @fn void printEmployee(Employee)
 * @brief
 * @param x
 */
void printEmployee(Employee x);

/**
 * @fn int printListEmployee(Employee*, int)
 * @brief print the content of employees array
 * @param list
 * @param len
 * @return
 */
int printEmployees(Employee* list,int len);

/**
 * @fn int changeDataEmployee(Employee*, int, int)
 * @brief
 * @param list
 * @param id
 * @param len
 * @return
 */
int changeDataEmployee(Employee* list,int id,int len);

/**
 * @fn int chargeDataEmployees(int*, char[], char[], float*, int*)
 * @brief
 * @param pId
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return
 */
int chargeDataEmployees(int *pId, char name[],char lastName[],float *salary,int *sector);

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 * @param list
 * @param len
 * @param order
 * @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list,int len,int order);

/**
 * @fn int sortEmployeesByLastname(Employee*, int, int)
 * @brief
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortEmployeesByLastname(Employee* list,int len,int order);

/**
 * @fn int sortEmployeesBySector(Employee*, int, int)
 * @brief
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortEmployeesBySector(Employee* list,int len,int order);

/**
 * @fn int accumulateSalary(Employee[], int, float*)
 * @brief
 * @param list
 * @param len
 * @param pAccumulator
 * @return
 */
int accumulateSalary(Employee list[],int len,float* pAccumulator);

/**
 * @fn int countEmployee(Employee[], int, int*)
 * @brief
 * @param list
 * @param len
 * @param pCount
 * @return
 */
int countEmployee(Employee list[],int len,int* pCount);

/**
 * @fn float calculateAverageSalary(float, int, float*)
 * @brief
 * @param accumulator
 * @param count
 * @param pAverage
 * @return
 */
float calculateAverageSalary(float accumulator,int count,float *pAverage);

/**
 * @fn float calculateAboveAverageSalary(Employee[], int, float, int*)
 * @brief
 * @param list
 * @param len
 * @param average
 * @param pCountAboveSalary
 * @return
 */
float calculateAboveAverageSalary(Employee list[],int len,float average,int* pCountAboveSalary);

/**
 * @fn int order(int, int)
 * @brief
 * @param up
 * @param down
 * @return
 */
int order(int up,int down);

/**
 * @fn void printSalaryAverageTotal(float, float, int)
 * @brief
 * @param totalSalary
 * @param averageSalary
 * @param countAboveAverage
 */
void printSalaryAverageTotal(float totalSalary, float averageSalary, int countAboveAverage);

#endif /* ARRAYEMPLOYEES_H_ */
