#ifndef DECK_H
#define DECK_H
#include <stdlib.h>
/**
* enum kind_e - this is the enumeration of cards
* @SPADE: the spades suit.
* @CLUB: the clubs suit.
* @HEART: the hearts suit.
* @DIAMOND: the diamonds suit.
*/
typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;
/**
* struct card_s - the playing card
*
* @value: shows the value of the card
* @kind: the kind of the card
*/
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;
/**
* struct deck_node_s - this is the deck of card
*
* @card: the pointer to the card.
* @next: the pointer to the next node.
* @prev: the pointer to the list.
*/
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;
void sort_deck(deck_node_t **deck);
#endif /* DECK_H */
