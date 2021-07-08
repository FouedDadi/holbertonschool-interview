#include "sort.h"

/**
 * getMax - get the maximum digit
 * @array: array
 * @size: size of array
 * Return: return the maximum digit
 */
int getMax(int *array, size_t size)
{
int mx = array[0];
size_t i;
if (array == NULL || size < 2)
return (0);
for (i = 1; i < size; i++){
if (array[i] > mx)
mx = array[i];
}
return (mx);
}

/**
 * countSort - count sort
 * @array: array
 * @size: size of array
 * @exp: exp
 */
void countSort(int *array, size_t size, int exp)
{
int count[10] = {0};
int x;
size_t i;
int *output;
output = malloc(sizeof(int *) * size);
if (output == NULL)
return;
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (x = size - 1; x >= 0; x--)
{
output[count[(array[x] / exp) % 10] - 1] = array[x];
count[(array[x] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
}

/**
 * radix_sort - LSD radix sort algorithm
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
int m = getMax(array, size);
int exp;
for (exp = 1; m / exp > 0; exp *= 10)
{
countSort(array, size, exp);
print_array(array, size);
}
}
