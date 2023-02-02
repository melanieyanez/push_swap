#include <stdio.h>
#include <stdlib.h>

struct node
{
	int			data;
	struct node	*next;
};

// Fonction pour allouer un nouveau nœud
struct node	*newNode(int data)
{
	struct node	*new_node = (struct node*) malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

// Fonction pour ajouter un élément au sommet de la pile
void	push(struct node **head, int data)
{
	struct node	*new_node = newNode(data);

	new_node->next = *head;
	*head = new_node;
}

// Fonction pour retirer un élément du sommet de la pile
void	pop(struct node **head)
{
	struct node	*temp = *head;

	if (*head == NULL)
		return ;
	*head = (*head)->next;
	free(temp);
}

// Fonction pour intervertir les deux premiers éléments de la pile
void	swap(struct node **head)
{
	struct node	*first = *head;
	struct node	*second = (*head)->next;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*head = second;
}

// Fonction pour décaler d'une position vers le haut tous les élements de la pile
void	rotate(struct node **head)
{
	struct node	*last = *head;
	struct node	*new_last = *head;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	*head = (*head)->next;
	new_last->next = NULL;
}

// Fonction pour décaler d'une position vers le bas tous les élements de la pile
void	reverse_rotate(struct node **head)
{
	struct node* last = *head;
	struct node* second_last = NULL;
	
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}
