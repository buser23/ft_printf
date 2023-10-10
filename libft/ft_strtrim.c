/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:56:40 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:41:13 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	Function that takes two string arguments s1 and set, and returns a new 
	string that is a copy of s1 with any leading or trailing characters from 
	set removed.

    1 - The function starts by declaring variables start and end to keep 
	track of the starting and ending indices of the trimmed string, 
	respectively. It also declares a character pointer c to store the 
	trimmed string.

    2 - The variable end is set to the length of the s1 string minus 1.

    3 - A while loop is used to find the starting index of the trimmed 
	string. It continues until start is less than or equal to end and 
	the character at s1[start] is present in the set string. ft_strchr 
	is a helper function that checks if a character is present 
	in a given string.

    4 - If the loop condition start > end is true, it means that 
	the entire string s1 consists of characters in the set string. 
	In this case, the function returns a duplicate of the empty 
	string, obtained using ft_strdup, to signify that there are 
	no non-set characters remaining.

    5 - After finding the starting index, another while loop is 
	used to find the ending index of the trimmed string. It 
	continues until end is greater than or equal to 0 and the 
	character at s1[end] is present in the set string.

    6 - The function then allocates memory for the trimmed string 
	c using malloc. The size of the allocated memory is 
	(end - start + 1) + 1, where end - start + 1 represents 
	the length of the trimmed string, and the extra +1 is for 
	the null terminator.

    7 - If the memory allocation fails (malloc returns NULL), 
	the function returns NULL.

    8 - If the memory allocation is successful, the function 
	copies the trimmed string from s1 to c using ft_strlcpy. 
	The length parameter of ft_strlcpy is (end - start + 1) + 1 
	to ensure the null terminator is included.

    9 - Finally, the function returns the trimmed string c.

*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*c;

	end = ft_strlen(s1) - 1;
	start = 0;
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	if (start > end)
		return (ft_strdup(&s1[end + 1]));
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	c = (char *) malloc(sizeof(char) * (end - start + 1) + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &s1[start], (end - start + 1) + 1);
	return (c);
}

/*
int	main(void)
{
	char *str = "   hello world   ";
    char *trimmed_str = ft_strtrim(str, " ");
    
    printf("Original string: \"%s\"\n", str);
    printf("Trimmed string: \"%s\"\n", trimmed_str);
    
    free(trimmed_str);
    return 0;
}
*/
