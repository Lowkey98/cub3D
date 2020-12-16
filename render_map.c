# include "includes/cub3d.h"
void    draw_rect(int i, int j,int color)
{
    int grid = 32;
    int x;
    int y;

    x = 0;
    y = 0;
    while(y != grid)
    {
        x = 0;
        while (x != grid)
        {
            my_mlx_pixel_put(&g_mlx, (j * grid) + x,(i * grid) + y,color);
            x++;
        }
        y++;
    }
}
int grid_color(t_struct *data,int i,int j)
{
    if (data->map[i][j] == '1')
        return (RED);
    if (data -> map[i][j] == '0')
        return (WHITE);
    if (data->map[i][j] == ' ')
        return (BLACK);
    // return (0);
    return (WHITE);
}
void    render_map(t_struct *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i])
    {
        j = 0;
        while (data ->map[i][j])
        {
            draw_rect(i,j,grid_color(data,i,j));
            //my_mlx_pixel_put(&g_mlx,1,1,0xffffff);
            j++;        
            //ft_putnbr(j);

        }
        i++;
    }
}