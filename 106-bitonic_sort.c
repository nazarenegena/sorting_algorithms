/*
* Auth: Nazarene Wanyaga
* File: 106-bitonic_sort.c
*/
#include "sort.h"
void swap_ints(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
char flow);
/**
* swap_ints - this swaps integers in the array.
* @a: this is the first integer to swap.
* @b: this is the second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmpArr;
tmpArr = *a;
*a = *b;
*b = tmpArr;
}
/**
* bitonic_merge - this is a sort bitonic sequence.
* @size: this shows the array size .
* @array: this is an array of integers.
* @seq: this is the size of the sequence sort.
* @start: this is the starting index.
* @flow: this is the direction sorted in.
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
char flow)
{
size_t k, jump = seq / 2;
if (seq > 1)
{
for (k = start; k < start + jump; k++)
{
if ((flow == UP && array[k] > array[k + jump]) ||
(flow == DOWN && array[k] < array[k + jump]))
swap_ints(array + k, array + k + jump);
}
bitonic_merge(array, size, start, jump, flow);
bitonic_merge(array, size, start + jump, jump, flow);
}
}
/**
* bitonic_seq - this converts an array to bitonic sequence.
* @size: this is the array size.
* @array: this is the array of int.
* @start: this is the starting index.
* @seq: this is the size of a block of bitonic sequence.
* @flow: this is the  direction to sort..
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
size_t cut = seq / 2;
char *str = (flow == UP) ? "UP" : "DOWN";
if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);
bitonic_seq(array, size, start, cut, UP);
bitonic_seq(array, size, start + cut, cut, DOWN);
bitonic_merge(array, size, start, seq, flow);
printf("Result [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);
}
}
/**
* bitonic_sort - Sort an array of integers in order
* @size: the array.
* @array: this is an array of integers.
*
* Description: this prints the array after swaps.
*/
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
bitonic_seq(array, size, 0, size, UP);
}
