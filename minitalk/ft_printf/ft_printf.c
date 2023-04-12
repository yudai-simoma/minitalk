/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/01 21:08:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_error_flg = 0;

/*
 * %c の場合に呼ばれる
 * 文字の出力と、出力した文字をの長さを格納する
 */
void	put_char(char a_c, size_t *a_return_num)
{
	int	x;

	x = 0;
	x = write(1, &a_c, 1);
	if (x == -1)
		g_error_flg = -1;
	(*a_return_num)++;
}

/*
 * %s の場合に呼ばれる
 * 文字列の出力と、出力した文字列の長さを格納する
 */
void	put_str(char *a_str, size_t *a_return_num)
{
	if (a_str == NULL)
		a_str = "(null)";
	ft_putstr_fd(a_str, 1);
	(*a_return_num) += ft_strlen(a_str);
}

/*
 * 第一引数が%の場合に%の次文字からのアドレスを受け取り、呼ばれる
 * 変換指定子を処理する
 */
void	ap_puts(const char *a_format, va_list *a_ap, size_t *a_return_num)
{
	if (*a_format == 'c')
		put_char((char)va_arg(*a_ap, int), a_return_num);
	else if (*a_format == 's')
		put_str((char *)va_arg(*a_ap, char *), a_return_num);
	else if (*a_format == 'p')
		put_16_address((void *)va_arg(*a_ap, void *), a_return_num);
	else if (*a_format == 'd' || *a_format == 'i')
		put_nbr((int)va_arg(*a_ap, int), a_return_num);
	else if (*a_format == 'u')
		put_u_nbr((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
	else if (*a_format == 'x')
		put_16_lower((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
	else if (*a_format == 'X')
		put_16_upper((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
	else if (*a_format == '%')
		put_char(*a_format, a_return_num);
	else
		put_char(*a_format, a_return_num);
}

/*
 * main関数から一番初めに呼ばれる関数
 * 第一引数の値を一文字つづ確認し、%が来たら処理を分ける
 * 戻り値は、出力した文字の長さ
 */
int	ft_printf(const char *a_format, ...)
{
	va_list	r_ap;
	size_t	r_return_num;
	size_t	i;

	r_return_num = 0;
	va_start(r_ap, a_format);
	i = 0;
	while (a_format[i] != '\0')
	{
		if (a_format[i] == '%')
			ap_puts(&a_format[++i], &r_ap, &r_return_num);
		else
			put_char(a_format[i], &r_return_num);
		i++;
	}
	va_end(r_ap);
	if (r_return_num > INT_MAX || g_error_flg != 0)
		return (-1);
	else
		return (r_return_num);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int x;
// 	int y;
// 	int a;

// 	x = 0;
// 	y = 0;
// 	a = UINT_MAX + 4;

// 	// x = printf("   printf : %c, %%, %s, %i, %d, %u, %X, %x, %p\n",
//	// a, a, a, a, a, a, a, a);
// 	// y = ft_printf("ft_printf : %c, %%, %s, %i, %d, %u, %X, %x, %p\n",
//	// a, a, a, a, a, a, a, a);
// 	x = printf("   printf : %p\n", a);
// 	y = ft_printf("ft_printf : %p\n", a);
// 	printf ("\nprintf  %d, ft_printf = %d", x, y);
// 	return (0);
// }
