/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/11 21:18:33 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strがlong型の最大値を超えるか判断する関数
*/
static long	ft_max_check(const char *str, int sign)
{
	long	return_num;
	long	i;

	return_num = 0;
	i = 0;
	while ((str[i] != '\0')
		&& (((str[i] == '+' || str[i] == '-') || (str[i] == '0'))
			|| ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))))
		i++;
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		if (return_num < ((LONG_MIN + (str[i] - '0')) / 10))
		{
			if (sign == 0)
				return (1);
			return (2);
		}
		return_num *= 10;
		return_num -= str[i] - '0';
		i++;
	}
	if (sign == 0 && return_num == LONG_MIN)
		return (1);
	return (0);
}

/*
** strが数値より前に+,-以外の文字があるかチェック
*/
static int	ft_err_check(const char *str)
{
	int	i;

	while ((*str != '\0')
		&& ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		if ((str[i] != '-' && str[i] != '+') && (str[i] < '0' || str[i] > '9'))
			return (1);
		if ((i > 0) && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
** strの符号チェック
*/
static int	ft_sign_check(const char *str)
{
	int	sign;

	sign = 0;
	while ((*str != '\0')
		&& (((*str == '+' || *str == '-') || (*str == '0'))
			|| ((*str >= 9 && *str <= 13) || (*str == 32))))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	return (sign);
}

/*
** strの文字列の最初の数字を、int型に変換する関数
*/
int	ft_atoi(const char *str)
{
	int		sign;
	long	result_num;

	result_num = 0;
	if (ft_err_check(str))
		return (0);
	sign = ft_sign_check(str);
	if (ft_max_check(str, sign) == 1)
		return ((int)LONG_MAX);
	else if (ft_max_check(str, sign) == 2)
		return ((int)LONG_MIN);
	while ((*str != '\0')
		&& (((*str == '+' || *str == '-') || (*str == '0'))
			|| ((*str >= 9 && *str <= 13) || (*str == 32))))
		str++;
	while ((*str != '\0') && (*str >= '0' && *str <= '9'))
	{
		result_num *= 10;
		result_num += (*str - 48);
		str++;
	}
	if (sign % 2 != 0)
		result_num *= -1;
	return (result_num);
}
