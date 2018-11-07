/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:17:05 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 13:02:44 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = malloc(size + 1);
	if (s)
	{
		(ft_bzero(s, size + 1));
		return (s);
	}
	else
		return (NULL);
}
