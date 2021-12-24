/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:11:41 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/17 17:15:04 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_execute(char *cmd, char **args)
{
	extern char	**environ;

	if (execve(cmd, args, environ) == -1)
	{
		free(cmd);
		ft_free(args);
		ft_error("Command not found ");
	}
	free(cmd);
	ft_free(args);
}

void	ft_child(char *argv)
{
	char		**args;
	char		*cmd;

	args = ft_split(argv, ' ');
	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
		cmd = ft_command_by_path(args);
	else
		cmd = ft_find_command(args);
	if (cmd == NULL)
	{
		ft_free(args);
		ft_putendl_fd("The path for the command was not found", 2);
		exit(1);
	}
	ft_execute(cmd, args);
}

void	ft_pipex(char *argv)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		ft_error("Creation of pipe failed ");
	pid = fork();
	if (pid == -1)
		ft_error("Creation of fork failed ");
	if (pid == 0)
	{
		if (dup2(end[1], 1) == -1)
			ft_error("Redirecting of file descriptor failed ");
		close(end[0]);
		close(end[1]);
		ft_child(argv);
	}
	else
	{
		if (dup2(end[0], 0) == -1)
			ft_error("Redirecting of file descriptor failed ");
		close(end[0]);
		close(end[1]);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		i;

	if (argc < 5)
	{
		ft_putendl_fd("Invalid arguments", 2);
		exit(1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd1 == -1 || fd2 == -1)
		ft_error("Opening of file failed ");
	if (dup2(fd2, 1) == -1 || dup2(fd1, 0) == -1)
		ft_error("Redirecting of file descriptor failed ");
	i = 1;
	while (++i < argc - 2)
		ft_pipex(argv[i]);
	ft_child(argv[i]);
	return (0);
}
