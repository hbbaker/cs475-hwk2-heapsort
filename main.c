#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	// TODO
	const int MAX_EMPLOYEES = 2;
	Employee employeeList[MAX_EMPLOYEES];

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Name: ");
		// fgets(employeeList[i].name, MAX_NAME_LEN, stdin);
		scanf("%s", employeeList[i].name);
		printf("Name is %s\n", employeeList[i].name);
		printf("Salary: ");
		scanf("%d", &employeeList[i].salary);
		printf("Salary is %d\n", employeeList[i].salary);
		printf("\n");
		scanf("*");
	}

	// heapSort(employeeList, MAX_EMPLOYEES);

	printList(employeeList, MAX_EMPLOYEES);

	return 0;
}
