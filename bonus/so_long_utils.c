/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:25:38 by ahallali          #+#    #+#             */
/*   Updated: 2023/02/07 16:48:44 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlenup(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str [i] != '\n')
	{
		i++;
	}
	return (i);
}

int	check_wall(char	*av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'E' \
		|| str[i] == 'P' || str [i] == 'C' || str[i] == '\n' || str[i] == 'K')
		{
			if (str[i] == 'E')
				data->counte += 1;
			else if (str[i] == 'P')
				data->countp += 1;
			else if (str[i] == 'C')
				data->countc++;
			else if (str[i] == 'K')
				data->countk++;
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	checkstr(char *str )
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str [i] != '1' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	checklast(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
