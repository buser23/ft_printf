/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:02 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 15:02:46 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_lstadd_back function is another function in a linked list 
	implementation in C. The purpose of ft_lstadd_back is to add a new 
	node to the end of the linked list that lst points to.

	1 - The function ft_lstadd_back takes two parameters: 
	**lst, a double pointer to the head of the list, 
	and *new, a pointer to the new node being added.

	2 - The function checks if either lst or new is NULL. 
	If either of them is NULL, it means an invalid argument 
	was provided, so the function returns without making 
	any changes to the list.

    3 - If both lst and new are not NULL, the function 
	checks if the list is empty by verifying if the head 
	pointer (*lst) is NULL. If the list is empty, it means 
	the new node should become the head of the list, so 
	the function assigns the new node to *lst.

    4 - If the list is not empty, the function enters 
	the else block. It initializes a pointer curr to 
	the head of the list.

    5 - Inside the while loop, the function traverses 
	the list by moving the curr pointer to the next 
	node (curr->next) until reaching the last node. 
	This is determined by checking if the next pointer 
	of the current node is NULL.

    6 - Once the last node is reached, the function 
	assigns the next pointer of the last node to the 
	new node (curr->next = new), effectively adding 
	the new node at the end of the list.

    7 - Finally, the function terminates.

	By using this ft_lstadd_back function, you can add a 
	new node to the end of a linked list by providing 
	the head of the list and the new node as arguments.

*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

/*
int	main(void)
{
	// Create a linked list with 3 nodes
    t_list *head = malloc(sizeof(t_list));
    head->content = "Hello";
    head->next = malloc(sizeof(t_list));
    head->next->content = "World";
    head->next->next = malloc(sizeof(t_list));
    head->next->next->content = "!";
    head->next->next->next = NULL;

    // Add a new element to the end of the linked list
    t_list *new = malloc(sizeof(t_list));
    new->content = "Goodbye";
    new->next = NULL;
    ft_lstadd_back(&head, new);

    // Print the contents of the linked list
    t_list *curr = head;
    while (curr != NULL) {
        printf("%s ", (char *) curr->content);
        curr = curr->next;
    }
    printf("\n");

    // Free the memory used by the linked list
    curr = head;
    while (curr != NULL) {
        t_list *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
*/