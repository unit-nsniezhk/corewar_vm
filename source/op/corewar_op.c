/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 16:52:49 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_st(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	if (carr->args_types[1] == REG)
		carr->regs[carr->args_values[1]] = carr->regs[carr->args_values[0]];
	else
	{
		pos = carr->pos + (((int)carr->args_values[1]) % IDX_MOD);
		corewar_write_arg(data, carr->regs[carr->args_values[0]], pos);
		if (vis)
			corewar_op_vis(carr, vis, pos, data->n_players);
	}
}

void	corewar_op_add(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]] + carr->regs[carr->args_values[1]];
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_ldi(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;
	int 			pos;

	(void)vis;
	if (carr->args_types[0] == REG)
		arg = carr->regs[carr->args_values[0]];
	else if (carr->args_types[0] == DIR)
		arg = carr->args_values[0];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[0])) % IDX_MOD);
		corewar_read_arg(data, &arg, REG_SIZE, pos);
	}
	if (carr->args_types[1] == REG)
		arg1 = carr->regs[carr->args_values[1]];
	else
		arg1 = carr->args_values[1];
	pos = carr->pos + (((int)(arg + arg1)) % IDX_MOD);
	corewar_read_arg(data, &value, REG_SIZE, pos);
	carr->regs[carr->args_values[2]] = value;
}

void	corewar_op_sti(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	value;
	int				pos;

	value = carr->regs[carr->args_values[0]];
	if (carr->args_types[1] == REG)
		arg1 = carr->regs[carr->args_values[1]];
	else if (carr->args_types[1] == DIR)
		arg1 = carr->args_values[1];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[1])) % IDX_MOD);
		corewar_read_arg(data, &arg1, REG_SIZE, pos);
	}
	if (carr->args_types[2] == REG)
		arg2 = carr->regs[carr->args_values[2]];
	else
		arg2 = carr->args_values[2];
	pos = carr->pos + (((int)(arg1 + arg2)) % IDX_MOD);
	corewar_write_arg(data, value, pos);
	if (vis)
		corewar_op_vis(carr, vis, pos, data->n_players);
}

void	corewar_op_lldi(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;
	int 			pos;

	(void)vis;
	if (carr->args_types[0] == REG)
		arg = carr->regs[carr->args_values[0]];
	else if (carr->args_types[0] == DIR)
		arg = carr->args_values[0];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[0])) % IDX_MOD);
		corewar_read_arg(data, &arg, REG_SIZE, pos);
	}
	if (carr->args_types[1] == REG)
		arg1 = carr->regs[carr->args_values[1]];
	else
		arg1 = carr->args_values[1];
	pos = carr->pos + (int)(arg + arg1);
	corewar_read_arg(data, &value, REG_SIZE, pos);
	carr->regs[carr->args_values[2]] = value;
}
