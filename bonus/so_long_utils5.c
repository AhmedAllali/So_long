/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:39 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 23:04:34 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	return (NULL);
}

void	get_map(t_mlx *mlx)
{
	if (mlx->i < 0)
		ft_exit("Error\n");
	else
		mlx->str = get_next_line(mlx->i);
	if (!mlx->str)
		ft_exit("Error\n");
}

void	check_characters(t_data *data)
{
	if (data->counte > 1 || data->counte == 0)
		ft_exit("Error\n");
	else if (data->countp > 1 || data->countp == 0)
		ft_exit("Error\n");
	else if (data->countc == 0)
		ft_exit("Error\n");
	else if (data->countk == 0)
		ft_exit("Error\n");
}

void	fun_norm(t_mlx *mlx, int x, int y)
{
	char	*tmp;

	tmp = NULL;
	is_collectible (mlx, mlx->data->x + x, mlx->data->y + y);
	if (is_enemy(mlx, mlx->data->x + x, mlx->data->y + y) == 1)
		ft_exit("LOSER!!");
	mlx_clear_window (mlx->mlx, mlx->mlx_win);
	mlx->data->x += x;
	mlx->data->y += y;
	mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, mlx->img3, \
	mlx->data->y * 50, mlx->data->x * 50);
	render_img(mlx);
	mlx->count3 ++;
	free (tmp);
}

int	check_path(char **str, int x, int y, t_mlx *mlx)
{
	if (str[y][x] == 'C')
		mlx->data->collectibleparsed++;
	if (str[y][x] == 'E')
		mlx->flag = 1;
	if (str[y][x] == '1' || str[y][x] == 'E' || str[y][x] == 'K')
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
