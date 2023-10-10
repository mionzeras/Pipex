/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:36:25 by gcampos-          #+#    #+#             */
/*   Updated: 2023/10/10 16:32:23 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_envp(char **envp)
{
	int	i;
	int	ok;

	i = -1;
	ok = 0;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			ok = 1;
	}
	if (!ok)
		msg("Error: PATH empty.", 0, 1);
}

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

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	check_envp(envp);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Pipe");
		child_pid = fork();
		if (child_pid == -1)
			ft_error("Fork");
		if (child_pid == 0)
			child_process(fd, argv, envp);
		else
		{
			waitpid(child_pid, NULL, 0);
			parent_process(fd, argv, envp);
		}
	}
	else
	{
		msg("Problem with arguments.\n", 1, 2);
		msg("Try this: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 0, 1);
	}
	return (0);
}
