/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:34:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 19:30:14 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"

void	corewar_op_ld(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;
	int				pos;

	(void)vis;
	if (carr->args_types[0] == DIR)
		value = carr->args_values[0];
	else
	{
		pos = carr->pos + (((int)carr->args_values[0]) % IDX_MOD);
		corewar_read_arg(data, &value, REG_SIZE, pos);
	}
	carr->regs[carr->args_values[1]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}
