/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:07:24 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:59:23 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The purpose of the ft_lstsize function is to count the number of nodes 
	in the linked list that lst points to, and return the count as an integer. 
	The ft_ prefix is likely used to indicate that this function is part of a 
	custom library or module, and is not a standard C library function.

	This function calculates the size of a linked list by 
	counting the number of nodes in it. 

	1 - The function ft_lstsize takes one parameter: lst, a 
	pointer to the head of the list.

    2 - The function initializes a variable count to 0. 
	This variable will be used to keep track of the 
	number of nodes in the list.

    3 - Inside the while loop, the function checks if 
	the current node (lst) is not NULL. If it's not NULL, 
	it means there are more nodes in the list, so 
	the loop continues.

    4 - Inside the loop, the count variable is 
	incremented by 1, indicating that a node has 
	been counted.

    5 - The lst pointer is then updated to point 
	to the next node (lst->next), moving the 
	traversal forward in the list.

    6 - The loop continues until lst becomes NULL, 
	which means the end of the list has been reached.

    7 - Finally, the function returns the value of 
	count, which represents the total number of 
	nodes in the list.

	By using this ft_lstsize function, you can determine 
	the size of a linked list by providing the head of the 
	list as an argument.
	
*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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

    // Get the size of the linked list
    int size = ft_lstsize(head);

    // Print the size
    printf("Size of the linked list: %d\n", size);

    // Free the memory used by the linked list
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
*/