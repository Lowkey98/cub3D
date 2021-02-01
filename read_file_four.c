# include "includes/cub3d.h"
# include "includes/libft.h"
# include "includes/get_next_line.h"

void	add_spaces()
{
	char *tmp;
	int i;
	int j;
	int tmplen;

	i = 0;
	j = 0;

	while (g_data.map[i])
	{
		tmplen = g_data.map_lenght - ft_strlen(g_data.map[i]);
		tmp = calloc(tmplen + 1,1);
		tmp = ft_memset(tmp,' ',tmplen);
		g_data.map[i] = ft_strjoin(g_data.map[i],tmp);

		i++;


	}

	// tmp = ft_calloc(g_data->map_lenght + 1, 1);
		// tmp = ft_strcpy(tmp,g_data->map[i]);
		//ft_putstr(tmp);
		// j = ft_strlen(g_data -> map[i]);
		//ft_putnbr(j);
		// while(j < g_data->map_lenght)
		// {
		// 	tmp[j] = 'a';
		// 	j++;
		// }
	//free(g_data -> map[i]);
		// g_data->map[i] = tmp;
		// ft_putstr(g_data -> map[i]);
		// 		ft_putstr("\n");
    // free(tmp);
	// while (g_data -> map[i])
	// {
	// 	printf("%s",g_data->map[i]);
	// 	i++;
	// }
	// printf("%s",g_data->map[1]);
}
void	check_player()
{
	if (g_player.exists == 0)
		g_player.exists = 1;
	else
		ft_error("there should be only one player");

}
void	check_mapstr_error(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] == '\n')
		i++;
	if (map_str[i] == '\0')
		ft_error("no map");
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			ft_error("ERROR \nempty line in the map");
		if (map_str[i] == 'N' || map_str[i] == 'S' || map_str[i] == 'E' || map_str[i] == 'W')
			check_player();
		else if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != ' ' && map_str[i] != '\n' && map_str[i] != '2')
			ft_error("ERROR \nbad character in the map");
		i++;
	}
	if (g_player.exists == 0)
		ft_error("no player nor surface to use");

}