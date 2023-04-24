#include "sort.h"
void swap_ints(int *a, int *b);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);
/**
* swap_ints - the function swaps the two integers.
* @a: this is the first integer swapped.
* @b: this is the second integer swapped.
*/
void swap_ints(int *a, int *b)
{
int tmpSwap;
tmpSwap = *a;
*a = *b;
*b = tmpSwap;
}
/**
* hoare_partition - this is the order of a subset.
* @size: this is the array size.
* @array: this is the array of integers.
* @right: this is the ending index to order.
* @left: this is the starting index to order.
* Return: returns the final partition of index.
* Description: this uses the last element as the pivot.
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
int pivot, above, below;
pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);
if (above < below)
{
swap_ints(array + above, array + below);
print_array(array, size);
}
}
return (above);
}
/**
* hoare_sort - this implements quicksort algorithm
* @size: this is the array size.
* @array: this is an array of integers sorted.
* @right: this is the ending index.
* @left: this is the starting index.
* Description: this uses Hoare partition scheme.
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
int partit;
if (right - left > 0)
{
partit = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, partit - 1);
hoare_sort(array, size, partit, right);
}
}
/**
* quick_sort_hoare - this is for sorting an array.
* @size: this is the array size.
* @array: this is an array of integers.
* Description: this uses Hoare partition scheme.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
hoare_sort(array, size, 0, size - 1);
}
