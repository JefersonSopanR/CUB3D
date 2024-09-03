#include "cub3d.h"

void	ft_retrieve_ea_texture(char *map_line, int *i, t_map *map)
{
	char	*east_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	east_texture = ft_substr(map_line, start, (*i) - start);
	if (!east_texture)
		return ;
	map->ea_texture = east_texture;
	return ;
}

void	ft_retrieve_we_texture(char *map_line, int *i, t_map *map)
{
	char	*west_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	west_texture = ft_substr(map_line, start, (*i) - start);
	if (!west_texture)
		return ;
	map->we_texture = west_texture;
	return ;
}

void	ft_retrieve_so_texture(char *map_line, int *i, t_map *map)
{
	char	*south_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	south_texture = ft_substr(map_line, start, (*i) - start);
	if (!south_texture)
		return ;
	map->so_texture = south_texture;
	return ;
}

void	ft_retrieve_no_texture(char *map_line, int *i, t_map *map)
{
	char	*north_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	north_texture = ft_substr(map_line, start, (*i) - start);
	if (!north_texture)
		return ;
	map->no_texture = north_texture;
	return ;
}
