#include "sort.h"
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
/**
* get_max - the function gets the max value in an array
* @array: shows the array of integers.
* @size: shows the array size.
* Return: The maximum integer in the array.
*/
int get_max(int *array, int size)
{
int maxi, k;
for (maxi = array[0], k = 1; k < size; k++)
{
if (array[k] > maxi)
maxi = array[k];
}
return (maxi);
}
/**
* radix_counting_sort - this sorts the  digits of an array of int
* @size: this is the array size.
* @array: this is the array of int.
* @buff: the buffer that stores the sorted list.
* @sig: this is the significant digit to be sorted.
*/
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t j;
for (j = 0; j < size; j++)
count[(array[j] / sig) % 10] += 1;
for (j = 0; j < 10; j++)
count[j] += count[j - 1];
for (j = size - 1; (int)j >= 0; j--)
{
buff[count[(array[j] / sig) % 10] - 1] = array[j];
count[(array[j] / sig) % 10] -= 1;
}
for (j = 0; j < size; j++)
array[j] = buff[j];
}
/**
* radix_sort - this sorts an array of ints in order
* @array: this is the array of ints.
* @size: this is the array size.
* Description: this implements LSD radix sort algorithm.
*/
void radix_sort(int *array, size_t size)
{
int maxi, sig, *buff;
if (array == NULL || size < 2)
return;
buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;
maxi = get_maxi(array, size);
for (sig = 1; maxi / sig > 0; sig *= 10)
{
radix_counting_sort(array, size, sig, buff);
print_array(array, size);
}
free(buff);
}
