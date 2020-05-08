#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		out_file;
	char		*line;
	char		*tmp;
	char		*res;
	int		i;
	int		j;
	int		line_c;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	out_file = open("result", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	while ((get_next_line(fd, &line)))
	{
		line_c = 0;
		while (line[line_c] != '\0')
		{
			res = (char *)malloc(sizeof(char) * 7);
			tmp = (char *)malloc(sizeof(char) * 12);
			ft_bzero(tmp, 12);
			ft_bzero(res, 7);
			tmp = ft_strncpy(tmp, &line[line_c], 12);
			i = 0;
			j = 0;
			while (tmp[i])
			{
				if (tmp[i] != 32)
				{
					res[j] = tmp[i];
					j++;
				}
				i++;
			}
			free(tmp);
			free(res);
			ft_putendl_fd(res, out_file);
			line_c += 12;
		}
		free(line);
	}
	close(fd);
	close(out_file);
	return(0);
}
