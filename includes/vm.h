/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 22:09:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "vm_defines.h"
# include "vm_parse_defines.h"

int		corewar_parse(t_parse *parse, unsigned int argc, const char **argv);
void	corewar_game(t_game_data *data, t_parse *parse);
int		corewar_game_loop(t_game_data *data);
void	corewar_dump(unsigned char *arena);

void	corewar_game_read_arg(t_game_data *data, int *arg_value,
		unsigned char arg_size, int arg_pos);

void	corewar_game_write_arg(t_game_data *data, int arg_value,
		unsigned char arg_size, int arg_pos);//TODO create function to loop memmory calls in ARENA SIZE using signed int

#endif
