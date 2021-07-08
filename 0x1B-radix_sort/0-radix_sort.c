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
unsigned int i;
for (i = 1; i < size; i++)
if (array[i] > mx)
mx = array[i];
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
int output[size];
unsigned int i;
int count[10] = { 0 };
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (int i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
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
