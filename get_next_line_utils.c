/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:58:31 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 15:23:20 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	findn(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char *splitn(char *s)
{
	char *nl;
	int	i;

	if (!s)
		return (NULL);
	i = findn(s);
	while (s[i])
	{
		*nl = s[i];	
		i++;
		nl++;
	}
	return (nl);
}

int	compear(char *s1, char *s2)
{
	size_t	i;
	size_t	n;
	char	*s1;
	i = 0;
	n = findn(s1);
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*join(char *line, char *buffer)
{
	char	*nl;
	char	*
	
	nl = splitn(line);
	compear(nl, buffer);
	
}

char	*dup(const char *s)
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
	*p = '\0'; 
	return (str); 
}
