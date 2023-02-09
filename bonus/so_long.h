/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:05:24 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/08 18:30:37 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include"../libft/libft.h"
# include <unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<mlx.h>
# include "../mandatory/GET_NEXT_LINE/get_next_line.h"

typedef struct s_data
{
	int		counte ;
	int		countp;
	int		countc ;
	int		countk;
	int		countcollect;
	int		collectibleparsed;
	int		exitfounds;
	int		x;
	int		y;
}	t_data;
typedef struct s_mlx
{
	t_data	*data;
	void	*mlx;
	int		flag;
	void	*mlx_win;
	int		i;
	int		x;
	int		y;
	int		count;
	int		count2;
	int		count3;
	char	*str;
	char	*tmp;
	char	**tmp2;
	char	*last;
	char	**str2;
	int		img_width;
	int		img_height;
	void	*col1;
	void	*col2;
	void	*col3;
	void	*col4;
	void	*col5;
	void	*col6;
	void	*col7;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		ex;
	int		ey;
}	t_mlx;
int		ft_strlenup(char	*str);
int		mouse(int keycode, t_mlx *mlx);
int		key(int keycode, t_mlx *mlx);
int		wall_collision(t_mlx *data, int x, int y);
int		is_collectible(t_mlx *data, int x, int y);
int		readmap(t_mlx *mlx);
void	so_long(t_data *data, t_mlx *mlx);
int		is_exit(t_mlx *data, int x, int y);
int		checkstr(char *str );
int		checklast(char *str);
int		check_wall(char *av);
int		check_line(char *str, t_data *data);
int		render_img(t_mlx *mlx);
void	xpm_to_img(t_mlx *mlx);
int		init_map(t_mlx *mlx);
void	init_map_helper(t_mlx *mlx, int k, int j);
void	destroy(t_mlx *mlx);
int		render_frames(t_mlx *mlx, int x, int y);
void	ft_exit(char *error);
t_mlx	*check_position(t_mlx *mlx);
int		check_path(char **str, int x, int y, t_mlx *mlx);
char	**ft_free(char **ptr);
int		is_enemy(t_mlx *data, int x, int y);
void	init_col(t_mlx *mlx);
int		render_col(t_mlx *mlx, int k, int j);
void	get_map(t_mlx *mlx);
void	check_characters(t_data *data);
void	fun_norm(t_mlx *mlx, int x, int y);
void	init_col_helper(t_mlx *mlx);
#endif
