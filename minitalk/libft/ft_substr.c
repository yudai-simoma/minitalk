/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/10 21:05:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * エラーチェック
 */
static int	ft_err_check(char const *s, unsigned int start)
{
	if (s == NULL)
		return (1);
	if (ft_strlen(s) <= (size_t)start)
		return (2);
	return (0);
}

/*
 * s文字列の中で、startから最大len分文字を抽出し、戻り値として返す。
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_str;
	size_t	malloc_size;
	size_t	i;

	if (ft_err_check(s, start) == 1)
		return (NULL);
	else if (ft_err_check(s, start) == 2)
		len = 0;
	if (ft_strlen(s) <= len)
		malloc_size = ft_strlen(s) - (size_t)start;
	else
		malloc_size = len;
	return_str = (char *)ft_calloc(sizeof(char) * (malloc_size + 1), 1);
	if (return_str == NULL)
		return (NULL);
	i = 0;
	while (i < malloc_size)
	{
		return_str[i] = s[start + i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}
