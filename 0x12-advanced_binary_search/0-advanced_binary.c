#include "search_algos.h"
/**
 * print_array - function to print the array
 * @array: the array
 * @l: first element of array
 * @r: last element of array
 */
void print_array(int *array, int l, int r)
{
printf("Searching in array: ");
while (l < r)
{
printf("%d, ", array[l]);
l++;
}
printf("%d", array[l]);
printf("\n");
}
/**
 * recursivebinary - recursive function
 * @array: the array
 * @l: first element of array
 * @r: last element of array
 * @value: value to be searched for
 * Return: return value depending on condition
 */
int recursivebinary(int *array, int l, int r, int value)
{
size_t mid;

	if (l < r)
	{
		mid = l + (r - l) / 2;
		print_array(array, (int)l, (int)r);
		if (array[mid] >= value)
			return (recursivebinary(array, l, mid, value));
		else
			return (recursivebinary(array, mid + 1, r, value));
		return ((int)(mid));
	}
	if (array[l] == value)
		return (l);
	print_array(array, (int)l, (int)r);
	return (-1);
}
/**
 * advanced_binary - function to search for value in array
 * @array: array
 * @size: size of the array
 * @value: value to be searched for
 * Return: return
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t l = 0;
size_t r = size - 1;
if (!array)
return (-1);
return (recursivebinary(array, l, r, value));
}

