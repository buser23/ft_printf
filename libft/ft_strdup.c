/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:29:01 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:40:03 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_strdup() function is a string manipulation function in C that 
	duplicates a string. It takes a const char *s parameter, which is a pointer 
	to the original string that we want to duplicate, and returns a pointer 
	to a new string that is a copy of the original.
	
	1 - It first calculates the length of the input string str using the 
	ft_strlen function. This length will be used to determine the size 
	of the memory block needed to store the duplicate string.

    2 - It then calls the malloc function to allocate memory for the 
	new string. It multiplies the length len by the size of a character 
	sizeof(char) and adds 1 to account for the null terminator.

    3 - If the malloc function returns NULL, indicating a failed 
	allocation, the function returns NULL to indicate the failure 
	to allocate memory.

    4 - If the memory allocation is successful, it proceeds to 
	the next step.

    5 - It initializes a variable i to 0 and enters a loop that 
	iterates len times.

    6 - Inside the loop, it copies each character from the 
	original string str to the newly allocated memory block p 
	character by character.

    7 - After copying all characters, it assigns the null terminator 
	'\0' to the last character of the duplicated string to ensure 
	proper string termination.

    8 - Finally, it returns the pointer p, which points to 
	the duplicated string.

	The ft_strdup function creates a duplicate of the given string 
	by allocating memory for the new string and copying the 
	contents of the original string into it. It handles the 
	allocation and copying process, and returns the pointer 
	to the duplicated string.

*/

char	*ft_strdup(const char *str)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	p = (char *) malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
int	main(void)
{
	char	str[] = "Hello";
	char	*d = ft_strdup(str);
	printf("Source: %s | Dest: %s | LastChar: '%c'\n", str, d, d[5]);
	free(d);

	return (0);
}
*/