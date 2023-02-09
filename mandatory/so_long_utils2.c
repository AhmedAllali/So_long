/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:26:39 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:33 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	wall_collision(t_mlx *data, int x, int y)
{
	if (data->str2[x][y] == '1' || (data->str2[x][y] == 'E'\
		&& data->data->countc != data->data->countcollect))
		return (1);
	return (0);
}

int	is_collectible(t_mlx *data, int x, int y)
{
	if (data->str2[x][y] == 'C')
	{
		data->data->countcollect++;
		data->str2[x][y] = '0';
		return (1);
	}
	return (0);
}

int	is_exit(t_mlx *data, int x, int y)
{
	if (data->str2[x][y] == 'E')
		return (1);
	return (0);
}

void	render_img(t_mlx *mlx)
{
	int	j;
	int	k;

	j = 0;
	while (j < mlx->count)
	{
	k = 0;
		while (k < mlx->count2 + 1)
		{
			if (mlx->str2[k][j] == '1')
				mlx_put_image_to_window \
				(mlx->mlx, mlx->mlx_win, mlx->img4, j * 50, k * 50);
			if (mlx->str2[k][j] == 'C')
				mlx_put_image_to_window \
				(mlx->mlx, mlx->mlx_win, mlx->img, j * 50, k * 50);
			if (mlx->str2[k][j] == '0')
				mlx_put_image_to_window \
				(mlx->mlx, mlx->mlx_win, mlx->img1, j * 50, k * 50);
			if (mlx->str2[k][j] == 'E')
				mlx_put_image_to_window \
				(mlx->mlx, mlx->mlx_win, mlx->img2, j * 50, k * 50);
				k++;
		}
			j++;
	}
}

void	render_frames(t_mlx *mlx, int x, int y)
{
	char	*tmp;

	tmp = NULL;
	if (!wall_collision(mlx, mlx->data->x + x, mlx->data->y + y))
	{
		if (is_exit(mlx, mlx->data->x + x, mlx->data->y + y))
		{
			if (mlx->data->countcollect == mlx->data->countc)
			{
				ft_free(mlx->str2);
				ft_exit("YOU WIN !!");
			}
		}
		else
		{
			is_collectible (mlx, mlx->data->x + x, mlx->data->y + y);
			mlx_clear_window (mlx->mlx, mlx->mlx_win);
			mlx->data->x += x;
			mlx->data->y += y;
			render_img (mlx);
			fun_norm(mlx);
		}
	}
}
