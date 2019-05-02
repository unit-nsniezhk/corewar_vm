/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:33:08 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:53:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	static_init_carr(t_data *data, unsigned int pos, unsigned int id)
{
	t_carriage		*carr_tmp;
	unsigned int	i;

	carr_tmp = ft_memalloc(sizeof(t_carriage));
	carr_tmp->id = id;
	carr_tmp->carry = 0;
	carr_tmp->op = 0;
	carr_tmp->last_live = 0;
	carr_tmp->timeout = 0;
	carr_tmp->pos = pos;
	carr_tmp->delta_pos = 0;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_tmp->regs[i] = 0;
		++i;
	}
	carr_tmp->regs[1] = id;
	if (data->carr)
		carr_tmp->next = data->carr;
	else
		carr_tmp->next = NULL;
	data->carr = carr_tmp;
}

static void	static_init_data(t_data *data, t_parse *parse)
{
	unsigned int	i;
	unsigned int	byte;

	data->dump = parse->dump;
	data->cycle = 0;
	data->check = 0;
	data->cycles_to_check = CYCLES_TO_CHECK;
	data->n_live = 0;
	data->n_carrs = parse->n_champs;
	data->carr = NULL;
	i = 0;
	while (i < parse->n_champs)
	{
		data->players[i].pos = ARENA_SIZE / parse->n_champs * i;
		data->players[i].name = parse->champs[i].name;
		byte = 0;
		while (byte < parse->champs[i].code_size)
		{
			data->arena[data->players[i].pos + byte] =
			parse->champs[i].code[byte];
			++byte;
		}
		static_init_carr(data, data->players[i].pos, parse->champs[i].id);
		++i;
	}
}

static void	static_dump(char *arena)
{
	unsigned int	i;

	i = 0;
	while (i < ARENA_SIZE)
	{
		if (arena[i] < 0)
		{
			arena[i] *= -1;
			write(1, "-", 1);
		}
		else
			write(1, " ", 1);
		if (arena[i] < 16)
			write(1, "0", 1);
		ft_printf("%x", arena[i] & 127);
		if (!((i + 1) % DUMP_BYTES_PER_LINE))
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		++i;
	}
}

static void	static_kill_carrs(t_data *data, t_carriage *carr_tmp)
{
	t_carriage	*carr_prev;

	carr_prev = NULL;
	while (carr_tmp != NULL && data->carr->next)
	{
		if (data->cycles_to_check <= 0
		|| carr_tmp->last_live < data->cycle - data->cycles_to_check)
		{
			if (carr_prev)
				carr_prev->next = carr_tmp->next;
			else
				data->carr = carr_tmp->next;
			ft_memdel((void**)&carr_tmp);
			if (carr_prev)
				carr_tmp = carr_prev->next;
			else
				carr_tmp = data->carr;
			data->n_carrs--;
		}
		else
		{
			carr_prev = carr_tmp;
			carr_tmp = carr_tmp->next;
		}
	}
}

void		corewar_vm(t_data *data, t_parse *parse)
{
	static_init_data(data, parse);
	while (data->carr->next != NULL)
	{
		if (!corewar_cycles(data))
		{
			static_dump(data->arena);
			break ;
		}
		static_kill_carrs(data, data->carr);
		if (data->n_live >= MIN_LIVE)
			data->cycles_to_check -= CYCLE_DELTA;
		else
			data->check++;
		if (data->check == MAX_CHECKS)
		{
			data->check = 0;
			data->cycles_to_check -= CYCLE_DELTA;
		}
		if (data->cycles_to_check <= 0)
			data->cycles_to_check = 1;
	}
	ft_printf("Player %d (%s) won\n", data->carr->id,
	data->players[data->carr->id].name);
}
