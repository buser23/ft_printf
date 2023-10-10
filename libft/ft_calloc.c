/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:10:27 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:49:42 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_calloc function in C dynamically allocates a block of memory 
	for an array of nmemb elements, each of size bytes, and initializes 
	all the bytes in the allocated memory to zero.

	The function returns a pointer to the allocated memory, 
	or NULL if the allocation fails.

	- Allocate memory for nmemb elements of size bytes each 
	p = malloc(nmemb * size);
	- Initialize all bytes of the allocated memory to 0
	ft_bzero (p, nmemb * size);
	
	1 - It first calls the malloc function to allocate memory for 
	the array of elements. It multiplies nmemb by size to determine 
	the total size needed for the allocation.

    2 - If the malloc function returns NULL, it means the allocation 
	was unsuccessful. In that case, the function returns NULL to 
	indicate the failure to allocate memory.

    3 - If the memory allocation is successful, it proceeds to 
	the next step.

    4 - The function calls ft_bzero to set all the bytes in the 
	allocated memory block to zero. This ensures that the allocated 
	memory is properly initialized.

    5 - Finally, the function returns the pointer p, which points 
	to the allocated and zero-initialized memory block.

	The calloc function is similar to malloc, but it also initializes 
	the allocated memory to zero. By using malloc followed by 
	ft_bzero, the ft_calloc function achieves the same effect as 
	the standard calloc function.

*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero (p, nmemb * size);
	return (p);
}

/*
int main(void) 
{
    int *arr;
    int n = 5;
	int i = 0;
    
    arr = (int*)ft_calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }
    
    while (i < n) {
        printf("%d ", arr[i]); // should print 0 0 0 0 0
        i++;
    }
    
    free(arr);
    return 0;
}
*/