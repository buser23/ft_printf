/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:54:11 by brunofernan       #+#    #+#             */
/*   Updated: 2023/05/22 15:07:46 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The function ft_lstiter takes in two parameters: a pointer to the first 
	element of a linked list, lst, and a pointer to a function, f, that takes 
	in a void pointer as its parameter and returns void.

	The purpose of ft_lstiter is to apply the function f to every element in 
	the linked list. This is achieved by iterating through the linked list 
	using a while loop and applying f to the data element of each node.

	This function applies a given function to each node of a 
	linked list.   

	1 - The function ft_lstiter takes two parameters: lst, 
	a pointer to the head of the list, and f, a function 
	pointer to the function to be applied to each node.

    2 - The function checks if both lst and f are not NULL. 
	If either of them is NULL, it means invalid arguments 
	were provided, so the function returns without 
	performing any iteration.

    3 - If both lst and f are not NULL, the function 
	enters the while loop. The loop continues as long 
	as lst is not NULL.

    4 - Inside the loop, the function calls the function f 
	and passes the content of the current node (lst->content) 
	as an argument. This allows the function f to perform 
	some operation on the content of the node.

    5 - After applying the function to the content, 
	the function updates lst to point to the next node 
	(lst = lst->next), effectively moving the traversal 
	forward in the list.

    6 - The loop continues until lst becomes NULL, 
	which means the end of the list has been reached.

    7 - Finally, the function terminates.

	By using this ft_lstiter function, you can apply a given 
	function to each node of a linked list by providing the 
	head of the list and the appropriate function as arguments. 
	This can be useful, for example, to perform some operation 
	on each element of the list or to update the content of 
	the nodes based on some criteria.

	The print_content function is an example 
	function that prints the content of a node. This 
	function can be used as the function to be applied 
	to each node in the ft_lstiter function to print 
	the content of each node in the linked list.

*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

/*
void	print_content(void *content)
{
    printf("%s\n", (char *)content);
}
*/

/*
int	main(void)
{
	// Create a linked list with 3 elements
    t_list *lst = malloc(sizeof(t_list));
    lst->content = "Hello";
    lst->next = malloc(sizeof(t_list));
    lst->next->content = "world";
    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->content = "!";
    lst->next->next->next = NULL;

    // Apply print_content to each element in the list
    ft_lstiter(lst, &print_content);

    // Free the memory allocated for the linked list
    t_list *curr = lst;
    while (curr)
    {
        t_list *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
*/