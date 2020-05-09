#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static void		free_matrix(int ***m)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			free(m[i][j]);
		free(m[i]);
	}
	free(m);
	m = NULL;
}

static int		***alloc_matrix(void)
{
	int		***matrix;

	matrix = (int ***)malloc(sizeof(int **) * 6);
	for (int i = 0; i < 6; i++)
		matrix[i] = (int **)malloc(sizeof(int *) * 6);
		for (int j = 0; j < 6; j++)
			matrix[i][j] = (int *)malloc(sizeof(int) * 6);
	return(matrix);
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
	return(res);
}

//TODO convert this to 3d (6*6*6)
static void		fill_matrix(int **matrix, int number)
{
	static int	row = 0;
	static int	col = 0;

	if (row < 6 && col < 5)
	{
		matrix[col][row] = number;
		row++;
	}
	else if (row == 6 && col < 6)
	{
		row = 0;
		col++;
		matrix[col][row] = number;
		row++;
	}
}


static int		***parse_data(int fd, char *line)
{
	int		line_c;
	int		i;
	int		j;
	char		*tmp;
	char		*bin;
	int		***result;
	int		nbr;

	int counter = 1;
	int c_t = 1;

	result = alloc_matrix();
	while ((get_next_line(fd, &line)))
	{
		line_c = 0;
		while (line[line_c] != '\0')
		{
			bin = (char *)malloc(sizeof(char) * 6);
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
					bin[j] = tmp[i];
					j++;
				}
				i++;
			}
			nbr = bin_to_dec(bin);

			printf("%i\n", nbr);
			counter++;
			c_t++;

			if (c_t == 36)
			{
				printf("\n------counter: %i-------\n", counter);
				c_t = 0;
			}

			fill_matrix(result, nbr);
			free(bin);
			free(tmp);
			line_c += 12;
		}
		free(line);
	}
	free(line);
	line = NULL;
	
	printf("\n----------counter: %i----------\n", counter);
	exit(0);

	return(result);
}	

int		main(int argc, char **argv)
{
	int		fd;
	char		*line;
	int		***decimals;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	decimals = parse_data(fd, line);

	for (int i = 0; i < 6; i++)
	{
		printf("\n");
		for (int j = 0; j < 6; j++)
			printf("%i ", decimals[i][j]);
	}

	free_matrix(decimals);
	close(fd);
	return(0);
}
