/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/04 12:42:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <strings.h>

//シグナルハンドラとして定義したい関数
void	ft_signal_handler(int signum)
{
	printf("処理を中断します");
	exit (1);
}

int	main(void)
{
	struct sigaction	sa;

	bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	while (1);
	return (0);
}
