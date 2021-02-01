# include "includes/cub3d.h"
int fetch_r_w(char *str, int i)
{
	int j;

	j = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '0' || !ft_isdigit(str[i]))
		ft_error("error in resolution",str);
	g_data.window_width = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
	{
		j++;
		i++;
	}
	if (str[i] != ' ')
		ft_error("error in resolution",str);
	if (g_data.window_width >= 2560 || j > 4)
		g_data.window_width = 2560;
	return (i);
}
int fetch_r_h(char *str, int i)
{
	int j;

	j = 0;
	while (str[i] == ' ')
		i++;

	g_data.window_height = ft_atoi(str + i);
	if (str[i] == '0' || !ft_isdigit(str[i]))
		ft_error("error in resolution",str);
	while (ft_isdigit(str[i]))
	{
		j++;
		i++;
	}
	if (str[i] != '\0')
		ft_error("error in resolution",str);
	if (g_data.window_height >= 1440 || j > 4)
		g_data.window_height = 1440;
	return (i);
}
void fetch_r(char *str)
{
	int i;

	i = 1;


	i = fetch_r_w(str,i);
	i = fetch_r_h(str,i);
	//printf("%d \n %d \n",g_data.window_width,g_data.window_height);
		g_data.r_completed = 1;
}