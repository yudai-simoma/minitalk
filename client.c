/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:35:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/08 23:06:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * 1文字をint(10進数)で受け取り8ビットの文字列(2進数)へ格納する関数
 * ビット演算で2進数へ変換
 * 変換方法
 * 	1は2進数で、00000001
 * 	1を基準に、桁を一つずつずらし、AND演算で0,1を格納している
 */
static void	ft_conversion_bit_2(int a_num, char a_bit_str[9])
{
	int	i;
	int	r_base_1;

	i = 7;
	while (i >= 0)
	{
		r_base_1 = 1 << i;
		r_base_1 = a_num & r_base_1;
		a_bit_str[i] = (r_base_1 >> i) + '0';
		i--;
	}
}

/*
 * serverへ文字列を送るプログラム（正常に送れたらserverからもシグナルを受け取る）
 * コマンドライン引数：第二引数　プロセスID
 * 　　　　　　　　　　第三引数　sarverへ送りたい文字列
 * 文字列を一文字ずつ送信、1文字を8ビットのバイナリデータで送信する
 * 一文字ずつft_conversion_bit2の関数へ渡し、バイナリデータを作成
 * 
 * usleepは450に設定、一秒間に約277文字遅れる設定にしている
 * 計算方法
 * 	1秒は1000000マイクロ秒 
 * 	450 * 8 = 3600マイクロ秒
 * 	1000000 / 3600 = 227
 */
int	main(int a_argc, char *a_argv[])
{
	int		i;
	int		j;
	char	r_bit_str[9];

	i = 0;
	r_bit_str[8] = '\0';
	while (a_argv[2][i] != '\0')
	{
		ft_conversion_bit_2((int)a_argv[2][i], r_bit_str);
		j = 0;
		while (j < 8)
		{
			if (r_bit_str[j] == '1')
				kill((pid_t)ft_atoi(a_argv[1]), SIGUSR1);
			else if (r_bit_str[j] == '0')
				kill((pid_t)ft_atoi(a_argv[1]), SIGUSR2);
			j++;
			usleep(450);
		}
		i++;
	}
	return (0);
}

//エラー処理
//秒数指定の秒数確認
//serverからのシグナル受け取り
//Makefile,libft,printfを使用できるようにする