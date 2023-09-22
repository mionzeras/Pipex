/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:36:25 by gcampos-          #+#    #+#             */
/*   Updated: 2023/09/22 18:58:29 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd,char **av,char **envp)
{
	int file_in;

	file_in = open(av[1], O_RDONLY, 0777);
	if (file_in == -1)
		ft_error("Error on open file_in");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	
}

void	parent_process(int *fd,char  **av,char **envp)
{
	int file_out;
	
	file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		ft_error("Error on open file_out");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
}
	
int main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t child_pid;
	
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Pipe");
		child_pid = fork();
		if (child_pid == -1)
			ft_error("Fork");
		if (child_pid == 0)
			child_process(fd, av, envp);
		waitpid(child_pid, NULL, 0);
		parent_process(fd, av, envp);
	}
}  