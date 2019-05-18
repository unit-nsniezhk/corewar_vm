/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:19:52 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 20:51:45 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "corewar_vis_color.h"

void	corewar_op_arg(t_data *data, t_carriage *carr, unsigned int n,
		unsigned int *arg)
{
	int	pos;

	if (carr->args_types[n] == REG)
		*arg = carr->regs[carr->args_values[n]];
	else if (carr->args_types[n] == DIR)
		*arg = carr->args_values[n];
	else
	{
		pos = carr->pos + (carr->args_values[n] % IDX_MOD);
		corewar_read_arg(data, arg, REG, data->arena[corewar_8(pos)]);
	}
}

void	corewar_op_larg(t_data *data, t_carriage *carr, unsigned int n,
		unsigned int *arg)
{
	int	pos;

	if (carr->args_types[n] == REG)
	{
		if (carr->args_values[n] < 1 || carr->args_values[n] > N_REGS)
			return ;
		*arg = carr->regs[carr->args_values[n]];
	}
	else if (carr->args_types[n] == DIR)
		*arg = carr->args_values[n];
	else
	{
		pos = carr->pos + carr->args_values[n];
		corewar_read_arg(data, arg, REG, data->arena[corewar_8(pos)]);
	}
}

void	corewar_op_new_carriage(t_data *data, t_carriage *carr_src, int pos)
{
	t_carriage		*carr_new;
	unsigned int	i;

	data->n_carrs++;
	data->n_a_carrs++;
	carr_new = ft_memalloc(sizeof(t_carriage));
	carr_new->id = data->n_a_carrs;
	carr_new->carry = carr_src->carry;
	carr_new->op = 0;
	carr_new->last_live = carr_src->last_live;
	carr_new->pos = corewar_8(pos);
	carr_new->delta_pos = 0;
	carr_new->shown = false;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_new->regs[i] = carr_src->regs[i];
		++i;
	}
	carr_new->next = data->carr;
	data->carr = carr_new;
}

void	corewar_op_vis(t_carriage *carr, t_vis *vis, int pos, int n_players)
{
	unsigned int	color;
	unsigned int	i;

	if ((int)(carr->regs[1] * -1) <= n_players
	&& (int)(carr->regs[1] * -1) >= (int)MIN_PLAYERS)
		color = g_color[(-carr->regs[1])];
	else
		color = g_color[0];
	i = 0;
	while (i < REG_SIZE)
	{
		vis->color[corewar_8(pos + i)] = color;
		++i;
	}
}
