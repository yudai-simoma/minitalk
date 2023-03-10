/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 20:36:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * リストに含まれるノードの数を数える
 */
int	ft_lstsize(t_list *lst)
{
	size_t	return_size;

	return_size = 0;
	while (lst != NULL)
	{
		return_size++;
		lst = lst->next;
	}
	return ((int)return_size);
}
