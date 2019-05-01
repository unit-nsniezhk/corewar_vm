/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parse_defines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:29:37 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 12:40:03 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARSE_DEFINES_H

# define VM_PARSE_DEFINES_H

# include "vm_settings.h"

# define MODE_MAGIC_HEADER 1
# define MODE_NAME 2
# define MODE_NULL 3
# define MODE_CODE_SIZE 4
# define MODE_COMMENT 5

typedef struct		s_champ
{
	unsigned int	id;
	char			name[CHAMPION_NAME_LENGTH + 1];
	char			comment[CHAMPION_COMMENT_LENGTH + 1];
	unsigned int	code_size;
	unsigned char	*code;
}					t_champ;

typedef struct		s_parse
{
	unsigned int	dump;
	unsigned int	n_champs;
	unsigned int	pos;
	t_champ			champs[MAX_CHAMPIONS];
}					t_parse;

#endif
