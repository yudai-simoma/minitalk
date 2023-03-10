/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:32:13 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/02/06 17:08:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 数値が何桁か判断する関数
 */
static size_t	ft_malloc_size(long n)
{
	size_t	malloc_size;

	malloc_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		malloc_size = 1;
	}
	while (n)
	{
		n /= 10;
		malloc_size++;
	}
	return (malloc_size);
}

/*
** 受け取った値を交換する
*/
static void	swap_arr_str(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** 配列の要素数の半分だけ繰り返しを行い、端から順に2つの値を取得する
** char配列
*/
static void	ft_rev_str_tab(char *str, size_t size)
{
	size_t	count_loop;
	size_t	arr_num;

	count_loop = size / 2;
	arr_num = 0;
	while (count_loop != 0)
	{
		swap_arr_str(&str[size - 1 - arr_num], &str[arr_num]);
		count_loop--;
		arr_num++;
	}
}

/*
 * 数値を文字列に格納する
 */
static char	*ft_set_itoa(char *return_str, long nn, size_t size, char sign)
{
	size_t	i;

	if (sign == '-')
	{
		size -= 1;
		return_str[size] = '-';
	}
	i = 0;
	while (i < size)
	{
		return_str[i] = (nn % 10) + '0';
		nn /= 10;
		i++;
	}
	return (return_str);
}

/*
 * 数値を文字列にして返す関数
 */
char	*ft_itoa(int n)
{
	char	*return_str;
	long	nn;
	char	sign;
	size_t	malloc_size;

	nn = (long)n;
	malloc_size = ft_malloc_size(nn);
	return_str = (char *)ft_calloc(malloc_size + 1, sizeof(char));
	if (return_str == NULL)
		return (NULL);
	sign = '+';
	if (nn < 0)
	{
		nn *= -1;
		sign = '-';
	}
	return_str = ft_set_itoa(return_str, nn, malloc_size, sign);
	ft_rev_str_tab(return_str, malloc_size);
	return (return_str);
}
