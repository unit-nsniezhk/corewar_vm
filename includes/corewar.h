/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 23:17:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "corewar_def.h"
# include "corewar_parse.h"

int		corewar_parse(t_parse *parse, unsigned int argc, const char **argv);

void	corewar_vm(t_data *data, t_parse *parse);
int		corewar_cycles(t_data *data);

void	corewar_read_arg(t_data *data, int *value, unsigned char size, int pos);
void	corewar_write_arg(t_data *data, int value, unsigned char size, int pos);
int		corewar_8(int pos);

#endif
