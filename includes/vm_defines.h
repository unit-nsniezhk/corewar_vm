/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 19:56:34 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_DEFINES_H

# define VM_DEFINES_H

# include "vm_settings.h"
# include "vm_operations.h"

typedef struct				s_player
{
	unsigned int			pos;
	char					*name;
	char					*comment;
}							t_player;

typedef struct				s_carriage
{
	unsigned int			id;
	unsigned int			carry : 1;
	unsigned int			zjmp_mode : 1;
	unsigned char			operation;
	unsigned int			cycle_live;//last executed live was in the cycle
	unsigned int			cycle_timeout;
	unsigned int			pos;
	unsigned int			delta_pos;
	int						args_values[3];
	unsigned char			args_types[3];
	int						registers[REGISTERS + 1];
	struct s_carriage		*next;
}							t_carriage;

typedef struct				s_game_data
{
	unsigned int			dump;
	unsigned int			cycle;
	int						cycles_to_die;//TODO see if it's possible to switch to unsigned
	unsigned int			live;
	unsigned int			leading_player;
	unsigned int			n_players;
	t_player				players[MAX_CHAMPIONS];
	char					arena[ARENA_SIZE];
	t_carriage				*carriage;
}							t_game_data;

typedef void				(*t_function)(t_game_data *data,
							t_carriage *carriage);

typedef struct				s_operation
{
	int						n_arguments;
	unsigned char			arguments[3];
	unsigned int			cycle_timeout;
	unsigned int			args_types : 1;
	int						carry;
	unsigned char			t_dir_size;
	t_function				function;
}							t_operation;

static const t_operation	g_table[OPERATIONS] =
{
	{1, {T_DIR}, 10, 0, 0, REG_SIZE, &corewar_operation1},
	{2, {T_DIR | T_IND, T_REG}, 5, 1, 0, REG_SIZE, &corewar_operation2},
	{2, {T_REG, T_IND | T_REG}, 5, 1, 0, REG_SIZE, &corewar_operation3},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 0, REG_SIZE, &corewar_operation4},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 0, REG_SIZE, &corewar_operation5},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0,
  	REG_SIZE, &corewar_operation6},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0,
  	REG_SIZE, &corewar_operation7},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0,
  	REG_SIZE / 2, &corewar_operation8},
	{1, {T_DIR}, 20, 0, 1, REG_SIZE / 2, &corewar_operation9},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1, 1, REG_SIZE / 2,
  	&corewar_operation10},
	{3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1, 1, REG_SIZE / 2,
  	&corewar_operation11},
	{1, {T_DIR}, 800, 0, 1, REG_SIZE / 2, &corewar_operation12},
	{2, {T_DIR | T_IND, T_REG}, 10, 1, 0, REG_SIZE, &corewar_operation13},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1, 1, REG_SIZE / 2,
  	&corewar_operation14},
	{1, {T_DIR}, 1000, 0, 1, REG_SIZE / 2, &corewar_operation15},
	{1, {T_REG}, 2, 1, 0, REG_SIZE, &corewar_operation16}
};

#endif
