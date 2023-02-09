/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:35:28 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 22:57:23 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_exit(char *error)
{
	write(1, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	readmap_helper(t_mlx *mlx)
{
	if (ft_strlenup(mlx->str) == mlx->count)
	{
		if (check_line(mlx->str, mlx->data))
			ft_exit("Error\n");
	}
	else
		ft_exit("Error\n");
	if (mlx->str[ft_strlen(mlx->str) - 2] != '1')
		ft_exit("Error\n");
	else if (mlx->str[0] != '1')
		ft_exit("Error\n");
	else
	mlx->tmp = ft_strjoin(mlx->tmp, mlx->str);
	mlx->last = mlx->str;
}

int	readmap(t_mlx *mlx)
{
	mlx->last = mlx->str;
	while (mlx->str)
	{
		mlx->str = get_next_line(mlx->i);
		if (mlx->str && mlx->str[0] == '\n')
			ft_exit("map invalid espace au debut");
		if (!mlx->str)
		{
			if (checklast(mlx->last) == 1)
				ft_exit("map invalid new line");
			else
				break ;
		}
		free(mlx->last);
		readmap_helper(mlx);
		mlx->count2++;
	}
	free(mlx->last);
	return (0);
}

void	destroy(t_mlx	*mlx)
{	
	write(1, "Error\n", 5);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	ft_free(mlx->str2);
	free(mlx);
	exit(0);
}
