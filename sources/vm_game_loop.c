/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:50:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 20:36:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "vm.h"

void		corewar_game_read_arg(t_game_data *data, unsigned int *arg_value,
			unsigned char arg_size, unsigned int arg_pos)
{
	unsigned int	i;

	*arg_value = 0;
	i = 0;
	while (i < arg_size)
	{
		*arg_value = *arg_value << 8
		| data->arena[(arg_pos + i) % ARENA_SIZE];
		++i;
	}
}

void		corewar_game_write_arg(t_game_data *data, unsigned int arg_value,
			unsigned char arg_size, unsigned int arg_pos)
{
	unsigned int	i;

	i = 0;
	while (i < arg_size)
	{
		data->arena[(arg_pos + i) % ARENA_SIZE] =
		(unsigned char)(arg_value >> (8 * (arg_size - i - 1)));
		++i;
	}
}

static int	static_valid_argument(t_game_data *data, t_carriage *carriage,
			t_operation *operation, unsigned int i)
{
	unsigned char	arg_size;
	unsigned int	ret;

	ret = 1;
	if (operation->args_types)
	{
		carriage->args_types[i] = data->arena[(carriage->pos + OPERATION_SIZE)
		% ARENA_SIZE] >> (8 - ((i + 1) * 2));
		if (!(operation->arguments[i] & carriage->args_types[i]))
			ret = 0;
	}
	else
		carriage->args_types[i] = operation->arguments[i];
	if (carriage->args_types[i] == T_DIR)
		arg_size = operation->t_dir_size;
	else if (carriage->args_types[i] == T_IND)
		arg_size = IND_SIZE;
	else
		arg_size = REG_SIZE;
	corewar_game_read_arg(data, &(carriage->args_values[i]), arg_size,
	carriage->pos + carriage->delta_pos);
	if (ret && carriage->args_types[i] == T_REG
	&& (!carriage->args_values[i] || carriage->args_values[i] > REGISTERS))
		ret = 0;
	carriage->delta_pos += arg_size;
	return (ret);
}

static int	static_valid_operation(t_game_data *data, t_carriage *carriage,
			t_operation *operation)
{
	unsigned int	ret;
	unsigned int	i;

	ret = 1;
	if (data->arena[carriage->pos % ARENA_SIZE] > 0
	&& data->arena[carriage->pos % ARENA_SIZE] <= 16)
	{
		if (operation->args_types)
			carriage->delta_pos += ARGS_TYPES_SIZE;
		i = 0;
		while (i < operation->n_arguments)
		{
			if (!static_valid_argument(data, carriage, operation, i))
				ret = 0;
			++i;
		}
	}
	return (ret);
}

static void	static_carriage(t_game_data *data, t_carriage *carriage)
{
	t_operation		*operation;

	operation = NULL;
	if (carriage->cycle_timeout == 0)
	{
		carriage->operation = data->arena[carriage->pos % ARENA_SIZE];
		if (carriage->operation > 0 && carriage->operation <= OPERATIONS)
		{
			operation = (t_operation*)&g_table[carriage->operation - 1];
			carriage->cycle_timeout = operation->cycle_timeout;
		}
		carriage->delta_pos = OPERATION_SIZE;
	}
	if (carriage->cycle_timeout)
		--carriage->cycle_timeout;
	if (!carriage->cycle_timeout)
	{
		if (operation && static_valid_operation(
		data, carriage, operation))
			operation->function(data, carriage);
		carriage->pos += carriage->delta_pos;
	}
}

int			corewar_game_loop(t_game_data *data)
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