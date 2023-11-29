/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/28 15:37:13 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_free(t_data *data)
{
	if (data->tex->no->img)
		mlx_destroy_image(data->mlx, data->tex->no->img);
	if (data->tex->so->img)
		mlx_destroy_image(data->mlx, data->tex->so->img);
	if (data->tex->ea->img)
		mlx_destroy_image(data->mlx, data->tex->ea->img);
	if (data->tex->we->img)
		mlx_destroy_image(data->mlx, data->tex->we->img);
	if (data->tex->door && data->tex->door->img)
		mlx_destroy_image(data->mlx, data->tex->door->img);
	if (data->tex->door1 && data->tex->door1->img)
		mlx_destroy_image(data->mlx, data->tex->door1->img);
	if (data->tex->door2 && data->tex->door2->img)
		mlx_destroy_image(data->mlx, data->tex->door2->img);
	if (data->tex->door3 && data->tex->door3->img)
		mlx_destroy_image(data->mlx, data->tex->door3->img);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

void	free_tex(t_data *data)
{
	free(data->tex->door);
	free(data->tex->door1);
	free(data->tex->door2);
	free(data->tex->door3);
	free(data->tex->no);
	free(data->tex->ea);
	free(data->tex->we);
	free(data->tex->so);
	free(data->tex);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->tex->ce);
	free(data->tex->fl);
	mlx_free(data);
	free_tex(data);
	free(data->player);
	free(data->ray);
	free(data->img);
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	free(data->file);
	free(data->mlx);
	free(data);
	exit (0);
}