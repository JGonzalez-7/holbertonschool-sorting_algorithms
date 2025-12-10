#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Description: After every swap, the array is printed.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	/* If array is NULL or size is less than 2, nothing to sort */
	if (array == NULL || size < 2)
		return;

	/* Outer loop: repeat passes through the array */
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Reset swap flag for each pass */

		/* Inner loop: compare adjacent elements */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If elements are out of order, swap them */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size); /* Print array after every swap */
				swapped = 1;
			}
		}

		/* If no swaps were made, the array is already sorted */
		if (!swapped)
			break;
	}
}
