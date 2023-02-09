/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:39 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 22:58:00 by ahallali         ###   ########.fr       */
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
		ft_exit("file not found");
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
}

void	fun_norm(t_mlx *mlx)
{
	char	*tmp;

	mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, mlx->img3, \
	mlx->data->y * 50, mlx->data->x * 50);
	mlx->count3 ++;
	tmp = ft_itoa (mlx->count3);
	write (1, "move : ", 7);
	write (1, tmp, ft_strlen(tmp));
	write (1, "\n", 1);
	free (tmp);
}
