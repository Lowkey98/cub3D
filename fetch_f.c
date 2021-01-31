# include "includes/cub3d.h"

int		rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void check_rgb(int *rgb)
{
	if (rgb[0] == -1 || rgb[0] > 255)
		ft_error("invalid rgb in f");
	if (rgb[1] == -1 || rgb[1] > 255)
		ft_error("invalid rgb in f");
	if (rgb[2] == -1 || rgb[2] > 255)
		ft_error("invalid rgb in f");
}
int*	initialize_rgb(int *rgb)
{
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	return (rgb);
}
int fetch_f_r(int i,int *rgb,char * str)
{
	rgb[0] = ft_atoi(str);
	if (!ft_isdigit(str[i]))
		ft_error("error information r in F");
	while (ft_isdigit(str[i]))
	{
		if (i == 3)
			ft_error("max rgb == 255");
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error("RGB format 000,000,000");
	i++;
	return (i);
}
int fetch_f_g(int i, int *rgb, char* str)
{
	int j;

	j = 0;
	rgb[1] = ft_atoi(str + i);
		while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 3)
			ft_error("long");
		j++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error(",");
	i++;
	return (i);
}
int fetch_f_b(int i, int *rgb, char *str)
{
	int j;

	j = 0;
	rgb[2] = ft_atoi(str + i);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 3)
			ft_error("bigass numb");
		i++;
	}

	return i;
}
void fetch_f(char *str)
{
	int i;
	int rgb[3];

	i = 0;
	initialize_rgb(rgb);
	i += fetch_f_r(i,rgb,str);
	i += fetch_f_g(i,rgb,str);
	i += fetch_f_b(i,rgb,str);
	if (str[i] != '\0')
		ft_error("error last ddf");
	check_rgb(rgb);
	g_data.f_completed = 1;
}