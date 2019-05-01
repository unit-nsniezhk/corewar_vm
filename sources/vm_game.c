/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:33:08 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 19:46:31 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

static void	static_init_carriage(t_game_data *data, unsigned int pos,
			unsigned int id)
{
	t_carriage		*carriage_tmp;
	unsigned int	i;

	carriage_tmp = ft_memalloc(sizeof(t_carriage));
	carriage_tmp->id = id;
	carriage_tmp->carry = 0;
	carriage_tmp->zjmp_mode = 0;
	carriage_tmp->operation = 0;
	carriage_tmp->cycle_live = 0;
	carriage_tmp->cycle_timeout = 0;
	carriage_tmp->pos = pos;
	carriage_tmp->delta_pos = 0;
	i = 0;
	while (i < REGISTERS + 1)
	{
		carriage_tmp->registers[i] = 0;
		++i;
	}
	carriage_tmp->registers[1] = id;
	if (data->carriage)
		carriage_tmp->next = data->carriage;
	else
		carriage_tmp->next = NULL;
	data->carriage = carriage_tmp;
}

static void	static_init_data(t_game_data *data, t_parse *parse)
{
	unsigned int	i;
	unsigned int	code_i;

	data->dump = parse->dump;
	data->cycle = 0;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->live = 0;
	data->n_players = parse->n_champs;
	data->leading_player = parse->n_champs;
	data->carriage = NULL;
	i = 0;
	while (i < parse->n_champs)
	{
		data->players[i].pos = ARENA_SIZE / parse->n_champs * i;
		data->players[i].name = parse->champs[i].name;
		data->players[i].comment = parse->champs[i].comment;
		code_i = 0;
		while (code_i < parse->champs[i].code_size)
		{
			data->arena[data->players[i].pos + code_i] =
			parse->champs[i].code[code_i];
			++code_i;
		}
		static_init_carriage(data, data->players[i].pos, parse->champs[i].id);
		++i;
	}
}

static void	static_kill_carriages(t_game_data *data)
{
	t_carriage	*carriage_tmp;
	t_carriage	*carriage_prev;

	carriage_prev = NULL;
	carriage_tmp = data->carriage;
	while (carriage_tmp != NULL)
	{
		if (!data->carriage->next)
			break ;
		if (data->cycles_to_die <= 0
		|| carriage_tmp->cycle_live < data->cycle - data->cycles_to_die)
		{
			if (carriage_prev)
				carriage_prev->next = carriage_tmp->next;
			else
				data->carriage = carriage_tmp->next;
			ft_memdel((void**)&carriage_tmp);
		}
		carriage_prev = carriage_tmp;
		carriage_tmp = carriage_tmp->next;
	}
}

void	corewar_game(t_game_data *data, t_parse *parse)
{
	unsigned int	check;

	static_init_data(data, parse);
	check = 0;
	while (data->carriage->next != NULL)
	{
		if (!corewar_game_loop(data))
			break ;
		static_kill_carriages(data);
		if (data->live >= NBR_LIVE)
			data->cycles_to_die -= CYCLE_DELTA;
		else
			++check;
		if (check == MAX_CHECKS)
		{
			check = 0;
			data->cycles_to_die -= CYCLE_DELTA;
		}
		if (data->cycles_to_die <= 0)
			data->cycles_to_die = 1;
	}
}
