#include "get_next_line.h"

char *ft_strchr(const char *str, int c) {
	int i = 0;
	if (!str) return 0;

	while (str[i]) {
		if (str[i] == c)
			return (char *) (str + i);
		i++;
	}
	if (c)
		return 0;
	return (char *) (str + i);
}

size_t ft_strlen(const char *c) {
	int i;

	if (!c)
		return 0;

	i = 0;
	while (c[i] != 0) {
		i++;
	}
	return (i * sizeof(char));
}

char *ft_strdup(const char *restrict src, size_t size) {
	size_t i;
	char *dest;

	if (!size)
		return NULL; //size is 0

	dest = (char *) malloc(size);
	if (!dest)
		return NULL; //memory allocation failed

	i = 0;
	while (i < size - 1 && src[i]) {
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return dest;
}

char *ft_strnjoin(char *from, char const *to, size_t len_of_to) {
	char *res;
	int i;
	int j;
	res = malloc(sizeof(char) * (ft_strlen(from) + len_of_to + 1));

	i = 0;
	while (from && from[i]) {
		res[i] = from[i];
		i++;
	}

	j = 0;
	while (to && j < len_of_to) {
		res[i] = to[j];
		i++;
		j++;
	}

	res[i] = '\0';

	free(from);
	return res;
}