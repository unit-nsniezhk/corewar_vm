/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:32:15 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 17:29:33 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_DEF_H

# define COREWAR_OP_DEF_H

# include "corewar_op.h"

typedef struct				s_operation
{
	char					*name;
	unsigned int			n_args;
	unsigned char			args[3];
	unsigned int			timeout;
	unsigned int			t_arg : 1;
	unsigned char			dir_size;
	t_function				op;
}							t_operation;

static const t_operation	g_op_table[N_OPS] =
{
	{"live", 1, {DIR}, 10, 0, DIR_SIZE, &corewar_op_live},
	{"ld", 2, {DIR | IND, REG}, 5, 1, DIR_SIZE, &corewar_op_ld},
	{"st", 2, {REG, IND | REG}, 5, 1, DIR_SIZE, &corewar_op_st},
	{"add", 3, {REG, REG, REG}, 10, 1, DIR_SIZE, &corewar_op_add},
	{"sub", 3, {REG, REG, REG}, 10, 1, DIR_SIZE, &corewar_op_sub},
	{"and", 3, {REG | DIR | IND, REG | IND | DIR, REG}, 6, 1, DIR_SIZE,
		&corewar_op_and},
	{"or", 3, {REG | IND | DIR, REG | IND | DIR, REG}, 6, 1, DIR_SIZE,
		&corewar_op_or},
	{"xor", 3, {REG | IND | DIR, REG | IND | DIR, REG}, 6, 1, IND_SIZE,
		&corewar_op_xor},
	{"zjmp", 1, {DIR}, 20, 0, IND_SIZE, &corewar_op_zjmp},
	{"ldi", 3, {REG | DIR | IND, DIR | REG, REG}, 25, 1, IND_SIZE,
		&corewar_op_ldi},
	{"sti", 3, {REG, REG | DIR | IND, DIR | REG}, 25, 1, IND_SIZE,
		&corewar_op_sti},
	{"fork", 1, {DIR}, 800, 0, IND_SIZE, &corewar_op_fork},
	{"lld", 2, {DIR | IND, REG}, 10, 1, DIR_SIZE, &corewar_op_lld},
	{"lldi", 3, {REG | DIR | IND, DIR | REG, REG}, 50, 1, IND_SIZE,
		&corewar_op_lldi},
	{"lfork", 1, {DIR}, 1000, 0, IND_SIZE, &corewar_op_lfork},
	{"aff", 1, {REG}, 2, 1, DIR_SIZE, &corewar_op_aff}
};

#endif
