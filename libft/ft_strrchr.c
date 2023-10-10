/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:24:55 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:34:44 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The function ft_strrchr is similar to ft_strchr, but it searches 
	for the last occurrence of the character c in the null-terminated string s. 

	1 - The function ft_strrchr takes two arguments: a pointer s to the input 
	string and an integer c representing the character to search for.

    2 - It declares a local variable a as a char pointer and 
	initializes it to NULL. This pointer a will be used to keep track 
	of the last occurrence of the character c in the string.

    3 - The code enters a while loop that continues until it reaches 
	the end of the string, which is indicated by the null terminator ('\0').

    4 - Inside the loop, it checks if the current character pointed 
	to by s is equal to the character c (after casting c to a char). 
	If they are equal, it updates the pointer a to point to the 
	current character. This is done to keep track of the 
	last occurrence of c in the string.

    5 - In each iteration, the pointer s is incremented to point 
	to the next character in the string.

    6 - After the loop completes, the code performs an additional 
	check to see if the character c is the null terminator. If it is, 
	it means the character is found at the end of the string, and 
	the pointer a is updated to point to the null terminator.

    7 - The function then returns the pointer a, which points to the 
	last occurrence of the character c in the string. If the character 
	is not found at all, the initial value of a (NULL) is returned.

*/

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			a = (char *)s;
		s++;
	}
	if (*s == (char)c)
		a = (char *)s;
	return (a);
}

/*
int main(void) 
{
    char str[] = "Bruno";
    char *ptr = ft_strrchr(str, 'r');
	long pos = (str + strlen(str) - ptr) - 1;
    if (ptr != NULL) 
	{
        printf("Found 'r' at position %ld from the end\n", pos);
    } 
	else 
	{
        printf("Character not found\n");
    }
    return 0;
}
*/