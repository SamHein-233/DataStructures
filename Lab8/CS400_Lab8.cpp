// CS400_Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/****************************************************************
 * A program that uses the quicksort algorithm to sort an array *
 * by calling the partition algorithm recursively. 		  	  *
 ****************************************************************/
#include <iostream>
using namespace std;

// Function declarations
void swap(int& x, int& y);
void print(int array[], int size);
int partition(int arr[], int beg, int end);
void quickSort(int arr[], int beg, int end);

// TODO: Swap function
// this function exchanges the values of two integers
void swap(int& x, int& y)
{
	// a temporary variable is assigned to hold the value of x
	int temp = x;
	// then x is assigned the value of y
	x = y;
	// then why is assigned the value of temp
	y = temp;
}


// TODO:  Print-array function
// this iterates through the array to print each element
void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// TODO: Partition function
// this function partitions the array around a pivot element and returns the index of the pivot
int partition(int arr[], int beg, int end)
{
	// the pivot is assigned to the last element in the array
	int pivot = arr[end];
	// i is initailized to one less than the beginning of the index
	int i = beg - 1;

	// this loop iterates through the array and sorts in ascending order. If an element is less than the pivot
	// then i icrements and that element is swapped with the element at i
	for (int j = beg; j < end; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	// after the loop, the pivot element is swapped into its correct position,
	// and the index of the pivot is returned
	swap(arr[i + 1], arr[end]);
	return i + 1;
}




// TODO: Quick sort function
// sorts the array using the quicksort algorithm
void quickSort(int arr[], int beg, int end)
{
	// checks if the beginning index is less than the ending index
	// if not, the array segment is already sorted or has one element
	if (beg < end) {
		// the array is partitioned around a pivot, and the index of the pivot is obtained
		int p = partition(arr, beg, end);
		// quicksort is called recursively on the two subarrays
		quickSort(arr, beg, p - 1);
		quickSort(arr, p + 1, end);
	}
}

int main()
{
	// Declaration of an unsorted array
	int array[10] = { 27, 22, 11, 94, 83, 14, 30, 19, 46, 33 };
	// Printing unsorted array
	cout << "Original array: " << endl;
	print(array, 10);
	// Calling quickSort function
	quickSort(array, 0, 9);
	// Printing sorted array
	cout << "Sorted array: " << endl;
	print(array, 10);
	return 0;
}

