#include "sort.h"

/**
 * bubble_sort - Implements the bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * Return: Nothing
 * Description: This algorithm works by comparing an element
 * to the one ahead. If the current element is greater than the
 * one ahead, they are swapped.
 * A premature exit is executed if after the first iteration
 * no elements are swapped
 * The array is printed each time two elements are swapped
 */
void bubble_sort(int *array, size_t size)
{
	size_t n;
	size_t i;
	int swaps = 0;
	int temp = 0;

	n = size - 1;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swaps += 1;
				print_array(array, size);
			}
		}
		if (!swaps) /* Premature exit if no swap after first iteration */
			return;
		n--;
	}
}
