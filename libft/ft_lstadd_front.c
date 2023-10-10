/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:54:41 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:58:18 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_lstadd_front function adds the given element new to the beginning 
	of the linked list pointed to by lst.

	1 - The function ft_lstadd_front takes two parameters: **lst, a 
	double pointer to the head of the list, and *new, a pointer to 
	the new node being added.

    2 - The function checks if both lst and new are not NULL. 
	This check ensures that valid pointers are provided for the 
	list and the new node.

    3 - If the check passes, the next pointer of the new 
	node is assigned the value of the current head of the 
	list (*lst). This step links the new node to the rest 
	of the list.

    4 - Finally, the head of the list (*lst) is updated to 
	point to the new node. This step makes the new node 
	the new head of the list, effectively adding it to the front.
	
	By using this ft_lstadd_front function, you can add a new node 
	to the beginning of a linked list.
	
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
int	main(void)
{
	t_list *lst = NULL;
    t_list *new_node;

    // Create a new node with content "Hello"
    new_node = ft_lstnew("Hello");

    // Add the new node to the front of the linked list
    ft_lstadd_front(&lst, new_node);

    // Print the contents of the first node in the linked list
    printf("First node content: %s\n", (char*)lst->content);

    return 0;
}
*/