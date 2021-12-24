/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:07:43 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/14 00:48:27 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_define_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	return (sign);
}

long long	ft_convert(const char *str, int sign, long long number)
{
	if (*str && ft_isdigit(*str))
		number = (number * 10) + ((int)*str - '0');
	if ((number - 1 > INT_MAX && sign == -1)
		|| (number > INT_MAX && sign == 1))
		return (-1);
	return (number);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = ft_define_sign(str);
		str++;
	}
	if (ft_isdigit(*str))
	{
		while (*str && ft_isdigit(*str))
		{
			number = ft_convert(str, sign, number);
			if (number == -1)
				return (0);
			str++;
		}
	}
	return (sign * number);
}
