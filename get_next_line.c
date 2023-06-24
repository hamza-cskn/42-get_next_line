#include "get_next_line.h"

char *put_next_line(int fd, char *buffer) {
	static char *last_leftover;
	char *line = last_leftover;
	char *end_of_line = NULL;
	ssize_t bytes_read = BUFFER_SIZE;

	while (!(end_of_line = ft_strchr(line, '\n')) && bytes_read == BUFFER_SIZE) {
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == -1)
			return NULL; //error reading the file

		line = ft_strnjoin(line, buffer, bytes_read);
	}

	if (ft_strlen(line) == 0 && bytes_read == 0)
		return NULL;

	last_leftover = 0;
	if (end_of_line) {
		if (!(last_leftover = ft_strdup(end_of_line + 1, ft_strlen(end_of_line) + 1)))
			return NULL; //could not copy
		end_of_line[1] = 0;
	}
	return line;
}

char *get_next_line(int fd) {
	char *buffer;
	if ((buffer = (char *) malloc(BUFFER_SIZE + sizeof(char))) == NULL)
		return NULL; //memory allocation failed
	buffer[BUFFER_SIZE] = 0;
	buffer = put_next_line(fd, buffer);
	return buffer;
}