/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:18:38 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 20:45:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** メモリに指定バイト数分の値をセットすることができます。
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bb;
	unsigned char	cc;
	size_t			i;

	bb = (unsigned char *)b;
	cc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*bb = cc;
		bb++;
		i++;
	}
	return (b);
}
