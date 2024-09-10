#include "cub3d.h"

void	ft_retrieve_ceiling_color(char *map_line, int *i, t_map *map)
{
	(*i)++;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	map->ceiling_color.r = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	map->ceiling_color.g = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	map->ceiling_color.b = ft_get_color(map_line, i);
}

void	ft_retrieve_floor_color(char *map_line, int *i, t_map *map)
{
	(*i)++;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	map->floor_color.r = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	map->floor_color.g = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	map->floor_color.b = ft_get_color(map_line, i);
}

int	ft_get_color(char *map_line, int *i)
{
	char	*str_color;
	int		color_number;
	int		start;

	start = (*i);
	while (map_line[*i] && ft_isdigit(map_line[*i]))
		(*i)++;
	str_color = ft_substr(map_line, start, (*i) - start);
	if (!str_color)
		return (0);
	color_number = ft_atoi(str_color);
	free(str_color);
	return (color_number);
}

void	ft_skip_comma(char *map_line, int *i)
{
	while (!ft_isdigit(map_line[*i]))
		(*i)++;
}
