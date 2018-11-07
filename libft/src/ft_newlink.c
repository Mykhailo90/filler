/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:11:14 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 00:11:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft.h"

t_list	*ft_newlink(t_list *list, void *content)
{
	t_list	*linkinf;

	if (!(linkinf = malloc(sizeof(t_list))))
		return (NULL);
	if (linkinf)
	{
		linkinf->content = content;
		linkinf->next = list;
	}
	return (linkinf);
}
