#include "cub3d.h"

void	ft_exit(char *msg, char *map, t_err_type type_error)
{
	if (map)
		free(map);
	if (type_error != E_MAP)
		ft_putstr_fd("Error\n", 2);
	if (type_error == E_NO)
		ft_putstr_fd("Wrong NO texture\n", 2);
	else if (type_error == E_SO)
		ft_putstr_fd("Wrong SO texture\n", 2);
	else if (type_error == E_WE)
		ft_putstr_fd("Wrong WE texture\n", 2);
	else if (type_error == E_EA)
		ft_putstr_fd("Wrong EA texture\n", 2);
	else if (type_error == E_F)
		ft_putstr_fd("Wrong F texture\n", 2);
	else if (type_error == E_C)
		ft_putstr_fd("Wrong C texture\n", 2);
	else if (type_error == E_WRONG_ELEM)
		ft_putstr_fd("Wrong element\n", 2);
	else if (type_error == E_DUP)
		ft_putstr_fd("Duplicate element\n", 2);
	else if (msg && type_error != E_MAP)
		ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_write_map_err(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\n', 2);
}
