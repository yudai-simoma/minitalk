/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/06 17:55:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;

	(void)argc;
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			c = 1 << j;
			c = argv[2][i] & c;
			kill((pid_t)atoi(argv[1]), SIGUSR1 + (c >> j));
			j++;
		}
		i++;
	}
	return (0);
}
