/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_operations_1to5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 22:44:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

static void	static_get_argument(t_game_data *data, t_carriage *carriage,
			unsigned int n, int *arg)
{
	unsigned int	pos;

	if (carriage->args_types[n] == T_REG)
		*arg = carriage->registers[carriage->args_values[0]];
	else if (carriage->args_types[n] == T_DIR)
		*arg = carriage->args_values[n];
	else
	{
		pos = carriage->pos + (carriage->args_values[n] % IDX_MOD);
		corewar_game_read_arg(
		data, arg, T_REG, data->arena[pos % ARENA_SIZE]);
	}
}

static void	static_get_long_argument(t_game_data *data, t_carriage *carriage,
			unsigned int n, int *arg)
{
	unsigned int	pos;

	if (carriage->args_types[n] == T_REG)
		*arg = carriage->registers[carriage->args_values[0]];
	else if (carriage->args_types[n] == T_DIR)
		*arg = carriage->args_values[n];
	else
	{
		pos = carriage->pos + carriage->args_values[n];
		corewar_game_read_arg(
				data, arg, T_REG, data->arena[pos % ARENA_SIZE]);
	}
}

static void	static_coppy_carriage(t_game_data *data, t_carriage *carriage_src,
			int pos)
{
	t_carriage		*carriage_new;
	unsigned int	i;

	carriage_new = ft_memalloc(sizeof(t_carriage));
	carriage_new->id = carriage_src->id;
	carriage_new->carry = carriage_src->carry;
	carriage_new->zjmp_mode = carriage_src->zjmp_mode;//TODO
	carriage_new->operation = 0;
	carriage_new->cycle_live = carriage_src->cycle_live;
	carriage_new->cycle_live = 0;
	carriage_new->pos = pos;
	carriage_new->delta_pos = 0;
	i = 0;
	while (i < REGISTERS + 1)
	{
		carriage_new->registers[i] = carriage_src->registers[i];
		++i;
	}
	carriage_new->next = data->carriage->next;
	data->carriage = carriage_new;
}

//live
void	corewar_operation1(t_game_data *data, t_carriage *carriage)
{
	carriage->cycle_live = data->cycle;
	ft_printf("A process shows that player %u %s is alive\n", carriage->id,
	data->players[carriage->id - 1]);
}

//ld
void	corewar_operation2(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int arg2;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	carriage->registers[arg2] = arg;
	if (!arg)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}


//st
void	corewar_operation3(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int	value;
	int	pos;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	value = carriage->registers[arg];
	if (carriage->args_types[1] == T_REG)
		carriage->registers[arg2] = value;
	else
	{
		pos = carriage->pos + (carriage->args_values[1] % IDX_MOD);
		corewar_game_write_arg(data, value, REG_SIZE, pos);
	}
}

//add
void	corewar_operation4(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int arg2;
	int	arg3;
	int value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	value = arg + arg2;
	carriage->registers[arg3] = value;
	if (!value)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

//sub
void	corewar_operation5(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int arg2;
	int arg3;
	int value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	value = arg - arg2;
	carriage->registers[arg3] = value;
	if (!value)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

//and
void		corewar_operation6(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int arg3;
	int	value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	value = arg & arg2;
	carriage->registers[arg3] = value;
	if (!value)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}


//or
void		corewar_operation7(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int arg3;
	int	value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	value = arg | arg2;
	carriage->registers[arg3] = value;
	if (!value)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

//xor
void		corewar_operation8(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int arg3;
	int	value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	value = arg ^ arg2;
	carriage->registers[arg3] = value;
	if (!value)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

//zjmp
void		corewar_operation9(t_game_data *data, t_carriage *carriage)
{
	int arg;

	if (carriage->carry)
	{
		static_get_argument(data, carriage, 0, &arg);
		carriage->pos += arg % IDX_MOD;
	}
}

//ldi
void		corewar_operation10(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int	arg3;
	int	value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	corewar_game_read_arg(data, &value, T_REG,
	carriage->pos + ((arg + arg2) % IDX_MOD));
	carriage->registers[arg3] = value;
}

//sti
void		corewar_operation11(t_game_data *data, t_carriage *carriage)
{
	int arg;
	int	arg2;
	int	arg3;
	int	pos;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	pos = carriage->pos + ((arg2 + arg3) % IDX_MOD);
	corewar_game_write_arg(data, arg, REG_SIZE, pos);
}

//fork
void		corewar_operation12(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	pos;

	static_get_argument(data, carriage, 0, &arg);
	pos = carriage->pos + (arg % IDX_MOD);
	static_coppy_carriage(data, carriage, pos);
}

//lld
void		corewar_operation13(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int arg2;

	static_get_long_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	carriage->registers[arg2] = arg;
	if (!arg)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

//lldi
void		corewar_operation14(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	arg2;
	int	arg3;
	int	value;

	static_get_argument(data, carriage, 0, &arg);
	static_get_argument(data, carriage, 1, &arg2);
	static_get_argument(data, carriage, 2, &arg3);
	corewar_game_read_arg(data, &value, T_REG, carriage->pos + (arg + arg2));
	carriage->registers[arg3] = value;
}

//lfork
void		corewar_operation15(t_game_data *data, t_carriage *carriage)
{
	int	arg;
	int	pos;

	static_get_argument(data, carriage, 0, &arg);
	pos = carriage->pos + arg;
	static_coppy_carriage(data, carriage, pos);
}

//aff
void		corewar_operation16(t_game_data *data, t_carriage *carriage)
{
	int	arg;

	static_get_argument(data, carriage, 0, &arg);
	ft_printf("%c", (char)arg);
}
