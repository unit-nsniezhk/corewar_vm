/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:34:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 17:33:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op_def.h"

void	corewar_op_ld(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int arg1;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	arg1 = carr->args_values[1];
	carr->regs[arg1] = arg;
	if (!arg)
		carr->carry = 1;
	else
		carr->carry = 0;
}
