#include "sort.h"
/**
* get_max - the function gets the max value int array.
* @array: this is an array of integers.
* @size: this is the array size.
* Return: this is the max array integer.
*/
int get_max(int *array, int size)
{
int max, m;
for (max = array[0], m = 1; m < size; m++)
{
if (array[m] > max)
max = array[m];
}
return (max);
}
/**
* counting_sort - the sorting of an integer array
* @size: this is the array size.
* @array: this is an integer array.
* Description: the counting array is printed.
*/
void counting_sort(int *array, size_t size)
{
int *count, *sorted, max, j;
if (array == NULL || size < 2)
return;
sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
max = get_max(array, size);
count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
{
free(sorted);
return;
}
for (j = 0; j < (max + 1); j++)
count[j] = 0;
for (j = 0; j < (int)size; j++)
count[array[j]] += 1;
for (j = 0; j < (max + 1); j++)
count[j] += count[j - 1];
print_array(count, max + 1);
for (j = 0; j < (int)size; j++)
{
sorted[count[array[j]] - 1] = array[j];
count[array[j]] -= 1;
}
for (j = 0; j < (int)size; j++)
array[j] = sorted[j];
free(sorted);
free(count);
}
