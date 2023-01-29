/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// BuildHeap on the heap
	buildHeap(A, n);

	// while n > 0:
	// swap A[n-1] with A[0], since A[0] is the smallest number.
	// A[n-1] now sorted in place, so decrement n
	// Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	while (n > 0)
	{
		swap(&A[n - 1], &A[0]);
		heapify(A, 0, n - 1);
		n--;
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// heapify() every element from A[n/2] down-to A[0]
	heapify(&A[n / 2], n / 2, n);
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	// get index of left child of element i
	int left_child = 2 * (i + 1) - 1;
	// get index of right child of element i
	int right_child = 2 * (i + 1);

	// determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	int smaller = left_child;

	if (A[right_child].salary < A[left_child].salary)
	{
		smaller = right_child;
	}

	// recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	// Continue recursion as long as i is within range AND either right_child or left_child are still within range.
	while ((i >= 0 && i < n) && ((right_child >= 0 && right_child < n) || (left_child >= 0 && left_child < n)))
	{
		if (A[i].salary > A[smaller].salary)
		{
			swap(&A[i], &A[smaller]);
			printf("Swapping...");
			heapify(&A[smaller], smaller, n);
		}
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// swap locations
	Employee *tmp = e1; // Store e1 in tmp
	e1 = e2;			// Set e1 to e2
	e2 = tmp;			// Set e2 to e1 via temp
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	// TODO

	for (int i = 0; i < n; i++)
	{
		if (i == (n - 1))
		{
			printf("[id= %s sal= %d]", A[i].name, A[i].salary);
		}
		else
		{
			printf("[id= %s sal= %d], ", A[i].name, A[i].salary);
		}
	}
	printf("\n");
}
