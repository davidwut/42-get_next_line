/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:04 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/11 17:54:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_str(char *dest, char src[BUFFER_SIZE], int size)
{
	int		dest_len;
	int		i;
	char	*res;

	dest_len = ft_strlen(dest);
	res = malloc(dest_len + size + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < dest_len)
		res[i] = dest[i];
	i = -1;
	while (++i < size)
		res[i + dest_len] = src[i];
	res[i + dest_len] = 0;
	if (dest)
		free(dest);
	return (res);
}

static char	*pop_str(char **buf)
{
	int		index;
	int		i;
	char	*res;
	char	*new_buf;
	int		buf_len;

	buf_len = ft_strlen(buf[0]);
	index = next_nl(buf[0], M_NULLBYTE);
	res = malloc(index + 1);
	if (!res)
		return (NULL);
	new_buf = malloc(buf_len - index);
	if (!new_buf)
		return (NULL);
	i = -1;
	while (++i < index)
		res[i] = buf[0][i];
	res[i] = 0;
	i = -1;
	while (++i < buf_len - index - 1)
		new_buf[i] = buf[0][i + index + 1];
	new_buf[i] = 0;
	free(buf[0]);
	buf[0] = new_buf;
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
		buffer[fd] = append_str(buffer[fd], temp, size);
	}
	free_null(line);
	*line = pop_str(&buffer[fd]);
	if (size != BUFFER_SIZE)
		return (EOF_RCHD);
	return (LINE_RD);
}

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line = NULL;
	int ret;
	while ((ret = get_next_line(fd, &line)) != ERR)
	{
		printf("%s\n", line);
		if (ret == EOF_RCHD)
			break ;
	}
	close(fd);
}
