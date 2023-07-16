/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:29 by hcoskun           #+#    #+#             */
/*   Updated: 2023/07/16 07:06:10 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
	char *line;
	int fd = open("/Users/hcoskun/Desktop/getnextline/42-get_next_line/test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
}
