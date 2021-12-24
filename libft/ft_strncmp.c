/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:38:17 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 19:38:18 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	if (len1 > len2)
		len = len2;
	else
		len = len1;
	if (len > n)
		len = n;
	return (ft_memcmp(s1, s2, len));
}
