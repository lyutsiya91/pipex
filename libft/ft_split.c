/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:07:30 by sgalio            #+#    #+#             */
/*   Updated: 2021/11/17 23:07:32 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	if (!s)
		return (num);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			num++;
		while (s[i] != c && s[i])
			i++;
	}
	return (num);
}

static int	ft_wordlen(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] && ptr[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **arr, int n)
{
	while (n)
	{
		free (arr[n]);
		n--;
	}
	free(arr);
}

static char	**ft_create(char const *s, char c, char **arr)
{
	int		i;
	int		icol;
	int		istr;

	istr = 0;
	i = 0;
	while (istr < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		arr[istr] = (char *)malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1));
		if (!arr[istr])
		{
			ft_free(arr, istr);
			return ((void *)0);
		}
		icol = 0;
		while (s[i] && s[i] != c)
			arr[istr][icol++] = s[i++];
		arr[istr][icol] = '\0';
		istr++;
	}
	arr[istr] = ((void *)0);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!arr || !s)
		return ((void *)0);
	return (ft_create(s, c, arr));
}
