
#include <stdio.h>
#include "includes/cub3d.h"

void initialize_data(t_struct *data)
{
    data -> map = 0;
    data -> x_render_size = 0;
    data -> y_render_size = 0;
    data -> r_completed = 0;
    data -> f_completed = 0;
    data -> map_lenght = 0;
}
int main()
{
    t_struct *data;
    data = malloc(sizeof(t_struct));
    initialize_data(data);
    read_file(data);
    return (0);
}
