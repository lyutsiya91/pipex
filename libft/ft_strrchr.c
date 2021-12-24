/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:17:31 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 19:18:30 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	char	*str;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	str = (char *)s;
	ans = (void *)0;
	while (*str)
	{
		str = ft_memchr(str, c, ft_strlen(str) + 1);
		if (str == (void *)0)
			break ;
		ans = str;
		str++;
	}
	return (ans);
}
