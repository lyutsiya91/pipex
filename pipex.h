/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:55:40 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/16 17:06:57 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

int			ft_error(char *message);
void		ft_free(char **arr);
char		*ft_find_command(char **args);
char		*ft_command_by_path(char **args);
char		**ft_define_path(void);
void		ft_child_first(int end[], char **argv);
void		ft_child_second(int end[], char **argv);
void		ft_pipex(char **argv);

#endif
