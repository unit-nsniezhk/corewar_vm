/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:12 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 15:05:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_SETTINGS_H

# define VM_SETTINGS_H

# define OPERATIONS 16
# define REGISTERS 16

# define T_REG 1
# define T_DIR 2
# define T_IND 4

# define OPERATION_SIZE 1
# define ARGS_TYPES_SIZE 1
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE
# define IND_SIZE 2

# define MAGIC_HEADER 0xea83f3
# define MAGIC_NULL 0x0

# define MIN_CHAMPIONS 2
# define MAX_CHAMPIONS 4

# define BASE_ARENA_SIZE 1024
# define ARENA_SIZE MAX_CHAMPIONS * BASE_ARENA_SIZE

# define MAGIC_HEADER_LENGTH 4
# define MAGIC_NULL_LENGTH 4
# define CHAMPION_NAME_LENGTH 128
# define CHAMPION_CODE_SIZE_LENGTH 4
# define CHAMPION_COMMENT_LENGTH 2048
# define CHAMPION_CODE_LENGTH ARENA_SIZE / 6

# define IDX_MOD ARENA_SIZE / 8

# define CYCLE_TO_DIE 1536
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

# define DUMP_LINE 32

#endif
