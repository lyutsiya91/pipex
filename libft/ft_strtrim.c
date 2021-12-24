/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:05:44 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 23:05:46 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char const *set, char s)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	n;

	if (!s1)
		return ((void *)0);
	n = 0;
	while (s1[n])
	{
		if (ft_find(set, s1[n]) != 1)
			break ;
		n++;
	}
	len = ft_strlen(s1) - 1;
	if (n > len)
		return (ft_strdup(""));
	while (s1[len])
	{
		if (ft_find(set, s1[len]) != 1)
			break ;
		len--;
	}
	return (ft_substr(s1, n, len - n + 1));
}
