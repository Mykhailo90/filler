/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:11:02 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:16:11 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char *)s;
	while (n-- > 0)
		*ptr++ = '\0';
	return (s);
}
