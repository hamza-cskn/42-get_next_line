/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:40:59 by hcoskun           #+#    #+#             */
/*   Updated: 2023/07/25 17:56:02 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*h_strndup(char *str, int size)
{
	char	*result;

	if (size <= 0)
		return (NULL);
	result = (char *) malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	h_strlcpy(result, str, size);
	return (result);
}

char	*h_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (1)
	{
		if (*str == c)
			return (str);
		if (!*str)
			return (NULL);
		str++;
	}
}

char	*abort_pointers(char *buffer, char **str_read, char *line)
{
	if (line)
		free(line);
	if (*str_read)
	{
		free(*str_read);
		*str_read = NULL;
	}
	if (buffer)
		free(buffer);
	return (NULL);
}

int	h_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	h_strlcpy(char *dst, char *str, int size)
{
	if (!dst || !str || size <= 0)
		return ;
	while (--size && *str)
		*dst++ = *str++;
	*dst = '\0';
}
