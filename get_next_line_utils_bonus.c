/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:22 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/11 15:14:50 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = -1;
	if (!str)
		return (0);
	while (str[++count])
		;
	return (count);
}

void	free_null(char **line)
{
	if (!*line)
		return ;
	free(*line);
	*line = NULL;
}

int	next_nl(char *str, int mode)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	if (mode == M_NULLBYTE)
		return (i);
	return (-1);
}