#include <stdlib.h>
#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the deck
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *deck = node2;

    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *next;
    int swapped;

    if (deck == NULL || *deck == NULL)
        return;

    do {
        swapped = 0;
        current = *deck;

        while (current->next != NULL)
        {
            next = current->next;

            if (strcmp(current->card->value, next->card->value) > 0 ||
                (strcmp(current->card->value, next->card->value) == 0 &&
                 current->card->kind > next->card->kind))
            {
                swap_nodes(deck, current, next);
                swapped = 1;
                print_deck(*deck);
            }
            else
            {
                current = current->next;
            }
        }
    } while (swapped);
}

