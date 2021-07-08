#include "sort.h"
/**
 * radix_sort - LSD radix sort algorithm
 * @array: Array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
int j;
int i;
int siz = size;
int maximum = array[0];
for (i = 1; i < siz; i++)
{
if (maximum < array[i])
maximum = array[i];
}
int digits = 0;
while (maximum > 0)
{
digits++;
maximum /= 10;
}
int power = 1;
for (i = 0; i < digits; i++)
{
int new_array[siz];
int count[10];
for (j = 0; j < 10; j++)
count[j] = 0;
for (j = 0; j < siz; j++)
{
int num = (array[j] / power) % 10;
count[num]++;
}
for (j = 1 ; j < 10; j++)
count[j] += count[j - 1];
for (j = siz - 1; j >= 0; j--)
{
int num = (array[j] / power) % 10;
new_array[count[num] - 1] = array[j];
count[num]--;
}
for (j = 0 ; j < siz; j++)
array[j] = new_array[j];
power *= 10;
print_array(array, size);
}
}
