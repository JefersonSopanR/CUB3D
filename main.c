#include "cub3d.h"

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("NO -> (%s)\n", map->no_texture);
	printf("SO -> (%s)\n", map->so_texture);
	printf("WE -> (%s)\n", map->we_texture);
	printf("EA -> (%s)\n", map->ea_texture);
	printf("F -> (%d, %d, %d)\n", map->floor_color.r, map->floor_color.g, map->floor_color.b);
	printf("C -> (%d, %d, %d)\n", map->ceiling_color.r, map->ceiling_color.g, map->ceiling_color.b);
	printf("MAP\n");
	while (map->map_2d[i])
	{
		printf("(%s)\n", map->map_2d[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (ac != 2)
		ft_exit("Wrong number of arguments\n", NULL, 0);
	ft_check_map_file(av);
	ft_retrieve_map(av, &map);
	ft_print_map(&map);
	ft_free_map(&map);
	return (0);
}