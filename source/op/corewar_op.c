/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/11 23:50:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_st(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int pos;

	corewar_op_arg(data, carr, 0, &arg);
	if (carr->args_types[1] == REG)
	{
		arg1 = carr->args_values[1];
		if (arg1 < 1 || arg1 > N_REGS)
			return ;
		carr->regs[arg1] = arg;
	}
	else
	{
		arg1 = carr->args_values[1];
		pos = carr->pos + (arg1 % IDX_MOD);
		corewar_write_arg(data, arg, REG_SIZE, pos);
		if (vis)
			corewar_op_vis(carr, vis, pos, data->n_players);
	}
}

void	corewar_op_add(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int arg1;
	int	arg2;
	int value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	if (arg2 < 1 || arg2 > N_REGS)
		return ;
	value = arg + arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_ldi(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int	arg2;
	int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	corewar_read_arg(data, &value, REG, carr->pos + ((arg + arg1) % IDX_MOD));
	if (arg2 < 1 || arg2 > N_REGS)
		return ;
	carr->regs[arg2] = value;
}

void	corewar_op_sti(t_data *data, t_carriage *carr, t_vis *vis)
{
	int arg;
	int	arg1;
	int	arg2;
	int	pos;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	corewar_op_arg(data, carr, 2, &arg2);
	pos = carr->pos + ((arg1 + arg2) % IDX_MOD);
	corewar_write_arg(data, arg, REG_SIZE, pos);
	if (vis)
		corewar_op_vis(carr, vis, pos, data->n_players);
}

void	corewar_op_lldi(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int	arg2;
	int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	corewar_read_arg(data, &value, REG, carr->pos + (arg + arg1));
	if (arg2 < 1 || arg2 > N_REGS)
		return ;
	carr->regs[arg2] = value;
}
