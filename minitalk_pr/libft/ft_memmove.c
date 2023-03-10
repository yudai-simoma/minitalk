/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:09:34 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/10 20:30:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 指定したバイト数のメモリをコピー(移動)する関数です。
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cp_dst;
	const unsigned char	*cp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	cp_dst = (unsigned char *)dst;
	cp_src = (const unsigned char *)src;
	if (dst > src)
	{
		while (len)
		{
			cp_dst[len - 1] = cp_src[len - 1];
			len--;
		}
	}
	else
		return (ft_memcpy(cp_dst, cp_src, len));
	return (dst);
}
