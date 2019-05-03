/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:19:52 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/03 15:33:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_arg(t_data *data, t_carriage *carr, unsigned int n, int *arg)
{
	int	pos;

	if (carr->args_types[n] == REG)
		*arg = carr->regs[carr->args_values[0]];
	else if (carr->args_types[n] == DIR)
		*arg = carr->args_values[n];
	else
	{
		pos = carr->pos + (carr->args_values[n] % IDX_MOD);
		corewar_read_arg(data, arg, REG, data->arena[corewar_8(pos)]);
	}
}

void	corewar_op_larg(t_data *data, t_carriage *carr, unsigned int n,
		int *arg)
{
	int	pos;

	if (carr->args_types[n] == REG)
		*arg = carr->regs[carr->args_values[0]];
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
	carr_new = ft_memalloc(sizeof(t_carriage));
	carr_new->id = data->n_carrs;
	carr_new->carry = carr_src->carry;
	carr_new->op = 0;
	carr_new->last_live = carr_src->last_live;
	carr_new->pos = pos;
	carr_new->delta_pos = 0;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_new->regs[i] = carr_src->regs[i];
		++i;
	}
	carr_new->next = data->carr;
	data->carr = carr_new;
}
