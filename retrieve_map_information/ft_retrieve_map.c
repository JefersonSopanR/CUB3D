#include "cub3d.h"

static void	ft_retrieve_map_2d(char *map_line, int *i, t_map *map);

void	ft_retrieve_map(char **av, t_map *map)
{
	char	*map_line;
	int		i;

	i = 0;
	map_line = ft_read_file(av[1]);
	ft_retrieve_textures(map_line, &i, map);
	ft_retrieve_colors(map_line, &i, map);
	ft_retrieve_map_2d(map_line, &i, map);
}

void	ft_retrieve_textures(char *map_line, int *i, t_map *map)
{
	while (map_line[*i])
	{
		if (map_line[*i] == '\n' || ft_isspace(map_line[*i]))
			(*i)++;
		else if (!ft_strncmp(&map_line[*i], "NO", 2))
			ft_retrieve_no_texture(map_line, i, map);
		else if (!ft_strncmp(&map_line[*i], "SO", 2))
			ft_retrieve_so_texture(map_line, i, map);
		else if (!ft_strncmp(&map_line[*i], "WE", 2))
			ft_retrieve_we_texture(map_line, i, map);
		else if (!ft_strncmp(&map_line[*i], "EA", 2))
			ft_retrieve_ea_texture(map_line, i, map);
		else
			break ;
	}
	return ;
}

void	ft_retrieve_colors(char *map_line, int *i, t_map *map)
{
	while (map_line[*i])
	{
		if (map_line[*i] == '\n' || ft_isspace(map_line[*i]))
			(*i)++;
		else if (!ft_strncmp(&map_line[*i], "F ", 2))
			ft_retrieve_floor_color(map_line, i, map);
		else if (!ft_strncmp(&map_line[*i], "C ", 2))
			ft_retrieve_ceiling_color(map_line, i, map);
		else
			break ;
	}
	return ;
}

static void	ft_retrieve_map_2d(char *map_line, int *i, t_map *map)
{
	char	**map_2d_array;

	map_2d_array = ft_split(&map_line[*i], '\n');
	if (!map_2d_array)
		return ;
	map->map_2d = map_2d_array;
	return ;
}
