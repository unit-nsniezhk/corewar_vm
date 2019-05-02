/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:31:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:33:59 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op_def.h"

void	corewar_op_lfork(t_data *data, t_carriage *carr)
{
	int	arg;
	int	pos;

	corewar_op_arg(data, carr, 0, &arg);
	pos = carr->pos + arg;
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_fork(t_data *data, t_carriage *carr)
{
	int	arg;
	int	pos;

	corewar_op_arg(data, carr, 0, &arg);
	pos = carr->pos + (arg % IDX_MOD);
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_lld(t_data *data, t_carriage *carr)
{
	int	arg;
	int arg1;

	corewar_op_larg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	carr->regs[arg1] = arg;
	if (!arg)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_xor(t_data *data, t_carriage *carr)
{
	int	arg;
	int	arg1;
	int arg2;
	int	value;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	corewar_op_arg(data, carr, 2, &arg2);
	value = arg ^ arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_zjmp(t_data *data, t_carriage *carr)
{
	int arg;

	if (carr->carry)
	{
		corewar_op_arg(data, carr, 0, &arg);
		carr->pos += arg % IDX_MOD;
	}
}
