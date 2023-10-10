/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:46:08 by brunofernan       #+#    #+#             */
/*   Updated: 2023/05/22 15:26:44 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	This function clears a linked list by deleting all nodes 
	and freeing the associated memory. 

	1 - The function ft_lstclear takes two parameters: 
	**lst, a double pointer to the head of the list, 
	and del, a function pointer to the delete function.

    2 - The function checks if both lst and del are not 
	NULL. If either of them is NULL, it means invalid arguments 
	were provided, so the function returns without performing 
	any deletion.

    3 - If both lst and del are not NULL, the function 
	assigns the head of the list (*lst) to the variable current.

    4 - Inside the while loop, the function iterates through 
	the list until reaching the end. The loop continues as 
	long as current is not NULL.

    5 - Within the loop, the function stores the next node 
	in the variable next before deleting the current node. 
	This is done to ensure we have a reference to the next 
	node after deleting the current one.

    6 - The function then calls the delete function del 
	and passes the content of the current node (current->content) 
	as an argument. This allows the delete function to free 
	any dynamically allocated memory associated with the content.

    7 - After freeing the content, the function calls 
	free to release the memory allocated for the 
	current node.

    8 - The variable current is updated to point to the 
	next node (current = next), effectively moving 
	the traversal forward in the list.

    9 - The loop continues until current becomes NULL, 
	which means the end of the list has been reached.

    10 - Finally, the head of the list (*lst) is set to NULL, 
	indicating that the list is now empty.

	By using this ft_lstclear function, you can clear a linked list 
	by providing a pointer to the head of the list and the 
	appropriate delete function as arguments.

	The del function is an example deletion function that frees 
	the memory of the content. This function can be used as the 
	delete function in the ft_lstdelone or ft_lstclear 
	functions to release the memory associated with the 
	content of a node.

*/

/*
void    del(void *content) 
{
    free(content); // Example deletion function, adjust according to your needs
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*current;

	if (lst != NULL && del != NULL)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			del(current->content);
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

/*
int	main(void)
{
	// Create a sample list
    t_list *node1 = malloc(sizeof(t_list));
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    node1->content = value1;

    t_list *node2 = malloc(sizeof(t_list));
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    node2->content = value2;

    t_list *node3 = malloc(sizeof(t_list));
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    node3->content = value3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Call ft_lstclear
    t_list *list = node1;
    ft_lstclear(&list, del);

    // Check if the list is cleared
    if (list == NULL) {
        printf("List cleared successfully!\n");
    } else {
        printf("List not cleared properly.\n");
    }

    return 0;
}
*/