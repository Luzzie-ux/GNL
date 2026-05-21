/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:08:44 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/21 14:15:43 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_string;
	size_t		total;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	total = len1 + len2;
	new_string = malloc(total + 1);
	if (!new_string)
		return (free(s1), NULL);
	ft_memcpy(new_string, s1, len1);
	ft_memcpy(new_string + len1, s2, len2);
	new_string[len1 + len2] = 0;
	return (free(s1), new_string);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*ps;
	unsigned char		*pd;

	ps = (unsigned const char *)src;
	pd = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*pd = *ps;
		pd++;
		ps++;
		n--;
	}
	return (dest);
}
