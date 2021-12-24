/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:07:14 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 23:07:15 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		c = 1;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static char	*ft_help(int len, int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != ((void *)0))
	{
		str[len] = '\0';
		if (n < 0)
		{
			n = -n;
			str[0] = '-';
		}
		if (n == 0)
			str[0] = '0';
		while (n)
		{
			str[--len] = n % 10 + '0';
			n /= 10;
		}
		return (str);
	}
	else
		return ((void *)0);
}

char	*ft_itoa(int n)
{
	int		len;

	len = ft_count(n);
	if (n < 0)
		len += 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_help(len, n));
}
