#include <stdlib.h>
#include <stdio.h>
/**
* print_array - the function prints an array of integers provided
* @array: this is the array to be printed
* @size: this is the number of elements in the array
*/
void print_array(const int *array, size_t size)
{
size_t x;
x = 0;
while (array && x < size)
{
if (x > 0)
printf(", ");
printf("%d", array[x]);
++x;
}
printf("\n");
}
