/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:39:13 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:40:43 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	This function concatenates two input strings s1 and s2 into a newly 
	allocated string. The function returns a pointer to the concatenated string, 
	or NULL if the allocation fails.

	1 - It calculates the total length of the resulting string by summing the 
	lengths of s1 and s2 using the ft_strlen function.

    2 - It calls malloc to allocate memory for the resulting string. It 
	multiplies the length len by the size of a character sizeof(char) and 
	adds 1 to account for the null terminator.

    3 - If the malloc function returns NULL, indicating a failed allocation, 
	the function returns NULL to indicate the failure to allocate memory.

    4 - If the memory allocation is successful, it proceeds to the next step.

    5 - It initializes a variable i to 0 and enters a loop that copies each 
	character from the first string s1 to the newly allocated memory block 
	c until it encounters the null terminator '\0'.

    6 - After copying all characters from s1, it initializes a variable j 
	to 0 and enters a loop that copies each character from the second string 
	s2 to the memory block c starting at the index i + j. This ensures 
	that the characters from s2 are appended to the end of s1 in the 
	resulting string.

    7 - Once all characters from s2 have been copied, it assigns the null 
	terminator '\0' to the last character of the resulting string to 
	ensure proper string termination.

    8 - Finally, it returns the pointer c, which points to the memory 
	block containing the concatenated string.

	The ft_strjoin function concatenates the given strings s1 and s2 by 
	allocating memory for the resulting string, copying the characters 
	from both strings into the new memory block, and properly 
	terminating the resulting string.

*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	c = (char *) malloc(len * sizeof(char) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		c[i + j] = s2[j];
		j++;
	}
	c[i + j] = '\0';
	return (c);
}

/*
int	main(void)
{
	char *s1 = "Hello";
    char *s2 = "World";
    char *result = ft_strjoin(s1, s2);
    if (result) // if result is not NULL
    {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
*/
