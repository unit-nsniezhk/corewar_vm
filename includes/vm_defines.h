/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 16:18:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_DEFINES_H

# define VM_DEFINES_H

# include "vm_settings.h"

typedef struct				s_player
{
	unsigned int			id;
	unsigned int			pos;
}							t_player;

typedef struct				s_operation
{
	int						n_arguments;
	unsigned char			arguments[3];
	unsigned int			cycle_timeout;
	unsigned int			args_types : 1;
	int						carry;
	unsigned char			t_dir_size;
}							t_operation;

static const t_operation	g_table[OPERATIONS + 1] =
{
	{0, {0}, 0, 0, 0, REG_SIZE},
	{1, {T_DIR}, 10, 0, 0, REG_SIZE},
	{2, {T_DIR | T_IND, T_REG}, 5, 1, 0, REG_SIZE},
	{2, {T_REG, T_IND | T_REG}, 5, 1, 0, REG_SIZE},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 0, REG_SIZE},
	{3, {T_REG, T_REG, T_REG}, 10, 1, 0, REG_SIZE},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, REG_SIZE},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, REG_SIZE},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 0, REG_SIZE / 2},
	{1, {T_DIR}, 20, 0, 1, REG_SIZE / 2},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1, 1, REG_SIZE / 2},
	{3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1, 1, REG_SIZE / 2},
	{1, {T_DIR}, 800, 0, 1, REG_SIZE / 2},
	{2, {T_DIR | T_IND, T_REG}, 10, 1, 0, REG_SIZE},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1, 1, REG_SIZE / 2},
	{1, {T_DIR}, 1000, 0, 1, REG_SIZE / 2},
	{1, {T_REG}, 2, 1, 0, REG_SIZE}
};

typedef struct				s_carriage
{
	unsigned int			id;
	unsigned int			carry;
	unsigned int			zjmp_mode : 1;
	unsigned char			operation;
	unsigned int			cycle_live;//last executed live was in the cycle
	unsigned int			cycle_timeout;
	unsigned int			pos;//in arena
	unsigned int			delta_pos;//distance to the next operation
	int						registers[REGISTERS];//TODO innit to -player id of player - first, remaining to 0
	struct s_carriage		*next;//TODO change start of the registers to 1 from 0 ^^^
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
	unsigned char			arena[ARENA_SIZE];
	t_carriage				*carriage;
}							t_game_data;

#endif
