/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:46:36 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/19 18:45:22 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//prototipos
size_t	ft_strlen(const char *s);
int		ft_find_n(char *s);
char	*fill_buffer(int fd, char *stash);
char	*get_next_line(int fd);
char	*next_line(char *stash);
char	*ft_strdup(const char *s);
char	*clean_stash(char *stash);
char	*extract_until_newline(char *stash);
char	*trim_stash(char *stash);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#endif
