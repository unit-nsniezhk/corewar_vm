/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_color.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:41:31 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 14:48:45 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_COLOR_H

# define COREWAR_VIS_COLOR_H

# define A(RGBA) (Uint8)((RGBA >> 24) & 255)
# define R(RGBA) (Uint8)((RGBA >> 16) & 255)
# define G(RGBA) (Uint8)((RGBA >> 8) & 255)
# define B(RGBA) (Uint8)(RGBA & 255)

# define RGBA_TEXT 0xFF66686A
# define RGBA_TEXT2 0xFFCCCCCC
# define RGBA_TEXT3 0xAAACACAC
# define RGBA_TEXTS 0xFF78A42B
# define RGBA_BUTTON 0xEA444444
# define PRESS -20
# define HOWER 20

# define RGBA_CARR 0x9FB4B4B4
# define CARR_OP 0x9F

# define RGBA_BG 0xFF2B2B2B
# define RGBA_SHADOW 0xFF44454A

# define EDGE_BRIGHT 0x64
# define RGBA_VALUE_BRIGHT 0xFFD2B4B4
# define RGBA_VALUE_DARK 0xFF141414

# define RGBA_PLAYER0 0xFF65655C
# define RGBA_PLAYER 0xFF78A42B
# define RGBA_PLAYER2 0xFF804980
# define RGBA_PLAYER3 0xFF999900
# define RGBA_PLAYER4 0xFFB96D40
# define PROCESS_INF_OP 0xD0
# define PlAYER_BAR_OP 0xCC
# define PLAYER_SHADOW_OP 0x30

static const unsigned int	g_color[MAX_PLAYERS + 1] =
{
	RGBA_PLAYER0,
	RGBA_PLAYER,
	RGBA_PLAYER2,
	RGBA_PLAYER3,
	RGBA_PLAYER4
};

#endif
