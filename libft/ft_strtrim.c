/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:15:11 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/04 09:49:52 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_checkstart( char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*start;

	start = s1;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
			{
				start = (s1 + i + 1);
				break ;
			}
			else if (s1[i] != set[j] && !set[j + 1])
				return ((char *)start);
			j++;
		}
		i++;
	}
	return ((char *)start);
}

static char	*ft_checkend(char *s1, char *set)
{
	int		i;
	int		j;
	char	*end;

	end = NULL;
	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				break ;
			}
			if (s1[i] != set[j] && !set[j + 1])
			{
				end = &(s1[i]);
				return ((char *)end);
			}
			j++;
		}
		i--;
	}
	return ((char *)end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*result;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	result = NULL;
	start = ft_checkstart((char *)s1, (char *)set);
	end = ft_checkend((char *)s1, (char *) set);
	result = ft_substr((char *) s1, (start - s1), \
	(size_t)((((end + 1) - s1) - (start - s1))));
	if (!result)
		return (NULL);
	return (result);
}
