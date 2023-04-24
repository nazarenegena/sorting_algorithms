#include "sort.h"
/**
* swap_ints - this function swaps two integers in the array.
* @a: this is the first integer to be swapped.
* @b: this is the second integer to be swapped.
*
*/
void swap_ints(int *a, int *b)
{
int tmpInt;
tmpInt = *a;
*a = *b;
*b = tmpInt;
}
/**
* selection_sort - this is sorting in ascending order
* @array: this value is an array of integers.
* @size: this is the size of the array.
* Description: this ends up printing the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
int *mini;
size_t i, k;
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
mini = array + i;
for (k = i + 1; k < size; k++)
mini = (array[k] < *mini) ? (array + k) : mini;
if ((array + i) != mini)
{
swap_ints(array + i, mini);
print_array(array, size);
}
}
}
