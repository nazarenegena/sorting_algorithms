#include "sort.h"
/**
* swap_ints - this function swaps two integers in the array.
* @a: swapping the first integer.
* @b: swapping the second integer.
*/
void swap_ints(int *a, int *b)
{
int tmpList;
tmpList = *a;
*a = *b;
*b = tmpList;
}
/**
* shell_sort - this is sorting the array of integers.
* @array: this is the int array.
* @size: this is the array size.
* Description: this applies Knuth interval sequence.
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, k;
if (array == NULL || size < 2)
return;
for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;
for (; gap >= 1; gap /= 3)
{
for (i = gap; i < size; i++)
{
k = i;
while (k >= gap && array[k - gap] > array[k])
{
swap_ints(array + k, array + (k - gap));
k -= gap;
}
}
print_array(array, size);
}
}
