/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:06 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 11:52:50 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		bytes;
	char 	*buffer;
	char	*phrase;

	bytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char *));
	if (!buffer)
		return (NULL);
	while (buffer)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
			return (NULL);
		else if (bytes == 0)
			return (buffer);
		else
			phrase = ft_strdup(buffer);
		// phrase[findn(phrase) + 1] = '\0';
		return (phrase);
		buffer++;
	}
	return (NULL);
}

/* int	findn(char *s)
{
	int i;

 	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	return (i);
} */

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	long	len;

	len = 0;
	while (s[len])
		len++;
	str = malloc(len + 2);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\n';
	return (str);
}