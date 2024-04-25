#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[9999999] = {'\0'};
	static int	i = 0;
	int	k = 0;
	int	read_byte = 1;
	char	*line;
	while (read_byte > 0)
	{
		read_byte = read(fd, &buff[k], BUFFER_SIZE);
		if (read_byte == -1 || buff[i] == '\0')
			return NULL;
		k += read_byte;
	}
	read_byte = 0;
	while (buff[i + read_byte] && buff[i + read_byte] != '\n')
		read_byte++;
	line = malloc(read_byte + 1 + (buff[i + read_byte] == '\n'));
	if (!line)
		return NULL;
	line[read_byte + (buff[i + read_byte] == '\n')] = '\0';
	k = 0;
	while (k <= read_byte)
		line[k++] = buff[i++];
	return line;
}

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("test",O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
