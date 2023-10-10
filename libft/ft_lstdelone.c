/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:38:53 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 15:03:35 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	This function deletes a single node from a linked list.

	1 - The function ft_lstdelone takes two parameters: 
	lst, a pointer to the node to be deleted, and del, 
	a function pointer to the delete function.

    2 - The function checks if both lst and del are not NULL. 
	If either of them is NULL, it means invalid arguments 
	were provided, so the function returns without 
	performing any deletion.

    3 - If both lst and del are not NULL, the function 
	calls the delete function del and passes the content 
	of the node (lst->content) as an argument. This 
	allows the delete function to free any dynamically 
	allocated memory associated with the content.

    4 - After freeing the content, the function calls 
	free to release the memory allocated for the node itself.

    5 - The variable lst is set to NULL (optional step). 
	Note that modifying the local variable lst does not 
	affect the original pointer outside the function.

    6 - Finally, the function terminates.

	By using this ft_lstdelone function, you can delete a single 
	node from a linked list by providing the node to be deleted 
	and the appropriate delete function as arguments.

*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}

/*
int	main(void)
{
	t_list *lst = malloc(sizeof(t_list));
    if (lst == NULL)
    {
        printf("Error: unable to allocate memory\n");
        return 1;
    }

    lst->content = malloc(sizeof(int)); 
	// replace with the actual type of content in your t_list
    if (lst->content == NULL)
    {
        printf("Error: unable to allocate memory\n");
        free(lst);
        return 1;
    }

    *(int *)(lst->content) = 42; 
	// replace with the actual value you want to store in lst->content

    void (*del)(void*) = free; 
	// replace with the actual function to free lst->content

    ft_lstdelone(lst, del);

    return 0;
}
*/