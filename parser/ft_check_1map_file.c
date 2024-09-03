#include "cub3d.h"

void	ft_check_map_file(char **av)
{
	char 			*map;
	t_err_type	type_error;

	type_error = 0;
	map = NULL;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		ft_exit("Incorrect file extension\n", NULL, 0);
	map = ft_read_file(av[1]);
	if (!map)
		ft_exit("couldn't open map file", NULL, 0);
	type_error = ft_check_elements(map);
	if (type_error)
		ft_exit("Wrong texture\n", map, type_error);
	free(map);
	return ;
}

char	*ft_read_file(char *file)
{
	int	fd;
	char *line;
	char	*tmp;
	char	*map_line;

	map_line = ft_strdup("");
	if (!map_line)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		tmp = map_line;
		map_line = ft_strjoin(map_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	if (!map_line[0])
		ft_exit("Map is empty\n", map_line, 0);
	return (map_line);
}
