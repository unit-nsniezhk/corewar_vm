/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:36:52 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 13:39:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARSE_H

# define VM_PARSE_H

# include "vm_parse_defines.h"

int	corewar_parse_options(t_parse *parse, const char **argv, unsigned int i);
int	corewar_parse_champion(t_parse *parse, const char *file);

#endif
