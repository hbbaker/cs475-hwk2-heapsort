#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	// TODO
	const int MAX_EMPLOYEES = 5;
	char name[128];
	Employee employeeList[MAX_EMPLOYEES];

	// Basic input handling
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Name: ");
		scanf("%s", name);
		strncpy(employeeList[i].name, name, MAX_NAME_LEN);
		printf("Salary: ");
		scanf("%d", &employeeList[i].salary);
		printf("\n");
	}

	// Sort List
	heapSort(employeeList, MAX_EMPLOYEES);

	// Print List
	printList(employeeList, MAX_EMPLOYEES);

	return 0;
}
