/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:38:00 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/26 17:18:50 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft.h"

# define BUFF_SIZE 10000

typedef struct			s_lists
{
	int					d;
	char				*str;
	struct s_lists		*next;
}						t_lists;

typedef struct			s_var
{
	int					i;
	char				*tmp;
	int					f;
	int					z;
	char				*del;
}						t_var;

typedef struct			s_var_gnl
{
	int					i;
	char				*buffer;
	int					t;
	t_lists				*start;
}						t_var_gnl;

typedef struct			s_var_ss
{
	int					i;
	char				*string;
	int					f;
}						t_var_ss;

int						get_next_line(const int fd, char **line);

#endif
