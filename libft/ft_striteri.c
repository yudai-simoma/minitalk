/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:37:01 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/01/31 19:29:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if ((s == NULL) || (f == NULL))
		return ((void)0);
	i = 0;
	while (s[i] != '\0')
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}
