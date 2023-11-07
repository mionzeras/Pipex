/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:45:24 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/07 14:57:16 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

void	ft_error(char *str);
void	msg(char *msg, int check, int output);
void	child_process(int *fd, char **av, char **envp);
void	parent_process(int *fd, char **av, char **envp);
void	check_envp(char **envp);
void	free_split(char **str);
void	exec_cmd(char *av, char **envp);
void	execute_process(char **argv, char **envp);
char	*find_path(char *cmd, char **envp, int count);

#endif