/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:14:37 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:34:12 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The function ft_strchr is typically used to find the first 
	occurrence of a character c in a null-terminated string s. 

	1 - The function ft_strchr takes two arguments: a pointer s to the input 
	string and an integer c representing the character to search for.

    2 - It declares a local variable a as a char pointer and initializes it 
	with the value of s. This pointer a will be used to iterate 
	over the characters of the string.

    3 - The code enters a while loop that continues until it reaches the end 
	of the string, which is indicated by the null terminator ('\0').

    4 - Inside the loop, it checks if the current character pointed to by a is 
	equal to the character c (after casting c to a char). If they are equal, 
	it means the character is found, and the function returns the pointer a, 
	pointing to the first occurrence of c in the string.

    5 - If the character is not found in the current iteration, the 
	pointer a is incremented to point to the next character in the string.

    6 - After the loop completes, the code performs an additional check to see 
	if the character c is the null terminator. If it is, it means the character 
	is found at the end of the string, and the function returns the pointer a.

    7 - If the character is not found at all, the function returns NULL, 
	indicating that the character c is not present in the string.

*/

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a != '\0')
	{
		if (*a == (char) c)
			return (a);
		a++;
	}
	if (*a == (char) c)
		return (a);
	return (NULL);
}

/*
int main(void) 
{
    char str[] = "Bruno";
    char *ptr = ft_strchr(str, 'r');
    if (ptr != NULL) 
	{
        printf("Found character 'r' at position %ld\n", ptr - str);
    } 
	else 
	{
        printf("Character not found\n");
    }
    return 0;
}
*/