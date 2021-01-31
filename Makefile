CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra  -g -O3
NAME	:= cub3D
SRC		:= fetch_f.c sprite_two.c sprite.c linked.c main.c ft_screenshot.c  render_walls.c cast_rays.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_error.c read_file.c render_map.c cub3d_utils.c mlx.c
SRC_PATH := srcs
LIBFT_PATH	:= libft
LIBFT	:= $(LIBFT_PATH)/libft.a
LINK	:= -I /usr/share/man/man3 -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
all: $(NAME)


$(NAME): $(SRC)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(SRC) $(LINK)  $(LIBFT) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all

