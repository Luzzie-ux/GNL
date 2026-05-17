/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:46:36 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/17 19:46:35 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//prototipos
size_t	ft_strlen(const char *s);

char	*relm(char *stash);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*read_line(int fd, char *stash);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
