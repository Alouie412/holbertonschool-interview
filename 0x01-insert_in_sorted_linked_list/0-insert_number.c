#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a node into the appropriate place
 * on the linked list
 * @head: Pointer to the beginning of the linked list
 * @number: The value to be inserted into the linked list
 * Return: The address of the new node. If memory allocation fails,
 * return NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
        listint_t *newhead = *head;
        listint_t *newnode;

        newnode = malloc(sizeof(listint_t));
        if (newnode == NULL)
                return (NULL);

        newnode->n = number;
        
        if (newhead->n > number)
        {
                newnode->next = newhead;
                *head = newnode;
                return (*head);
        }

        while (newhead->next->n < number)
                newhead = newhead->next;
        
        newnode->next = newhead->next;

        newhead->next = newnode;

        return (newhead);
}
