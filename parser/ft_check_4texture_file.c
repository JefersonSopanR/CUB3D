#include "cub3d.h"

int	ft_check_texture_file(char	*map, int *i, t_identifier *id)
{
	char	*file_xpm;
	int		start;

	start = (*i);
	if (map[*i] == '\n')
		return (id->checker);
	while (map[*i] && map[*i] != '\n' && !ft_isspace(map[*i]))
		(*i)++;
	file_xpm = ft_substr(map, start, (*i) - start);
	if (!file_xpm)
		return (1);
	free(file_xpm);
	return (0);
}
