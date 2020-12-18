# include "includes/cub3d.h"
void    fetch_player_info(t_struct *data)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' ||data->map[i][j] == 'W')
            {
                g_player.direction = data->map[i][j];
                g_player.x = j * TILE_SIZE + TILE_SIZE/2;
                g_player.y = i * TILE_SIZE + TILE_SIZE/2;
            }
            j++;
        }
        i++;
    }
    
    ft_putchar(g_player.direction);
    my_mlx_pixel_put(&g_mlx, g_player.x,g_player.y,RED);
}
void    draw_rect(int i, int j,int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y != TILE_SIZE)
    {
        x = 0;
        while (x != TILE_SIZE)
        {
            my_mlx_pixel_put(&g_mlx, (j * TILE_SIZE) + x,(i * TILE_SIZE) + y,color);
            if (y == 0 || x == TILE_SIZE - 1)
                my_mlx_pixel_put(&g_mlx, (j * TILE_SIZE) + x,(i * TILE_SIZE) + y,RED);
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