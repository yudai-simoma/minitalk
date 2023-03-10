/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_address_itoa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:32:13 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/03/01 20:31:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 数値が16進数で何桁か判断する関数
 */
static size_t	ft_malloc_size(uintptr_t n)
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
static char	*ft_set_itoa(char *return_str, uintptr_t n, size_t size)
{
	int		x;
	char	*str;

	str = "0123456789abcdef";
	return_str[0] = '0';
	return_str[1] = 'x';
	size += 2;
	while (size > 2)
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
char	*ft_16_address_itoa(uintptr_t n)
{
	char	*return_str;
	size_t	malloc_size;

	malloc_size = ft_malloc_size(n);
	return_str = (char *)ft_calloc(malloc_size + 3, sizeof(char));
	if (return_str == NULL)
		return (NULL);
	return_str = ft_set_itoa(return_str, n, malloc_size);
	return (return_str);
}
