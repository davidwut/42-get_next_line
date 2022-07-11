/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:18:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/11 20:50:30 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	append_str(char **dest, char src[BUFFER_SIZE], int size)
{
	char	*res;
	int		dest_len;
	int		i;

	dest_len = ft_strlen(*dest);
	res = malloc(dest_len + size + 1);
	if (!res)
		return ;
	i = -1;
	while (++i < dest_len)
		res[i] = dest[0][i];
	i = -1;
	while (++i < size)
		res[i + dest_len] = src[i];
	res[i + dest_len] = 0;
	free_null(dest);
	*dest = res;
}

static void	slice_str(char **str, int from, int len)
{
	char	*res;
	int		i;

	res = malloc(len - from);
	if (!res)
		return ;
	i = -1;
	while (++i < len - from - 1)
		res[i] = str[0][i + from + 1];
	res[i] = 0;
	free(*str);
	*str = res;
}

static char	*pop_str(char **buf)
{
	char	*res;
	int		buf_len;
	int		index;
	int		i;

	buf_len = ft_strlen(buf[0]);
	index = next_nl(buf[0], M_NULLBYTE);
	res = malloc(index + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < index)
		res[i] = buf[0][i];
	res[i] = 0;
	slice_str(&buf[0], index, buf_len);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		temp[BUFFER_SIZE];
	int			size;

	if (fd < 0)
		return (ERR);
	size = BUFFER_SIZE;
	while (size == BUFFER_SIZE && next_nl(buffer[fd], M_NEWLINE) == -1)
	{
		size = read(fd, temp, BUFFER_SIZE);
		append_str(&buffer[fd], temp, size);
	}
	free_null(line);
	if (!buffer[fd])
	{
		free_null(&buffer[fd]);
		return (ERR);
	}
	if (size == 0)
	{
		free_null(&buffer[fd]);
		return (EOF_RCHD);
	}
	*line = pop_str(&buffer[fd]);
	return (LINE_RD);
}
