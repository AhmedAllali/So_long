/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:04 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 19:22:54 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	xpm_to_img(t_mlx *mlx)
{
mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window (mlx->mlx, mlx->count * 50, \
		(mlx->count2 + 1) * 50, "GAME");
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, \
	"mandatory/xpmfiles/collectibles.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img)
		destroy(mlx);
	mlx->img1 = mlx_xpm_file_to_image(mlx->mlx, \
		"mandatory/xpmfiles/empty.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img1)
		destroy(mlx);
	mlx->img2 = mlx_xpm_file_to_image(mlx->mlx, "mandatory/xpmfiles/exit.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img2)
		destroy(mlx);
	mlx->img3 = mlx_xpm_file_to_image(mlx->mlx, \
	"mandatory/xpmfiles/player.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img3)
		destroy(mlx);
	mlx->img4 = mlx_xpm_file_to_image(mlx->mlx, "mandatory/xpmfiles/wall.xpm", \
		&mlx->img_width, &mlx->img_height);
	if (!mlx->img4)
		destroy(mlx);
}

void	init_map_helper(t_mlx *mlx, int k, int j)
{
	if (mlx->str2[k][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img4, j * 50, k * 50);
	if (mlx->str2[k][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img, j * 50, k * 50);
	if (mlx->str2[k][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img1, j * 50, k * 50);
	if (mlx->str2[k][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->img2, j * 50, k * 50);
	if (mlx->str2[k][j] == 'P')
	{
		mlx->data->x = k;
		mlx->data->y = j;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
		mlx->img3, j * 50, k * 50);
	}
}

void	init_map(t_mlx	*mlx)
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
}

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

int	check_path(char **str, int x, int y, t_mlx *mlx)
{
	if (str[y][x] == 'C')
		mlx->data->collectibleparsed++;
	if (str[y][x] == 'E')
		mlx->flag = 1;
	if (str[y][x] == '1' || str[y][x] == 'E')
		return (1);
	str[y][x] = '1';
	if (str[y + 1][x] != '1')
		check_path(str, x, y + 1, mlx);
	if (str[y - 1][x] != '1')
		check_path(str, x, y - 1, mlx);
	if (str[y][x + 1] != '1')
		check_path(str, x + 1, y, mlx);
	if (str[y][x - 1] != '1')
		check_path(str, x - 1, y, mlx);
	if (mlx->flag && mlx->data->collectibleparsed == mlx->data->countc)
		return (1);
	return (0);
}
