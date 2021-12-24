/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:15:53 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/17 17:16:47 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void		ft_child(char *argv);
void		ft_pipex(char *argv);

#endif
