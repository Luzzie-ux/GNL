/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:08:44 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/18 17:16:13 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*snew;
	char	*start;
	int		total;
	char	*save;

	if (!s1 || !s2)
		return (free(s1), NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	snew = malloc (total + 1);
	if (!snew)
		return (free(s1), NULL);
	start = snew;
	save = s1;
	while (*s1)
		*start++ = *s1++;
	while (*s2)
		*start++ = *s2++;
	*start = 0;
	return (free(save), snew);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	s += start;
	while (i < len)
		sub[i++] = *s++;
	sub[i] = 0;
	return (sub);
}
