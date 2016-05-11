#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.h"

void sortEmployee(Employee* array, int length);

void sortEmployeeIndex(Employee** array, int length);

void fillArrayOfPointer(Employee* array, Employee* arrayPointers[], int length);

void printEmployeeFromIndex(Employee** list, int length);


////////////////////////// MAIN
int main()
{
    Employee employeeList[1000];
    Employee* employeePointerList[1000];

    getEmployeeList(employeeList, 1000,"../MOCK.txt"); // Made with https://www.mockaroo.com/

    fillArrayOfPointer(employeeList,employeePointerList, 1000);


    clock_t start = clock();

    //sortEmployee(employeeList,1000);

    sortEmployeeIndex(employeePointerList,1000);

    clock_t end = clock();

    //printEmployeeList(employeeList, 1000);
    printEmployeeFromIndex(employeePointerList,1000);

    printf("Elapsed: %0.2f ms\n", 1000 *((double)(end-start) / CLOCKS_PER_SEC));

    return 0;
}

 ////////////////////////////////// FUNCTIONS

void sortEmployeeIndex(Employee** array, int length)
{
    int i, j;

    for(i= 0; i < length-1;i++)
    {
        for(j = i+1; j<length ;j++)
        {
            if( strcmp( (*(array+i))->name , (*(array+j))->name) > 0 )
            {
                swap( array+i , array+j, sizeof(Employee*));
            }
        }
    }
}


void printEmployeeFromIndex(Employee** list, int length)
{
    int i;
    for(i = 0; i < length;i++)
    {
        printf("%s\n",(*(list+i))->name);
    }
}


void fillArrayOfPointer(Employee* array, Employee** arrayPointers, int length)
{
    int i;

    for(i = 0;i< length;i++)
    {
        *(arrayPointers+i) = (array+i);
    }
}


void sortEmployee(Employee* array, int length)
{
    int i, j;

    for(i= 0; i < length-1;i++)
    {
        for(j = i+1; j<length ;j++)
        {
            if( strcmp( (*(array+i)).name , (*(array+j)).name) > 0 )
            {
                swap( (array+i) , (array+j), sizeof(Employee));
            }
        }
    }

}
