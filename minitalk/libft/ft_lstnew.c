/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:54:53 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/06 17:39:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * t_list型の構造体を作成し、作成した構造体を戻りとする
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*return_list;

	return_list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (return_list == NULL)
		return (NULL);
	return_list->content = content;
	return_list->next = NULL;
	return (return_list);
}
