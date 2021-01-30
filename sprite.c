# include "includes/cub3d.h"
void fetch_sprite_position(int i,int j)
{
	t_sprite *tmp;
	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	tmp->x = i * g_tile_size + 30;
	tmp->y = j * g_tile_size + 30;

	ft_lstadd_back(&g_sprite_h, ft_lstnew((void *)tmp));
			//printf("x == > %d \n",((t_sprite* )g_sprite_h ->content)->x);

}
