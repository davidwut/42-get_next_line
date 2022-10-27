/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:55:11 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/26 20:44:42 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c % 256)
			return ((char *)s);
		s++;
	}
	if (*s == c % 256)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen((char *)src);
	if (size < 1)
		return (str_len);
	i = -1;
	while (++i < size - 1 && src[i])
		dest[i] = src[i];
	dest[i] = 0;
	return (str_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (size < 1)
		return (src_len + size);
	i = dest_len;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	if (size < dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen((char *)s);
	res = malloc(len + 1);
	if (res == 0)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = 0;
	return (res);
}
