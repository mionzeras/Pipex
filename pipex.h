/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:45:24 by gcampos-          #+#    #+#             */
/*   Updated: 2023/09/22 18:57:12 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

void ft_error(char *str);
void child_process(int *fd,char **av,char **envp);
void parent_process(int *fd,char  **av,char **envp);


#endif