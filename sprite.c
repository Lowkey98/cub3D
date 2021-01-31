# include "includes/cub3d.h"
void fetch_sprite_position(int i,int j)
{
	t_sprite *tmp;
	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	tmp->x = j * g_tile_size + g_tile_size/2;
	tmp->y = i * g_tile_size + g_tile_size/2;

	ft_lstadd_back(&g_sprite_h, ft_lstnew((void *)tmp));
			//printf("x == > %d \n",((t_sprite* )g_sprite_h ->content)->x);
}
void	sprite_distance()
{
	int x;
	int y;

	t_list *tmp;
	tmp = g_sprite_h;
	while (tmp!= NULL)
	{
		x = ((t_sprite *)tmp->content)->x;
		y = ((t_sprite *)tmp->content)->y;
		// printf("x %d\n",x);
		// printf("y %d\n",y);
		// printf("px  %f\n",g_player.x);
		// printf("py %f\n",g_player.y);

		((t_sprite *)tmp->content)->distance = distance_two_points(g_player.x,g_player.y,x,y);
		//printf("distance ==> %f\n",((t_sprite *)tmp->content)->distance);
		tmp = tmp -> next;
	}
}
void print_distance()
{

	while (g_sprite_h != NULL)
	{
		printf("distance ==> %f\n",((t_sprite*) g_sprite_h-> content) -> distance);
		g_sprite_h = g_sprite_h -> next;
	}
}
void sort_sprites()
{

	t_list	*new;
	t_list	*temp;
	t_sprite	*inter;

	new = g_sprite_h;
	while (new != NULL)
	{
		temp = new;
		while (temp->next != NULL)
		{
			if (((t_sprite *)temp->content)->distance < ((t_sprite *)temp->next->content)->distance)
			{
				inter = (t_sprite *)temp->content;
				temp->content = temp->next->content;
				temp->next->content = (void *)inter;
			}
			temp = temp->next;
		}
		new = new->next;
}
}
void	render_sprite()
{
	sprite_distance();
	sort_sprites();
	print_distance();
	render_sprites();
}