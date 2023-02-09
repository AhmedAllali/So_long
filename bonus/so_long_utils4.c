/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:04 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 22:38:24 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	xpm_to_img(t_mlx *mlx)
{
mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window (mlx->mlx, mlx->count * 50, \
		(mlx->count2 + 1) * 50, "GAME");
	init_col(mlx);
	mlx->img1 = mlx_xpm_file_to_image(mlx->mlx, "bonus/xpmfiles/empty.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img1)
		destroy(mlx);
	mlx->img2 = mlx_xpm_file_to_image(mlx->mlx, "bonus/xpmfiles/exit.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img2)
		destroy(mlx);
	mlx->img3 = mlx_xpm_file_to_image(mlx->mlx, "bonus/xpmfiles/player.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img3)
		destroy(mlx);
	mlx->img4 = mlx_xpm_file_to_image(mlx->mlx, "bonus/xpmfiles/wall.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img4)
		destroy(mlx);
	mlx->img5 = mlx_xpm_file_to_image(mlx->mlx, "bonus/xpmfiles/enemy.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img5)
		destroy (mlx);
}

void	render_col_helper(t_mlx *mlx, int x, int k, int j)
{
	if (x % 7 == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->col1, j * 50, k * 50);
	if (x % 7 == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col2, j * 50, k * 50);
	if (x % 7 == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col3, j * 50, k * 50);
	if (x % 7 == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col4, j * 50, k * 50);
	if (x % 7 == 4)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col5, j * 50, k * 50);
	if (x % 7 == 5)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col6, j * 50, k * 50);
	if (x % 7 == 6)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col7, j * 50, k * 50);
}

int	render_col(t_mlx *mlx, int k, int j)
{
	static int	x;
	static int	z;

	render_col_helper(mlx, x, k, j);
	z++;
	if (z == 18)
	{
		x++;
		z = 0;
	}
	return (0);
}

void	init_map_helper(t_mlx *mlx, int k, int j)
{
	if (mlx->str2[k][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->col1, j * 50, k * 50);
	if (mlx->str2[k][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img1, j * 50, k * 50);
	if (mlx->str2[k][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img2, j * 50, k * 50);
	if (mlx->str2[k][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img4, j * 50, k * 50);
	if (mlx->str2[k][j] == 'K')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img5, j * 50, k * 50);
	if (mlx->str2[k][j] == 'P')
	{
		mlx->data->x = k;
		mlx->data->y = j;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
		mlx->img3, j * 50, k * 50);
	}
}

void	init_col_helper(t_mlx *mlx)
{
	mlx->col1 = mlx_xpm_file_to_image(mlx->mlx, \
	"bonus/xpmfiles/collectible1.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col1)
		destroy(mlx);
	mlx->col2 = mlx_xpm_file_to_image(mlx->mlx, \
	"bonus/xpmfiles/collectible2.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col2)
		destroy(mlx);
	mlx->col3 = mlx_xpm_file_to_image(mlx->mlx, \
		"bonus/xpmfiles/collectible3.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col3)
		destroy(mlx);
	mlx->col4 = mlx_xpm_file_to_image(mlx->mlx, \
		"bonus/xpmfiles/collectible4.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->col4)
		destroy(mlx);
}
