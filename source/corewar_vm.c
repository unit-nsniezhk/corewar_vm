/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:33:08 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/12 00:23:01 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "corewar.h"
#include "corewar_vis_color.h"

static void	static_init_carr(t_data *data, unsigned int pos, unsigned int id)
{
	t_carriage		*carr_tmp;
	unsigned char	i;

	carr_tmp = ft_memalloc(sizeof(t_carriage));
	carr_tmp->id = id;
	carr_tmp->carry = false;
	carr_tmp->op = 0;
	carr_tmp->last_live = 0;
	carr_tmp->timeout = 0;
	carr_tmp->pos = pos;
	carr_tmp->delta_pos = 0;
	carr_tmp->shown = false;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_tmp->regs[i] = 0;
		++i;
	}
	carr_tmp->regs[1] = -id;
	if (data->carr)
		carr_tmp->next = data->carr;
	else
		carr_tmp->next = NULL;
	data->carr = carr_tmp;
}

static void	static_init_data(t_data *data, t_parse *parse, t_vis *vis)
{
	unsigned int	i;
	unsigned int	byte;

	data->dump = parse->dump;
	data->cycle = 0;
	data->leader = parse->n_champs;
	data->check = 0;
	data->ctc = CYCLES_TO_CHECK;
	data->n_live = 0;
	data->n_carrs = parse->n_champs;
	data->n_a_carrs = data->n_carrs;
	data->n_players = parse->n_champs;
	data->carr = NULL;
	ft_memset(data->arena, 0, ARENA_SIZE);
	i = 0;
	while (i < parse->n_champs)
	{
		data->players[i].pos = (ARENA_SIZE / parse->n_champs) * i;
		data->players[i].name = ft_strndup(parse->champs[i].name, -1);
		data->players[i].comment = parse->champs[i].comment;
		data->players[i].code_size = parse->champs[i].code_size;
		data->players[i].last_live = 0;
		data->players[i].n_lives = 0;
		byte = 0;
		while (byte < parse->champs[i].code_size)
		{
			data->arena[data->players[i].pos + byte] =
			parse->champs[i].code[byte];
			if (vis)
				vis->color[data->players[i].pos + byte] = g_color[i + 1];
			++byte;
		}
		static_init_carr(data, data->players[i].pos, parse->champs[i].id);
		++i;
	}
}

static void	static_dump(const unsigned char *arena, t_vis *vis)
{
	unsigned int	i;

	if (vis)
		return ;
	i = 0;
	while (i < ARENA_SIZE)
	{
		if (!i)
			write(1, "0x0000 : ", 9);
		else if (!(i % DUMP_BYTES_PER_LINE))
			ft_printf("%#06x : ", i);
		if (arena[i] < 16)
			write(1, "0", 1);
		ft_printf("%x", arena[i]);
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
		if (data->ctc == 0 || carr_tmp->last_live < data->cycle - data->ctc)
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

void	set_players(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_players)
	{
		data->players[i].last_live = 0;
		data->players[i].n_lives = 0;
		++i;
	}
}

void		corewar_vm(t_data *data, t_parse *parse, t_vis *vis)
{
	static_init_data(data, parse, vis);
	while (!data->cycle || data->carr->next != NULL)
	{
		if (!corewar_cycles(data, vis))
		{
			static_dump(data->arena, vis);
			return ;
		}
		static_kill_carrs(data, data->carr);
		if (data->n_live >= MIN_LIVE || data->check == MAX_CHECKS)
		{
			if (data->ctc > CYCLE_DELTA)
				data->ctc -= CYCLE_DELTA;
			else
				data->ctc = 0;
			data->check = 0;
		}
		else
			data->check++;
		data->n_live = 0;
		set_players(data);
	}
	if (vis)
	{
		vis->game_over = true;
		corewar_vis(data, vis);
	}
	else
		ft_printf("Player %d (%s) won\n", data->leader,
		data->players[data->leader - 1].name);
}
