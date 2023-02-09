/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:26:39 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 17:47:21 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	is_enemy(t_mlx *data, int x, int y)
{
	if (data->str2[x][y] == 'K')
		return (1);
	return (0);
}

int	is_exit(t_mlx *data, int x, int y)
{
	if (data->str2[x][y] == 'E')
		return (1);
	return (0);
}

void	render_img_helper(t_mlx *mlx, int k, int j)
{
	if (mlx->str2[k][j] == 'P')
		mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, mlx->img3, \
			mlx->data->y * 50, mlx->data->x * 50);
	if (mlx->str2[k][j] == 'K')
		mlx_put_image_to_window \
		(mlx->mlx, mlx->mlx_win, mlx->img5, j * 50, k * 50);
	if (mlx->str2[k][j] == '1')
	{
		if (k == 0 || j == 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
				mlx->img4, 0, 0);
			mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, \
			0xFFFFFF, ft_itoa(mlx->count3));
		}
		mlx_put_image_to_window \
		(mlx->mlx, mlx->mlx_win, mlx->img4, j * 50, k * 50);
	}
	if (mlx->str2[k][j] == 'C')
		render_col(mlx, k, j);
	if (mlx->str2[k][j] == 'E')
		mlx_put_image_to_window \
			(mlx->mlx, mlx->mlx_win, mlx->img2, j * 50, k * 50);
}

int	render_img(t_mlx *mlx)
{
	int	j;
	int	k;

	j = 0;
	while (j < mlx->count)
	{
		k = 0;
		while (k < mlx->count2 + 1)
		{
			render_img_helper(mlx, k, j);
			k++;
		}
			j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img3, j * 50, k * 50);
	return (0);
}

int	render_frames(t_mlx *mlx, int x, int y)
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
			fun_norm(mlx, x, y);
	}
	return (0);
}
