/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:27:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 19:27:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 指定バイト数分のメモリをコピーする関数です。
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cp_dst;
	const unsigned char	*cp_src;
	size_t				i;

	if ((dst == src) || (n == 0))
		return (dst);
	cp_dst = (unsigned char *)dst;
	cp_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cp_dst[i] = cp_src[i];
		i++;
	}
	return (dst);
}
