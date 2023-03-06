/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/06 21:40:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	reverse_str(char bit_str[9])
{
	int		i;
	char	p;

	i = 0;
	while (i < 4)
	{
		p = bit_str[i];
		bit_str[i] = bit_str[7 - i];
		bit_str[7 - i] = p;
		i++;
	}
}

// 2進数表示用の関数
static void	ft_conversion_bit(int num, char bit_str[9])
{
	int	i;
	int	x;

	i = 0;
	while (i < 8)
	{
		x = 1 << i;
		x = num & x;
		bit_str[i] = (x >> i) + '0';
		i++;
	}
	reverse_str(bit_str);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	bit_str[9];

	i = 0;
	bit_str[8] = '\0';
	while (argv[2][i] != '\0')
	{
		ft_conversion_bit(argv[2][i], bit_str);
		j = 0;
		while (j < 8)
		{
			if (bit_str[j] == '1')
				kill((pid_t)atoi(argv[1]), SIGUSR1);
			else if (bit_str[j] == '0')
				kill((pid_t)atoi(argv[1]), SIGUSR2);
			j++;
			usleep(100000);
		}
		i++;
	}
	return (0);
}
