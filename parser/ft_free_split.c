#include "cub3d.h"

void	free_split(char **split_str)
{
	int	i;

	i = 0;
	if (!split_str)
		return ;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}
