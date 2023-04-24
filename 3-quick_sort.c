#include "sort.h"
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
/**
* swap_ints - this takes two integers and swaps them.
* @a: this is the first integer to be swapped.
* @b: this is the second integer to be swapped.
*/
void swap_ints(int *a, int *b)
{
int tmpInt;
tmpInt = *a;
*a = *b;
*b = tmpInt;
}
/**
* lomuto_partition - this is arranging a set of arrays in scheme
* @array: this reps the integers array.
* @size: this reps the array size.
* @right: this is the ending of the index being ordered.
* @left: this is the first index of the set being ordered.
* Return: the value returned is the final partition index.
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;
pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap_ints(array + below, array + above);
print_array(array, size);
}
above++;
}
}
if (array[above] > *pivot)
{
swap_ints(array + above, pivot);
print_array(array, size);
}
return (above);
}
/**
* lomuto_sort - this is the implementation of the quicksort algorithm.
* @array: this is an array of integers to be sorted.
* @size: this is the size of the array.
* @right: this is the ending array index to be ordered.
* @left: this is the starting array index to be ordered.
* Description: this value applies the Lomuto scheme.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
int partit;
if (right - left > 0)
{
partit = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, partit - 1);
lomuto_sort(array, size, partit + 1, right);
}
}
/**
* quick_sort - this is where we sort int arrays in order
* @array: this is an array of integers.
* @size: this displays the array size.
* Description: this applies and returns the Lomuto scheme
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
lomuto_sort(array, size, 0, size - 1);
}
