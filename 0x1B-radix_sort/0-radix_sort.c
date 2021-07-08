#include "sort.h"
/**
 * getMax - get the maximum digit
 * @array: array
 * @size: size of array
 * Return: return the maximum digit
 */
int getMax(int *array, size_t size)
{
int n = size;
int mx = array[0];
int i;
for (i = 1; i < n; i++)
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
int n = size;
int output[n];
int i, count[10] = { 0 };
for (i = 0; i < n; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = n - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < n; i++)
array[i] = output[i];
}
/**
 * radix_sort - LSD radix sort algorithm
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
int n = size;
int m = getMax(array, n);
int exp;
for (exp = 1; m / exp > 0; exp *= 10)
{
countSort(array, n, exp);
print_array(array, size);
}
}
