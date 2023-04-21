#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
/* this is the macros comparison for bitonic sort */
#define UP 0
#define DOWN 1
/**
* enum bool - the enumeration of Boolean values.
* @true: shows that true equals 1.
* @false: shows that false equals 0.
*/
typedef enum bool
{
false = 0,
true
} bool;
/**
* struct listint_s - this is the doubly linked list node
* @n: the integer is then stored in the node
* @prev: this is the pointer to the previous element in the list
* @next: this is the pointer to the next element in the list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;
/* to print the helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
/* operations for Sorting the algoritms */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
#endif /* SORT_H */
