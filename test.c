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
#include <string.h>

int main() {
	char *line;
	int fd = open("/Users/hamza/CLionProjects/getnextline-remake/multiple_nl.txt", O_RDONLY);
	printf("pid: %d\n", getpid());
	while ((line = get_next_line(fd))) {
		printf("'\\%d' (%lu)\n", *line, strlen(line));
		free(line);
	}
	while (1);
}
