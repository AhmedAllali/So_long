/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:02:51 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/31 15:20:18 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i ;

	i = 0;
	while (i < len)
		((unsigned char *)ptr)[i++] = (unsigned char)c;
	return (ptr);
}
