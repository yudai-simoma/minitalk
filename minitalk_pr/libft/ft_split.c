/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:30:48 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/03/01 21:39:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** mallocに失敗した場合、それまでに作成されていたメモリをfreeしてNULLを返す
*/
static char	**ft_free(char **split_s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split_s[i]);
		split_s[i] = NULL;
		i++;
	}
	free(split_s);
	split_s = NULL;
	return (NULL);
}

/*
** split文字か判断、split文字なら0を返し、split文字でない場合は1を返す
*/
static int	charset_jud(char const s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

/*
** 2次元目の配列のにサイズを確保し代入する
*/
static char	*ft_add_s(char const *s, char c)
{
	int		i;
	char	*return_str;

	i = 0;
	while (s[i] != '\0' && charset_jud(s[i], c) == 1)
		i++;
	return_str = (char *)ft_calloc(sizeof(char) * (i + 1), sizeof(char));
	if (return_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && charset_jud(s[i], c) == 1)
	{
		return_str[i] = s[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

/*
** 1次元目の配列の要素数を返す
*/
static char	**ft_array_malloc(char const *s, char c)
{
	size_t	i;
	size_t	array_size;
	char	**return_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	array_size = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && charset_jud(s[i], c) == 0)
			i++;
		if (s[i] != '\0')
			array_size++;
		while (s[i] != '\0' && charset_jud(s[i], c) == 1)
			i++;
	}
	return_str = (char **)ft_calloc(sizeof(char *) * (array_size + 1), 1);
	return (return_str);
}

/*
** sの中からcの文字列を区切り文字とし、2次元配列へ格納する
*/
char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	i;
	size_t	j;

	split_s = ft_array_malloc(s, c);
	if (split_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && charset_jud(s[i], c) == 0)
			i++;
		if (s[i] != '\0')
		{
			split_s[j] = ft_add_s(&s[i], c);
			if (split_s[j] == NULL)
				return (ft_free(split_s, j));
			++j;
		}
		while (s[i] != '\0' && charset_jud(s[i], c) == 1)
			i++;
	}
	split_s[j] = NULL;
	return (split_s);
}
