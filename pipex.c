/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:36:25 by gcampos-          #+#    #+#             */
/*   Updated: 2023/11/02 15:17:04 by gcampos-         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	check_envp(envp);
	if (argc == 5)
		execute_process(argv, envp);
	else
	{
		msg("Problem with arguments.\n", 1, 2);
		msg("Try this: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 0, 1);
	}
	return (0);
}
