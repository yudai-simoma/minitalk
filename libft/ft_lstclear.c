/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:23:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/13 16:24:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 与えられたノードを全て削除し，解放する。
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cp_lst;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		cp_lst = *lst;
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
		*lst = cp_lst->next;
	}
	*lst = NULL;
}
