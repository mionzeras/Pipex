/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:54:36 by gcampos-          #+#    #+#             */
/*   Updated: 2023/10/05 22:21:53 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

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
	{
		ft_putstr_fd("Error: PATH empty.", 2);
		exit(1);
	}
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*part_path;
	char	*cmd_path;
	char	**envp_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	envp_path = ft_split(envp[i] + 5, ':');
	i = -1;
	while (envp_path[++i])
	{
		part_path = ft_strjoin(envp_path[i], "/");
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
	ft_putstr_fd("command not found\n", 2);
	return (NULL);
}

void	exec_cmd(char *av, char **envp)
{
	char	*path;
	char	**cmd;

	if(av[0])
	{
		cmd = ft_split(av, ' ');
		path = find_path(cmd[0], envp);
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
