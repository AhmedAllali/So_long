/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:14:15 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/04 02:35:07 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_countdigit(long long int c)
{
	int	count ;

	count = 0;
	if (c < 0)
	{
		c *= -1;
		count = 1;
	}
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	int				len;
	int				sign;
	long long int	i;

	i = n;
	sign = 0;
	len = ft_countdigit(i);
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (len > 0)
	{
		ptr[len - 1] = '0' + (i % 10);
		i = i / 10;
		len--;
	}
	if (sign)
		ptr[0] = '-';
	return (ptr);
}
