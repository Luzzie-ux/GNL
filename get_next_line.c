/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:19:06 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 12:45:31 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static int	findn(char *s); */
static char	*ft_strdup(const char *s);

char	*get_next_line(int fd)
{
	int		bytes;
	char 	*buffer;
	char	*phrase;

	bytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	if (bytes < 0)
		return (free(buffer), NULL);
	else if (bytes == 0)
		return (buffer);
	else
		phrase = ft_strdup(buffer);
	return (free(phrase), phrase);
}

static char	*ft_strdup(const char *s)
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
	p[len + 1] = '\n';
	p[len + 2] = '\0';
	return (str);
}
