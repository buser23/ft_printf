/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:42:08 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:56:18 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

# define HEXBASE "0123456789abcdef"

int		ft_printf(const char *param, ...);
int		print_chr(char c, int *flags);
int		print_str(char *s, int *flags);
int		print_nbr(int n, int *flags);
int		print_hex(unsigned int nbr, int *flags, const char c);
int		print_unsigned(unsigned int n, int *flags);
int		print_pointer(unsigned long long addr, int *flags);
int		ft_intlen(long long n, int base);
void	ft_puthex_fd(unsigned int num, const char c, int fd);
char	*ft_itoapositive(long long n);

#endif