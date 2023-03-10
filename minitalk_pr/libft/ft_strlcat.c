/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:39:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 20:06:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 与えられた文字列の桁数を返すかつ、NULLでもsegmentation fault	を起こさない
*/
static size_t	ft_strlen_null(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

/*
** 文字型配列destのうしろに文字列srcを連結します。
** 最大でsize - strlen(dst) - 1バイトを追記（-1バイトに'\0'を追加）
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result_num;

	if (dst == NULL && dstsize != 0)
		ft_strlen(NULL);
	if (dstsize != 0)
		result_num = ft_strlen_null(dst) + ft_strlen(src);
	if (ft_strlen_null(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = ft_strlen_null(dst);
	j = 0;
	while (i + 1 < dstsize && j < ft_strlen(src))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result_num);
}
