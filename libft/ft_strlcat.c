/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:23:09 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 19:23:11 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize > dstlen)
	{
		dstsize -= dstlen;
		if (srclen >= dstsize)
			len = dstsize - 1;
		else
			len = srclen;
		ft_memcpy(dst + dstlen, src, len);
		dst[dstlen + len] = '\0';
		return (dstlen + srclen);
	}
	else
		return (dstsize + srclen);
}
