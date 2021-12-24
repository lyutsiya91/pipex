/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:57:11 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/16 17:02:29 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *message)
{
	perror(message);
	exit(errno);
}

void	ft_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**ft_define_path(void)
{
	extern char	**environ;
	char		**paths;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "PATH=", 5))
		{
			environ[i] += 5;
			break ;
		}
		i++;
	}
	paths = ft_split(environ[i], ':');
	return (paths);
}

char	*ft_command_by_path(char **args)
{
	if (access(args[0], 0) == 0)
		return (args[0]);
	else
		return (NULL);
}

char	*ft_find_command(char **args)
{
	extern char	**environ;
	int			i;
	char		*cmd;
	char		*cmd2;
	char		**paths;

	i = 0;
	paths = ft_define_path();
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], "/");
		cmd2 = ft_strjoin(cmd, args[0]);
		if (access(cmd2, 0) == 0)
		{
			free(cmd);
			ft_free(paths);
			return (cmd2);
		}
		free(cmd);
		free(cmd2);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
