# include "includes/cub3d.h"

void check_rgb_c(int *rgb)
{
	if (rgb[0] == -1 || rgb[0] > 255)
		ft_error("invalid rgb in c");
	if (rgb[1] == -1 || rgb[1] > 255)
		ft_error("invalid rgb in c");
	if (rgb[2] == -1 || rgb[2] > 255)
		ft_error("invalid rgb in c");
	g_data.c_color = rgb_to_int(0, rgb[0],rgb[1], rgb[2]);
}

int fetch_c_r(int i,int *rgb,char * str)
{
	int j;

	j = 0;
	rgb[0] = ft_atoi(str + i);
	printf("aaaa%d",rgb[0]);
	if (!ft_isdigit(str[i]))
		ft_error("error information r in F");
	while (ft_isdigit(str[i]))
	{
		if (j == 3)
			ft_error("max rgb == 255");
		i++;
		j++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error("RGB format 000,000,000");
	i++;
	return (i);
}
int fetch_c_g(int i, int *rgb, char* str)
{
	int j;

	j = 0;
	rgb[1] = ft_atoi(str + i);
	printf("qqq%d\n",rgb[1]);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 3)
			ft_error("max is 255 in c info");
		j++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error("need , after second information");
	i++;
	return (i);
}
int fetch_c_b(int i, int *rgb, char *str)
{
	int j;

	j = 0;
	rgb[2] = ft_atoi(str + i);
	printf("\n%d\n",rgb[2]);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		//printf("a %c \n",str[i]);
		if (j > 3)
			ft_error("max is 255 in c info");
		i++;
	}

	return i;
}
void fetch_c(char *str)
{
	int i;
	int rgb[3];

	i = 2;
	initialize_rgb(rgb);
	while (str[i] == ' ')
		i++;
	i = fetch_c_r(i,rgb,str);
	i = fetch_c_g(i,rgb,str);
	i = fetch_c_b(i,rgb,str);
	if (str[i] != '\0')
		ft_error("error last info in c");
	check_rgb_c(rgb);
	g_data.c_completed = 1;
}