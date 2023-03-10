/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:37:32 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/06 17:08:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** f関数に文字列sの文字を渡し、文字列を作成する
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*src;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	src = (char *)ft_calloc(sizeof(char) * ft_strlen(s) + 1, sizeof(char));
	if (src == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		src[i] = f((unsigned int)i, s[i]);
		i++;
	}
	src[i] = '\0';
	return (src);
}
