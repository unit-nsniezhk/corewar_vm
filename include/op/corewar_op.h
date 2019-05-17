/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:55:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 21:26:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_H

# define COREWAR_OP_H

# include "corewar_def.h"

void	corewar_op_arg(t_data *data, t_carriage *carr, unsigned int n,
		unsigned int *arg);
void	corewar_op_larg(t_data *data, t_carriage *carr, unsigned int n,
		unsigned int *arg);
void	corewar_op_new_carriage(t_data *data, t_carriage *carr_src, int pos);
void	corewar_write_arg(t_data *data, unsigned int value, int pos);
void	corewar_op_vis(t_carriage *carr, t_vis *vis, int pos, int n_players);

void	corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_ld(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_st(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_add(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_xor(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_zjmp(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_ldi(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_sti(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_fork(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lld(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lldi(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lfork(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis);

#endif
