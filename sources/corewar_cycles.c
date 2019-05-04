/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_cycles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:50:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 16:36:14 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "corewar_op_def.h"
#include "corewar.h"

static int	static_valid_arg(t_data *data, t_carriage *carr, t_operation *op,
			unsigned int i)
{
	unsigned char	arg_size;
	unsigned int	ret;

	ret = 1;
	if (op->t_arg)
	{
		carr->args_types[i] = (char)(data->arena[corewar_8(
		carr->pos + OP_SIZE)] >> (8 - ((i + 1) * 2)) & TYPE_SIZE);
		if (!(op->args[i] & carr->args_types[i]))
			ret = 0;
	}
	else
		carr->args_types[i] = op->args[i];
	if (carr->args_types[i] == DIR)
		arg_size = op->dir_size;
	else if (carr->args_types[i] == IND)
		arg_size = IND_SIZE;
	else
		arg_size = REG_LINK_SIZE;
	corewar_read_arg(data, &(carr->args_values[i]), arg_size,
	carr->pos + carr->delta_pos);
	if (ret && carr->args_types[i] == REG
	&& (!carr->args_values[i] || carr->args_values[i] > N_REGS))
		ret = 0;
	carr->delta_pos += arg_size;
	return (ret);
}

static int	static_valid_op(t_data *data, t_carriage *carr, t_operation *op)
{
	unsigned int	i;
	unsigned int	ret;

	ret = 0;
	if (data->arena[carr->pos] > 0 && data->arena[carr->pos] <= N_OPS)
	{
		ret = 1;
		if (op->t_arg)
			carr->delta_pos += ARGS_TYPES_SIZE;
		i = 0;
		while (i < op->n_args)
		{
			if (!static_valid_arg(data, carr, op, i))
				ret = 0;
			++i;
		}
	}
	return (ret);
}

static void	static_exec_carr(t_data *data, t_carriage *carr, t_vis *vis)
{
	t_operation	*op;

	if (!carr->timeout)
	{
		carr->op = data->arena[corewar_8(carr->pos)];
		if (carr->op > 0 && carr->op <= N_OPS)
		{
			op = (t_operation*)&g_op_table[carr->op - 1];
			carr->timeout = op->timeout;
		}
		carr->delta_pos = OP_SIZE;
	}
	if (carr->timeout)
		--carr->timeout;
	if (!carr->timeout)
	{
		op = (t_operation*)&g_op_table[carr->op - 1];
		if (static_valid_op(data, carr, op))
			op->op(data, carr, vis);
		carr->pos = corewar_8(carr->pos + carr->delta_pos);
	}
}

int			corewar_cycles(t_data *data, t_vis *vis)
{
	unsigned int	i;
	t_carriage		*carr_tmp;

	i = 0;
	while (i < data->cycles_to_check)
	{
		if (vis)
			corewar_vis(vis, data);
		carr_tmp = data->carr;
		if ((data->dump && data->cycle == data->dump) || (vis && vis->quit))
			return (0);
		while (carr_tmp != NULL)
		{
			static_exec_carr(data, carr_tmp, vis);
			carr_tmp = carr_tmp->next;
		}
		++i;
		data->cycle++;
	}
	return (1);
}
