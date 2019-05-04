/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 17:47:44 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar_op_def.h"

void	corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;

	carr->last_live = data->cycle;
	data->n_live++;
	corewar_op_arg(data, carr, 0, &arg);
	if (-arg > 0 && -arg <= data->n_players)
	{
		if (!vis)
			ft_printf("A process shows that player %u (%s) is alive\n", -arg,
			data->players[(-arg) - 1].name);
		data->leader = (unsigned int)(-carr->regs[1]);
	}
}

void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	ft_printf("%c", (char)arg);
}

void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int arg1;
	int arg2;
	int value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg - arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int arg2;
	int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg & arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	arg;
	int	arg1;
	int arg2;
	int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg | arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = 1;
	else
		carr->carry = 0;
}
