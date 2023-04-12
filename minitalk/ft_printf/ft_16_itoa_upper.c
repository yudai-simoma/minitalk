/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_itoa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:50:39 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/01 18:39:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 数値が16進数で何桁か判断する関数
 */
static size_t	ft_malloc_size(unsigned int n)
{
	size_t	malloc_size;

	malloc_size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		malloc_size++;
	}
	return (malloc_size);
}

/*
 * 数値を小文字16進数に変換した文字列に格納する
 */
static char	*ft_set_itoa(char *return_str, unsigned int n, size_t size)
{
	int		x;
	char	*str;

	str = "0123456789ABCDEF";
	while (size > 0)
	{
		x = n % 16;
		return_str[size - 1] = str[x];
		n /= 16;
		size--;
	}
	return (return_str);
}

/*
 * 数値を小文字16進数に変換し、変換後を文字列にして返す関数
 */
char	*ft_16_itoa_upper(unsigned int n)
{
	char	*return_str;
	size_t	malloc_size;

	malloc_size = ft_malloc_size(n);
	return_str = (char *)ft_calloc(malloc_size + 1, sizeof(char));
	if (return_str == NULL)
		return (NULL);
	return_str = ft_set_itoa(return_str, n, malloc_size);
	return (return_str);
}
