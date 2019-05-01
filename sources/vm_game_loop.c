/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:50:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 16:59:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "vm.h"

static int	static_valid_register(t_game_data *data, t_carriage *carriage)
{
	unsigned int	reg;
	unsigned int	i;

	reg = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		reg = reg << 8 | data->arena[(carriage->delta_pos + i) % ARENA_SIZE];
		++i;
	}
	if (!reg || reg > REGISTERS)
		return (0);
	return (1);
}

static int	static_valid_argument(t_game_data *data, t_carriage *carriage,
			t_operation *operation, unsigned int i)
{
	unsigned char	arg;
	unsigned char	arg_size;

	if (operation->args_types)
	{
		arg = data->arena[(carriage->pos + OPERATION_SIZE) % ARENA_SIZE] >>
		(8 - ((i + 1) * 2));
		if (!(operation->arguments[i] & arg))
			return (0);
	}
	else
		arg = operation->arguments[i];
	if (arg == T_DIR)
		arg_size = operation->t_dir_size;
	else if (arg == T_IND)
		arg_size = IND_SIZE;
	else
	{
		arg_size = REG_SIZE;
		if (!static_valid_register(data, carriage))
			return (0);
	}
	carriage->delta_pos += arg_size;
	return (1);
}

static int	static_valid_operation(t_game_data *data, t_carriage *carriage)
{
	t_operation		*operation;
	unsigned int	i;

	operation = (t_operation*)&g_table[carriage->operation];
	if (data->arena[carriage->pos % ARENA_SIZE] > 0
	&& data->arena[carriage->pos % ARENA_SIZE] <= 16)
	{
		if (operation->args_types)
			carriage->delta_pos += ARGS_TYPES_SIZE;
		i = 0;
		while (i < operation->n_arguments)
		{
			if (!static_valid_argument(data, carriage, operation, i))
				return (0);
			++i;
		}
	}
	return (1);
}

static void	static_carriage(t_game_data *data, t_carriage *carriage)
{
	if (carriage->cycle_timeout == 0)
	{
		carriage->operation = data->arena[carriage->pos % ARENA_SIZE];
		if (carriage->operation > 0 && carriage->operation <= OPERATIONS)
			carriage->cycle_timeout =
			g_table[carriage->operation].cycle_timeout;
		carriage->delta_pos = OPERATION_SIZE;
	}
	if (carriage->cycle_timeout)
		--carriage->cycle_timeout;
	if (!carriage->cycle_timeout)
	{
		if (static_valid_operation(data, carriage))
		{
			;//TODO operation[] array of pointers to operations
			carriage->pos += carriage->delta_pos;
		}
		else
			carriage->pos += OPERATION_SIZE;
	}
}

static int	corewar_game_loop(t_game_data *data)
{
	unsigned int	i;
	t_carriage		*carriage_tmp;

	i = 0;
	carriage_tmp = data->carriage;
	while (i < data->cycles_to_die)
	{
		if (data->dump && data->cycle == data->dump)
		{
			corewar_dump(data->arena);
			return (0);
		}
		while (carriage_tmp != NULL)
		{
			static_carriage(data, carriage_tmp);
			carriage_tmp = carriage_tmp->next;
		}
		++i;
		data->cycle++;
	}
	return (1);
}