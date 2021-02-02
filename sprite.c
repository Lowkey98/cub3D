/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:40:28 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:42:44 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	fetch_sprite_position(int i, int j)
{
	t_sprite *tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	tmp->x = j * g_tile_size + g_tile_size / 2;
	tmp->y = i * g_tile_size + g_tile_size / 2;
	ft_lstadd_back(&g_sprite_h, ft_lstnew((void *)tmp));
}

void	sprite_distance(void)
{
	int		x;
	int		y;
	t_list	*tmp;

	tmp = g_sprite_h;
	while (tmp != NULL)
	{
		x = ((t_sprite *)tmp->content)->x;
		y = ((t_sprite *)tmp->content)->y;
		((t_sprite *)tmp->content)->distance =
		distance_two_points(g_player.x, g_player.y, x, y);
		tmp = tmp->next;
	}
}

void	sort_sprites(void)
{
	t_list		*new;
	t_list		*temp;
	t_sprite	*inter;

	new = g_sprite_h;
	while (new != NULL)
	{
		temp = new;
		while (temp->next != NULL)
		{
			if (((t_sprite *)temp->content)->distance <
			((t_sprite *)temp->next->content)->distance)
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

void	sprite(void)
{
	sprite_distance();
	sort_sprites();
	render_sprites();
}
