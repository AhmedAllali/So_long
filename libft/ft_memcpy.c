/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:56:56 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/03 21:11:15 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	i = 0;
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	if (!c_dest && !c_src)
		return (NULL);
	while (i < size)
	{
			c_dest[i] = c_src[i];
			i++;
	}
	return (dest);
}
