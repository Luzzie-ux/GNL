/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:37:44 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/17 19:53:58 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	// char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	stash = read_line(fd, stash);
	if (!stash)
		return (free(stash), stash = NULL, NULL);
	// line = relm(stash);
	return (stash);
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

// char	*relm(char *stash)
// {
// 	char	*new_line;
// 	char	*new_stash;
// 	new_line = ft_strchr(stash, '\n');
// 	return (new_line);
// }