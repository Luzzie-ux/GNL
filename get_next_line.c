/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:06 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/13 16:50:03 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char 	*buffer;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE+1 * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (buffer)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (!i)
			return (NULL);			
	}
	return (NULL);
}
