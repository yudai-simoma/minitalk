/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/06 17:41:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	c;

	(void)argc;
	i = 0;
	while (*argv != '\0')
	{
		while (i < 8)
		{
			c = 1 << i;//iの数だけ1をシフトするため1で固定
			c = *argv[2] & c;
			kill((pid_t)atoi(argv[1]), SIGUSR1 + (c >> i));
			i++;
			argv[2]++;
		}
	}
	return (0);
}
