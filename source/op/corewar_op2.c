/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 16:22:46 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "corewar_op_def.h"

void	corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;

	carr->last_live = data->cycle;
	++(data->n_live);
	arg = carr->args_values[0];
	if ((((int)arg) * -1) >= (int)MIN_PLAYERS
	&& (((int)arg) * -1) <= (int)data->n_players)
	{
		data->players[(((int)arg) * -1) - 1].n_lives++;
		data->players[(((int)arg) * -1) - 1].last_live = data->cycle;
		if (!vis)
			ft_printf("A process shows that player %u (%s) is alive\n",
			((int)arg) * -1, data->players[(((int)arg) * -1) - 1].name);
		data->leader = (unsigned int)(((int)arg) * -1);
	}
}

void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]];
	ft_printf("%c", value % 256);
}

void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]] - carr->regs[carr->args_values[1]];
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis)
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
	value = arg & arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis)
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
	value = arg | arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}
