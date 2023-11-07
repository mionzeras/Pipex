/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:53:36 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/07 15:05:32 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		ft_error("Error on open file_in");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	exec_cmd(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		ft_error("Error on open file_out");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	exec_cmd(argv[3], envp);
}

void	execute_process(char **argv, char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	if (pipe(fd) == -1)
		ft_error("Pipe");
	child_pid = fork();
	if (child_pid == -1)
		ft_error("Fork");
	if (child_pid == 0)
		child_process(fd, argv, envp);
	else
	{
		waitpid(child_pid, NULL, WNOHANG);
		parent_process(fd, argv, envp);
	}
}
