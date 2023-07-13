/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:20:42 by hamza             #+#    #+#             */
/*   Updated: 2023/07/13 19:27:32 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*free_null(char *str);

size_t	ft_strlen(const char *c);

char	*ft_strchr(const char *str, int c);

char	*ft_safe_strnjoin(char *from, char const *to, size_t len_of_to);

char	*ft_strdup(const char *src, size_t size);

char	*get_next_line(int fd);

#endif
