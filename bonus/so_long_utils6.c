/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:25:38 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 17:29:49 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*check_position(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < mlx->count)
	{
		mlx->y = 0;
		while (mlx->y < mlx->count2 + 1)
		{
			if (mlx->tmp2 [mlx->y][mlx->x] == 'P')
				return (mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	return (mlx);
}

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
