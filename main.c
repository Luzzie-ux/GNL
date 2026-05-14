/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:12:45 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/14 12:15:42 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	read_file(char *argv)
{
	int		file;
	char	*buffer;

	file = open(argv, O_RDONLY);
	if (file == -1)
		return (printf("Cannot read file"), 0);
	buffer = get_next_line(file);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(file);
	}
	close (file);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return(printf("File name is missing.\n"), 0);
	else if (argc > 2)
		return (printf ("Too many arguments"), 0);
	else
		return (read_file(argv[1]));
	return (0);
}
