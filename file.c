/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:37:44 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 18:28:03 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static char	*line(char *s)
{
	char	*str;
	char	*p;
	long	len;

	len = 0;
	while (s[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++; 
	*p = '\0'; 
	return (str);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char 		*buffer;
	static char	*stash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	stash = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer || !stash)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (NULL);
	buffer[bytes] = '\0';
	while (buffer[i])
	{
		stash[j] = buffer[i];
		if (buffer[i] == '\n')
		{
			stash[j + 1] = '\0';
			return (stash);
		}
		else if (buffer[i] != '\n')
		{
			strcat(stash, line(buffer));
		}
		i++;
		j++;
	}
	stash[j] = '\0';
	return (stash);
}