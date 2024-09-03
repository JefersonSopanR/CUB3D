#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef enum e_err_type
{
	NONE,
	OTHER,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_F,
	E_C,
	E_WRONG_ELEM,
	E_DUP,
	E_MAP,
}	t_err_type;

typedef struct s_identifier
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	t_err_type	checker;
	bool			dup;
	bool			is_fc;
}	t_identifier;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor_color;
	t_color	ceiling_color;		
	char	**map_2d;
}	t_map;

			//PASER_FUNCTIONS_PROTOTYPES


//ft_check_1map_file.c
void	ft_check_map_file(char **av);
char	*ft_read_file(char *file);


//ft_check_2elements.c
t_err_type	ft_check_elements(char *map);
t_err_type	ft_check_identifier(char *map, int *i, t_identifier *id);
void	ft_check_dup_elem(int *i, t_identifier *id, int	*element, t_err_type err_type);
int	ft_count_elements(t_identifier *id, char *map, int *i);


//ft_check_3fc_numbers.c
int	ft_check_fc_numbers(char *map, int *i, t_identifier *id);
int	ft_check_digit_fc(char *map, int *i);
int	ft_skip_spaces(char *map, int *i, int *comma);


//ft_check_4texture_file.c
int	ft_check_texture_file(char	*map, int *i, t_identifier *id);


//ft_check_5map_emty_lines.c
int	ft_check_empty_lines(char *map, int *i);


//ft_check_6map_walls.c
int	ft_check_map_walls(char *map, int *i);
int	ft_check_map_surroenders(char *map_line);
int	ft_check_zeros(char **map_2d, int y, int x);


//ft_especial_map_split.c
char	**ft_especial_split(char *str);
int	ft_check_map_ends(char **map_2d);
char	**ft_fill_map_with_doces(char **split, int i, int max_len);


//ft_exit_parser_error.c
void	ft_exit(char *msg, char *map, t_err_type type_error);
void	ft_write_map_err(char *err_msg);



//ft_free_split.c
void	free_split(char **split_str);


			//RETIEVES_MAP_FUNCTIONS_PROTOTYPES


//ft_retrieve_map.c
void	ft_retrieve_map(char **av, t_map *map);
void	ft_retrieve_textures(char *map_line, int *i, t_map *map);
void	ft_retrieve_colors(char *map_line, int *i, t_map *map);


//ft_retrieve_texture.c
void	ft_retrieve_ea_texture(char *map_line, int *i, t_map *map);
void	ft_retrieve_we_texture(char *map_line, int *i, t_map *map);
void	ft_retrieve_so_texture(char *map_line, int *i, t_map *map);
void	ft_retrieve_no_texture(char *map_line, int *i, t_map *map);


//ft_retrieve_color.c
void	ft_retrieve_ceiling_color(char *map_line, int *i, t_map *map);
void	ft_retrieve_floor_color(char *map_line, int *i, t_map *map);
int		ft_get_color(char *map_line, int *i);
void	ft_skip_comma(char *map_line, int *i);


//ft_free_map.c
void	ft_free_map(t_map *map);

#endif
