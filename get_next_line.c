/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:06 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/18 16:33:50 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0) //verificar a necessidade disto
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	stash = read_line(fd, stash);
	if (!stash || !*stash)
		return (stash = NULL, NULL);
 	line = next_line(stash);
	stash = clean_stash(stash);
	if (!stash || !*stash)
		stash = NULL;
	return (line);
}

char	*read_line(int fd, char *stash)
{
	int				bytes;
	char 			*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while(!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

char	*next_line(char *stash)
{
	char	*new_line;

	if (ft_strchr(stash, '\n'))
	{
		new_line = ft_strchr(stash, '\n');
		return (ft_substr(stash, 0, (new_line - stash) + 1));
	}
	return (ft_substr(stash, 0, ft_strlen(stash)));
}

char	*clean_stash(char *stash)
{
	int		len;
	int		i;
	char	*stack;

	i = 0;
	len = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	len = i;
	if (ft_strchr(stash, '\n'))
		len++;
	stack = ft_substr(stash, len, ft_strlen(stash) - len);
	free(stash);
	return (stack);
}
