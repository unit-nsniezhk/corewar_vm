/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:17:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_DEF_H

# define COREWAR_DEF_H

# include "corewar_settings.h"

typedef struct			s_player
{
	unsigned int		pos;
	char				*name;
}						t_player;

typedef struct			s_carriage
{
	unsigned int		id;
	unsigned int		carry : 1;
	char				op;
	unsigned int		last_live;
	unsigned int		timeout;
	int					pos;
	unsigned int		delta_pos;
	int					args_values[3];
	char				args_types[3];
	int					regs[N_REGS + 1];
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_data
{
	unsigned int		dump;
	unsigned int		check;
	unsigned int		cycle;
	int					cycles_to_check;
	unsigned int		n_live;
	unsigned int		n_carrs;
	t_player			players[MAX_PLAYERS];
	char				arena[ARENA_SIZE];
	t_carriage			*carr;
}						t_data;

typedef void			(*t_function)(t_data *data, t_carriage *carr);

#endif
