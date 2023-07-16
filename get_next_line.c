/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:59 by hamza             #+#    #+#             */
/*   Updated: 2023/07/16 07:35:48 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int bytes_to_eol(char *buffer, int bytes_read)
{
	char	*eol;
	
	eol = ft_strchr(buffer, '\n');
	if (eol && eol - buffer < bytes_read)
		return eol - buffer + 1;
	else
		return bytes_read;
}

char	*set_last_leftover(char **last_leftover, char *end_of_str)
{
	*last_leftover = ft_strdup(end_of_str, ft_strlen(end_of_str) + 1);
	if (!*last_leftover)
		return (NULL);
	*end_of_str = '\0';
	return (*last_leftover);
}
char	*put_next_line(int fd, char *buffer)
{
	static char	*last_leftover = NULL;
	char		*line;
	char		*end_of_line;
	ssize_t		bytes_read;

	line = last_leftover;
	end_of_line = NULL;
	bytes_read = BUFFER_SIZE;
	while (!end_of_line && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			last_leftover = NULL;
			return (free_null(line));
		}

		line = ft_safe_strnjoin(line, buffer, bytes_to_eol(buffer, bytes_read));
		if (!line) {
			last_leftover = NULL;
			return (NULL);
		}
		end_of_line = ft_strchr(line, '\n');
	}
	if (ft_strlen(line) == 0 && bytes_read == 0)
	{
		last_leftover = NULL;
		return (free_null(line));
	}
	last_leftover = NULL;
	if (end_of_line && !set_last_leftover(&last_leftover, end_of_line + 1))
	{
		last_leftover = NULL;
		return (free_null(line));
	}
	return (line);
}

char	*init_buffer(size_t size)
{
	char	*buffer;
	
	buffer = (char *) malloc(size * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[size - 1] = 0;
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*result;

	buffer = init_buffer(BUFFER_SIZE + 1);
	result = put_next_line(fd, buffer);
	free(buffer);
	return (result);
}
