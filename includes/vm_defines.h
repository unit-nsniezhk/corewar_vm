/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 19:49:46 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_DEFINES_H

# define VM_DEFINES_H

# include "vm_settings.h"
# include "vm_operations.h"

typedef struct				s_operation
{
	int						n_arguments;
	unsigned char			arguments[3];
	unsigned int			cycle_timeout;
	unsigned int			args_types : 1;
	unsigned char			t_dir_size;
	t_function				function;
}							t_operation;

static const t_operation	g_table[OPERATIONS] =
{
	{1, {T_DIR}, 10, 0, DIR_SIZE, &corewar_operation1},
	{2, {T_DIR | T_IND, T_REG}, 5, 1, DIR_SIZE, &corewar_operation2},
	{2, {T_REG, T_IND | T_REG}, 5, 1, DIR_SIZE, &corewar_operation3},
	{3, {T_REG, T_REG, T_REG}, 10, 1, DIR_SIZE, &corewar_operation4},
	{3, {T_REG, T_REG, T_REG}, 10, 1, DIR_SIZE, &corewar_operation5},
	{3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, DIR_SIZE, &corewar_operation6},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, DIR_SIZE, &corewar_operation7},
	{3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, 1, IND_SIZE, &corewar_operation8},
	{1, {T_DIR}, 20, 0, IND_SIZE, &corewar_operation9},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, 1, IND_SIZE, &corewar_operation10},
	{3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, 1, IND_SIZE, &corewar_operation11},
	{1, {T_DIR}, 800, 0, IND_SIZE, &corewar_operation12},
	{2, {T_DIR | T_IND, T_REG}, 10, 1, DIR_SIZE, &corewar_operation13},
	{3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, 1, IND_SIZE, &corewar_operation14},
	{1, {T_DIR}, 1000, 0, IND_SIZE, &corewar_operation15},
	{1, {T_REG}, 2, 1, DIR_SIZE, &corewar_operation16}
};

#endif
