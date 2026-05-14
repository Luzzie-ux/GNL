/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:37:44 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 17:26:41 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes;
	char 		*buffer;
	char		*line;
	static char	*stash;
	
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while(*buffer)
	{
		stash = buffer;
		if (*buffer == '\n')
			return (stash);
		buffer++;
	}
	return (stash);
}

void walker(char *buffer)
{
	char *stash;
	
}