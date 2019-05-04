/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_settings.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:12 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/03 19:25:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_SETTINGS_H

# define COREWAR_SETTINGS_H

# define N_OPS 16
# define N_REGS 16

# define REG 1
# define DIR 2
# define IND 3

# define TYPE_SIZE 3
# define OP_SIZE 1
# define ARGS_TYPES_SIZE 1
# define REG_SIZE 4
# define REG_LINK_SIZE 1
# define DIR_SIZE REG_SIZE
# define IND_SIZE 2

# define MAGIC_HEADER 0xea83f3
# define MAGIC_NULL 0

# define MIN_CHAMPIONS 1
# define MAX_CHAMPIONS 4
# define MAX_PLAYERS MAX_CHAMPIONS
# define MIN_PLAYERS MIN_CHAMPIONS

# define BASE_ARENA_SIZE 1024
# define ARENA_SIZE (MAX_CHAMPIONS * BASE_ARENA_SIZE)
# define IDX_MOD (ARENA_SIZE / 8)

# define MAGIC_HEADER_LENGTH 4
# define MAGIC_NULL_LENGTH 4
# define NAME_LENGTH 128
# define CODE_SIZE_LENGTH 4
# define COMMENT_LENGTH 2048
# define CODE_LENGTH (ARENA_SIZE / 6)

# define CYCLES_TO_CHECK 1536
# define MIN_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

# define DUMP_BYTES_PER_LINE 32

#endif
