/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:18:00 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 15:01:55 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_lstlast function is likely another function in a linked list 
	implementation in C. The purpose of ft_lstlast is to find the last 
	node in the linked list that lst points to and return a pointer to it.

	1 - The function ft_lstlast takes one parameter: lst, a pointer 
	to the head of the list.

    2 - The function checks if the list is empty by verifying if 
	the head pointer (lst) is NULL. If it is NULL, it means the 
	list is empty, so the function returns NULL.

    3 - If the list is not empty, the function enters a 
	while loop that continues until the last node is reached. 
	This is determined by checking if the next pointer of the 
	current node is NULL.

    4 - Inside the loop, the function updates the lst pointer 
	to point to the next node (lst->next), effectively 
	traversing the list towards the end.

    5 - Once the last node is reached, the loop exits.

    6 - Finally, the function returns the pointer to the 
	last node (lst), which represents the last element 
	of the list.

	By using this ft_lstlast function, you can obtain a pointer 
	to the last node of a linked list by providing the head 
	of the list as an argument.

*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
	the size of a linked list by providing the head of the (sizeof(t_list));
    head->content = "Hello";
    head->next = malloc(sizeof(t_list));
    head->next->content = "World";
    head->next->next = malloc(sizeof(t_list));
    head->next->next->content = "!";
    head->next->next->next = NULL;

    // Get the last element of the linked list
    t_list *last = ft_lstlast(head);

    // Print the last element's content
    printf("Last element's content: %s\n", (char *) last->content);

    // Free the memory used by the linked list
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
*/