# include "includes/cub3d.h"

void fetch_s(char *str)
{
	int i;
	void *tmp;
	i = 1;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&g_sprite_width,&g_sprite_height);
	if (tmp == NULL)
		ft_error("ERROR\n Sprite file not valid",str);
	g_texture.sprite_texture= (int *)mlx_get_data_addr(tmp, &i,&i,&i);

	g_data.s_completed = 1;

}
void fetch_ea(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n East texture file doesnt exist",str);
	g_texture.west_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.west_texture == NULL)
		ft_error("ERROR \n East texture file  isnt readable",str);

	g_data.ea_completed = 1;

}
void fetch_we(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&g_texture.west_texture_w,&g_texture.west_texture_h);
	if (tmp == NULL)
		ft_error("ERROR\n West texture file doesnt exist",str);
	g_texture.east_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.east_texture == NULL)
		ft_error("ERROR \n West texture file  isnt readable",str);

	g_data.we_completed = 1;

}
void fetch_so(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n South texture file doesnt exist",str);
	g_texture.north_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.north_texture == NULL)
		ft_error("ERROR \n South texture file  isnt readable",str);

	g_data.so_completed = 1;

}

void fetch_no(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n Invalid North texture file",str);
	g_texture.south_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);


	g_data.no_completed = 1;

}