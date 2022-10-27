/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:53:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/27 00:00:57 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
char	*pop_str(char **memory)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	printf("mem %d= [%s]\n", ft_strlen(*memory), *memory);
	printf("### %c\n", (*memory)[6]);
	while (*memory[i] && *memory[i] != '\n')
	{
		printf("i = %d\n", i);
		i++;
	}
	printf("PLEASE -%d\n", *memory[i] == '\n');
	str = malloc(i + 1 + *memory[i] == '\n');
	if (!str)
		return (NULL);
	ft_strlcpy(str, *memory, i + 1 + *memory[i] == '\n');
	if (*memory[i] == '\n')
	{
		tmp = *memory;
		*memory = ft_strdup(*memory + i + 1);
		free(tmp);
	}
	else
	{
		free(*memory);
		*memory = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			bytes_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!memory[fd])
		memory[fd] = ft_strdup("");
	if (ft_strchr(memory[fd], '\n') != NULL)
		return (pop_str(&memory[fd]));
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && ft_strchr(memory[fd], '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = 0;
		tmp = ft_strjoin(memory[fd], buffer);
		free(memory[fd]);
		memory[fd] = tmp;
	}
	return (pop_str(&memory[fd]));
}
