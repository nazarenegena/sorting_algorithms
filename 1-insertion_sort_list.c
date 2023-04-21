#include "sort.h"
/**
* swap_nodes - this is the operational swap for two nodes in the listint_t.
* @h: this is a pointer to the head of our doubly-linked list.
* @n1: this is a pointer to the first node to the swap operation.
* @n2: this is the second node to the swap operation.
*/
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}
/**
* insertion_sort_list - this operation sorts list of the integers.
* @list: this is a pointer to the head of a list of the integers.
* Description: the printed value is the list after swaps.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *iter, *insert, *tmpValue;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (iter = (*list)->next; iter != NULL; iter = tmpValue)
{
tmpValue = iter->next;
insert = iter->prev;
while (insert != NULL && iter->n < insert->n)
{
swap_nodes(list, &insert, iter);
print_list((const listint_t *)*list);
}
}
}
