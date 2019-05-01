/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/28 18:08:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_DEFS_H

# define FT_GNL_DEFS_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define FT_GNL_BUFF_SIZE 40

typedef struct				s_gnl_list
{
	int						fd;
	char					*buff;
	struct s_gnl_list		*next;
}							t_gnl_list;

typedef struct				s_gnl_data
{
	t_gnl_list				*node;
	char					rbuff[FT_GNL_BUFF_SIZE + 1];
	ssize_t					rlen;
	ssize_t					len;
	char					*tmp;
	int						ret_flag;
}							t_gnl_data;

#endif
