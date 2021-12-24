/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:02:11 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 19:02:14 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (size_t *)malloc(size * count);
	if (str != ((void *)0))
	{
		ft_memset(str, '\0', size * count);
		return (str);
	}
	else
		return ((void *)0);
}
