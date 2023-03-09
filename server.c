/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/09 18:23:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * int(2進数)を受け取り、1文字の10進数へ変換する関数
 * 変換方法
 * 	例えば、1001を10進数に変換する場合、1001の1に1をかけて1、次に0に2を掛けて0、
 * 	次に0に4をかけて0、次に1に8を掛けて8、最後に全部足した値の9が10進数の数値になる。
 */
char	ft_conversion_bit_10(int a_base_2)
{
	int	r_return_c;
	int	r_up_num;

	r_return_c = 0;
	r_up_num = 1;
	while (a_base_2 > 0)
	{
		r_return_c = r_return_c + ((a_base_2 % 10) * r_up_num);
		a_base_2 = a_base_2 / 10;
		r_up_num *= 2;
	}
	return ((char)r_return_c);
}

//シグナルハンドラとして定義したい関数
/*
 * シグナルハンドラとして定義した関数
 * シグナルが送られてくると呼ばれ8ビット分の0,1を受け取り、ft_conversion_bit_10へ渡し2進数に変換
 * 2進数になった数値を10進数へ変換し、出力する
 * 
 */
void	ft_signal_handler(int a_signum)
{
	static int	r_binary_num;
	static int	r_count;
	char		r_put_c;

	if (a_signum == SIGUSR1)
		r_binary_num = (r_binary_num * 10) + 1;
	if (a_signum == SIGUSR2)
		r_binary_num = (r_binary_num * 10) + 0;
	r_count++;
	if (r_count == 8)
	{
		r_put_c = ft_conversion_bit_10(r_binary_num);
		write(1, &r_put_c, 1);
		r_binary_num = 0;
		r_count = 0;
		r_put_c = '\0';
	}
}

/*
 * clientからシグナル(0,1)を受け取り文字に変換後、出力するプログラム（正常に受け取れたらclientにシグナルを送信する）
 * SIGUSR1 : 1
 * SIGUSR2 : 0
 * シグナルが送られるとft_signal_handler関数が呼ばれ、2進数の数値を作成する
 * pause関数を使用し、スレッドの実行を中断しておく
 */
int	main(void)
{
	struct sigaction	r_sa;

	ft_bzero(&r_sa, sizeof(struct sigaction));
	r_sa.sa_handler = ft_signal_handler;
	sigemptyset(&r_sa.sa_mask);
	sigaddset(&r_sa.sa_mask, SIGUSR1);
	sigaddset(&r_sa.sa_mask, SIGUSR2);
	r_sa.sa_flags = 0;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &r_sa, NULL);
	sigaction(SIGUSR2, &r_sa, NULL);
	while (1)
		pause();
	return (0);
}

//client側へのシグナル送信
//exit関数の使用有無

/*
 * 実行方法
 * cc server.c -o server
 * ./server
 */