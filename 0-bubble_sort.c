#include "sort.h"
/**
* swap_ints - the operation swaps two integers in the array.
* @a: this is the first integer to swap.
* @b: this is the second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmpVal;
tmpVal = *a;
*a = *b;
*b = tmpVal;
}
/**
* bubble_sort - this is to sort an array of integers in the ascending order.
* @array: this is an array of integers that we are sorting.
* @size: this is the size of the array.
* Description: the description prints the array after each swap.
*/
void bubble_sort(int *array, size_t size)
{
size_t k, len = size;
bool bubble = false;
if (array == NULL || size < 2)
return;
while (bubble == false)
{
bubble = true;
for (k = 0; k < len - 1; k++)
{
if (array[k] > array[k + 1])
{
swap_ints(array + k, array + i + 1);
print_array(array, size);
bubble = false;
}
}
len--;
}
}
