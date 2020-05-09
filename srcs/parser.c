#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static void		free_matrix(int **m)
{
	for (int i = 0; i < 6; i++)
		free(m[i]);
	free(m);
	m = NULL;
}

static int		**alloc_matrix(void)
{
	int		**decimals;

	decimals = (int **)malloc(sizeof(int *) * 6);
	for (int i = 0; i < 6; i++)
		decimals[i] = (int *)malloc(sizeof(int) * 6);
	return(decimals);
}

static int		bin_to_dec(char *bin)
{
	int	binary[6];
	int	pwr = 5;
	int	res = 0;
	
	for (int i = 0; i < 6; i++)
	{
		binary[i] = bin[i] - 48;
		res = res + (binary[i] * pow(2, pwr));
		pwr--;
	}
	return(0);
}

static int		**parse_data(int fd, char *line)
{
	int		line_c;
	int		i;
	int		j;
	char		*tmp;
	char		*res;
	int		**decimals;

	decimals = alloc_matrix();
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
			bin_to_dec(res);
			free(res);
			free(tmp);
			line_c += 12;
		}
		free(line);
	}
	free(line);
	line = NULL;
	return(decimals);
}	

int		main(int argc, char **argv)
{
	int		fd;
	char		*line;
	int		**decimals;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	decimals = parse_data(fd, line);
	free_matrix(decimals);
	close(fd);
	return(0);
}
