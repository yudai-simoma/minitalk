/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:52:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 前方の削除したい文字数を返す
 */
static size_t	ft_start_num(char const *s1, char const *set)
{
	size_t	i;
	size_t	return_num;

	i = 0;
	return_num = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr((const char *)set, (int)s1[i]) != 0)
			return_num++;
		else
			return (return_num);
		i++;
	}
	return (0);
}

/*
 * 文字数 - 前方の削除したい文字数 - 後方の削除したい文字数を返す
 */
static size_t	ft_trim_len(char const *s1, char const *set, size_t	start_num)
{
	size_t	i;
	size_t	return_num;

	i = ft_strlen(s1);
	return_num = 0;
	while (i)
	{
		i--;
		if (ft_strrchr((const char *)set, (int)s1[i]) != 0)
			return_num++;
		else
			return (ft_strlen(s1) - return_num - start_num);
	}
	return (0);
}

/*
** 文字列*s1 から文字列*s2 を取り除いた文字列を返す
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_num;
	size_t	trim_len;
	char	*return_src;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	start_num = ft_start_num(s1, set);
	trim_len = ft_trim_len(s1, set, start_num);
	return_src = ft_substr((const char *)s1, (unsigned int)start_num, trim_len);
	return (return_src);
}
