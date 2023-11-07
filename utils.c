/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:54:36 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/07 14:57:32 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	msg(char *msg, int check, int output)
{
	write(output, msg, ft_strlen(msg));
	if (check == 0)
		exit(1);
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*find_path(char *cmd, char **envp, int count)
{
	char	*part_path;
	char	*cmd_path;
	char	**envp_path;

	while (!ft_strnstr(*envp, "PATH=", 5))
		envp++;
	envp_path = ft_split(*envp + 5, ':');
	while (envp_path[++count] && cmd[0] != '/')
	{
		part_path = ft_strjoin(envp_path[count], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free (part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(envp_path);
			return (cmd_path);
		}
		free (cmd_path);
	}
	free_split(envp_path);
	if (cmd[0] == '/' && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	msg("command not found\n", 1, 2);
	return (NULL);
}

void	exec_cmd(char *argv, char **envp)
{
	char	*path;
	char	**cmd;

	if (argv[0])
	{
		cmd = ft_split(argv, ' ');
		path = find_path(cmd[0], envp, -1);
		if (!path)
		{
			free_split(cmd);
			free (path);
			exit(127);
		}
		if (execve(path, cmd, envp) == -1)
		{
			free_split(cmd);
			free (path);
			ft_error("Error: cant execute command.");
		}
	}
}
