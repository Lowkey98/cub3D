# include "includes/cub3d.h"
void    fetch_rotation_angle()
{
    if (g_player.direction == 'S')
        g_player.rotation_angle = PI/2;
    else if(g_player.direction == 'E')
        g_player.rotation_angle = PI;
    else if(g_player.direction == 'N')    
        g_player.rotation_angle = 3 * PI/2;
    else if(g_player.direction == 'W')
        g_player.rotation_angle = 2 * PI;     
}
void    fetch_player_info()
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (g_data.map[i])
    {
        j = 0;
        while (g_data.map[i][j])
        {
            if (g_data.map[i][j] == 'N' || g_data.map[i][j] == 'S' || g_data.map[i][j] == 'E' ||g_data.map[i][j] == 'W')
            {
                g_player.direction = g_data.map[i][j];
                g_player.x = j * TILE_SIZE + TILE_SIZE/2;
                g_player.y = i * TILE_SIZE + TILE_SIZE/2;
            }
            j++;
        }
        i++;
    }
    fetch_rotation_angle();
    //initialize_player_info();

    //ft_putchar(g_player.direction);
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
int grid_color(int i,int j)
{
    if (g_data.map[i][j] == '1')
        return (RED);
    if (g_data.map[i][j] == '0')
        return (WHITE);
    if (g_data.map[i][j] == ' ')
        return (BLACK);
    // return (0);
    return (WHITE);
}
void    draw_map()
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_data.map[i])
    {
        j = 0;
        while (g_data.map[i][j])
        {
            draw_rect(i,j,grid_color(i,j));
            //my_mlx_pixel_put(&g_mlx,1,1,0xffffff);
            j++;        
            //ft_putnbr(j);

        }
        i++;
    }
}