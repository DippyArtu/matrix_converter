#include "libft.h"
#include <stdio.h>

char		*parse_data(int fd, char *line)
{
	int		line_c;
	int		i;
	int		j;
	char		*tmp;
	char		*res;
	char		*binary;

	binary = (char *)malloc(sizeof(char) * 400);
	ft_bzero(binary, 400);
	while ((get_next_line(fd, &line)))
	{
		line_c = 0;
		while (line[line_c] != '\0')
		{
			res = (char *)malloc(sizeof(char) * 6);
			tmp = (char *)malloc(sizeof(char) * 12);
			ft_bzero(tmp, 12);
			ft_bzero(res, 6);
			tmp = ft_strncpy(tmp, &line[line_c], 12);
			i = 0;
			j = 0;
			while (tmp[i])
			{
				if (tmp[i] == 48 || tmp[i] == 49)
				{
					res[j] = tmp[i];
					j++;
				}
				i++;
			}
			binary = ft_strcat(binary, res);
			binary = ft_strcat(binary, "\n");
			free(res);
			line_c += 12;
		}
		free(line);
	}
	return(binary);
}	

int		main(int argc, char **argv)
{
	int		fd;
	char		*line;
	char		*binary;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	binary = parse_data(fd, line);
	printf("%s", binary);
	free(binary);
	close(fd);
	return(0);
}
