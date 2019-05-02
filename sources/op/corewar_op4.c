/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:34:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:53:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op_def.h"

void	corewar_op_ld(t_data *data, t_carriage *carr)
{
	int	arg;
	int arg1;

	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	carr->regs[arg1] = arg;
	if (!arg)
		carr->carry = 1;
	else
		carr->carry = 0;
}
