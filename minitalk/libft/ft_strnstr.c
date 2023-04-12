/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:52:17 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/01 21:39:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 引数のエラーチェックをする
*/
static void	ft_err_check(const char *dst, const char *src, size_t dstsize)
{
	if (src == NULL)
		ft_strlen(NULL);
	if (dst == NULL && dstsize != 0)
		ft_strlen(NULL);
}

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
** s1 の文字と s2 の文字が一致した場合、次の文字同士を比較する
** s2の文字数と、一致した数が同じ場合、tureを返す
*/
static int	ft_match_src(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (*haystack != '\0' && needle[i] != '\0' && i < len)
	{
		if (*haystack != needle[i])
			return (0);
		haystack++;
		i++;
	}
	if (i == ft_strlen(needle))
		return (1);
	return (0);
}

/*
** 文字列 s1 の先頭からsize_t文字目まで、文字列 s2 を探し、見つかったときにはその位置をポインタで返却し、
** 見つからなかったときにはNULLを返却します。
** s１とs２で同じ文字なら、別関数に渡し２文字目からn回を見る
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	ft_err_check(haystack, needle, len);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen_null(haystack) < ft_strlen(needle) || ft_strlen(needle) > len)
		return (0);
	i = 0;
	while (haystack[i] != '\0' && len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			if (ft_match_src(&haystack[i], &needle[j], len))
				return ((char *)&haystack[i]);
		}
		len--;
		i++;
	}
	return (0);
}
