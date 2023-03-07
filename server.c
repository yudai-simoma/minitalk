/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/07 15:43:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <strings.h>

char	ft_conversion_bit_10(int base_2)
{
	int	result;
	int	base;
	int	i;

	result = 0;
	base = 1;
	i = 0;
	/* 2進数を10進数に変換 */
	while(base_2>0){
		result = result + ( base_2 % 10 ) * base;
		base_2 = base_2 / 10;
		base = base * 2;
		i++;
	}

	return ((char)result);
}

//シグナルハンドラとして定義したい関数
void	ft_signal_handler(int signum)
{
	static	int	put_num;
	static	int count;

	if (signum == SIGUSR1)
		put_num = (put_num * 10) + 1;
	if (signum == SIGUSR2)
		put_num = (put_num * 10) + 0;
	count++;
	// printf("put_num = %d, count = %d\n", put_num, count);
	if (count == 8)
	{
		printf("%c\n", ft_conversion_bit_10(put_num));//ft_に変更
		//\nがないと出ない
		put_num = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	printf("%d\n", getpid());//ft_に直す
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
