#include "cub3d.h"

void	ft_free_map(t_map *map)
{
	free(map->no_texture);
	free(map->so_texture);
	free(map->we_texture);
	free(map->ea_texture);
	free_split(map->map_2d);
}
