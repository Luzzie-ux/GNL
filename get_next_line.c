/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:06 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/19 19:07:53 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_n(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_buffer(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = extract_until_newline(stash);
	stash = trim_stash(stash);
	if (!stash)
		stash = NULL;
	return (line);
}

char	*fill_buffer(int fd, char *stash)
{
	char		*buffer;
	ssize_t		bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_find_n(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), stash = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash || !*stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

char	*extract_until_newline(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash)
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(stash), NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*trim_stash(char *stash)
{
	char	*rest_of_line;
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	l = 0;
	if (!stash)
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = ft_strlen(stash);
	rest_of_line = malloc((j - i) + 1);
	if (!rest_of_line)
		return (free(stash), NULL);
	while (i != j)
		rest_of_line[l++] = stash[i++];
	rest_of_line[l] = 0;
	return (free(stash), rest_of_line);
}
