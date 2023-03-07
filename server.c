/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/07 12:47:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <strings.h>

// char bit_str[9];

//シグナルハンドラとして定義したい関数
void	ft_signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("1 : SIGUSR1 : signum = %d\n", signum);
	else if (signum == SIGUSR2)
		printf("0 : SIGUSR2 : signum = %d\n", signum);
}

int	main(void)
{
	struct sigaction	sa;

	// bit_str[8] = '\0';
	bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1);
	return (0);
}
