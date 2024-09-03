NAME = cub3d
CLANG = clang
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

PARSER_DIR = ./parser/
RETRIEVE_MAP_INFORMATION_DIR = ./retrieve_map_information/

PARSER = $(addprefix $(PARSER_DIR), \
        ft_check_1map_file.c ft_check_2elements.c \
        ft_check_3fc_numbers.c ft_check_4texture_file.c \
        ft_check_5map_empty_lines.c ft_check_6map_walls.c \
        ft_especial_map_split.c ft_exit_parser_error.c ft_free_split.c)

RETRIEVE_MAP_INFORMATION = $(addprefix $(RETRIEVE_MAP_INFORMATION_DIR), \
		ft_retrieve_map.c ft_retrieve_texture.c \
		ft_retrieve_color.c ft_free_map.c)

SRCS = main.c $(PARSER) $(RETRIEVE_MAP_INFORMATION)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CLANG) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re