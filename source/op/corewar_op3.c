/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:31:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 16:37:52 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_lfork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	pos = carr->pos + (int)carr->args_values[0];
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_fork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	pos = carr->pos + (((int)(carr->args_values[0])) % IDX_MOD);
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_lld(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;
	int				pos;

	(void)vis;
	if (carr->args_types[0] == DIR)
		value = carr->args_values[0];
	else
	{
		pos = carr->pos + (int)carr->args_values[0];
		corewar_read_arg(data, &value, REG_SIZE, pos);
	}
	carr->regs[carr->args_values[1]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_xor(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	pos;
	unsigned int	value;

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
	else if (carr->args_types[1] == DIR)
		arg1 = carr->args_values[1];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[1])) % IDX_MOD);
		corewar_read_arg(data, &arg1, REG_SIZE, pos);
	}
	value = arg ^ arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_zjmp(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	(void)data;
	if (carr->carry)
	{
		pos = ((int)(carr->args_values[0])) % IDX_MOD;
		carr->pos = corewar_8(carr->pos + pos);
		carr->delta_pos = 0;
	}
}
