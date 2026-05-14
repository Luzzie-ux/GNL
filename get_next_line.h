/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:46:36 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 16:57:17 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//prototipos

char	*get_next_line(int fd);

/* char	*ft_dupp(const char *s);
int	compear(char *s1, char *s2);
char *splitn(char *s);
int	findn(char *str); */


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
