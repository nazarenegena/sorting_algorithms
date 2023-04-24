#include "sort.h"
void max_heapify(int *array, size_t size, size_t base, size_t root);
void swap_ints(int *a, int *b);
void heap_sort(int *array, size_t size);
/**
* swap_ints - the function swaps two array integers.
* @a: this is the first integer to swap.
* @b: this is the second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmpList;
tmpList = *a;
*a = *b;
*b = tmpList;
}
/**
* max_heapify - this turns a binary tree into a binary heap.
* @array: this is an array of integers for a binary tree.
* @base: this is the index of the base row.
* @root: this is the root node of the binary tree.
* @size: this is the size of the array.
*
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;
left = 2 * root + 1;
right = 2 * root + 2;
large = root;
if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;
if (large != root)
{
swap_ints(array + root, array + large);
print_array(array, size);
max_heapify(array, size, base, large);
}
}
/**
* heap_sort - this sorts an array of integers in order
* @array: this is an array of integers.
* @size: shows the array size.
* algorithm. the algorithim prints the swapped array.
* Description: this implements heap sort
*/
void heap_sort(int *array, size_t size)
{
int k;
if (array == NULL || size < 2)
return;
for (k = (size / 2) - 1; k >= 0; k--)
max_heapify(array, size, size, k);
for (k = size - 1; k > 0; k--)
{
swap_ints(array, array + k);
print_array(array, size);
max_heapify(array, size, k, 0);
}
}
