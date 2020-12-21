# include "includes/cub3d.h"
void    my_mlx_pixel_put(t_lib *g_mlx, int x, int y, int color)
{
    char    *dst;

    dst = g_mlx->addr  + (y * g_mlx->line_length + x * (g_mlx->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void    draw_line(float x_one,float y_one,float x_zero,float y_zero)
{
    float dx;
    float dy;
    float steps;
    float x_inc;
    float y_inc;
    float i;
    i = 0;
    dx = x_one - x_zero;
    dy = y_one - y_zero;

    if (fabsf(dx) > fabsf(dy))
        steps = fabsf(dx);
    else 
        steps = fabsf(dy);
    x_inc = dx / steps;
    y_inc = dy / steps;
    while (i < steps)
    {        
        my_mlx_pixel_put(&g_mlx,x_zero,y_zero,BLACK);
        x_zero += x_inc;
        y_zero  += y_inc;
        //printf("%f\n",y);
        //printf("%f\n",x);
        i++;
    }
    
    
}