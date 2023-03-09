/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:32:09 by yshimoma          #+#    #+#             */
/*   Updated: 2023/01/31 14:37:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 'lst'を繰り返し処理し、関数'f'に'lst'のcontentを適用した結果の新しいリストを作成する
 * 途中で処理が失敗した場合は、全てのノードの内容を削除する
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_list;
	t_list	*new_lst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	return_list = NULL;
	while (lst != NULL)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&return_list, del);
			return (NULL);
		}
		ft_lstadd_back(&return_list, new_lst);
		lst = lst->next;
	}
	return (return_list);
}
