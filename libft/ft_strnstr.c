/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:02:19 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/03 01:45:49 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (!*needle || (haystack == needle && ft_strlen(needle) == len))
		return ((char *)haystack);
	while (len && *haystack)
	{
		i = 0;
		while (*(needle + i) == *(haystack + i) && *(needle + i) && len--)
			if (!*(needle + ++i))
				return ((char *)(haystack));
		len += i;
				len--;
		haystack++;
	}
	return (NULL);
}
