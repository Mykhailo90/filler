/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:37:09 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/26 18:45:47 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lists			*add_list(t_lists *list, int fd, char *buffer, int i)
{
	int					k;
	t_lists				*current;
	t_lists				*new_fd;

	k = ft_strlen(buffer);
	current = list;
	new_fd = malloc(sizeof(t_lists));
	new_fd->d = fd;
	new_fd->str = ft_memalloc(k - i);
	new_fd->str = ft_strncpy(new_fd->str, &buffer[i + 1], k - i);
	new_fd->next = NULL;
	if (current == NULL)
		list = new_fd;
	else
	{
		while (current->next != NULL)
			current = current->next;
	}
	current->next = new_fd;
	while (list)
		list = list->next;
	return (list);
}

static int				check_list(int i, t_lists *list)
{
	while (list)
	{
		if (i == list->d)
			return (1);
		list = list->next;
	}
	return (0);
}

static int				read_str(int fd, char **buffer)
{
	t_var				vars;

	vars.z = 1;
	vars.f = 0;
	vars.tmp = ft_memalloc(BUFF_SIZE + 1);
	while (vars.z)
	{
		vars.z = read(fd, vars.tmp, BUFF_SIZE);
		if (vars.z == -1)
			return (-1);
		vars.i = 0;
		while (vars.tmp[vars.i] != '\0')
		{
			if (vars.tmp[vars.i++] == '\n')
				vars.f = 1;
		}
		vars.del = *buffer;
		*buffer = ft_ald_strjoin(*buffer, vars.tmp);
		ft_strdel(&vars.del);
		ft_bzero(vars.tmp, BUFF_SIZE);
		if (vars.f)
			break ;
	}
	ft_strdel(&vars.tmp);
	return (0);
}

static int				search_str(int fd, char **buffer, t_lists *list)
{
	t_var_ss			ss;

	ss.i = 0;
	while (list->d != fd || !list->str)
	{
		if (list->next)
			list = list->next;
		else
		{
			read_str(fd, buffer);
			return (-5);
		}
	}
	ss.string = list->str;
	list->str = NULL;
	*buffer = ft_ald_strjoin(*buffer, ss.string);
	ft_strdel(&ss.string);
	while (buffer[0][ss.i] != '\0')
	{
		if (buffer[0][ss.i++] == '\n')
			ss.f = 1;
	}
	read_str(fd, buffer);
	return (-5);
}

int						get_next_line(const int fd, char **line)
{
	t_var_gnl			gnl;
	static t_lists		list;

	gnl.t = 0;
	list.d = -1;
	if (fd < 0 || fd == 2 || !(line))
		return (-1);
	gnl.i = 0;
	gnl.start = &list;
	gnl.buffer = (char *)ft_memalloc(BUFF_SIZE);
	gnl.t = (check_list(fd, gnl.start) == 0) ? read_str(fd, &gnl.buffer) :
		search_str(fd, &gnl.buffer, gnl.start);
	if (gnl.t == -1)
		return (-1);
	while (gnl.buffer[gnl.i] != '\n' && gnl.buffer[gnl.i] != '\0')
		gnl.i++;
	*line = ft_memalloc(gnl.i + 1);
	*line = ft_strncpy(*line, gnl.buffer, gnl.i);
	add_list(gnl.start, fd, gnl.buffer, gnl.i);
	if (gnl.buffer[0] == '\0')
		return (0);
	ft_strdel(&gnl.buffer);
	return (1);
}
