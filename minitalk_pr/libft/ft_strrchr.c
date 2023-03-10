/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:22:56 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/05 12:02:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 文字列の「最後」から「文字」を検索して見つかった場所をポインタで返します。
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
