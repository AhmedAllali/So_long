/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:50:46 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/08 17:31:30 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	mouse(int keycode, t_mlx *mlx)
{
	if (keycode == 17)
	{
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		free(mlx->mlx);
		free(mlx);
		exit(0);
	}
	exit(1);
}

int	key(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		render_frames(mlx, -1, 0);
	if (keycode == 0)
		render_frames(mlx, 0, -1);
	if (keycode == 1)
		render_frames(mlx, 1, 0);
	if (keycode == 2)
		render_frames(mlx, 0, 1);
	if (keycode == 53)
		destroy(mlx);
	return (0);
}

void	hack_norm(t_data *data, t_mlx *mlx)
{
	(void)mlx;
	data->countcollect = 0;
	data->countc = 0;
	data->countp = 0;
	data->counte = 0;
	mlx->last = NULL;
	free(mlx->tmp);
	mlx->tmp = NULL;
	mlx->count2 = 0;
	mlx->count = 0;
	mlx->count3 = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->tmp2 = NULL;
	mlx->flag = 0;
	mlx->check = 0;
}

void	so_long(t_data *data, t_mlx *mlx)
{
	char	**tmp;

	get_map(mlx);
	mlx->count = ft_strlenup(mlx->str);
	if (checkstr(mlx->str))
		ft_exit("Error\n");
	mlx->tmp = ft_strjoin(mlx->tmp, mlx->str);
	readmap (mlx);
	mlx->str2 = ft_split (mlx->tmp, '\n');
	tmp = ft_split (mlx->tmp, '\n');
	mlx->tmp2 = mlx->str2;
	check_wall(mlx->str2[0]);
	check_characters(data);
	mlx->data->collectibleparsed = 0;
	check_position(mlx);
	free(mlx->tmp);
	if (check_path(tmp, mlx->x, mlx->y, mlx) == 0)
		ft_exit ("Err++or");
	ft_free(tmp);
	xpm_to_img (mlx);
	init_map (mlx);
	mlx_hook (mlx->mlx_win, 2, 1L << 0, key, mlx);
	mlx_hook (mlx->mlx_win, 17, 1L << 19, mouse, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_mlx	*mlx;

	data = malloc(sizeof(t_data));
	mlx = malloc(sizeof(t_mlx));
	mlx->tmp = malloc(sizeof(char));
	if (!mlx->tmp || !mlx || !data)
		ft_exit ("Error\n");
	hack_norm(data, mlx);
	mlx->data = data;
	if (ac == 2)
	{
		mlx->i = open(av[1], O_RDONLY);
		so_long(data, mlx);
	}
	else
	{
		free(mlx->tmp);
		free(data);
		free(mlx);
	}
	return (0);
}
