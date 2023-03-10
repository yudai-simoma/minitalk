/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:06:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 19:26:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 印字文字（表示可能文字）かどうか判定する。
*/
int	ft_isprint(int c)
{
	if (c >= 0040 && c <= 0176)
		return (1);
	else
		return (0);
}
