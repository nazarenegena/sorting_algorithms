#include <stdio.h>
#include "sort.h"
/**
* print_list - this function prints the list of integers
*
* @list: this is the list to be printed
*/
void print_list(const listint_t *list)
{
int x;
x = 0;
while (list)
{
if (x > 0)
printf(", ");
printf("%d", list->n);
++x;
list = list->next;
}
printf("\n");
}
