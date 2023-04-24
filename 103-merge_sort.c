#include "sort.h"
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort(int *array, size_t size);
/**
* merge_subarr - function to sort the subarray integer .
* @buff: this is a buffer to the sorted subarray.
* @subarr: the subarray of sorted int.
* @mid: this is the middle index .
* @front: this is the front index of the array.
* @back: this is the back index of the array.
*/
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
size_t back)
{
size_t m, n, k = 0;
printf("Merging...\n[left]: ");
print_array(subarr + front, mid - front);
printf("[right]: ");
print_array(subarr + mid, back - mid);
for (m = front, n = mid; m < mid && n < back; k++)
buff[k] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
for (; m < mid; m++)
buff[k++] = subarr[m];
for (; n < back; n++)
buff[k++] = subarr[n];
for (m = front, k = 0; m < back; m++)
subarr[m] = buff[k++];
printf("[Done]: ");
print_array(subarr + front, back - front);
}
/**
* merge_sort_recursive - this is to implement sort algorithm .
* @buff: this is the buffer used to store the sorted result.
* @subarr: the subarray of an array of integers to be sort.
* @front: this is the front index of the subarray.
* @back: this is the back index of the subarray.
*/
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
size_t mid;
if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(subarr, buff, front, mid);
merge_subarr(subarr, buff, front, mid, back);
merge_sort_recursive(subarr, buff, mid, back);
}
}
/**
* merge_sort - this is to sort an array of int
* @array: this is an integer array.
* @size: this is the array size.
* Description: the sort algorithim is implemented.
*/
void merge_sort(int *array, size_t size)
{
int *buff;
if (array == NULL || size < 2)
return;
buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;
merge_sort_recursive(array, buff, 0, size);
free(buff);
}
