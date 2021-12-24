/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:56:34 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/16 17:11:49 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_child_first(int end[], char **argv)
{
	char		**args;
	char		*cmd;

	if (dup2(end[1], 1) == -1)
		ft_error("Redirecting of file descriptor failed ");
	close(end[0]);
	close(end[1]);
	args = ft_split(argv[2], ' ');
	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
		cmd = ft_command_by_path(args);
	else
		cmd = ft_find_command(args);
	if (cmd == NULL)
	{
		ft_free(args);
		ft_putendl_fd("The path for the first command was not found", 2);
		exit(1);
	}
	ft_execute(cmd, args);
}

void	ft_child_second(int end[], char **argv)
{
	char		**args;
	char		*cmd;

	if (dup2(end[0], 0) == -1)
		ft_error("Redirecting of file descriptor failed ");
	close(end[0]);
	close(end[1]);
	args = ft_split(argv[3], ' ');
	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
		cmd = ft_command_by_path(args);
	else
		cmd = ft_find_command(args);
	if (cmd == NULL)
	{
		ft_free(args);
		ft_putendl_fd("The path for the second command was not found", 2);
		exit(1);
	}
	ft_execute(cmd, args);
}

void	ft_pipex(char **argv)
{
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(end) == -1)
		ft_error("Creation of pipe failed ");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Creation of fork failed ");
	if (pid1 == 0)
		ft_child_first(end, argv);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Creation of fork failed ");
	if (pid2 == 0)
		ft_child_second(end, argv);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;

	if (argc != 5)
	{
		ft_putendl_fd("Invalid arguments", 2);
		exit(1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd1 == -1 || fd2 == -1)
		ft_error("Opening of file failed ");
	if (dup2(fd2, 1) == -1 || dup2(fd1, 0) == -1)
		ft_error("Redirecting of file descriptor failed ");
	ft_pipex(argv);
	return (0);
}
