#include "sort.h"
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
/**
* swap_node_ahead - this is a swap node in a doubly-linked list
* @list: this points to the head of the doubly-linked list.
* @tail: this points to the tail of the doubly-linked list.
* @shaker: this is a pointer to the swapping node .
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmpList = (*shaker)->next;
if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmpList;
else
*list = tmpList;
tmpList->prev = (*shaker)->prev;
(*shaker)->next = tmpList->next;
if (tmpList->next != NULL)
tmpList->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmpList;
tmpList->next = *shaker;
*shaker = tmpList;
}
/**
* swap_node_behind - this is a swap node in a doubly-linked list
* @list: this is a pointer to the head of doubly-linked list.
* @tail: this is a pointer to the tail of doubly-linked list.
* @shaker: this is a pointer to the swapping node.
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmpList = (*shaker)->prev;
if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmpList;
else
*tail = tmpList;
tmpList->next = (*shaker)->next;
(*shaker)->prev = tmpList->prev;
if (tmpList->prev != NULL)
tmpList->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = tmpList;
tmpList->prev = *shaker;
*shaker = tmpList;
}
/**
* cocktail_sort_list - this funct sorts a list of integers in order
* @list: this points to the head of list.
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (tail = *list; tail->next != NULL;)
tail = tail->next;
while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
