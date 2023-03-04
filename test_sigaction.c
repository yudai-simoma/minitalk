/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:05:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/04 11:26:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

//シグナルハンドラとして定義したい関数
void	ft_signal_handler(int signum)
{
	printf("処理を中断します");
	exit (1);
}

int	main(void)
{
	//シグナルハンドラの登録
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ft_signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);

	while (1);

	return (0);
}

// int	main(void)
// {
// 	signal(SIGINT, ft_signal_handler);

// 	while (1);
// 	return (0);
// }