/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 21:26:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar_op_def.h"

void	corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;

	carr->last_live = data->cycle;
	data->n_live++;
	corewar_op_arg(data, carr, 0, &arg);
	if (-arg >= MIN_PLAYERS && -arg <= data->n_players)
	{
		data->players[-arg - 1].n_lives++;
		data->players[-arg - 1].last_live = data->cycle;
		if (!vis)
			ft_printf("A process shows that player %u (%s) is alive\n", -arg,
			data->players[-arg - 1].name);
		data->leader = (unsigned int)(-arg);
	}
}

void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	ft_printf("%c", arg);
}

void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg - arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg & arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	value;

	(void)vis;
	corewar_op_arg(data, carr, 0, &arg);
	corewar_op_arg(data, carr, 1, &arg1);
	arg2 = carr->args_values[2];
	value = arg | arg1;
	carr->regs[arg2] = value;
	if (!value)
		carr->carry = true;
	else
		carr->carry = false;
}
