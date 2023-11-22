/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:37 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/22 14:58:46 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_no_event(t_data *data)
{
	usleep(33333);
	mouse_hook(data);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	if (data->rl == 1 || data->rr)
		view_player(data);
	if (data->mf == 1 || data->mb == 1)
		move_player(data);
	if (data->ml == 1 || data->mr == 1)
		move_playerlr(data);
	clear_map(data);
	do_floor_cel(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	key_press(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 109)
	{
		if (data->minimap)
			data->minimap = 0;
		else
			data->minimap = 1;
	}
	if (keysym == 65361)
		data->rl = 1;
	if (keysym == 65363)
		data->rr = 1;
	if (keysym == 115)
		data->mf = 1;
	if (keysym == 119)
		data->mb = 1;
	if (keysym == 97)
		data->ml = 1;
	if (keysym == 100)
		data->mr = 1;
	if (keysym == XK_Escape)
		free_all(data);
	return (0);
}

int	key_release(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 65361)
		data->rl = 0;
	if (keysym == 65363)
		data->rr = 0;
	if (keysym == 119)
		data->mb = 0;
	if (keysym == 115)
		data->mf = 0;
	if (keysym == 97)
		data->ml = 0;
	if (keysym == 100)
		data->mr = 0;
	return (0);
}

int	cross_kill(t_data *data)
{
	free_all(data);
	return (0);
}
