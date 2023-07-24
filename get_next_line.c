#include "get_next_line.h"

char	*h_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while(1)
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

int		h_strlen(const char *str)
{
	int	i;

	if (!str)
		return 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	h_strlcpy(char *dst, char *str, int size)
{
	if (!dst || !str || size <= 0)
		return;
	while (--size && *str)
		*dst++ = *str++;
	*dst = '\0';
}

char	*h_strjoin(char *str1, char *str2)
{
	char	*result;
	int		len_of_str1;
	int		len_of_str2;

	len_of_str1 = h_strlen(str1);
	len_of_str2 = h_strlen(str2);
	result = (char *) malloc(sizeof(char) * (len_of_str1 + len_of_str2 + 1));
	if (result == NULL)
		return (NULL);
	h_strlcpy(result, str1, len_of_str1 + 1);
	h_strlcpy(result + len_of_str1, str2, len_of_str2 + 1);
	return result;
}

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

int h_linelen(const char *str)
{
	int	i;

	if (!str)
		return 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	expand_str(char **org, char *append)
{
	char	*result;

	result = h_strjoin(*org, append);
	if (*org)
		free(*org);
	*org = result;
}

char	*get_next_line(int fd)
{
	static char *str_read = NULL;
	char		*eol;
	ssize_t		bytes_read;
	char		*buffer;

	//initialize buffer
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1)); //!
	if (buffer == NULL)
		return (NULL);

	//read until reach eol(end of line/file) or get error.
	eol = NULL;
	while (1)
	{
		eol = h_strchr(str_read, '\n');
		if (eol)
			break; //found end of line.
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (abort_pointers(buffer, &str_read, NULL));
		buffer[bytes_read] = '\0';
		expand_str(&str_read, buffer); //!
		if (!str_read)
			return (abort_pointers(buffer, &str_read, NULL));
		if (bytes_read != BUFFER_SIZE)
		{
			eol = str_read + h_linelen(str_read);
			break; //found end of line(file).
		}
	}

	if (h_strlen(str_read) == 0 && bytes_read == 0)
		return (abort_pointers(buffer, &str_read, NULL));

	// create line
	int	line_len = h_linelen(str_read);
	char *line = h_strndup(str_read, line_len + 1 + (*eol != 0)); //! check eol
	if (!line)
		return (abort_pointers(buffer, &str_read, NULL));

	// narrow str_read
	char *temp;
	if (*eol) {
		char *line_start = str_read + line_len + 1;
		int len_left = h_strlen(line_start);
		if (len_left == 0) {
			temp = NULL;
		} else {
			temp = h_strndup(line_start, len_left + 1); //!
			if (temp == NULL)
				return (abort_pointers(buffer, &str_read, line));
		}
	} else {
		temp = (NULL);
	}
	free(str_read);
	str_read = temp;

	free(buffer);
	return (line);
}
