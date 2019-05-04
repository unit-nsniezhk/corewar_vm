/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:31:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 17:31:14 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_lfork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	pos;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	pos = carr->pos + arg;
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_fork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	pos;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	pos = carr->pos + (arg % IDX_MOD);
	corewar_op_new_carriage(data, carr, pos);
}

void	corewar_op_lld(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int arg1;

	(void)vis;
	corewar_op_larg(data, carr, 0, &arg);
	arg1 = carr->args_values[1];
	carr->regs[arg1] = arg;
	if (!arg)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_xor(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int arg2;
	int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg ^ arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_zjmp(t_data *data, t_carriage *carr, t_vis *vis)
{
	int arg;

	(void)vis;
	if (carr->carry)
	{
		corewar_op_arg(data, carr, 0, &arg);
		carr->pos = corewar_8(carr->pos + (arg % IDX_MOD));
	}
}
