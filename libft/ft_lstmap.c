/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:10:08 by brunofernan       #+#    #+#             */
/*   Updated: 2023/05/22 15:08:59 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_lstmap function takes a linked list lst and applies the function f 
	to each element of the list, creating a new list with the modified content. 
	The del function is used to free the memory of the original linked list in 
	case of an error during the execution of ft_lstmap.	

	This function creates a new linked list by applying a 
	function to each node of an existing linked list. 

	1 - The function ft_lstmap takes three parameters: lst, 
	a pointer to the head of the original list, f, a function 
	pointer to the function to be applied to each node, and del, 
	a function pointer to the delete function.

    2 - The function checks if either lst or f is NULL. If either 
	of them is NULL, it means invalid arguments were provided, 
	so the function returns NULL without performing any mapping.

    3 - If both lst and f are not NULL, the function initializes 
	two pointers: new_lst to keep track of the new list being 
	created, and new_node to temporarily store the newly created nodes.

    4 - The function enters the while loop, which iterates 
	through the original list until reaching the end (NULL).

    5 - Inside the loop, the function creates a new node by 
	applying the function f to the content of the current 
	node (f(lst->content)). The returned value is used as 
	the content of the new node.

    6 - The function checks if the memory allocation 
	for the new node failed (!new_node). If it did fail, 
	indicating insufficient memory, the function clears 
	the new list using ft_lstclear to free any memory 
	that has been allocated so far. Then it returns 
	NULL to indicate the failure.

    7 - If the memory allocation is successful, the 
	function adds the new node to the new list using 
	ft_lstadd_back.

    8 - The pointer lst is updated to point to the next 
	node in the original list (lst = lst->next), 
	effectively moving the traversal forward.

    9 - The loop continues until lst becomes NULL, 
	which means the end of the original list has been reached.

    10 - Finally, the function returns the new list 
	(new_lst) that has been created.

	By using this ft_lstmap function, you can create a new linked 
	list by applying a given function to each node of an existing list. 
	The new list will contain nodes with content obtained by 
	applying the function to the content of the original list's nodes.

	The add_one function is an example function 
	that adds one to an integer. This function can be used as the 
	function to be applied to each node in the ft_lstmap function 
	to create a new linked list where each node contains an 
	integer incremented by one.

	The print_list function is an example function 
	that prints the content of each node in a linked list. It assumes 
	that the content of each node is an integer.

*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
void *add_one(void *num)
{
    int *result = malloc(sizeof(int));
    if (result)
        *result = (*(int*)num) + 1;
    return result;
}
*/

/*
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", *(int*)lst->content);
        lst = lst->next;
    }
    printf("\n");
}
*/

/*
int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
  int arr_size = sizeof(arr) / sizeof(int);
  t_list *lst = NULL;

  for (int i = 0; i < arr_size; i++)
      ft_lstadd_back(&lst, ft_lstnew(&arr[i]));

  printf("Original list: ");
  print_list(lst);

  t_list *new_lst = ft_lstmap(lst, add_one, free);

  printf("New list: ");
  print_list(new_lst);

  ft_lstclear(&lst, NULL);
  ft_lstclear(&new_lst, NULL);

  return 0;
}
*/