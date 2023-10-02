/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:41:40 by gcampos-          #+#    #+#             */
/*   Updated: 2023/04/26 18:34:03 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int					result;
	size_t				i;

	p1 = s1;
	p2 = s2;
	result = 0;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			result = (p1[i] - p2[i]);
			break ;
		}
		i++;
	}
	if (result > 0)
		return (1);
	else if (result < 0)
		return (-1);
	return (0);
}
