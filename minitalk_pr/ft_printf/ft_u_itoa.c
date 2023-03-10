/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:32:13 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/03/01 21:18:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 数値が何桁か判断する関数
 */
static size_t	ft_malloc_size(unsigned int n)
{
	size_t	malloc_size;

	malloc_size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		malloc_size++;
	}
	return (malloc_size);
}

/*
 * 数値を文字列に格納する
 */
static char	*ft_set_itoa(char *return_str, unsigned int n, size_t size)
{
	while (size > 0)
	{
		return_str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (return_str);
}

/*
 * unsigned intの数値を文字列にして返す関数
 */
char	*ft_u_itoa(unsigned int n)
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
