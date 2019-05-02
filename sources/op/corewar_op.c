/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:53:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_st(t_data *data, t_carriage *carr)
{
	int	arg;
	int	arg1;
	int	value;
	int	pos;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	value = carr->regs[arg];
	if (carr->args_types[1] == REG)
		carr->regs[arg1] = value;
	else
	{
		pos = carr->pos + (carr->args_values[1] % IDX_MOD);
		corewar_write_arg(data, value, REG_SIZE, pos);
	}
}

void	corewar_op_add(t_data *data, t_carriage *carr)
{
	int	arg;
	int arg1;
	int	arg2;
	int value;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	corewar_op_arg(data, carr, 2, &arg2);
	value = arg + arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_ldi(t_data *data, t_carriage *carr)
{
	int	arg;
	int	arg1;
	int	arg2;
	int	value;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	corewar_op_arg(data, carr, 2, &arg2);
	corewar_read_arg(data, &value, REG, carr->pos + ((arg + arg1) % IDX_MOD));
	carr->regs[arg2] = value;
}

void	corewar_op_sti(t_data *data, t_carriage *carr)
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
}

void	corewar_op_lldi(t_data *data, t_carriage *carr)
{
	int	arg;
	int	arg1;
	int	arg2;
	int	value;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	corewar_op_arg(data, carr, 2, &arg2);
	corewar_read_arg(data, &value, REG, carr->pos + (arg + arg1));
	carr->regs[arg2] = value;
}
