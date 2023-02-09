/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:47:08 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 22:15:19 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_col(t_mlx *mlx)
{
	init_col_helper(mlx);
	mlx->col5 = mlx_xpm_file_to_image(mlx->mlx, \
		"bonus/xpmfiles/collectible5.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col5)
		destroy(mlx);
	mlx->col6 = mlx_xpm_file_to_image(mlx->mlx, \
		"bonus/xpmfiles/collectible6.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col6)
		destroy(mlx);
	mlx->col7 = mlx_xpm_file_to_image(mlx->mlx, \
		"bonus/xpmfiles/collectible7.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col7)
		destroy(mlx);
}

int	init_map(t_mlx	*mlx)
{
	int	j;
	int	k;

	j = 0;
	while (j < mlx->count)
	{
		k = 0;
		while (k < mlx->count2 + 1)
		{
			init_map_helper(mlx, k, j);
			k++;
		}
		j++;
	}
	return (0);
}
