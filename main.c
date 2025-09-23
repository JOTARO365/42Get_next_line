#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h",O_RDONLY);

	line = get_next_line(fd);
	while (line)
	{
		printf("%s",&line);
		line = get_next_line(fd);
		free(fd);
	}
	close(fd);
	return (0);
}
