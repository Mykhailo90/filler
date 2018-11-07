/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:16:05 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:50:07 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ptr != NULL)
		{
			ptr = ft_strcat(ptr, s1);
			ptr = ft_strcat(ptr, s2);
		}
		return (ptr);
	}
	return (NULL);
}
