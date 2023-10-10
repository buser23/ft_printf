/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:53:48 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:47:57 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The function ft_strmapi takes in a string s and a function pointer f that 
	takes an unsigned integer and a character as arguments and returns a character. 
	The function returns a new string that is the result of applying the 
	function f to each character in the input string s.

    1 - Declare size_t variables len and i. len will be used to store 
	the length of the input string s, and i will be used as a 
	loop counter.

    2 - Calculate the length of the input string s using the 
	ft_strlen function.

    3 - Allocate memory for the resulting string result 
	using malloc. The size of the allocated memory is 
	calculated as (len + 1) to accommodate the characters 
	of the string plus the null character '\0' at the end.

    4 - Check if the memory allocation was successful. 
	If not, return NULL to indicate an error.

    5 - Start a loop that continues while i is less than len.

    6 - Inside the loop, assign the character returned by 
	applying the function f to the index i and the character 
	s[i] to result[i].

    7 - Increment i to move to the next character 
	in the string.

    8 - Assign the null character '\0' to the last 
	position in the string result to terminate it.

    9 - Return the dynamically allocated string result.

	In summary, the function ft_strmapi applies a 
	provided function f to each character of an input 
	string s and creates a new string containing the 
	results. It dynamically allocates memory for the 
	resulting string and returns it.

*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

/*
char	add_one(unsigned int index, char c)
{
    return c + 1;
}
*/

/*
int	main(void)
{
	const char* input = "Hello, world!";

    char* output = ft_strmapi(input, add_one);

    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);

    free(output); // Free memory allocated by ft_strmapi

    return 0;
}
*/
