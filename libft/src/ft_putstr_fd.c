/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:28:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/20 15:01:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = -1;
	if (s)
	{
		while (s[++i] != '\0')
			ft_putchar_fd(s[i], fd);
	}
	else
		return ;
}
