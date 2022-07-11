/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/11 19:40:35 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 4096

# define ERR -1
# define EOF_RCHD 0
# define LINE_RD 1

# define M_NEWLINE 1
# define M_NULLBYTE 0

int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		next_nl(char *str, int mode);
void	free_null(char **line);

#endif
